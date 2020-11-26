	extern	ft_strcpy
	extern	ft_strlen
	extern	malloc
	global	ft_strdup
	section	.text

ft_strdup:
	push	rdi					; save rdi

	call	ft_strlen			; get src size

	mov		rdi, rax			; move size into rdi to allocate size with malloc
	call	malloc wrt ..plt	; call malloc

	pop		rdi
	cmp		rax, 0
	je		.end

	mov		rsi, rdi
	mov		rdi, rax			; move malloc ptr into strcpy param
	call	ft_strcpy			; copy string


.end:
	ret