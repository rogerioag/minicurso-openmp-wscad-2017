	.file	"example-for-constructor-dynamic.c"
	.section	.rodata
	.align 8
.LC0:
	.string	"Thread[%d][%lu]: Antes da Regi\303\243o Paralela.\n"
	.align 8
.LC1:
	.string	"Thread[%d][%lu]: Depois da Regi\303\243o Paralela.\n"
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%rbx
	subq	$24, %rsp
	movl	$0, %eax
	call	pthread_self
	movslq	%eax, %rbx
	call	omp_get_thread_num
	movq	%rbx, %rdx
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$4, %edx
	movl	$0, %esi
	movl	$main._omp_fn.0, %edi
	call	GOMP_parallel_start
	movl	$0, %edi
	call	main._omp_fn.0
	call	GOMP_parallel_end
	movl	$0, %eax
	call	pthread_self
	movslq	%eax, %rbx
	call	omp_get_thread_num
	movq	%rbx, %rdx
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.size	main, .-main
	.section	.rodata
	.align 8
.LC2:
	.string	"Thread[%d][%lu]: Trabalhando na itera\303\247\303\243o %lu.\n"
	.text
	.type	main._omp_fn.0, @function
main._omp_fn.0:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%rbx
	subq	$56, %rsp
	movq	%rdi, -56(%rbp)
	call	omp_get_thread_num
	movl	%eax, -24(%rbp)
	leaq	-32(%rbp), %rdx
	leaq	-40(%rbp), %rax
	movq	%rdx, %r9
	movq	%rax, %r8
	movl	$2, %ecx
	movl	$1, %edx
	movl	$16, %esi
	movl	$0, %edi
	call	GOMP_loop_dynamic_start
	testb	%al, %al
	je	.L4
.L6:
	movq	-40(%rbp), %rax
	movl	%eax, -20(%rbp)
	movq	-32(%rbp), %rax
	movl	%eax, %ebx
.L5:
	movl	$0, %eax
	call	pthread_self
	movslq	%eax, %rdx
	movl	-20(%rbp), %ecx
	movl	-24(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -20(%rbp)
	cmpl	%ebx, -20(%rbp)
	jl	.L5
	leaq	-32(%rbp), %rdx
	leaq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	GOMP_loop_dynamic_next
	testb	%al, %al
	jne	.L6
.L4:
	call	GOMP_loop_end_nowait
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.size	main._omp_fn.0, .-main._omp_fn.0
	.ident	"GCC: (Debian 4.8.4-1) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
