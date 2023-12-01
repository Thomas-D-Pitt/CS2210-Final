.data
Enter:	.asciiz "  
"
base:
.text
.globl main
.data
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
.data
	.word	3
	.word	5
	.word	7
.text
main:					#method entry
	la	$28	base		#store global area address into $gp
	move	$t1	$28		#init base
	add	$t1	$t1	0	#init main access link in $t1; .data 0
	li	$t2	0		#init $t2 as 0-global access
	move	$fp	$sp		#init fp pointer
	sw	$ra	0($sp)		#save return address on stack
	addi	$sp	$sp	-4	#increase st
	sw	$0	0($sp)		#store $0 to stack top
	addi	$sp	$sp	-4	#increase st
	sw	$0	0($sp)		#store $0 to stack top
	addi	$sp	$sp	-4	#increase st
	sw	$0	0($sp)		#store $0 to stack top
	addi	$sp	$sp	-4	#increase st
	sw	$0	0($sp)		#store $0 to stack top
	addi	$sp	$sp	-4	#increase st
	sw	$0	0($sp)		#store $0 to stack top
	addi	$sp	$sp	-4	#increase st
	sw	$0	0($sp)		#store $0 to stack top
	addi	$sp	$sp	-4	#increase st
	sw	$0	0($sp)		#store $0 to stack top
	addi	$sp	$sp	-4	#increase st
	sw	$0	0($sp)		#store $0 to stack top
	addi	$sp	$sp	-4	#increase st
	sw	$0	0($sp)		#store $0 to stack top
	addi	$sp	$sp	-4	#increase st
	sw	$0	0($sp)		#store $0 to stack top
	addi	$sp	$sp	-4	#increase st
	sw	$0	0($sp)		#store $0 to stack top
	addi	$sp	$sp	-4	#increase st
	sw	$0	0($sp)		#store $0 to stack top
	addi	$sp	$sp	-4	#increase st
	sw	$0	0($sp)		#store $0 to stack top
	addi	$sp	$sp	-4	#increase st
	sw	$0	0($sp)		#store $0 to stack top
	addi	$sp	$sp	-4	#increase st
	sw	$0	0($sp)		#store $0 to stack top
	addi	$sp	$sp	-4	#increase st
	sw	$0	0($sp)		#store $0 to stack top
	addi	$sp	$sp	-4	#increase st
	sw	$0	0($sp)		#store $0 to stack top
	addi	$sp	$sp	-4	#increase st
	sw	$0	0($sp)		#store $0 to stack top
	addi	$sp	$sp	-4	#increase st
	sw	$0	0($sp)		#store $0 to stack top
	addi	$sp	$sp	-4	#increase st
	sw	$0	0($sp)		#store $0 to stack top
	addi	$sp	$sp	-4	#increase st
	sw	$0	0($sp)		#store $0 to stack top
	addi	$sp	$sp	-4	#increase st
	sw	$0	0($sp)		#store $0 to stack top
	addi	$sp	$sp	-4	#increase st
	sw	$0	0($sp)		#store $0 to stack top
	addi	$sp	$sp	-4	#increase st
	sw	$0	0($sp)		#store $0 to stack top
	addi	$sp	$sp	-4	#increase st
	sw	$0	0($sp)		#store $0 to stack top
	addi	$sp	$sp	-4	#increase st

	li	$11	0		#load immediate 0 to t11
	sw	$11	0($sp)		#store t11 to stack top
	addi	$sp	$sp	-4	#increase st

	li	$11	4		#load offset in $11
	li	$12	3		#exp NUMNode $12<-imme
	sw	$12	0($sp)		#push imme on stack
	addi	$sp	$sp	-4	#increase st
	lw	$v0	4($sp)		#stack top -> $v0
	sll	$v0	$v0	2	#shift $v0 2 bits left
	addi	$sp	$sp	4
	add	$11	$11	$v0	#offr=base+i*width
	sub	$11	$fp	$11	#absoult addr by $fp
	move	$t0	$11		#$offr=>$t0, return address			// y assignment
	li	$11	17		#exp NUMNode $11<-imme
	sw	$11	0($sp)		#push imme on stack
	addi	$sp	$sp	-4	#increase st
	lw	$v0	4($sp)		#stack top -> $v0
	sw	$v0	0($t0)		# (t0):=v0
	addi	$sp	$sp	4	#pop st
