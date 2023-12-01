.data
Enter:	.asciiz "  
"
base:
.text
.globl main
.text
main:					#method entry
	la	$28	base		#store global area address into $gp
	move	$t1	$28		#init base
	add	$t1	$t1	0	#init main access link in $t1; .data 0
	li	$t2	0		#init $t2 as 0-global access
	move	$fp	$sp		#init fp pointer
	sw	$ra	0($sp)		#save return address on stack
	addi	$sp	$sp	-4	#increase st
	li	$11	4		#load immediate 4 to t11
	sw	$11	0($sp)		#store t11 to stack top
	addi	$sp	$sp	-4	#increase st
	lw	$ra	0($fp)		#get back control line
	move	$sp	$fp		#pop stack to fp
	jr	$ra			#routine call return
