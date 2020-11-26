	section .bss

	global ft_write
	extern __errno_location
	section .text

ft_write:
	push		rbx
	push		r12

	mov			rax, 1
	syscall

	cmp			rax, 0
	jge			.end

	neg			rax
	mov			r12, rax
	call		__errno_location wrt ..plt
	mov			[rax], r12
	mov			rax, -1

.end:
	pop			r12
	pop			rbx
	ret