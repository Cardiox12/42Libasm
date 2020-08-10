	section .bss

WRITE_CODE	equ	0x02000004
	
	global ft_write
	extern __errno_location
	section .text

ft_write:
	call		__errno_location wrt ..plt	; call errno
	mov			rax, WRITE_CODE
	syscall
	ret