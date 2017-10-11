	.file	"example-sections-reduction.c"
	.section	.rodata
	.align 8
.LC0:
	.string	"Thread[%d][%lu]: Antes da Regi\303\243o Paralela.\n"
	.align 8
.LC1:
	.string	"Thread[%d][%lu]: Depois da Regi\303\243o Paralela.\n"
.LC2:
	.string	"Thread[%d][%lu]: sum: %d\n"
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%rbx
	subq	$40, %rsp
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	movl	$0, -20(%rbp)
	movl	$0, %eax
	call	pthread_self
	movslq	%eax, %rbx
	movl	$0, %eax
	call	omp_get_thread_num
	movl	%eax, %edx
	movq	stdout(%rip), %rax
	movq	%rbx, %rcx
	movl	$.LC0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	-24(%rbp), %eax
	movl	%eax, -32(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, -28(%rbp)
	leaq	-32(%rbp), %rax
	movl	$8, %edx
	movq	%rax, %rsi
	movl	$main._omp_fn.0, %edi
	call	GOMP_parallel_start
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	main._omp_fn.0
	call	GOMP_parallel_end
	movl	-32(%rbp), %eax
	movl	%eax, -24(%rbp)
	movl	-28(%rbp), %eax
	movl	%eax, -20(%rbp)
	movl	$0, %eax
	call	pthread_self
	movslq	%eax, %rbx
	movl	$0, %eax
	call	omp_get_thread_num
	movl	%eax, %edx
	movq	stdout(%rip), %rax
	movq	%rbx, %rcx
	movl	$.LC1, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	$0, %eax
	call	pthread_self
	movslq	%eax, %rbx
	movl	$0, %eax
	call	omp_get_thread_num
	movl	%eax, %edx
	movq	stdout(%rip), %rax
	movl	-20(%rbp), %ecx
	movl	%ecx, %r8d
	movq	%rbx, %rcx
	movl	$.LC2, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	$0, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.size	main, .-main
	.section	.rodata
	.align 8
.LC3:
	.string	"   Thread[%lu,%lu]: Trabalhando na se\303\247\303\243o 2.\n"
	.align 8
.LC4:
	.string	"   Thread[%lu,%lu]: Trabalhando na se\303\247\303\243o 1.\n"
	.text
	.type	main._omp_fn.0, @function
main._omp_fn.0:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	$0, %eax
	call	omp_get_thread_num
	movl	%eax, -8(%rbp)
	movl	$0, -4(%rbp)
	movl	$2, %edi
	call	GOMP_sections_start
.L8:
	cmpl	$1, %eax
	je	.L5
	cmpl	$1, %eax
	jb	.L6
	cmpl	$2, %eax
	je	.L7
	ud2
.L6:
	movq	-24(%rbp), %rax
	leaq	4(%rax), %rdx
	movl	-4(%rbp), %eax
	lock addl	%eax, (%rdx)
	call	GOMP_sections_end_nowait
	jmp	.L14
.L10:
	call	GOMP_sections_next
	jmp	.L8
.L7:
	movl	$0, %eax
	call	pthread_self
	movslq	%eax, %rcx
	movq	stdout(%rip), %rax
	movl	-8(%rbp), %edx
	movl	$.LC3, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movq	-24(%rbp), %rax
	movl	$0, (%rax)
.L11:
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	cmpl	$1023, %eax
	jg	.L10
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	addl	%eax, -4(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	leal	1(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	jmp	.L11
.L5:
	movl	$0, %eax
	call	pthread_self
	movslq	%eax, %rcx
	movq	stdout(%rip), %rax
	movl	-8(%rbp), %edx
	movl	$.LC4, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movq	-24(%rbp), %rax
	movl	$0, (%rax)
.L13:
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	cmpl	$1023, %eax
	jg	.L10
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	addl	%eax, -4(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	leal	1(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	jmp	.L13
.L14:
	leave
	ret
	.size	main._omp_fn.0, .-main._omp_fn.0
	.ident	"GCC: (Debian 4.8.4-1) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
