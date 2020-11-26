	global ft_strcpy
	section	.text

ft_strcpy:
	mov		rax, rdi

.loop:
	cmp		byte [rsi], 0x0	; Check for null-byte
	jz		.returns		; if null-byte, jump to returns

	movsb					; Move bytes from rsi to rdi
							; movsb stands for move string byte
	jmp		.loop			; Jump to loop until rsi byte is null

.returns:
	mov		byte [rdi], 0
	ret