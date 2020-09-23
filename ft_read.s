	section .bss

READ_OPCODE	equ	0x02000003

	global ft_read
	extern	__errno_location
	section	.text

ft_read:
	mov		rax, READ_OPCODE
	syscall
	ret