L_1:				#begin of a while loop
	li	$11	104		#load offset in $11
	sub	$11	$fp	$11	#absoult addr by $fp
	lw	$12	($11)		#load value from ($11) to t12
	sw	$12	0($sp)		#push value on stack
	addi	$sp	$sp	-4	#increase st
	li	$11	2		#exp NUMNode $11<-imme
	sw	$11	0($sp)		#push imme on stack
	addi	$sp	$sp	-4	#increase st
	lw	$11	4($sp)		#stack top -> $11
	addi	$sp	$sp	4	#pop st
	lw	$12	4($sp)		#stack top -> $12
	slt	$11	$12	$11	#add r1 to r2
	sw	$11	4($sp)		#push the sum on stack
	lw	$11	4($sp)		#load boolean value into register
	beqz	$11	L_0		#boolean false, jump to the end of while
	li	$11	40		#load offset in $11
	li	$12	104		#load offset in $12
	sub	$12	$fp	$12	#absoult addr by $fp
	lw	$13	($12)		#load value from ($12) to t13
	sw	$13	0($sp)		#push value on stack								// could be move but isnt
	addi	$sp	$sp	-4	#increase st
	li	$12	1		#exp NUMNode $12<-imme
	sw	$12	0($sp)		#push imme on stack
	addi	$sp	$sp	-4	#increase st
	lw	$12	4($sp)		#stack top -> $12
	addi	$sp	$sp	4	#pop st
	lw	$13	4($sp)		#stack top -> $13
	add	$12	$13	$12	#add r1 to r2
	sw	$12	4($sp)		#push the sum on stack
	lw	$v0	4($sp)		#stack top -> $v0
	sll	$v0	$v0	2	#shift $v0 2 bits left
	addi	$sp	$sp	4
	add	$11	$11	$v0	#offr=base+i*width
	beqz	$t2	L_2		#if called from a global obj
	sub	$11	$t1	$11	#sub $offr from t1
	b	L_3
L_2:
	add	$11	$11	$t1	#add $offr with base
L_3:
	move	$t0	$11		#$offr=>$t0, return address					// 
	li	$11	1		#exp NUMNode $11<-imme
	sw	$11	0($sp)		#push imme on stack
	addi	$sp	$sp	-4	#increase st
	li	$11	104		#load offset in $11
	sub	$11	$fp	$11	#absoult addr by $fp
	lw	$12	($11)		#load value from ($11) to t12
	sw	$12	0($sp)		#push value on stack
	addi	$sp	$sp	-4	#increase st
	li	$11	2		#exp NUMNode $11<-imme
	sw	$11	0($sp)		#push imme on stack
	addi	$sp	$sp	-4	#increase st
	lw	$11	4($sp)		#stack top -> $11
	addi	$sp	$sp	4	#pop st
	lw	$12	4($sp)		#stack top -> $12
	mul	$11	$12	$11	#add r1 to r2
	sw	$11	4($sp)		#push the sum on stack
	lw	$11	4($sp)		#stack top -> $11
	addi	$sp	$sp	4	#pop st
	lw	$12	4($sp)		#stack top -> $12
	add	$11	$12	$11	#add r1 to r2
	sw	$11	4($sp)		#push the sum on stack
	li	$11	104		#load offset in $11
	sub	$11	$fp	$11	#absoult addr by $fp
	lw	$12	($11)		#load value from ($11) to t12
	sw	$12	0($sp)		#push value on stack
	addi	$sp	$sp	-4	#increase st
	li	$11	104		#load offset in $11
	sub	$11	$fp	$11	#absoult addr by $fp
	lw	$12	($11)		#load value from ($11) to t12
	sw	$12	0($sp)		#push value on stack
	addi	$sp	$sp	-4	#increase st
	lw	$11	4($sp)		#stack top -> $11
	addi	$sp	$sp	4	#pop st
	lw	$12	4($sp)		#stack top -> $12
	mul	$11	$12	$11	#add r1 to r2
	sw	$11	4($sp)		#push the sum on stack
	lw	$11	4($sp)		#stack top -> $11
	addi	$sp	$sp	4	#pop st
	lw	$12	4($sp)		#stack top -> $12
	add	$11	$12	$11	#add r1 to r2
	sw	$11	4($sp)		#push the sum on stack
	lw	$v0	4($sp)		#stack top -> $v0
	sw	$v0	0($t0)		# (t0):=v0
	addi	$sp	$sp	4	#pop st
	li	$11	104		#load offset in $11
	sub	$11	$fp	$11	#absoult addr by $fp
	move	$t0	$11		#$offr=>$t0, return address
	li	$11	104		#load offset in $11
	sub	$11	$fp	$11	#absoult addr by $fp
	lw	$12	($11)		#load value from ($11) to t12
	sw	$12	0($sp)		#push value on stack
	addi	$sp	$sp	-4	#increase st
	li	$11	1		#exp NUMNode $11<-imme
	sw	$11	0($sp)		#push imme on stack
	addi	$sp	$sp	-4	#increase st
	lw	$11	4($sp)		#stack top -> $11
	addi	$sp	$sp	4	#pop st
	lw	$12	4($sp)		#stack top -> $12
	add	$11	$12	$11	#add r1 to r2
	sw	$11	4($sp)		#push the sum on stack
	lw	$v0	4($sp)		#stack top -> $v0
	sw	$v0	0($t0)		# (t0):=v0
	addi	$sp	$sp	4	#pop st
	b	L_1			#go to the loop beginning
