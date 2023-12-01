#include "proj2.h"
#include "proj3.h"
#include "proj4.h"
#include <stdio.h>

extern int st[ST_SIZE];

typedef struct objDeclList
{
    tree declNode;
    struct objDeclList *next;
    struct objDeclList *tail;
    
} ODL, *declList;


int dataStackOffset = 0;
int localStackOffset = 0;
int nextFuncOffset = -1;
int labelCount = 0;
int funcLabelCount = 0;
int strLabelCount = 0;
bool inMethod = false;
bool mainMethod = true;
bool fileCleared = false;
bool isNegative = false;
bool parsingArgs = false;
bool reinstating = false;
bool inCall = false;
int targetRegister = 11;
int functionCallIndx = -1;
int currentClassIndx = -1;

#define VarOpSTACK 0
#define VarOpT0 1
#define VarOpSTACKADDR 2
int varOpMethod = VarOpSTACK;
int stackPushCount = 0;
// struct argParse *argsHead = NULL;
int argsCount = 0;

void codeGen(tree node, int tabs){
    int indx;
    int id;
    int tempInt;
    char *name;
    char *emitVal[100], *labelName[100], *tempStr[100];
    tree childNode;

    if (node->NodeKind == NUMNode){
        if (inMethod){
            sprintf(emitVal, "li\t$%d\t%d\t\t#exp NUMNode $%d<-imme", targetRegister, node->IntVal, targetRegister);
            emit(emitVal, tabs);
            sprintf(emitVal, "sw\t$%d\t0($sp)\t\t#push imme on stack", targetRegister);
            emit(emitVal, tabs);
            emit("addi\t$sp\t$sp\t-4\t#increase st", tabs);
            stackPushCount++;
            localStackOffset += 4;
        }
        else{
            emit(".data", tabs);
            if (isNegative){
                sprintf(emitVal, ".word\t-%d\t\t\t#offset %d", node->IntVal, dataStackOffset);
            }
            else{
                sprintf(emitVal, ".word\t%d\t\t\t#offset %d", node->IntVal, dataStackOffset);
            }
            emit(emitVal, tabs);
            emit(".text", tabs);
            dataStackOffset += 4;
        }
        

        return;
    }

    if (node->NodeOpType == 0){
        return;
    }

    switch(node->NodeOpType){
        case ProgramOp:
            emit(".data", tabs);
            emit("Enter:\t.asciiz \"  \n\"", tabs);
            emit("base:", tabs);
            emit(".text", tabs);
            emit(".globl main", tabs);
            emit(".text", tabs);
            codeGen(node->LeftC, tabs);
            break;

        case CommaOp:
            if (parsingArgs){
                argsCount++;
                codeGen(node->RightC, tabs);
                tempInt = varOpMethod;
                if (GetAttr(functionCallIndx + argsCount, KIND_ATTR) == REF_ARG){
                    varOpMethod = VarOpSTACKADDR; // push address to stack
                }
                codeGen(node->LeftC, tabs);
                varOpMethod = tempInt;
                argsCount--;
                break;
            }
            // else continue
        case ClassOp:
        case BodyOp:
        case StmtOp:
        case ArrayTypeOp:
        
        case SpecOp:
            codeGen(node->LeftC, tabs);
            codeGen(node->RightC, tabs);
            break;

        case ClassDefOp:
            indx = IntVal(node->RightC);
            currentClassIndx = indx;
            SetAttr(currentClassIndx, DIMEN_ATTR, 0);
            SetAttr(indx, OFFSET_ATTR, dataStackOffset);
            nextFuncOffset = dataStackOffset;
            id =  GetAttr(indx, NAME_ATTR);
            name = getname(id);

            sprintf(emitVal, "# Class: %s\n", name);
            emit(emitVal, tabs);

            codeGen(node->LeftC, tabs + 1);

            sprintf(emitVal, "# End Class: %s\n", name);
            emit(emitVal, tabs);
            break;

        case MethodOp:
            indx = IntVal(node->LeftC->LeftC);
            id =  GetAttr(indx, NAME_ATTR);
            name = getname(id);

            sprintf(emitVal, "# Method: %s\n", name);
            emit(emitVal, tabs);

            bool prevMethod = mainMethod;

            tabs++;
            if (strcmp(name, "main") == 0) {
                emit("main:", tabs);
                emit("la\t$28\tbase\t\t#store global area address into $gp", tabs);
                emit("move\t$t1\t$28\t\t#init base", tabs);
                sprintf(emitVal, "add\t$t1\t$t1\t%d\t#init main access link in $t1; .data %d", nextFuncOffset, -1);
                emit(emitVal, tabs);
                emit("li\t$t2\t0\t\t#init $t2 as 0-global access", tabs);
                emit("move\t$fp\t$sp\t\t#init fp pointer", tabs);
                emit("sw\t$ra\t0($sp)\t\t#save return address on stack", tabs);
                emit("addi\t$sp\t$sp\t-4\t#increase st", tabs);
                stackPushCount++;
                mainMethod = true;
                
            }

            else{
                sprintf(emitVal, "%s_%d:", name, funcLabelCount++);
                SetAttr(indx, VALUE_ATTR, funcLabelCount-1);
                emit(emitVal, tabs);
                emit("lw\t$t1\t80($fp)\t\t#init base", tabs);
                emit("lw\t$t2\t84($fp)\t\t#init base", tabs);
                emit("sw\t$ra\t0($sp)\t\t#save return address on stack", tabs);
                emit("addi\t$sp\t$sp\t-4\t#increase st", tabs);
                stackPushCount++;
                mainMethod = false;


            }

            emit("", tabs);
            tempInt = argsCount;
            argsCount = 0;
            codeGen(node->LeftC, tabs);
            argsCount = tempInt;
            inMethod = true;
            localStackOffset = 4; // one item in the stack already

            codeGen(node->RightC, tabs);
            mainMethod = prevMethod;
            inMethod = false;
            emit("", tabs);

            emit_return(tabs);
            tabs--;
            sprintf(emitVal, "# End Method: %s\n", name);
            emit(emitVal, tabs);
            break;

        case HeadOp:
            codeGen(node->RightC, tabs);
            break;

        case DeclOp:{


            indx = IntVal(node->RightC->LeftC);
            id =  GetAttr(indx, NAME_ATTR);
            name = getname(id);

            sprintf(emitVal, "# Variable: %s", name);
            emit(emitVal, tabs);

            int startingOffset;
            if (inMethod){
                if (!reinstating){
                    SetAttr(indx, OFFSET_ATTR, localStackOffset);
                }
                
                startingOffset = localStackOffset;
            }
            else{
                int size = 4; // default to int
                if (GetAttr(indx, KIND_ATTR) == ARR){
                    size = 4 * node->RightC->RightC->RightC->LeftC->RightC->IntVal;
                }
                else if (GetAttr(indx, KIND_ATTR) == VAR){
                    tree type = GetAttr(indx, TYPE_ATTR);
                    if (type->LeftC->NodeKind == STNode){
                        
                        if (GetAttr(type->LeftC->IntVal, KIND_ATTR) == CLASS){
                            size = GetAttr(type->LeftC->IntVal, DIMEN_ATTR);
                        }
                        
                    }
                    
                }
                startingOffset = dataStackOffset;
                if (!reinstating){
                    SetAttr(currentClassIndx, DIMEN_ATTR, size + GetAttr(currentClassIndx, DIMEN_ATTR));
                    SetAttr(indx, OFFSET_ATTR, dataStackOffset - GetAttr(currentClassIndx, OFFSET_ATTR));
                    
                    declList p = (declList)malloc(sizeof(ODL));
                    p->declNode = node;
                    p->next = NULL;
                    p->tail = p;
                    if (IsAttr(currentClassIndx, TREE_ATTR)){
                        declList head = GetAttr(currentClassIndx, TREE_ATTR);
                        if (head->tail != NULL){
                            head->tail->next = p;
                        }
                        head->tail = p;
                    }
                    else{
                        SetAttr(currentClassIndx, TREE_ATTR, p);
                    }
                    
                }
                
            }
            
            codeGen(node->RightC, tabs);

            

            if ((inMethod && startingOffset == localStackOffset) || (!inMethod && startingOffset == dataStackOffset)){
                // no defined value, create one with default value
                emit("# Using default value", tabs);
                tree newNode = MakeLeaf(NUMNode, 0);
                int words = 1;
                if (node->RightC->RightC->LeftC->LeftC->NodeKind == STNode && GetAttr(node->RightC->RightC->LeftC->LeftC->IntVal, KIND_ATTR) == CLASS){
                    words = GetAttr(node->RightC->RightC->LeftC->LeftC->IntVal, DIMEN_ATTR) / 4;
                    declList cur = GetAttr(node->RightC->RightC->LeftC->LeftC->IntVal, TREE_ATTR);
                    reinstating = true;
                    while (cur != NULL){
                        codeGen(cur->declNode, tabs+1);
                        cur = cur->next;
                    }
                    reinstating = false;
                    // for (int i = 0; i < words; i++){
                    //     codeGen(newNode, tabs);
                    // }
                }
                else{
                    codeGen(newNode, tabs);
                }
                
                
                free(newNode);
            }

            emit("", tabs);

            if (!reinstating){
                codeGen(node->LeftC, tabs);
            }
            
            break;
        }

        case BoundOp:{
            if (inMethod){
                int i;
                for (i = 0; i < node->RightC->IntVal; i++){
                    emit("sw\t$0\t0($sp)\t\t#store $0 to stack top", tabs);
                    emit("addi\t$sp\t$sp\t-4\t#increase st", tabs);
                    stackPushCount++;
                    localStackOffset += 4;
                }
            }   
            else{
                emit(".data", tabs);
                int i;
                for (i = 0; i < node->RightC->IntVal; i++){
                    emit(".word 0", tabs);
                    dataStackOffset += 4;

                }

                emit(".text", tabs);
            }
            
            break;
        }

        case RoutineCallOp:{

            emit("", tabs);
            emit("# Function Call", tabs);
            tabs++;

            if (GetAttr(node->LeftC->LeftC->IntVal, NEST_ATTR) == 1){
            // if (GetAttr(node->LeftC->LeftC->IntVal, KIND_ATTR) == VAR && GetAttr(node->LeftC->RightC->LeftC->LeftC->IntVal, KIND_ATTR) == PROCE) {// instance
                int l0 = labelCount++;
                int l1 = labelCount++;
                sprintf(emitVal, "li	$11	%d		#load offset in $11", GetAttr(node->LeftC->LeftC->IntVal, OFFSET_ATTR));
                emit(emitVal, tabs);
                emit("add	$11	$11	0	#offr+field relative addr", tabs);
                sprintf(emitVal, "beqz	$t2	L_%d		#if called from a global obj", l0);
                emit(emitVal, tabs);
                emit("sub	$11	$t1	$11	#sub $offr from t1", tabs);
                sprintf(emitVal, "b	L_%d", l1);
                emit(emitVal, tabs);
                emit_label(l0, tabs);
                emit("add	$11	$11	$t1	#add $offr with base", tabs);
                emit_label(l1, tabs);
                emit("move\t$25\t$11\t\t#$offr=>$t25, base address", tabs);
                emit("move\t$24\t$t2\t\t#$offr=>$t24, flag", tabs);
                emit("sw\t$24\t0($sp)\t\t#push base $t2", tabs);
                emit("addi\t$sp\t$sp\t-4\t#push st", tabs);
                stackPushCount++;
                emit("sw\t$25\t0($sp)\t\t#push base $t1", tabs);
                emit("addi\t$sp\t$sp\t-4\t#push st", tabs);
                stackPushCount++;
            }

            else if (GetAttr(node->LeftC->LeftC->IntVal, KIND_ATTR) == VAR && GetAttr(node->LeftC->RightC->LeftC->LeftC->IntVal, KIND_ATTR) == VAR ){
                //local on stack
                sprintf(emitVal, "li	$11	%d		#load offset in $11", GetAttr(node->LeftC->LeftC->IntVal, OFFSET_ATTR));
                emit(emitVal, tabs);
                sprintf(emitVal, "add	$11	$11	%d	#offr+field relative addr", GetAttr(node->LeftC->RightC->LeftC->LeftC->IntVal, OFFSET_ATTR));
                emit(emitVal, tabs);
                emit("add	$11	$11	0	#offr+field relative addr", tabs);
                emit("sub	$11	$fp	$11	#absoult addr by $fp", tabs);
                emit("move	$25	$11		#$offr=>$t25, base address", tabs);
                emit("li	$24	1\t\t#routine call from a local on stack", tabs);
                emit("sw\t$24\t0($sp)\t\t#push base $t2", tabs);
                emit("addi\t$sp\t$sp\t-4\t#push st", tabs);
                stackPushCount++;
                emit("sw\t$25\t0($sp)\t\t#push base $t1", tabs);
                emit("addi\t$sp\t$sp\t-4\t#push st", tabs);
                stackPushCount++;
            }

            else {//if ((GetAttr(node->LeftC->LeftC->IntVal, KIND_ATTR) == CLASS)){// class
                sprintf(emitVal, "li\t$11\t%d\t\t#load offset in $11", GetAttr(node->LeftC->LeftC->IntVal, OFFSET_ATTR));
                emit(emitVal, tabs);
                emit("add\t$11\t$11\t0\t#offr+field relative addr", tabs);
                emit("add\t$11\t$11\t$gp\t#class.---, add to t1 base", tabs);
                emit("move\t$25\t$11\t\t#$offr=>$t25, base address", tabs);
                emit("move\t$24\t$t2\t\t#$offr=>$t24, flag", tabs);
                emit("sw\t$24\t0($sp)\t\t#push base $t2", tabs);
                emit("addi\t$sp\t$sp\t-4\t#push st", tabs);
                stackPushCount++;
                emit("sw\t$25\t0($sp)\t\t#push base $t1", tabs);
                emit("addi\t$sp\t$sp\t-4\t#push st", tabs);
                stackPushCount++;
            }
            
            // check for system call
            if (node->LeftC->LeftC->NodeKind == STNode){
                indx = IntVal(node->LeftC->LeftC);
                id =  GetAttr(indx, NAME_ATTR);
                name = getname(id);
                if (strcmp(name, "system") == 0){
                    
                    

                    indx = IntVal(node->LeftC->RightC->LeftC->LeftC);
                    id =  GetAttr(indx, NAME_ATTR);
                    name = getname(id);
                    if (strcmp(name, "println") == 0){
                        emit_printCallOp(node, tabs);
                    }
                    else if (strcmp(name, "readln") == 0){
                        emit_readln(node, tabs);
                    }
                    tabs--;
                    emit("# End Function Call", tabs);
                    emit("", tabs);
                    break;
                }
            }

            tree type = (tree)GetAttr(node->LeftC->LeftC->IntVal, TYPE_ATTR);
            
            tree lastSelect = node->LeftC->RightC;
            while (lastSelect->NodeKind != DUMMYNode && lastSelect->RightC->NodeOpType == SelectOp){
                lastSelect = lastSelect->RightC;
            }
            if (type != NULL && type->LeftC->NodeKind == STNode && GetAttr(type->LeftC->IntVal, KIND_ATTR) == CLASS){
                // get class func (instanced object)

                indx = IntVal(lastSelect->LeftC->LeftC);
            }
            else if (GetAttr(node->LeftC->LeftC->IntVal, KIND_ATTR) == CLASS){
                // get class func
                indx = IntVal(lastSelect->LeftC->LeftC);
            }
            else{
                // get func
                indx = IntVal(node->LeftC->LeftC);
            }

            
            
            id =  GetAttr(indx, NAME_ATTR);
            name = getname(id);

            sprintf(tempStr, "%s_%d", name, GetAttr(indx, VALUE_ATTR));
            emit_call(tempStr, node, tabs);
            
            emit("addi\t$sp\t$sp\t4\t#pop st", tabs);
            stackPushCount--;
            emit("addi\t$sp\t$sp\t4\t#pop st", tabs);
            stackPushCount--;
            emit("addi\t$sp\t$sp\t4\t#pop st", tabs);
            stackPushCount--;
            emit("sw\t$v1\t0($sp)", tabs);
            emit("addi\t$sp\t$sp\t-4\t#push st", tabs);
            stackPushCount++;

            tabs--;
            emit("# End Function Call", tabs);
            emit("", tabs);

            break;
        }

        case IfElseOp:{
            int elseLabel = labelCount++;
            int endLabel = labelCount++;

            emit("# If Stmt", tabs);
            emit_ifElse(node, elseLabel, endLabel, tabs+1);

            if (node->RightC->NodeOpType == StmtOp){
                emit("# Else", tabs+1);
                codeGen(node->RightC, tabs+1);
                emit("# End Else", tabs+1);
            }

            emit_label(endLabel, tabs);
            emit("# End If Stmt", tabs);


            break;
        }

        case IndexOp:{
            codeGen(node->LeftC, tabs);
            codeGen(node->RightC, tabs);
            break;
        }

        case VarOp:{
            indx = IntVal(node->LeftC);
            switch(GetAttr(indx, KIND_ATTR)){
                case CLASS:
                    sprintf(emitVal, "li\t$11\t%d\t\t#load class offset in $11", GetAttr(indx, OFFSET_ATTR));
                    emit(emitVal, tabs);
                    sprintf(emitVal, "add\t$11\t$11\t%d\t#add field relative offset", GetAttr(IntVal(node->RightC->LeftC->LeftC), OFFSET_ATTR));
                    emit(emitVal, tabs);
                    emit("add\t$11\t$11\t$gp\t\t#class.---, add to t1 base", tabs);
                    break;

                case ARR:
                    sprintf(emitVal, "li\t$11\t%d\t\t#load offset in $11", GetAttr(indx, OFFSET_ATTR));
                    emit(emitVal, tabs);

                    targetRegister++;
                    codeGen(node->RightC->LeftC, tabs); // index op
                    targetRegister--;
                    // sprintf(emitVal, "li\t$12\t%d\t\t#exp NUMNode $12<-imme", node->RightC->LeftC->LeftC->IntVal);
                    // emit(emitVal, tabs);
                    // emit("sw\t$12\t0($sp)\t\t#push imme on stack", tabs);
                    // emit("addi\t$sp\t$sp\t-4\t#increase st", tabs);

                    emit("lw\t$v0\t4($sp)\t\t#stack top -> $v0", tabs);
                    emit("sll\t$v0\t$v0\t2\t#shift $v0 2 bits left", tabs);
                    emit("addi\t$sp\t$sp\t4", tabs);
                    stackPushCount--;
                    emit("add\t$11\t$11\t$v0\t#offr=base+i*width", tabs);
                    // no break;

                case VAR:
                    if (GetAttr(indx, KIND_ATTR) == VAR){
                        sprintf(emitVal, "li\t$%d\t%d\t\t#load offset in $%d", targetRegister, GetAttr(indx, OFFSET_ATTR), targetRegister);
                        emit(emitVal, tabs);
                        codeGen(node->RightC, tabs);
                        
                    }

                    if (GetAttr(indx, NEST_ATTR) > 1){
                        sprintf(emitVal, "sub\t$%d\t$fp\t$%d\t#absoult addr by $fp", targetRegister, targetRegister);
                        emit(emitVal, tabs);
                    }
                    else{
                            int L0 = labelCount++;
                            int L1 = labelCount++;
                            sprintf(emitVal, "beqz\t$t2\tL_%d\t\t#if called from a global obj", L0);
                            emit(emitVal, tabs);

                            sprintf(emitVal, "sub\t$%d\t$t1\t$%d\t#sub $offr from t1", targetRegister, targetRegister);
                            emit(emitVal, tabs);

                            sprintf(emitVal, "b\tL_%d", L1);
                            emit(emitVal, tabs);

                            sprintf(emitVal, "L_%d:", L0);
                            emit(emitVal, tabs);

                            sprintf(emitVal, "add\t$%d\t$%d\t$t1\t#add $offr with base", targetRegister, targetRegister);
                            emit(emitVal, tabs);

                            sprintf(emitVal, "L_%d:", L1);
                            emit(emitVal, tabs);
                    }
                    break;

                case VALUE_ARG:
                    sprintf(emitVal, "li\t$11\t%d\t\t#load offset in $11", GetAttr(indx, OFFSET_ATTR));
                    emit(emitVal, tabs);
	                emit("add\t$11\t$fp\t$11\t#reference arg is above fp", tabs);
                    localStackOffset += 4;
                    break;

                case REF_ARG:
                    sprintf(emitVal, "li\t$11\t%d\t\t#load offset in $11", GetAttr(indx, OFFSET_ATTR));
                    emit(emitVal, tabs);
	                emit("add\t$11\t$fp\t$11\t#reference arg is above fp", tabs);
                    emit("lw\t$11\t($11)\t\t#get ref_arg", tabs);
                    localStackOffset += 4;

				
                    break;

                default:
                    emit("[UNK Var kind]", tabs);
            }

            switch (varOpMethod){
                case VarOpT0:
                    if (targetRegister == 11){
                        emit("move\t$t0\t$11\t\t#$offr=>$t0, return address", tabs);
                        break;
                    }
                case VarOpSTACK:
                    sprintf(emitVal, "lw\t$%d\t($%d)\t\t#load value from ($%d) to t%d", targetRegister+1, targetRegister, targetRegister+1, targetRegister);
                    emit(emitVal, tabs);

                    sprintf(emitVal, "sw\t$%d\t0($sp)\t\t#push value on stack", targetRegister+1);
                    emit(emitVal, tabs);
                    emit("addi\t$sp\t$sp\t-4\t#increase st", tabs);
                    stackPushCount++;
                    break;

                case VarOpSTACKADDR:
                    emit("move\t$t0\t$11\t\t#$offr=>$t0, return address", tabs);
                    emit("sw\t$t0\t0($sp)\t\t#push arg address", tabs);
                    emit("addi\t$sp\t$sp\t-4\t#increase st", tabs);
                    stackPushCount++;
                    break;
                
            }
            break;
        }

        case VArgTypeOp:
        case RArgTypeOp:{
            argsCount++;
            indx = node->LeftC->LeftC->IntVal;
            SetAttr(indx, OFFSET_ATTR, argsCount*4);
            codeGen(node->RightC, tabs);
            break;
        }

        case SelectOp:{
            switch (node->LeftC->NodeOpType){
                case FieldOp:{
                    tree type = (tree)GetAttr(node->LeftC->LeftC->IntVal, TYPE_ATTR);
                    if (type != 0 && type->LeftC->NodeKind == STNode && GetAttr(type->LeftC->IntVal, KIND_ATTR) == CLASS){
                        sprintf(emitVal, "add\t$11\t$11\t%d\t#offr+field relative addr", GetAttr(node->LeftC->LeftC->IntVal, OFFSET_ATTR));
                        emit(emitVal, tabs);
                    }
                    else if (node->LeftC->LeftC->NodeKind == STNode){
                        sprintf(emitVal, "add\t$11\t$11\t%d\t#offr+field relative addr", GetAttr(node->LeftC->LeftC->IntVal, OFFSET_ATTR));
                        emit(emitVal, tabs);
                    }
                    codeGen(node->RightC, tabs);
                    break;
                }
                case IndexOp:{
                    targetRegister++;
                    codeGen(node->LeftC, tabs);
                    targetRegister--;

                    emit("lw\t$v0\t4($sp)\t\t#stack top -> $v0", tabs);
                    emit("sll\t$v0\t$v0\t2\t#shift $v0 2 bits left", tabs);
                    emit("addi\t$sp\t$sp\t4", tabs);
                    stackPushCount--;
                    emit("add\t$11\t$11\t$v0\t#offr=base+i*width", tabs);
                    
                    
                    break;
                }
                default:
                    emit("UNK SELECT_OP", tabs);
            }
            
            break;
        }

        case UnaryNegOp:{
            if (inMethod){
                codeGen(node->LeftC, tabs);
                emit("lw\t$11\t4($sp)\t\t#stack top -> $11", tabs);
                emit("neg\t$11\t$11\t\t#unaryneg", tabs);
                emit("sw\t$11\t4($sp)\t\t#push value on stack", tabs);
            }
            else{
                isNegative = true;
                codeGen(node->LeftC, tabs);
            }
            break;
        }

        case AddOp:{
            codeGen(node->LeftC, tabs);
            codeGen(node->RightC, tabs);
            sprintf(emitVal, "lw\t$%d\t4($sp)\t\t#stack top -> $%d", targetRegister, targetRegister);
            emit(emitVal, tabs);
            emit("addi\t$sp\t$sp\t4\t#pop st", tabs);
            stackPushCount--;
            sprintf(emitVal, "lw\t$%d\t4($sp)\t\t#stack top -> $%d", targetRegister+1, targetRegister+1);
            emit(emitVal, tabs);
            sprintf(emitVal, "add\t$%d\t$%d\t$%d\t#add r1 to r2", targetRegister, targetRegister+1, targetRegister);
            emit(emitVal, tabs);
            sprintf(emitVal, "sw\t$%d\t4($sp)\t\t#push the sum on stack", targetRegister);
            stackPushCount++;
            emit(emitVal, tabs);
            break;
        }

        case MultOp:{
            codeGen(node->LeftC, tabs);
            codeGen(node->RightC, tabs);

            emit("lw\t$11\t4($sp)\t\t#stack top -> $11", tabs);
            emit("addi\t$sp\t$sp\t4\t#pop st", tabs);
            stackPushCount--;
            emit("lw\t$12\t4($sp)\t\t#stack top -> $12", tabs);
            emit("mul\t$11\t$12\t$11\t#add r1 to r2", tabs);
            emit("sw\t$11\t4($sp)\t\t#push the sum on stack", tabs);

            break;
        }

        case SubOp:{
            codeGen(node->LeftC, tabs);
            codeGen(node->RightC, tabs);

            sprintf(emitVal, "lw\t$%d\t4($sp)\t\t#stack top -> $%d", targetRegister, targetRegister);
            emit(emitVal, tabs);
            emit("addi\t$sp\t$sp\t4\t#pop st", tabs);
            stackPushCount--;
            sprintf(emitVal, "lw\t$%d\t4($sp)\t\t#stack top -> $%d", targetRegister+1, targetRegister+1);
            emit(emitVal, tabs);
            sprintf(emitVal, "sub\t$%d\t$%d\t$%d\t#add r1 to r2", targetRegister, targetRegister+1, targetRegister);
            emit(emitVal, tabs);
            sprintf(emitVal, "sw\t$%d\t4($sp)\t\t#push the sum on stack", targetRegister);
            emit(emitVal, tabs);
            break;
        }

        case AssignOp:{

            codeGen(node->LeftC, tabs);

            if (node->RightC->NodeOpType == VarOp && node->LeftC->NodeKind == DUMMYNode){
                indx = IntVal(node->RightC->LeftC);
                // id =  GetAttr(indx, NAME_ATTR);
                // name = getname(id);
                // printf("%s\n", name);
                if (true){//(GetAttr(indx, KIND_ATTR) != ARR){
                // if (node->LeftC->NodeKind == DUMMYNode && (node->RightC->NodeOpType != VarOp || GetAttr(node->RightC->LeftC, TYPE_ATTR) != ARR)){
                    varOpMethod = VarOpT0;
                }
            }
            
            
            codeGen(node->RightC, tabs);
            varOpMethod = VarOpSTACK;
            breakFunc();
            if (node->LeftC->NodeOpType == AssignOp){
            // if (node->RightC->NodeOpType == RoutineCallOp || node->RightC->NodeKind == NUMNode || node->RightC == AddOp || node->RightC == MultOp){
                emit("lw\t$v0\t4($sp)\t\t#stack top -> $v0", tabs); // put RHS into result register
                emit("sw\t$v0\t0($t0)\t\t# (t0):=v0", tabs); // store the result in stack at address of variable
                emit("addi\t$sp\t$sp\t4\t#pop st", tabs);
                stackPushCount--;
            }

            break;
        }

        case ReturnOp:{
            codeGen(node->LeftC, tabs);
            codeGen(node->RightC, tabs);

            emit("lw\t$v1\t4($sp)\t\t#copy return value to register v1", tabs);

            break;
        }

        case GEOp:
            emit("sge\t$11\t$12\t$11\t#greater than or equal", tabs);
            break;
        case GTOp:
            emit("sgt\t$11\t$12\t$11\t#greater than", tabs);
            break;
        case LEOp:
            emit("sle\t$11\t$12\t$11\t#Less than or equal", tabs);
            break;
        case LTOp:
            emit("slt\t$11\t$12\t$11\t#add r1 to r2", tabs);
            break;
        case EQOp:
            emit("seq\t$11\t$12\t$11\t#add r1 to r2", tabs);
            break;

        case LoopOp:{
            int loopEnd = labelCount++;
            int loopBegin = labelCount++;
            
            emit("# Begin Loop Eval", tabs);
            emit_label(loopBegin, tabs);
            codeGen(node->LeftC->LeftC, tabs);
            codeGen(node->LeftC->RightC, tabs);

            emit("lw\t$11\t4($sp)\t\t#stack top -> $11", tabs);
            emit("addi\t$sp\t$sp\t4\t#pop st", tabs);
            stackPushCount--;
            emit("lw\t$12\t4($sp)\t\t#stack top -> $12", tabs);

            codeGen(node->LeftC, tabs);

            emit("sw\t$11\t4($sp)\t\t#push result to stack", tabs);
            stackPushCount++;
            emit("lw\t$11\t4($sp)\t\t#store boolean result in register", tabs);
            
            sprintf(emitVal, "beqz\t$11\tL_%d\t\t#boolean false, jump to the end of while", loopEnd);
            emit(emitVal, tabs);

            emit("# Begin Loop Stmt", tabs);
            codeGen(node->RightC, tabs);

            sprintf(emitVal, "b\tL_%d\t\t\t#go to the loop beginning", loopBegin);
            emit(emitVal, tabs);

            emit("# End Loop", tabs);
            emit_label(loopEnd, tabs);
            break;
        }

        case TypeIdOp:
            break;

        default:
            breakFunc();
            sprintf(emitVal, "Kind:%d OpType:%d OpName:", node->NodeKind, node->NodeOpType);
            emit(emitVal, tabs);
            printNode(node);
            break;
    }


}

