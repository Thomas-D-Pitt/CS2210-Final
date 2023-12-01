.data
Enter:	.asciiz "  
"
base:
.text
.globl main
.data
	.word	7			#offset 0
	.word	3			#offset 4
.data
	.word	5			#offset 8
.text
main:					#method entry
	la	$28	base		#store global area address into $gp
	move	$t1	$28		#init base
	add	$t1	$t1	8	#init main access link in $t1; .data 8
	li	$t2	0		#init $t2 as 0-global access
	move	$fp	$sp		#init fp pointer
	sw	$ra	0($sp)		#save return address on stack
	addi	$sp	$sp	-4	#increase st
	lw	$ra	0($fp)		#get back control line
	move	$sp	$fp		#pop stack to fp
	jr	$ra			#routine call return
