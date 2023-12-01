.data
Enter:  .asciiz "  
"
base:
.text
.globl main
.text
# Class: rect

        # Variable: length
        .data
        .word   7                       #offset 0
        .text

        # Variable: width
        .data
        .word   3                       #offset 4
        .text

        # Method: getarea

                getarea_7:
                lw      $t1     80($fp)         #init base
                lw      $t2     84($fp)         #init base
                sw      $ra     0($sp)          #save return address on stack
                addi    $sp     $sp     -4      #increase st


                # Function Call
                        li      $11     0               #load offset in $11
                        add     $11     $11     0       #offr+field relative addr
                        add     $11     $11     $gp     #class.---, add to t1 base
                        move    $25     $11             #$offr=>$t25, base address
                        move    $24     $t2             #$offr=>$t24, flag
                        sw      $24     0($sp)          #push base $t2
                        addi    $sp     $sp     -4      #push st
                        sw      $25     0($sp)          #push base $t1
                        addi    $sp     $sp     -4      #push st
                        .data
                        .align 2
                        S_1:    .asciiz "test case 2:  "
                        .text
                        li      $v0     4               #print_str
                        la      $a0     S_1             #address of string to print
                        syscall                         #print the arg

                # Function Call
                        li      $11     0               #load offset in $11
                        add     $11     $11     0       #offr+field relative addr
                        add     $11     $11     $gp     #class.---, add to t1 base
                        move    $25     $11             #$offr=>$t25, base address
                        move    $24     $t2             #$offr=>$t24, flag
                        sw      $24     0($sp)          #push base $t2
                        addi    $sp     $sp     -4      #push st
                        sw      $25     0($sp)          #push base $t1
                        addi    $sp     $sp     -4      #push st
                        li      $11     4               #load offset in $11
                        beqz    $t2     L_2             #if called from a global obj
                        sub     $11     $t1     $11     #sub $offr from t1
                        b       L_3
                        L_2:
                        add     $11     $11     $t1     #add $offr with base
                        L_3:
                        lw      $12     ($11)           #load value from ($11) to t12
                        sw      $12     0($sp)          #push value on stack
                        addi    $sp     $sp     -4      #increase st
                        li      $v0     1               #print_int
                        lw      $a0     4($sp)          #integer to print
                        syscall                         #print the arg
                        li      $v0     4               #print_str
                        la      $a0     Enter           #address of entering to print
                        syscall                         #print the arg

                # Function Call
                        li      $11     0               #load offset in $11
                        add     $11     $11     0       #offr+field relative addr
                        add     $11     $11     $gp     #class.---, add to t1 base
                        move    $25     $11             #$offr=>$t25, base address
                        move    $24     $t2             #$offr=>$t24, flag
                        sw      $24     0($sp)          #push base $t2
                        addi    $sp     $sp     -4      #push st
                        sw      $25     0($sp)          #push base $t1
                        addi    $sp     $sp     -4      #push st
                        li      $11     0               #load offset in $11
                        beqz    $t2     L_4             #if called from a global obj
                        sub     $11     $t1     $11     #sub $offr from t1
                        b       L_5
                        L_4:
                        add     $11     $11     $t1     #add $offr with base
                        L_5:
                        lw      $12     ($11)           #load value from ($11) to t12
                        sw      $12     0($sp)          #push value on stack
                        addi    $sp     $sp     -4      #increase st
                        li      $v0     1               #print_int
                        lw      $a0     4($sp)          #integer to print
                        syscall                         #print the arg
                        li      $v0     4               #print_str
                        la      $a0     Enter           #address of entering to print
                        syscall                         #print the arg
                li      $11     4               #load offset in $11
                beqz    $t2     L_6             #if called from a global obj
                sub     $11     $t1     $11     #sub $offr from t1
                b       L_7
                L_6:
                add     $11     $11     $t1     #add $offr with base
                L_7:
                lw      $12     ($11)           #load value from ($11) to t12
                sw      $12     0($sp)          #push value on stack
                addi    $sp     $sp     -4      #increase st
                li      $11     0               #load offset in $11
                beqz    $t2     L_88            #if called from a global obj
                sub     $11     $t1     $11     #sub $offr from t1
                b       L_99
                L_88:
                add     $11     $11     $t1     #add $offr with base
                L_99:
                lw      $12     ($11)           #load value from ($11) to t12
                sw      $12     0($sp)          #push value on stack
                addi    $sp     $sp     -4      #increase st
                lw      $11     4($sp)          #stack top -> $11
                addi    $sp     $sp     4       #pop st
                lw      $12     4($sp)          #stack top -> $12
                mul     $11     $12     $11     #add r1 to r2
                sw      $11     4($sp)          #push the sum on stack
                lw      $v1     4($sp)          #copy return value to register v1

                lw      $ra     0($fp)          #get back control line
                move    $sp     $fp             #pop stack to fp
                jr      $ra                     #routine call return
        # End Method: getarea

