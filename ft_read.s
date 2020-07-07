	section .bss

READ_OPCODE	equ	0x02000003

	global _ft_read
	section	.text

_ft_read:
	mov rax, READ_OPCODE
	syscall
	ret