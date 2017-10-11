	.file	"example-taskloop.c"
	.section	.rodata
.LC0:
	.string	"Thread[%lu,%lu]: taskloop...\n"
	.text
	.globl	func
	.type	func, @function
func:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%rbx
	subq	$24, %rsp
	call	pthread_self
	movq	%rax, %rbx
	call	omp_get_thread_num
	movl	%eax, %edx
	movq	stdout(%rip), %rax
	movq	%rbx, %rcx
	movl	$.LC0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	$0, %edx
	movl	$16, %ecx
	leaq	-32(%rbp), %rax
	subq	$8, %rsp
	pushq	$1
	pushq	%rcx
	pushq	%rdx
	pushq	$0
	pushq	$8
	movl	$1280, %r9d
	movl	$8, %r8d
	movl	$16, %ecx
	movl	$0, %edx
	movq	%rax, %rsi
	movl	$func._omp_fn.0, %edi
	call	GOMP_taskloop
	addq	$48, %rsp
	nop
	movq	-8(%rbp), %rbx
	leave
	ret
	.size	func, .-func
	.section	.rodata
	.align 8
.LC1:
	.string	"Thread[%lu,%lu]: Before parallel region.\n"
	.align 8
.LC2:
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
	call	pthread_self
	movq	%rax, %rbx
	call	omp_get_thread_num
	movslq	%eax, %rdx
	movq	stdout(%rip), %rax
	movq	%rbx, %rcx
	movl	$.LC1, %esi
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
	movl	$.LC2, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	$0, %eax
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.size	main, .-main
	.section	.rodata
	.align 8
.LC3:
	.string	"Thread[%lu,%lu]: Trabalhando na itera\303\247\303\243o (%d,%d).\n"
	.text
	.type	func._omp_fn.0, @function
func._omp_fn.0:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%r12
	pushq	%rbx
	subq	$32, %rsp
	movq	%rdi, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	(%rax), %rdx
	movq	-40(%rbp), %rax
	movq	8(%rax), %rax
	movl	%eax, %r12d
	movl	%edx, -20(%rbp)
.L6:
	movl	$0, -24(%rbp)
.L7:
	movl	-24(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl	.L5
	addl	$1, -20(%rbp)
	cmpl	%r12d, -20(%rbp)
	jl	.L6
	jmp	.L8
.L5:
	call	pthread_self
	movq	%rax, %rbx
	call	omp_get_thread_num
	movl	%eax, %esi
	movq	stdout(%rip), %rax
	movl	-24(%rbp), %ecx
	movl	-20(%rbp), %edx
	movl	%ecx, %r9d
	movl	%edx, %r8d
	movq	%rbx, %rcx
	movl	%esi, %edx
	movl	$.LC3, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	addl	$1, -24(%rbp)
	jmp	.L7
.L8:
	addq	$32, %rsp
	popq	%rbx
	popq	%r12
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
	jne	.L9
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
	call	GOMP_taskgroup_start
	subq	$8, %rsp
	pushq	$0
	pushq	$0
	pushq	$0
	movl	$1, %r9d
	movl	$1, %r8d
	movl	$0, %ecx
	movl	$0, %edx
	movl	$0, %esi
	movl	$main._omp_fn.2, %edi
	call	GOMP_task
	addq	$32, %rsp
	subq	$8, %rsp
	pushq	$0
	pushq	$0
	pushq	$0
	movl	$1, %r9d
	movl	$1, %r8d
	movl	$0, %ecx
	movl	$0, %edx
	movl	$0, %esi
	movl	$main._omp_fn.3, %edi
	call	GOMP_task
	addq	$32, %rsp
	call	GOMP_taskgroup_end
.L9:
	movq	-8(%rbp), %rbx
	leave
	ret
	.size	main._omp_fn.1, .-main._omp_fn.1
	.section	.rodata
	.align 8
.LC5:
	.string	"Thread[%lu,%lu]: Trabalhando na task avulsa.\n"
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
	movl	$.LC5, %esi
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
.LC6:
	.string	"Thread[%lu,%lu]: Trabalhando na task func().\n"
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
	movl	$.LC6, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	$0, %eax
	call	func
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.size	main._omp_fn.3, .-main._omp_fn.3
	.ident	"GCC: (GNU) 6.2.0"
	.section	.note.GNU-stack,"",@progbits