void emit_printCallOp(tree node, int tabs){
    char *labelName[100], *tempStr[100], *emitVal[100];

    if (node->RightC->LeftC->NodeKind == STRINGNode){
        sprintf(labelName, "S_%d", strLabelCount++);
        sprintf(tempStr, "\"%s\"", getstring(node->RightC->LeftC->IntVal));
        emit_str_def(labelName, tempStr, tabs);
    }

    


    if (node->RightC->LeftC->NodeKind == STRINGNode){
        emit("li\t$v0\t4\t\t#print_str", tabs);
        sprintf(emitVal, "la\t$a0\t%s\t\t#address of string to print", labelName);
        emit(emitVal, tabs);
        emit("syscall\t\t\t\t#print the arg", tabs);
    }
    else{
        codeGen(node->RightC->LeftC, tabs);

        emit("li\t$v0\t1\t\t#print_int", tabs);
        emit("lw\t$a0\t4($sp)\t\t#integer to print", tabs);
        emit("syscall\t\t\t\t#print the arg", tabs);
        emit("li\t$v0\t4\t\t#print_str", tabs);
        emit("la\t$a0\tEnter\t\t#address of entering to print", tabs);
        emit("syscall\t\t\t\t#print the arg", tabs);
    }

    
}

void emit_readln(tree node, int tabs){
    emit("sw\t$25\t0($sp)\t\t#push base $t1", tabs);
    emit("addi\t$sp\t$sp\t-4\t#push st", tabs);
    stackPushCount++;
    emit("li\t$v0\t5\t\t#system call code for read_int", tabs);
    emit("syscall", tabs);
    emit("li\t$11\t4\t\t#load offset in $11", tabs);
    emit("sub\t$11\t$fp\t$11\t#absoult addr by $fp", tabs);
    emit("move\t$t0\t$11\t\t#$offr=>$t0, return address", tabs);
    emit("sw\t$v0\t($t0)\t\t#save readln result in ($t0)", tabs);
}

