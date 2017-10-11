	.file	"example-simd.c"
	.comm	h_a,8388608,32
	.comm	h_b,8388608,32
	.comm	h_c,8388608,32
	.section	.rodata
.LC0:
	.string	"Inicializando os arrays.\n"
	.text
	.globl	init_array
	.type	init_array, @function
init_array:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	stdout(%rip), %rax
	movq	%rax, %rcx
	movl	$25, %edx
	movl	$1, %esi
	movl	$.LC0, %edi
	call	fwrite
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	movl	-4(%rbp), %eax
	cltq
	movsd	.LC1(%rip), %xmm0
	movsd	%xmm0, h_a(,%rax,8)
	movl	-4(%rbp), %eax
	cltq
	movsd	.LC1(%rip), %xmm0
	movsd	%xmm0, h_b(,%rax,8)
	addl	$1, -4(%rbp)
.L2:
	cmpl	$1048575, -4(%rbp)
	jle	.L3
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	init_array, .-init_array
	.section	.rodata
	.align 8
.LC2:
	.string	"Thread[%lu,%lu]: Antes do simd.\n"
	.align 8
.LC3:
	.string	"Thread[%lu,%lu]: Depois do simd.\n"
.LC4:
	.string	"Thread[%lu,%lu]: res: %g\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	movl	$0, %eax
	call	init_array
	call	pthread_self
	movq	%rax, %rbx
	call	omp_get_thread_num
	movslq	%eax, %rdx
	movq	stdout(%rip), %rax
	movq	%rbx, %rcx
	movl	$.LC2, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	$0, -20(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L5
.L6:
	movl	-20(%rbp), %eax
	cltq
	movsd	h_c(,%rax,8), %xmm1
	movl	-20(%rbp), %eax
	cltq
	movsd	h_a(,%rax,8), %xmm2
	movl	-20(%rbp), %eax
	cltq
	movsd	h_b(,%rax,8), %xmm0
	mulsd	%xmm2, %xmm0
	addsd	%xmm1, %xmm0
	movl	-20(%rbp), %eax
	cltq
	movsd	%xmm0, h_c(,%rax,8)
	addl	$1, -20(%rbp)
.L5:
	cmpl	$1048576, -20(%rbp)
	jl	.L6
	cmpl	$1048576, -20(%rbp)
	jne	.L7
	movl	-20(%rbp), %eax
	movl	%eax, -24(%rbp)
.L7:
	call	pthread_self
	movq	%rax, %rbx
	call	omp_get_thread_num
	movslq	%eax, %rdx
	movq	stdout(%rip), %rax
	movq	%rbx, %rcx
	movl	$.LC3, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	call	pthread_self
	movq	%rax, %rbx
	call	omp_get_thread_num
	movslq	%eax, %rdx
	movq	stdout(%rip), %rax
	movq	-32(%rbp), %rcx
	movq	%rcx, -56(%rbp)
	movsd	-56(%rbp), %xmm0
	movq	%rbx, %rcx
	movl	$.LC4, %esi
	movq	%rax, %rdi
	movl	$1, %eax
	call	fprintf
	movl	$0, %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC1:
	.long	0
	.long	1071644672
	.ident	"GCC: (GNU) 6.2.0"
	.section	.note.GNU-stack,"",@progbits
