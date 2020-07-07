	global	_ft_strdup
	extern	_ft_strcpy
	extern	_ft_strlen
	extern	_malloc
	section	.text

_ft_strdup:
	push	rdi			; save rdi
	call	_ft_strlen	; get src size
	mov		rdi, rax	; move size into rdi to allocate size with malloc
	call	_malloc		; call malloc
	mov		rdi, rax	; move malloc ptr into strcpy param
	pop		rsi			; get the original string
	call	_ft_strcpy	; copy string
	mov		rax, rdi
	ret
	; Get size of string for malloc
	; Malloc the size of src
	; Copy src into dst