void emit_ifElse(tree node, int elseLabel, int endLabel, int tabs){
    char *emitVal[100];

    if (node->LeftC->NodeOpType == IfElseOp){
        int myLabel = labelCount++;
        emit_ifElse(node->LeftC, myLabel, endLabel, tabs);
    }
    if (node->RightC->NodeOpType == StmtOp){
        // on else node, already taken care of in codeGen
        return;
    }

    tree evalNode = node->RightC->LeftC;

    codeGen(evalNode->LeftC, tabs);
    codeGen(evalNode->RightC, tabs);

    emit("lw\t$11\t4($sp)\t\t#stack top -> $11", tabs);
    emit("addi\t$sp\t$sp\t4\t#pop st", tabs);
    stackPushCount--;
    emit("lw\t$12\t4($sp)\t\t#stack top -> $12", tabs);

    codeGen(node->RightC->LeftC, tabs);

    emit("sw\t$11\t4($sp)\t\t#push result to stack", tabs);
    emit("lw\t$11\t4($sp)\t\t#store boolean result in register", tabs);
    sprintf(emitVal, "beqz\t$11\tL_%d\t\t#$11 == 0 ? if false, jump to L_%d", elseLabel, elseLabel);
    emit(emitVal, tabs);

    emit("# IfElse True", tabs);
    codeGen(node->RightC->RightC, tabs+1);
    sprintf(emitVal, "b\tL_%d\t\t\t#true branch end, jump to end_if", endLabel);
    emit(emitVal, tabs+1);
    emit_label(elseLabel, tabs);
}

