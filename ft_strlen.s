	global	ft_strlen
	section .text

ft_strlen:
	mov		r8, rdi
loop:
	cmp		byte [rdi], 0
	jz		endloop

	inc		rdi
	jmp		loop

endloop:
	mov		rax, rdi
	sub		rax, r8
	ret