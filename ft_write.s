	section .bss

WRITE_CODE	equ	0x02000004
	
	global ft_write
	section .text

ft_write:
	mov			rax, WRITE_CODE
	syscall
	ret