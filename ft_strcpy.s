	global ft_strcpy
	section	.text

ft_strcpy:
	push	rdi
	push	rsi

loop:
	mov		al, byte [rsi]
	cmp		al, 0x0
	jz		returns

	mov 	byte [rdi], al
	inc		rdi
	inc		rsi
	jmp		loop

returns:
	mov 	byte [rdi], al
	mov		rax, rsi
	pop		rsi
	pop		rdi
	ret