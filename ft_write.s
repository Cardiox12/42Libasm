	section .bss
	
	global ft_write
	extern __errno_location
	section .text

ft_write:
	call		__errno_location wrt ..plt	; call errno
	mov			rax, 1
	syscall
	ret