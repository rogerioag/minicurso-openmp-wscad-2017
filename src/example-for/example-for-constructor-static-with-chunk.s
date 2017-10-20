	.file	"example-for-constructor-static-with-chunk.c"
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
	subq	$8, %rsp
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
	addq	$8, %rsp
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
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$32, %rsp
	movq	%rdi, -56(%rbp)
	call	omp_get_thread_num
	movl	%eax, -40(%rbp)
	call	omp_get_num_threads
	movl	%eax, %r12d
	call	omp_get_thread_num
	movl	%eax, %r13d
	movl	$0, %ebx
.L6:
	movl	%ebx, %eax
	imull	%r12d, %eax
	addl	%r13d, %eax
	addl	%eax, %eax
	leal	2(%rax), %edx
	movl	$16, %ecx
	cmpl	$16, %edx
	cmovle	%edx, %ecx
	movl	%ecx, %r14d
	cmpl	$16, %eax
	jge	.L3
	movl	%eax, -36(%rbp)
.L5:
	movl	$0, %eax
	call	pthread_self
	movslq	%eax, %rdx
	movl	-36(%rbp), %ecx
	movl	-40(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -36(%rbp)
	cmpl	%r14d, -36(%rbp)
	jl	.L5
	addl	$1, %ebx
	jmp	.L6
.L3:
	addq	$32, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%rbp
	ret
	.size	main._omp_fn.0, .-main._omp_fn.0
	.ident	"GCC: (Debian 4.8.4-1) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
