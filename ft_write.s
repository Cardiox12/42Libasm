	section .bss

WRITE_CODE	equ	0x02000004
	
	global _ft_write
	section .text

_ft_write:
	mov			rax, WRITE_CODE
	syscall
	ret