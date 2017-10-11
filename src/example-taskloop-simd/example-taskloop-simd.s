	.file	"example-taskloop-simd.c"
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
	ret
	.size	init_array, .-init_array
	.globl	func
	.type	func, @function
func:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$48, %rsp
	movl	$0, %edx
	movl	$1048576, %ecx
	leaq	-36(%rbp), %rax
	movq	%rax, -16(%rbp)
	leaq	-32(%rbp), %rax
	subq	$8, %rsp
	pushq	$1
	pushq	%rcx
	pushq	%rdx
	pushq	$0
	pushq	$4
	movl	$1280, %r9d
	movl	$8, %r8d
	movl	$24, %ecx
	movl	$0, %edx
	movq	%rax, %rsi
	movl	$func._omp_fn.0, %edi
	call	GOMP_taskloop
	addq	$48, %rsp
	nop
	leave
	ret
	.size	func, .-func
	.section	.rodata
	.align 8
.LC2:
	.string	"Thread[%lu,%lu]: Before parallel region.\n"
	.align 8
.LC3:
	.string	"Thread[%lu,%lu]: After parallel region.\n"
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%rbx
	subq	$24, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
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
	movl	$0, %ecx
	movl	$4, %edx
	movl	$0, %esi
	movl	$main._omp_fn.1, %edi
	call	GOMP_parallel
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
	movl	$0, %eax
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.size	main, .-main
	.type	func._omp_fn.0, @function
func._omp_fn.0:
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movl	%edx, %ecx
	movl	%eax, %edx
	movl	%edx, %esi
	movl	$0, -4(%rbp)
	movl	%ecx, -4(%rbp)
.L9:
	cmpl	%edx, -4(%rbp)
	jge	.L8
	movl	-4(%rbp), %eax
	cltq
	movsd	h_a(,%rax,8), %xmm1
	movl	-4(%rbp), %eax
	cltq
	movsd	h_b(,%rax,8), %xmm0
	mulsd	%xmm1, %xmm0
	movl	-4(%rbp), %eax
	cltq
	movsd	%xmm0, h_c(,%rax,8)
	addl	$1, -4(%rbp)
	jmp	.L9
.L8:
	cmpl	$1048576, -4(%rbp)
	je	.L10
.L13:
	cmpl	$1048576, %esi
	jne	.L7
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movl	-8(%rbp), %edx
	movl	%edx, (%rax)
	jmp	.L7
.L10:
	movl	-4(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp	.L13
.L7:
	popq	%rbp
	ret
	.size	func._omp_fn.0, .-func._omp_fn.0
	.section	.rodata
	.align 8
.LC4:
	.string	"  Thread[%lu,%lu]: Before tasks.\n"
	.text
	.type	main._omp_fn.1, @function
main._omp_fn.1:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%rbx
	subq	$24, %rsp
	movq	%rdi, -24(%rbp)
	call	GOMP_single_start
	cmpb	$1, %al
	jne	.L14
	call	pthread_self
	movq	%rax, %rbx
	call	omp_get_thread_num
	movslq	%eax, %rdx
	movq	stdout(%rip), %rax
	movq	%rbx, %rcx
	movl	$.LC4, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	$0, %eax
	call	func
.L14:
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.size	main._omp_fn.1, .-main._omp_fn.1
	.section	.rodata
	.align 8
.LC1:
	.long	0
	.long	1071644672
	.ident	"GCC: (GNU) 6.2.0"
	.section	.note.GNU-stack,"",@progbits
