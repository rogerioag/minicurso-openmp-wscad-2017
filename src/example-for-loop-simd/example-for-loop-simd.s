	.file	"example-for-loop-simd.c"
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
	.section	.rodata
.LC2:
	.string	"h_c[%07d]: %f\n"
	.text
	.globl	print_array
	.type	print_array, @function
print_array:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	jmp	.L5
.L6:
	movl	-4(%rbp), %eax
	cltq
	movq	h_c(,%rax,8), %rcx
	movq	stdout(%rip), %rax
	movl	-4(%rbp), %edx
	movq	%rcx, -24(%rbp)
	movsd	-24(%rbp), %xmm0
	movl	$.LC2, %esi
	movq	%rax, %rdi
	movl	$1, %eax
	call	fprintf
	addl	$1, -4(%rbp)
.L5:
	cmpl	$1048575, -4(%rbp)
	jle	.L6
	nop
	leave
	ret
	.size	print_array, .-print_array
	.section	.rodata
.LC4:
	.string	"Verificando o resultado.\n"
.LC6:
	.string	"Resultado Final: (%f, %f)\n"
	.text
	.globl	check_result
	.type	check_result, @function
check_result:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$32, %rsp
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -16(%rbp)
	movq	stdout(%rip), %rax
	movq	%rax, %rcx
	movl	$25, %edx
	movl	$1, %esi
	movl	$.LC4, %edi
	call	fwrite
	movl	$0, -4(%rbp)
	jmp	.L8
.L9:
	movl	-4(%rbp), %eax
	cltq
	movsd	h_c(,%rax,8), %xmm0
	movsd	-16(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -16(%rbp)
	addl	$1, -4(%rbp)
.L8:
	cmpl	$1048575, -4(%rbp)
	jle	.L9
	movsd	-16(%rbp), %xmm0
	movsd	.LC5(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movq	stdout(%rip), %rax
	movq	-16(%rbp), %rdx
	movapd	%xmm0, %xmm1
	movq	%rdx, -24(%rbp)
	movsd	-24(%rbp), %xmm0
	movl	$.LC6, %esi
	movq	%rax, %rdi
	movl	$2, %eax
	call	fprintf
	nop
	leave
	ret
	.size	check_result, .-check_result
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$48, %rsp
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	movl	$0, %eax
	call	init_array
	leaq	-32(%rbp), %rax
	pushq	$0
	pushq	$32
	movl	$1, %r9d
	movl	$1048576, %r8d
	movl	$0, %ecx
	movl	$4, %edx
	movq	%rax, %rsi
	movl	$main._omp_fn.0, %edi
	call	GOMP_parallel_loop_dynamic
	addq	$16, %rsp
	movl	-32(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.type	main._omp_fn.0, @function
main._omp_fn.0:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%rbx
	subq	$56, %rsp
	movq	%rdi, -56(%rbp)
	movl	$0, %ebx
	leaq	-32(%rbp), %rdx
	leaq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	GOMP_loop_dynamic_next
	testb	%al, %al
	je	.L13
.L17:
	movq	-40(%rbp), %rax
	movl	%eax, %ecx
	movq	-32(%rbp), %rax
	movl	%eax, %edx
	movl	%edx, %ebx
	movl	$0, -20(%rbp)
	movl	%ecx, -20(%rbp)
.L15:
	cmpl	%edx, -20(%rbp)
	jge	.L14
	movl	-20(%rbp), %eax
	cltq
	movsd	h_a(,%rax,8), %xmm1
	movl	-20(%rbp), %eax
	cltq
	movsd	h_b(,%rax,8), %xmm0
	mulsd	%xmm1, %xmm0
	movl	-20(%rbp), %eax
	cltq
	movsd	%xmm0, h_c(,%rax,8)
	addl	$1, -20(%rbp)
	jmp	.L15
.L14:
	cmpl	$1048576, -20(%rbp)
	je	.L16
.L18:
	leaq	-32(%rbp), %rdx
	leaq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	GOMP_loop_dynamic_next
	testb	%al, %al
	jne	.L17
	jmp	.L13
.L16:
	movl	-20(%rbp), %eax
	movl	%eax, -24(%rbp)
	jmp	.L18
.L13:
	cmpl	$1048576, %ebx
	je	.L19
.L20:
	call	GOMP_loop_end_nowait
	jmp	.L21
.L19:
	movq	-56(%rbp), %rax
	movl	-24(%rbp), %edx
	movl	%edx, (%rax)
	jmp	.L20
.L21:
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.size	main._omp_fn.0, .-main._omp_fn.0
	.section	.rodata
	.align 8
.LC1:
	.long	0
	.long	1071644672
	.align 8
.LC5:
	.long	0
	.long	1093664768
	.ident	"GCC: (GNU) 6.2.0"
	.section	.note.GNU-stack,"",@progbits