void emit_call(char* func_name, tree node, int tabs){
    /*emit a call instruction;
    func name: function id lexeme pointer;
    num arg: number of arguments */
    char * emitVal[100];

    

    emit("sw\t$fp\t0($sp)\t\t#push $fp ", tabs);
	emit("addi\t$sp\t$sp\t-4\t#push st", tabs);
    stackPushCount++;

    int i;
    for (i = 8; i <= 25; i++){
        sprintf(emitVal, "sw\t$%d\t0($sp)\t\t#save $%d", i, i);
        emit(emitVal, tabs);
        emit("addi\t$sp\t$sp\t-4\t#push st", tabs);
        stackPushCount++;
    }

    // args p = (args)malloc(sizeof(argNode));
    // p->next = argsHead;
    // argsHead = p;
    int tempInt = stackPushCount;
    int tempPrevArgs = argsCount;
    int prevFunctionCallIndx = functionCallIndx;
    bool prevInCall = inCall;
    inCall = true;
    parsingArgs = true;
    argsCount = 0;
    functionCallIndx = node->LeftC->LeftC->IntVal;
    codeGen(node->RightC, tabs); // params
    inCall = prevInCall;
    functionCallIndx = prevFunctionCallIndx;
    argsCount = tempPrevArgs;
    parsingArgs = false;
    int num_arg = stackPushCount - tempInt;
    // int argCount = argsHead->count;
    // argsHead = p->next;
    // free(p);
    SetAttr(node->LeftC->LeftC->IntVal, ARGNUM_ATTR, num_arg);



    emit("move\t$fp\t$sp\t\t#increase fp", tabs);
    sprintf(emitVal, "jal\t%s\t\t#function call", func_name);
    emit(emitVal, tabs);
    sprintf(emitVal, "add\t$sp\t%d\t\t#pop %d arguments", num_arg*4, num_arg);
    emit(emitVal, tabs);
    for (i = 25; i >= 8; i--){
        sprintf(emitVal, "lw\t$%d\t4($sp)\t\t#restore register %d", i, i);
        emit(emitVal, tabs);
        emit("addi\t$sp\t$sp\t4\t#pop st", tabs);
        stackPushCount--;
    }
    emit("lw\t$fp\t4($sp)\t\t#restore fp", tabs);
}

