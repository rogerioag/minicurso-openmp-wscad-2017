	.file	"example-simd.c"
	.comm	h_a,8388608,64
	.comm	h_b,8388608,64
	.comm	h_c,8388608,64
	.section	.rodata
.LC0:
	.string	"Inicializando os arrays.\n"
	.text
	.globl	init_array
	.type	init_array, @function
init_array:
	pushq	%rbp
	movq	%rsp, %rbp
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
	movslq	%eax, %rdx
	movabsq	$4602678819172646912, %rax
	movq	%rax, h_a(,%rdx,8)
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movabsq	$4602678819172646912, %rax
	movq	%rax, h_b(,%rdx,8)
	addl	$1, -4(%rbp)
.L2:
	cmpl	$1048575, -4(%rbp)
	jle	.L3
	leave
	ret
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
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%rbx
	subq	$56, %rsp
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
	addsd	%xmm0, %xmm1
	movq	%xmm1, %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	movq	%rax, h_c(,%rdx,8)
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
	ret
	.size	main, .-main
	.ident	"GCC: (Debian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
