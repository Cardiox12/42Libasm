	global ft_strcmp
	section .text

ft_strcmp:
	push	rdi				; save rdi
	push	rsi				; save rsi
	push	rbx				; save rbx
	xor		rax, rax		; set rax to 0
	xor		rbx, rbx		; set rbx to 0

loop:
	mov		al, byte [rdi]	; mov char pointed by rdi into al
	mov		bl, byte [rsi]	; mov char pointed by rsi into bl

	cmp		al, 0			; check null-byte
	jz		endloop			; if null-byte jump to endloop
	cmp		bl, 0			; check null-byte
	jz		endloop			; if null-byte jump to endloop

	cmp		al, bl			; compare al and bl
	jne		endloop			; if al != bl then jump to endloop
							; otherwise
	inc		rdi				; increment rdi pointer
	inc		rsi				; increment rsi pointer
	jmp		loop			; jump to loop tag

endloop:
	sub		rax, rbx		; subtract rax from rbx
	; al representing the lowest byte of rax
	; rax [    [  eax   ]
	; rax        [  ax  ]
	; rax [         [al]]

	; bl representing the lowest byte of rax
	; rbx [    [  ebx   ]
	; rbx        [  bx  ]
	; rbx [         [bl]]

returns:
	pop		rbx				; restore rbx value
	pop		rsi				; restore rsi value
	pop		rdi				; restore rdi value
	ret						; return