void emit_return(int tabs){
    emit("lw\t$ra\t0($fp)\t\t#get back control line", tabs);
    emit("move\t$sp\t$fp\t\t#pop stack to fp", tabs);
    emit("jr\t$ra\t\t\t#routine call return", tabs);
}

void get_label(int l_num, char *result){
    sprintf(result, "L_%d", l_num);
}

void emit_label(int l_num, int tabs){
    /*emit a definition of a label;
    l num: label number; example: L=102, code
    generated = “L_102” */
    char *formattedString[10];
    char *label[10];
    get_label(l_num, label);
    sprintf(formattedString, "%s:", label);
    emit(formattedString, tabs);
    return;
}

void emit_goto(operator, l_num){
    /*emit unconditional and conditional jump instructions;
    operator: an operator in the branch-jump group;
    l num: label number */
    return;
}

void emit_data(name, type, size){
    /* emit one data line, which is used for STATIC allocation;
    name: data object id lexeme pointer;
    type: type width;
    size: number of elements of above type */
   return;
}

int emit_str_def(char* name, char* str, int tabs){
    /* emit a string constant definition line;
    name: pointer to the name lexeme;
    str: pointer to the str */
    int stringLength = strlen(str);
    emit(".data", tabs);
    emit(".align 2", tabs);
    char * emitVal[100];
    sprintf(emitVal, "%s:\t.asciiz\t%s", name, str);
    emit(emitVal, tabs);
    emit(".text", tabs);

    dataStackOffset += stringLength;
    if (stringLength % 4 != 0){
        dataStackOffset += (4 - (stringLength % 4));
    }
}