# End Class: rect

# Class: mc

        # Variable: len
        .data
        .word   0                       #offset 24
        .text

        # Method: main

main:
                la      $28     base            #store global area address into $gp
                move    $t1     $28             #init base
                add     $t1     $t1     24      #init main access link in $t1; .data -1
                li      $t2     0               #init $t2 as 0-global access
                move    $fp     $sp             #init fp pointer
                sw      $ra     0($sp)          #save return address on stack
                addi    $sp     $sp     -4      #increase st

				# Variable: area
                li      $11     0               #load immediate 0 to t11
                sw      $11     0($sp)          #store t11 to stack top
                addi    $sp     $sp     -4      #increase st

				# If Stmt
						li      $11     0               #load class offset in $11
                        add     $11     $11     4       #add field relative offset
                        add     $11     $11     $gp             #class.---, add to t1 base
                        lw      $12     ($11)           #load value from ($11) to t12
                        sw      $12     0($sp)          #push value on stack
                        addi    $sp     $sp     -4      #increase st
                        li      $11     0               #exp NUMNode $11<-imme
                        sw      $11     0($sp)          #push imme on stack
                        addi    $sp     $sp     -4      #increase st
                        lw      $11     4($sp)          #stack top -> $11
                        addi    $sp     $sp     4       #pop st
                        lw      $12     4($sp)          #stack top -> $12
                        sgt     $11     $12     $11     #greater than
                        sw      $11     4($sp)          #push result to stack
                        lw      $11     4($sp)          #store boolean result in register
						beqz	$11	L_9		#if false, jump to L_9
						# IfElse True
                                li      $11     0               #load class offset in $11
                                add     $11     $11     4       #add field relative offset
                                add     $11     $11     $gp             #class.---, add to t1 base
                                move    $t0     $11             #$offr=>$t0, return address
                                li      $11     5               #exp NUMNode $11<-imme
                                sw      $11     0($sp)          #push imme on stack
                                addi    $sp     $sp     -4      #increase st
                                lw      $v0     4($sp)          #stack top -> $v0
                                sw      $v0     0($t0)          # (t0):=v0
                                addi    $sp     $sp     4       #pop st
                                b       L_8                    #true branch end, jump to end_if
                L_9:
                L_8:
                # End If Stmt

	# Function Call
                        li      $11     0               #load offset in $11
                        add     $11     $11     0       #offr+field relative addr
                        add     $11     $11     $gp     #class.---, add to t1 base
                        move    $25     $11             #$offr=>$t25, base address
                        move    $24     $t2             #$offr=>$t24, flag
                        sw      $24     0($sp)          #push base $t2
                        addi    $sp     $sp     -4      #push st
                        sw      $25     0($sp)          #push base $t1
                        addi    $sp     $sp     -4      #push st
                        sw      $fp     0($sp)          #push $fp 
                        addi    $sp     $sp     -4      #push st
                        sw      $8      0($sp)          #save $8
                        addi    $sp     $sp     -4      #push st
                        sw      $9      0($sp)          #save $9
                        addi    $sp     $sp     -4      #push st
                        sw      $10     0($sp)          #save $10
                        addi    $sp     $sp     -4      #push st
                        sw      $11     0($sp)          #save $11
                        addi    $sp     $sp     -4      #push st
                        sw      $12     0($sp)          #save $12
                        addi    $sp     $sp     -4      #push st
                        sw      $13     0($sp)          #save $13
                        addi    $sp     $sp     -4      #push st
                        sw      $14     0($sp)          #save $14
                        addi    $sp     $sp     -4      #push st
                        sw      $15     0($sp)          #save $15
                        addi    $sp     $sp     -4      #push st
                        sw      $16     0($sp)          #save $16
                        addi    $sp     $sp     -4      #push st
                        sw      $17     0($sp)          #save $17
                        addi    $sp     $sp     -4      #push st
                        sw      $18     0($sp)          #save $18
                        addi    $sp     $sp     -4      #push st
                        sw      $19     0($sp)          #save $19
                        addi    $sp     $sp     -4      #push st
                        sw      $20     0($sp)          #save $20
                        addi    $sp     $sp     -4      #push st
                        sw      $21     0($sp)          #save $21
                        addi    $sp     $sp     -4      #push st
                        sw      $22     0($sp)          #save $22
                        addi    $sp     $sp     -4      #push st
                        sw      $23     0($sp)          #save $23
                        addi    $sp     $sp     -4      #push st
                        sw      $24     0($sp)          #save $24
                        addi    $sp     $sp     -4      #push st
                        sw      $25     0($sp)          #save $25
                        addi    $sp     $sp     -4      #push st
						move    $fp     $sp             #increase fp
                        jal     getarea_7               #function call
                        add     $sp     0               #pop 25 arguments
						lw      $25     4($sp)          #restore register 25
                        addi    $sp     $sp     4       #pop st
                        lw      $24     4($sp)          #restore register 24
                        addi    $sp     $sp     4       #pop st
                        lw      $23     4($sp)          #restore register 23
                        addi    $sp     $sp     4       #pop st
                        lw      $22     4($sp)          #restore register 22
                        addi    $sp     $sp     4       #pop st
                        lw      $21     4($sp)          #restore register 21
                        addi    $sp     $sp     4       #pop st
                        lw      $20     4($sp)          #restore register 20
                        addi    $sp     $sp     4       #pop st
                        lw      $19     4($sp)          #restore register 19
                        addi    $sp     $sp     4       #pop st
                        lw      $18     4($sp)          #restore register 18
                        addi    $sp     $sp     4       #pop st
                        lw      $17     4($sp)          #restore register 17
                        addi    $sp     $sp     4       #pop st
                        lw      $16     4($sp)          #restore register 16
                        addi    $sp     $sp     4       #pop st
                        lw      $15     4($sp)          #restore register 15
                        addi    $sp     $sp     4       #pop st
                        lw      $14     4($sp)          #restore register 14
                        addi    $sp     $sp     4       #pop st
                        lw      $13     4($sp)          #restore register 13
                        addi    $sp     $sp     4       #pop st
                        lw      $12     4($sp)          #restore register 12
                        addi    $sp     $sp     4       #pop st
                        lw      $11     4($sp)          #restore register 11
                        addi    $sp     $sp     4       #pop st
                        lw      $10     4($sp)          #restore register 10
                        addi    $sp     $sp     4       #pop st
                        lw      $9      4($sp)          #restore register 9
                        addi    $sp     $sp     4       #pop st
                        lw      $8      4($sp)          #restore register 8
                        addi    $sp     $sp     4       #pop st
                        lw      $fp     4($sp)          #restore fp
                        addi    $sp     $sp     4       #pop st
                        addi    $sp     $sp     4       #pop st
                        addi    $sp     $sp     4       #pop st
                        sw      $v1     0($sp)
                        addi    $sp     $sp     -4      #push st

						
	
                li      $11     0               #load class offset in $11
                add     $11     $11     0       #add field relative offset
                add     $11     $11     $gp             #class.---, add to t1 base
                move    $t0     $11             #$offr=>$t0, return address
                li      $11     4               #exp NUMNode $11<-imme
                sw      $11     0($sp)          #push imme on stack
                addi    $sp     $sp     -4      #increase st
                lw      $v0     4($sp)          #stack top -> $v0
                sw      $v0     0($t0)          # (t0):=v0
                addi    $sp     $sp     4       #pop st
                li      $11     4               #load offset in $11
                sub     $11     $fp     $11     #absoult addr by $fp
                move    $t0     $11             #$offr=>$t0, return address
						li      $11     0               #load offset in $11
                        add     $11     $11     0       #offr+field relative addr
                        add     $11     $11     $gp     #class.---, add to t1 base
                        move    $25     $11             #$offr=>$t25, base address
                        move    $24     $t2             #$offr=>$t24, flag
                        sw      $24     0($sp)          #push base $t2
                        addi    $sp     $sp     -4      #push st
                        sw      $25     0($sp)          #push base $t1
                        addi    $sp     $sp     -4      #push st
                        sw      $fp     0($sp)          #push $fp 
                        addi    $sp     $sp     -4      #push st
                        sw      $8      0($sp)          #save $8
                        addi    $sp     $sp     -4      #push st
                        sw      $9      0($sp)          #save $9
                        addi    $sp     $sp     -4      #push st
                        sw      $10     0($sp)          #save $10
                        addi    $sp     $sp     -4      #push st
                        sw      $11     0($sp)          #save $11
                        addi    $sp     $sp     -4      #push st
                        sw      $12     0($sp)          #save $12
                        addi    $sp     $sp     -4      #push st
                        sw      $13     0($sp)          #save $13
                        addi    $sp     $sp     -4      #push st
                        sw      $14     0($sp)          #save $14
                        addi    $sp     $sp     -4      #push st
                        sw      $15     0($sp)          #save $15
                        addi    $sp     $sp     -4      #push st
                        sw      $16     0($sp)          #save $16
                        addi    $sp     $sp     -4      #push st
                        sw      $17     0($sp)          #save $17
                        addi    $sp     $sp     -4      #push st
                        sw      $18     0($sp)          #save $18
                        addi    $sp     $sp     -4      #push st
                        sw      $19     0($sp)          #save $19
                        addi    $sp     $sp     -4      #push st
                        sw      $20     0($sp)          #save $20
                        addi    $sp     $sp     -4      #push st
                        sw      $21     0($sp)          #save $21
                        addi    $sp     $sp     -4      #push st
                        sw      $22     0($sp)          #save $22
                        addi    $sp     $sp     -4      #push st
                        sw      $23     0($sp)          #save $23
                        addi    $sp     $sp     -4      #push st
                        sw      $24     0($sp)          #save $24
                        addi    $sp     $sp     -4      #push st
                        sw      $25     0($sp)          #save $25
                        addi    $sp     $sp     -4      #push st
                        move    $fp     $sp             #increase fp
                        jal     getarea_7               #function call
                        add     $sp     0               #pop 25 arguments
                        lw      $25     4($sp)          #restore register 25
                        addi    $sp     $sp     4       #pop st
                        lw      $24     4($sp)          #restore register 24
                        addi    $sp     $sp     4       #pop st
                        lw      $23     4($sp)          #restore register 23
                        addi    $sp     $sp     4       #pop st
                        lw      $22     4($sp)          #restore register 22
                        addi    $sp     $sp     4       #pop st
                        lw      $21     4($sp)          #restore register 21
                        addi    $sp     $sp     4       #pop st
                        lw      $20     4($sp)          #restore register 20
                        addi    $sp     $sp     4       #pop st
                        lw      $19     4($sp)          #restore register 19
                        addi    $sp     $sp     4       #pop st
                        lw      $18     4($sp)          #restore register 18
                        addi    $sp     $sp     4       #pop st
                        lw      $17     4($sp)          #restore register 17
                        addi    $sp     $sp     4       #pop st
                        lw      $16     4($sp)          #restore register 16
                        addi    $sp     $sp     4       #pop st
                        lw      $15     4($sp)          #restore register 15
                        addi    $sp     $sp     4       #pop st
                        lw      $14     4($sp)          #restore register 14
                        addi    $sp     $sp     4       #pop st
                        lw      $13     4($sp)          #restore register 13
                        addi    $sp     $sp     4       #pop st
                        lw      $12     4($sp)          #restore register 12
                        addi    $sp     $sp     4       #pop st
                        lw      $11     4($sp)          #restore register 11
                        addi    $sp     $sp     4       #pop st
                        lw      $10     4($sp)          #restore register 10
                        addi    $sp     $sp     4       #pop st
                        lw      $9      4($sp)          #restore register 9
                        addi    $sp     $sp     4       #pop st
                        lw      $8      4($sp)          #restore register 8
                        addi    $sp     $sp     4       #pop st
                        lw      $fp     4($sp)          #restore fp
                        addi    $sp     $sp     4       #pop st
                        addi    $sp     $sp     4       #pop st
                        addi    $sp     $sp     4       #pop st
                        sw      $v1     0($sp)
                        addi    $sp     $sp     -4      #push st
				lw	$v0	4($sp)		#stack top -> $v0
				sw	$v0	0($t0)		# (t0):=v0
				addi	$sp	$sp	4	#pop st
	li	$11	0		#load offset in $11
	add	$11	$11	0	#offr+field relative addr
	add	$11	$11	$gp		#class.---, add to t1 base
	move	$25	$11		#$offr=>$t25, base address
	move	$24	$t2		#$offr=>$t24, flag
	sw	$24	0($sp)		#push base $t2
	addi	$sp	$sp	-4	#push st
	sw	$25	0($sp)		#push base $t1
	addi	$sp	$sp	-4	#push st
	li	$11	4		#load offset in $11
	sub	$11	$fp	$11	#absoult addr by $fp
	lw	$12	($11)		#load value from ($11) to t12
	sw	$12	0($sp)		#push value on stack
	addi	$sp	$sp	-4	#increase st
	li	$v0	1		#print_int
	lw	$a0	4($sp)		#integer to print
	syscall				#print the arg
	li	$v0	4		#print_str
	la	$a0	Enter		#address of entering to print
	syscall				#print the arg
	li	$11	0		#load offset in $11
	add	$11	$11	0	#offr+field relative addr
	add	$11	$11	$gp		#class.---, add to t1 base
	move	$25	$11		#$offr=>$t25, base address
	move	$24	$t2		#$offr=>$t24, flag
	sw	$24	0($sp)		#push base $t2
	addi	$sp	$sp	-4	#push st
	sw	$25	0($sp)		#push base $t1
	addi	$sp	$sp	-4	#push st
	li	$11	0		#load offset in $11
	add	$11	$11	0	#offr+field relative addr
	add	$11	$11	$gp		#class.---, add to t1 base
	move	$25	$11		#$offr=>$t25, base address
	move	$24	$t2		#$offr=>$t24, flag
	sw	$24	0($sp)		#push base $t2
	addi	$sp	$sp	-4	#push st
	sw	$25	0($sp)		#push base $t1
	addi	$sp	$sp	-4	#push st
	sw	$fp	0($sp)		#push $fp 
	addi	$sp	$sp	-4	#push st
	sw	$8	0($sp)		#save $8
	addi	$sp	$sp	-4	#push st
	sw	$9	0($sp)		#save $9
	addi	$sp	$sp	-4	#push st
	sw	$10	0($sp)		#save $10
	addi	$sp	$sp	-4	#push st
	sw	$11	0($sp)		#save $11
	addi	$sp	$sp	-4	#push st
	sw	$12	0($sp)		#save $12
	addi	$sp	$sp	-4	#push st
	sw	$13	0($sp)		#save $13
	addi	$sp	$sp	-4	#push st
	sw	$14	0($sp)		#save $14
	addi	$sp	$sp	-4	#push st
	sw	$15	0($sp)		#save $15
	addi	$sp	$sp	-4	#push st
	sw	$16	0($sp)		#save $16
	addi	$sp	$sp	-4	#push st
	sw	$17	0($sp)		#save $17
	addi	$sp	$sp	-4	#push st
	sw	$18	0($sp)		#save $18
	addi	$sp	$sp	-4	#push st
	sw	$19	0($sp)		#save $19
	addi	$sp	$sp	-4	#push st
	sw	$20	0($sp)		#save $20
	addi	$sp	$sp	-4	#push st
	sw	$21	0($sp)		#save $21
	addi	$sp	$sp	-4	#push st
	sw	$22	0($sp)		#save $22
	addi	$sp	$sp	-4	#push st
	sw	$23	0($sp)		#save $23
	addi	$sp	$sp	-4	#push st
	sw	$24	0($sp)		#save $24
	addi	$sp	$sp	-4	#push st
	sw	$25	0($sp)		#save $25
	addi	$sp	$sp	-4	#push st
	move	$fp	$sp		#increase fp
	jal	getarea_7			#function call
	add	$sp	0		#pop 0 arguments
	lw	$25	4($sp)		#restore register 25
	addi	$sp	$sp	4	#pop st
	lw	$24	4($sp)		#restore register 24
	addi	$sp	$sp	4	#pop st
	lw	$23	4($sp)		#restore register 23
	addi	$sp	$sp	4	#pop st
	lw	$22	4($sp)		#restore register 22
	addi	$sp	$sp	4	#pop st
	lw	$21	4($sp)		#restore register 21
	addi	$sp	$sp	4	#pop st
	lw	$20	4($sp)		#restore register 20
	addi	$sp	$sp	4	#pop st
	lw	$19	4($sp)		#restore register 19
	addi	$sp	$sp	4	#pop st
	lw	$18	4($sp)		#restore register 18
	addi	$sp	$sp	4	#pop st
	lw	$17	4($sp)		#restore register 17
	addi	$sp	$sp	4	#pop st
	lw	$16	4($sp)		#restore register 16
	addi	$sp	$sp	4	#pop st
	lw	$15	4($sp)		#restore register 15
	addi	$sp	$sp	4	#pop st
	lw	$14	4($sp)		#restore register 14
	addi	$sp	$sp	4	#pop st
	lw	$13	4($sp)		#restore register 13
	addi	$sp	$sp	4	#pop st
	lw	$12	4($sp)		#restore register 12
	addi	$sp	$sp	4	#pop st
	lw	$11	4($sp)		#restore register 11
	addi	$sp	$sp	4	#pop st
	lw	$10	4($sp)		#restore register 10
	addi	$sp	$sp	4	#pop st
	lw	$9	4($sp)		#restore register 9
	addi	$sp	$sp	4	#pop st
	lw	$8	4($sp)		#restore register 8
	addi	$sp	$sp	4	#pop st
	lw	$fp	4($sp)		#restore fp
	addi	$sp	$sp	4	#pop st
	addi	$sp	$sp	4	#pop st
	addi	$sp	$sp	4	#pop st
	sw	$v1	0($sp)
	addi	$sp	$sp	-4	#push st
	li	$v0	1		#print_int
	lw	$a0	4($sp)		#integer to print
	syscall				#print the arg
	li	$v0	4		#print_str
	la	$a0	Enter		#address of entering to print
	syscall				#print the arg
	lw	$ra	0($fp)		#get back control line
	move	$sp	$fp		#pop stack to fp
	jr	$ra			#routine call return
