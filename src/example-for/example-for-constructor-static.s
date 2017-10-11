	.file	"example-for-constructor-static.c"
	.section	.rodata
	.align 8
.LC0:
	.string	"Thread[%d][%lu]: Before parallel region...\n"
	.align 8
.LC1:
	.string	"Thread[%d][%lu]: After parallel region...\n"
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
	.string	"Thread[%d][%lu]: Working in %lu loop iteration...\n"
	.text
	.type	main._omp_fn.0, @function
main._omp_fn.0:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%rbx
	subq	$40, %rsp
	movq	%rdi, -40(%rbp)
	call	omp_get_thread_num
	movl	%eax, -24(%rbp)
	call	omp_get_num_threads
	movl	%eax, %ebx
	call	omp_get_thread_num
	movl	%eax, %esi
	movl	$16, %eax
	cltd
	idivl	%ebx
	movl	%eax, %ecx
	movl	$16, %eax
	cltd
	idivl	%ebx
	movl	%edx, %eax
	cmpl	%eax, %esi
	jl	.L4
.L7:
	imull	%ecx, %esi
	movl	%esi, %edx
	addl	%edx, %eax
	leal	(%rax,%rcx), %ebx
	cmpl	%ebx, %eax
	jge	.L3
	movl	%eax, -20(%rbp)
.L6:
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
	jl	.L6
	jmp	.L3
.L4:
	movl	$0, %eax
	addl	$1, %ecx
	jmp	.L7
.L3:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.size	main._omp_fn.0, .-main._omp_fn.0
	.ident	"GCC: (Debian 4.8.4-1) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