void emit(char *instruction, int tabs){
    
    FILE *file;
    if (fileCleared){
        file = fopen("mycode.s", "a");FILE *file = fopen("mycode.s", "a");
    }
    else{
        file = fopen("mycode.s", "w");FILE *file = fopen("mycode.s", "a");
        fileCleared = true;
    }
    
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1; // Return an error code
    }

    // Write text to the file
    int i;
    for (i = 0; i < tabs; i++){
        printf("\t");
        fprintf(file, "\t");
    }
    printf("%s\n", instruction);
    fprintf(file, "%s\n", instruction);

    // Close the file
    fclose(file);

}

void breakFunc(){
    // for gdb to break on
}

extern char *opnodenames [];

void printDeclList(declList head){
    if (head == NULL){
        return;
    }
    printtree(head->declNode, 0);
    printDeclList(head->next);
}

printNode(tree nd){
    int indx;
    int id;
    char* treelst = "";
    switch (NodeKind (nd))
  {
    case IDNode:
            indx = IntVal(nd);
            if (indx >= 0)
            {
              id = indx; /*GetAttr(indx, NAME_ATTR); */
              printf("[IDNode,%d,\"%s\"]\n", IntVal(nd),
                                                    getname(id));
            }
            else
              printf("[IDNode,%d,\"%s\"]\n", indx, "err");
            break;

    case STNode:
                    indx = IntVal(nd);
                    if (indx > 0)
                    {
                      id =  GetAttr(indx, NAME_ATTR);
                      printf("[STNode,%d,\"%s\"]\n", IntVal(nd),
                                                    getname(id));
                    }
                    else
                      printf("[IDNode,%d,\"%s\"]\n", indx, "err");
                    break;

    case INTEGERTNode:
                      printf("[INTEGERTNode]\n");
                    break;

    case NUMNode:   printf("[NUMNode,%d]\n", IntVal (nd));
            break;

    case CHARNode:  if (isprint (IntVal (nd)))
              printf("[CHARNode,%d,\'%c\']\n",
                     IntVal (nd), IntVal (nd));
            else
              printf("[CHARNode,%d,\'\\%o\']\n",
                     IntVal (nd), IntVal (nd));
            break;

    case STRINGNode:printf("[STRINGNode,%d,\"%s\"]\n", IntVal (nd),
                            getstring(IntVal(nd)));
            break;

    case EXPRNode:  printf("[%s]\n",
                    opnodenames [NodeOp(nd) - ProgramOp]);
            break;

    case DUMMYNode:  printf("[DUMMYnode]\n");
            break;


    default:        printf("INVALID!!!\n");
            break;
  }
}