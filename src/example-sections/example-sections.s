	.file	"example-sections.c"
	.section	.rodata
	.align 8
.LC0:
	.string	"Thread[%lu]: Antes da Regi\303\243o Paralela.\n"
	.align 8
.LC1:
	.string	"Thread[%lu]: Depois da Regi\303\243o Paralela.\n"
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$0, %eax
	call	pthread_self
	movslq	%eax, %rdx
	movq	stdout(%rip), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	-4(%rbp), %eax
	movl	%eax, -16(%rbp)
	leaq	-16(%rbp), %rax
	movl	$4, %edx
	movq	%rax, %rsi
	movl	$main._omp_fn.0, %edi
	call	GOMP_parallel_start
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	main._omp_fn.0
	call	GOMP_parallel_end
	movl	-16(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	$0, %eax
	call	pthread_self
	movslq	%eax, %rdx
	movq	stdout(%rip), %rax
	movl	$.LC1, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.section	.rodata
	.align 8
.LC2:
	.string	"   Thread[%lu,%lu]: Trabalhando na se\303\247\303\243o 3.\n"
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
	call	omp_get_thread_num
	movq	-24(%rbp), %rdx
	movl	%eax, (%rdx)
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movl	$3, %edi
	call	GOMP_sections_start
.L9:
	cmpl	$1, %eax
	je	.L5
	cmpl	$1, %eax
	jb	.L6
	cmpl	$2, %eax
	je	.L7
	cmpl	$3, %eax
	je	.L8
	ud2
.L6:
	call	GOMP_sections_end_nowait
	jmp	.L11
.L10:
	call	GOMP_sections_next
	jmp	.L9
.L8:
	movl	$0, %eax
	call	pthread_self
	movslq	%eax, %rcx
	movq	stdout(%rip), %rax
	movl	-4(%rbp), %edx
	movl	$.LC2, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	jmp	.L10
.L7:
	movl	$0, %eax
	call	pthread_self
	movslq	%eax, %rcx
	movq	stdout(%rip), %rax
	movl	-4(%rbp), %edx
	movl	$.LC3, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	jmp	.L10
.L5:
	movl	$0, %eax
	call	pthread_self
	movslq	%eax, %rcx
	movq	stdout(%rip), %rax
	movl	-4(%rbp), %edx
	movl	$.LC4, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	jmp	.L10
.L11:
	leave
	ret
	.size	main._omp_fn.0, .-main._omp_fn.0
	.ident	"GCC: (Debian 4.8.4-1) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