L_0:					#end while
	li	$11	104		#load offset in $11
	sub	$11	$fp	$11	#absoult addr by $fp
	move	$t0	$11		#$offr=>$t0, return address					store z offset
	li	$11	0		#exp NUMNode $11<-imme
	sw	$11	0($sp)		#push imme on stack
	addi	$sp	$sp	-4	#increase st
	lw	$v0	4($sp)		#stack top -> $v0
	sw	$v0	0($t0)		# (t0):=v0
	addi	$sp	$sp	4	#pop st
L_5:				#begin of a while loop
	li	$11	104		#load offset in $11
	sub	$11	$fp	$11	#absoult addr by $fp
	lw	$12	($11)		#load value from ($11) to t12
	sw	$12	0($sp)		#push value on stack
	addi	$sp	$sp	-4	#increase st
	li	$11	2		#exp NUMNode $11<-imme
	sw	$11	0($sp)		#push imme on stack
	addi	$sp	$sp	-4	#increase st
	lw	$11	4($sp)		#stack top -> $11
	addi	$sp	$sp	4	#pop st
	lw	$12	4($sp)		#stack top -> $12
	sle	$11	$12	$11	#add r1 to r2
	sw	$11	4($sp)		#push the sum on stack
	lw	$11	4($sp)		#load boolean value into register
	beqz	$11	L_4		#boolean false, jump to the end of while
	li	$11	0		#load offset in $11
	add	$11	$11	0	#offr+field relative addr
	add	$11	$11	$gp		#class.---, add to t1 base
	move	$25	$11		#$offr=>$t25, base address
	move	$24	$t2		#$offr=>$t24, flag
	sw	$24	0($sp)		#push base $t2
	addi	$sp	$sp	-4	#push st
	sw	$25	0($sp)		#push base $t1
	addi	$sp	$sp	-4	#push st
	li	$11	40		#load offset in $11
	li	$12	104		#load offset in $12
	sub	$12	$fp	$12	#absoult addr by $fp
	lw	$13	($12)		#load value from ($12) to t13
	sw	$13	0($sp)		#push value on stack
	addi	$sp	$sp	-4	#increase st
	lw	$v0	4($sp)		#stack top -> $v0
	sll	$v0	$v0	2	#shift $v0 2 bits left
	addi	$sp	$sp	4
	add	$11	$11	$v0	#offr=base+i*width
	beqz	$t2	L_6		#if called from a global obj
	sub	$11	$t1	$11	#sub $offr from t1
	b	L_7
L_6:
	add	$11	$11	$t1	#add $offr with base
L_7:
	lw	$12	($11)		#load value from ($11) to t12
	sw	$12	0($sp)		#push value on stack
	addi	$sp	$sp	-4	#increase st
	li	$v0	1		#print_int
	lw	$a0	4($sp)		#integer to print
	syscall				#print the arg
	li	$v0	4		#print_str
	la	$a0	Enter		#address of entering to print
	syscall				#print the arg
	li	$11	104		#load offset in $11
	sub	$11	$fp	$11	#absoult addr by $fp
	move	$t0	$11		#$offr=>$t0, return address							z offset
	li	$11	104		#load offset in $11
	sub	$11	$fp	$11	#absoult addr by $fp
	lw	$12	($11)		#load value from ($11) to t12
	sw	$12	0($sp)		#push value on stack
	addi	$sp	$sp	-4	#increase st
	li	$11	1		#exp NUMNode $11<-imme
	sw	$11	0($sp)		#push imme on stack
	addi	$sp	$sp	-4	#increase st
	lw	$11	4($sp)		#stack top -> $11
	addi	$sp	$sp	4	#pop st
	lw	$12	4($sp)		#stack top -> $12
	add	$11	$12	$11	#add r1 to r2
	sw	$11	4($sp)		#push the sum on stack
	lw	$v0	4($sp)		#stack top -> $v0
	sw	$v0	0($t0)		# (t0):=v0
	addi	$sp	$sp	4	#pop st
	b	L_5			#go to the loop beginning
L_4:					#end while
	lw	$ra	0($fp)		#get back control line
	move	$sp	$fp		#pop stack to fp
	jr	$ra			#routine call return
