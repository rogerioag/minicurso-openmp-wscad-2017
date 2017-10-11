	.file	"example-tasks.c"
	.section	.rodata
.LC0:
	.string	"Uso: %s <x>\n"
	.align 8
.LC1:
	.string	"Thread[%lu,%lu]: Antes da regi\303\243o paralela.\n"
	.align 8
.LC2:
	.string	"Thread[%lu,%lu]: Depois da regi\303\243o paralela.\n"
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
	cmpl	$1, -36(%rbp)
	jg	.L2
	movq	-48(%rbp), %rax
	movq	(%rax), %rdx
	movq	stderr(%rip), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	$0, %edi
	call	exit
.L2:
	movl	$0, -20(%rbp)
	movq	-48(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -24(%rbp)
	call	pthread_self
	movq	%rax, %rbx
	call	omp_get_thread_num
	movl	%eax, %edx
	movq	stdout(%rip), %rax
	movq	%rbx, %rcx
	movl	$.LC1, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	-24(%rbp), %eax
	movl	%eax, -32(%rbp)
	leaq	-32(%rbp), %rax
	movl	$8, %edx
	movq	%rax, %rsi
	movl	$main._omp_fn.0, %edi
	call	GOMP_parallel_start
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	main._omp_fn.0
	call	GOMP_parallel_end
	call	pthread_self
	movq	%rax, %rbx
	call	omp_get_thread_num
	movl	%eax, %edx
	movq	stdout(%rip), %rax
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
	.string	"  Thread[%lu,%lu]: Todas as threads executam.\n"
	.align 8
.LC4:
	.string	"  Thread[%lu,%lu]: Antes de criar tasks.\n"
	.align 8
.LC5:
	.string	"    Thread[%lu,%lu]: Antes do taskwait.\n"
	.align 8
.LC6:
	.string	"    Thread[%lu,%lu]: Depois do taskwait.\n"
	.text
	.type	main._omp_fn.0, @function
main._omp_fn.0:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	call	omp_get_thread_num
	movl	%eax, -8(%rbp)
	call	pthread_self
	movq	%rax, %rcx
	movq	stdout(%rip), %rax
	movl	-8(%rbp), %edx
	movl	$.LC3, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	call	GOMP_single_start
	cmpb	$1, %al
	jne	.L4
	call	pthread_self
	movq	%rax, %rcx
	movq	stdout(%rip), %rax
	movl	-8(%rbp), %edx
	movl	$.LC4, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	cmpl	$10, -4(%rbp)
	setg	%al
	movl	$0, (%rsp)
	movl	%eax, %r9d
	movl	$1, %r8d
	movl	$0, %ecx
	movl	$0, %edx
	movl	$0, %esi
	movl	$main._omp_fn.1, %edi
	call	GOMP_task
	cmpl	$20, -4(%rbp)
	setg	%al
	movl	$0, (%rsp)
	movl	%eax, %r9d
	movl	$1, %r8d
	movl	$0, %ecx
	movl	$0, %edx
	movl	$0, %esi
	movl	$main._omp_fn.2, %edi
	call	GOMP_task
	call	pthread_self
	movq	%rax, %rcx
	movq	stdout(%rip), %rax
	movl	-8(%rbp), %edx
	movl	$.LC5, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	call	GOMP_taskwait
	call	pthread_self
	movq	%rax, %rcx
	movq	stdout(%rip), %rax
	movl	-8(%rbp), %edx
	movl	$.LC6, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	$0, (%rsp)
	movl	$1, %r9d
	movl	$1, %r8d
	movl	$0, %ecx
	movl	$0, %edx
	movl	$0, %esi
	movl	$main._omp_fn.3, %edi
	call	GOMP_task
.L4:
	leave
	ret
	.size	main._omp_fn.0, .-main._omp_fn.0
	.section	.rodata
	.align 8
.LC7:
	.string	"    Thread[%lu,%lu]: Trabalhando na task 1.\n"
	.text
	.type	main._omp_fn.1, @function
main._omp_fn.1:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%rbx
	subq	$24, %rsp
	movq	%rdi, -24(%rbp)
	call	pthread_self
	movq	%rax, %rbx
	call	omp_get_thread_num
	movl	%eax, %edx
	movq	stdout(%rip), %rax
	movq	%rbx, %rcx
	movl	$.LC7, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.size	main._omp_fn.1, .-main._omp_fn.1
	.section	.rodata
	.align 8
.LC8:
	.string	"    Thread[%lu,%lu]: Trabalhando na task 2.\n"
	.text
	.type	main._omp_fn.2, @function
main._omp_fn.2:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%rbx
	subq	$24, %rsp
	movq	%rdi, -24(%rbp)
	call	pthread_self
	movq	%rax, %rbx
	call	omp_get_thread_num
	movl	%eax, %edx
	movq	stdout(%rip), %rax
	movq	%rbx, %rcx
	movl	$.LC8, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.size	main._omp_fn.2, .-main._omp_fn.2
	.section	.rodata
	.align 8
.LC9:
	.string	"    Thread[%lu,%lu]: Trabalhando na task 3.\n"
	.text
	.type	main._omp_fn.3, @function
main._omp_fn.3:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%rbx
	subq	$24, %rsp
	movq	%rdi, -24(%rbp)
	call	pthread_self
	movq	%rax, %rbx
	call	omp_get_thread_num
	movl	%eax, %edx
	movq	stdout(%rip), %rax
	movq	%rbx, %rcx
	movl	$.LC9, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.size	main._omp_fn.3, .-main._omp_fn.3
	.ident	"GCC: (Debian 4.8.4-1) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
