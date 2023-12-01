.data
Enter:	.asciiz "  
"
base:
.text
.globl main
.text
# Class: test

	# Method: main

		main:
		la	$28	base		#store global area address into $gp
		move	$t1	$28		#init base
		add	$t1	$t1	0	#init main access link in $t1; .data -1
		li	$t2	0		#init $t2 as 0-global access
		move	$fp	$sp		#init fp pointer
		sw	$ra	0($sp)		#save return address on stack
		addi	$sp	$sp	-4	#increase st
		
		# Variable: x
		# Using default value
		li	$11	0		#exp NUMNode $11<-imme
		sw	$11	0($sp)		#push imme on stack
		addi	$sp	$sp	-4	#increase st
		
		# Variable: i
		# Using default value
		li	$11	0		#exp NUMNode $11<-imme
		sw	$11	0($sp)		#push imme on stack
		addi	$sp	$sp	-4	#increase st
		
		
		# Function Call
			li	$11	0		#load offset in $11
			add	$11	$11	0	#offr+field relative addr
			add	$11	$11	$gp	#class.---, add to t1 base
			move	$25	$11		#$offr=>$t25, base address
			move	$24	$t2		#$offr=>$t24, flag
			sw	$24	0($sp)		#push base $t2
			addi	$sp	$sp	-4	#push st
			sw	$25	0($sp)		#push base $t1
			addi	$sp	$sp	-4	#push st
			sw	$25	0($sp)		#push base $t1
			addi	$sp	$sp	-4	#push st
			li	$v0	5		#system call code for read_int
			syscall
			li	$11	4		#load offset in $11
			sub	$11	$fp	$11	#absoult addr by $fp
			move	$t0	$11		#$offr=>$t0, return address
			sw	$v0	($t0)		#save readln result in ($t0)
		# End Function Call
		
		# If Stmt
			li	$11	4		#load offset in $11
			sub	$11	$fp	$11	#absoult addr by $fp
			lw	$12	($11)		#load value from ($12) to t11
			sw	$12	0($sp)		#push value on stack
			addi	$sp	$sp	-4	#increase st
			li	$11	10		#exp NUMNode $11<-imme
			sw	$11	0($sp)		#push imme on stack
			addi	$sp	$sp	-4	#increase st
			lw	$11	4($sp)		#stack top -> $11
			addi	$sp	$sp	4	#pop st
			lw	$12	4($sp)		#stack top -> $12
			sgt	$11	$12	$11	#greater than
			sw	$11	4($sp)		#push result to stack
			lw	$11	4($sp)		#store boolean result in register
			beqz	$11	L_0		#$11 == 0 ? if false, jump to L_0
			# IfElse True
				li	$11	8		#load offset in $11
				sub	$11	$fp	$11	#absoult addr by $fp
				move	$t0	$11		#$offr=>$t0, return address
				li	$11	1		#exp NUMNode $11<-imme
				sw	$11	0($sp)		#push imme on stack
				addi	$sp	$sp	-4	#increase st
				lw	$v0	4($sp)		#stack top -> $v0
				sw	$v0	0($t0)		# (t0):=v0
				addi	$sp	$sp	4	#pop st
				b	L_1			#true branch end, jump to end_if
			L_0:
		L_1:
		# End If Stmt
		# If Stmt
			li	$11	4		#load offset in $11
			sub	$11	$fp	$11	#absoult addr by $fp
			lw	$12	($11)		#load value from ($12) to t11
			sw	$12	0($sp)		#push value on stack
			addi	$sp	$sp	-4	#increase st
			li	$11	6		#exp NUMNode $11<-imme
			sw	$11	0($sp)		#push imme on stack
			addi	$sp	$sp	-4	#increase st
			lw	$11	4($sp)		#stack top -> $11
			addi	$sp	$sp	4	#pop st
			lw	$12	4($sp)		#stack top -> $12
			sgt	$11	$12	$11	#greater than
			sw	$11	4($sp)		#push result to stack
			lw	$11	4($sp)		#store boolean result in register
			beqz	$11	L_5		#$11 == 0 ? if false, jump to L_5
			# IfElse True
				li	$11	8		#load offset in $11
				sub	$11	$fp	$11	#absoult addr by $fp
				move	$t0	$11		#$offr=>$t0, return address
				li	$11	2		#exp NUMNode $11<-imme
				sw	$11	0($sp)		#push imme on stack
				addi	$sp	$sp	-4	#increase st
				lw	$v0	4($sp)		#stack top -> $v0
				sw	$v0	0($t0)		# (t0):=v0
				addi	$sp	$sp	4	#pop st
				b	L_3			#true branch end, jump to end_if
			L_5:
			li	$11	4		#load offset in $11
			sub	$11	$fp	$11	#absoult addr by $fp
			lw	$12	($11)		#load value from ($12) to t11
			sw	$12	0($sp)		#push value on stack
			addi	$sp	$sp	-4	#increase st
			li	$11	3		#exp NUMNode $11<-imme
			sw	$11	0($sp)		#push imme on stack
			addi	$sp	$sp	-4	#increase st
			lw	$11	4($sp)		#stack top -> $11
			addi	$sp	$sp	4	#pop st
			lw	$12	4($sp)		#stack top -> $12
			sgt	$11	$12	$11	#greater than
			sw	$11	4($sp)		#push result to stack
			lw	$11	4($sp)		#store boolean result in register
			beqz	$11	L_4		#$11 == 0 ? if false, jump to L_4
			# IfElse True
				li	$11	8		#load offset in $11
				sub	$11	$fp	$11	#absoult addr by $fp
				move	$t0	$11		#$offr=>$t0, return address
				li	$11	3		#exp NUMNode $11<-imme
				sw	$11	0($sp)		#push imme on stack
				addi	$sp	$sp	-4	#increase st
				lw	$v0	4($sp)		#stack top -> $v0
				sw	$v0	0($t0)		# (t0):=v0
				addi	$sp	$sp	4	#pop st
				b	L_3			#true branch end, jump to end_if
			L_4:
			# Else
			li	$11	8		#load offset in $11
			sub	$11	$fp	$11	#absoult addr by $fp
			move	$t0	$11		#$offr=>$t0, return address
			li	$11	4		#exp NUMNode $11<-imme
			sw	$11	0($sp)		#push imme on stack
			addi	$sp	$sp	-4	#increase st
			lw	$v0	4($sp)		#stack top -> $v0
			sw	$v0	0($t0)		# (t0):=v0
			addi	$sp	$sp	4	#pop st
			# End Else
		L_3:
		# End If Stmt
		
		# Function Call
			li	$11	0		#load offset in $11
			add	$11	$11	0	#offr+field relative addr
			add	$11	$11	$gp	#class.---, add to t1 base
			move	$25	$11		#$offr=>$t25, base address
			move	$24	$t2		#$offr=>$t24, flag
			sw	$24	0($sp)		#push base $t2
			addi	$sp	$sp	-4	#push st
			sw	$25	0($sp)		#push base $t1
			addi	$sp	$sp	-4	#push st
			.data
			.align 2
			S_0:	.asciiz	"i="
			.text
			li	$v0	4		#print_str
			la	$a0	S_0		#address of string to print
			syscall				#print the arg
		# End Function Call
		
		
		# Function Call
			li	$11	0		#load offset in $11
			add	$11	$11	0	#offr+field relative addr
			add	$11	$11	$gp	#class.---, add to t1 base
			move	$25	$11		#$offr=>$t25, base address
			move	$24	$t2		#$offr=>$t24, flag
			sw	$24	0($sp)		#push base $t2
			addi	$sp	$sp	-4	#push st
			sw	$25	0($sp)		#push base $t1
			addi	$sp	$sp	-4	#push st
			li	$11	8		#load offset in $11
			sub	$11	$fp	$11	#absoult addr by $fp
			lw	$12	($11)		#load value from ($12) to t11
			sw	$12	0($sp)		#push value on stack
			addi	$sp	$sp	-4	#increase st
			li	$v0	1		#print_int
			lw	$a0	4($sp)		#integer to print
			syscall				#print the arg
			li	$v0	4		#print_str
			la	$a0	Enter		#address of entering to print
			syscall				#print the arg
		# End Function Call
		
		
		lw	$ra	0($fp)		#get back control line
		move	$sp	$fp		#pop stack to fp
		jr	$ra			#routine call return
	# End Method: main

# End Class: test

# Class: test2

# End Class: test2

# Class: test3

	# Method: hahah

		hahah_0:
		lw	$t1	80($fp)		#init base
		lw	$t2	84($fp)		#init base
		sw	$ra	0($sp)		#save return address on stack
		addi	$sp	$sp	-4	#increase st
		
		
		lw	$ra	0($fp)		#get back control line
		move	$sp	$fp		#pop stack to fp
		jr	$ra			#routine call return
	# End Method: hahah

# End Class: test3

