	section .bss

	global ft_read
	extern	__errno_location
	section	.text

ft_read:
	push	rbx							; align the stack

	mov		rax, 0						; set instruction register to op code of write
	syscall								; call read syscall

	cmp		rax, 0						; compare return of read to 0
	jge		.end						; if the return of read is greater or equal to 0, just return
	
	neg		rax							; otherwise make rax positive, to retrieve errno
	mov		r8, rax						; save rax in r8
	call	__errno_location wrt ..plt	; call __errno_location to retrieve errno ptr
	mov		[rax], r8					; set errno from read return
	mov		rax, -1						; set return to -1

.end:
	pop		rbx
	ret