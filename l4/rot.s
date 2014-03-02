	.file	"rot.c"
	.text
	.globl	rot_r
	.type	rot_r, @function
rot_r:
.LFB24:
	.cfi_startproc
	movl	$32, %ecx
	subl	%esi, %ecx
	movl	%edi, %eax
	sall	%cl, %eax
	movl	%esi, %ecx
	shrl	%cl, %edi
	orl	%edi, %eax
	ret
	.cfi_endproc
.LFE24:
	.size	rot_r, .-rot_r
	.globl	rot_l
	.type	rot_l, @function
rot_l:
.LFB25:
	.cfi_startproc
	movl	$32, %ecx
	subl	%esi, %ecx
	movl	%edi, %eax
	shrl	%cl, %eax
	movl	%esi, %ecx
	sall	%cl, %edi
	orl	%edi, %eax
	ret
	.cfi_endproc
.LFE25:
	.size	rot_l, .-rot_l
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%u"
.LC1:
	.string	""
	.text
	.globl	printBits
	.type	printBits, @function
printBits:
.LFB26:
	.cfi_startproc
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	movl	%edi, %r14d
	subl	$1, %r14d
	js	.L4
	movq	%rsi, %r13
	movl	$1, %ebp
	jmp	.L5
.L7:
	movl	%ebp, %edx
	movl	%ebx, %ecx
	sall	%cl, %edx
	andb	0(%r13,%r12), %dl
	movzbl	%dl, %edx
	sarl	%cl, %edx
	movzbl	%dl, %edx
	movl	$.LC0, %esi
	movl	%ebp, %edi
	movl	$0, %eax
	call	__printf_chk
	subl	$1, %ebx
	cmpl	$-1, %ebx
	jne	.L7
	subl	$1, %r14d
	js	.L4
.L5:
	movl	$7, %ebx
	movslq	%r14d, %r12
	jmp	.L7
.L4:
	movl	$.LC1, %edi
	call	puts
	popq	%rbx
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE26:
	.size	printBits, .-printBits
	.globl	rot_r_asm
	.type	rot_r_asm, @function
rot_r_asm:
.LFB27:
	.cfi_startproc
	movl	%edi, %eax
	movl	%esi, %ecx
#APP
# 35 "rot.c" 1
	ror %cl, %eax
# 0 "" 2
#NO_APP
	ret
	.cfi_endproc
.LFE27:
	.size	rot_r_asm, .-rot_r_asm
	.globl	rot_l_asm
	.type	rot_l_asm, @function
rot_l_asm:
.LFB28:
	.cfi_startproc
	movl	%edi, %eax
	movl	%esi, %ecx
#APP
# 45 "rot.c" 1
	rol %cl, %eax
# 0 "" 2
#NO_APP
	ret
	.cfi_endproc
.LFE28:
	.size	rot_l_asm, .-rot_l_asm
	.globl	add_asm
	.type	add_asm, @function
add_asm:
.LFB29:
	.cfi_startproc
	movl	%edi, %eax
#APP
# 55 "rot.c" 1
	add %esi, %eax
# 0 "" 2
#NO_APP
	ret
	.cfi_endproc
.LFE29:
	.size	add_asm, .-add_asm
	.globl	add
	.type	add, @function
add:
.LFB30:
	.cfi_startproc
	movl	%edi, %eax
	cltd
	idivl	%esi
	ret
	.cfi_endproc
.LFE30:
	.size	add, .-add
	.section	.rodata.str1.1
.LC2:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB31:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	movl	$843267973, 12(%rsp)
	movl	$20, %ebx
.L15:
	leaq	12(%rsp), %rsi
	movl	$4, %edi
	call	printBits
	movl	12(%rsp), %eax
	movl	$2, %ecx
#APP
# 35 "rot.c" 1
	ror %cl, %eax
# 0 "" 2
#NO_APP
	movl	%eax, 12(%rsp)
	subl	$1, %ebx
	jne	.L15
	movl	$20, %ebx
.L17:
	leaq	12(%rsp), %rsi
	movl	$4, %edi
	call	printBits
	movl	12(%rsp), %eax
	movl	$2, %ecx
#APP
# 45 "rot.c" 1
	rol %cl, %eax
# 0 "" 2
#NO_APP
	movl	%eax, 12(%rsp)
	subl	$1, %ebx
	jne	.L17
	movl	$234, %edx
	movl	$235, %eax
#APP
# 55 "rot.c" 1
	add %eax, %edx
# 0 "" 2
#NO_APP
	movl	$.LC2, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	$0, %eax
	addq	$16, %rsp
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE31:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.8.1-10ubuntu9) 4.8.1"
	.section	.note.GNU-stack,"",@progbits
