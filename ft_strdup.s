	global	ft_strdup
	extern	ft_strcpy
	extern	ft_strlen
	extern	malloc
	section	.text

ft_strdup:
	push	rdi					; save rdi
	call	ft_strlen			; get src size
	mov		rdi, rax			; move size into rdi to allocate size with malloc
	call	malloc wrt ..plt	; call malloc

	pop		rdi
	mov		rsi, rdi
	mov		rdi, rax			; move malloc ptr into strcpy param
	call	ft_strcpy			; copy string
	ret
								; Get size of string for malloc
								; Malloc the size of src
								; Copy src into dst