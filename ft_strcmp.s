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

	cmp		al, 0			;
	jz		endloop
	cmp		bl, 0
	jz		endloop

	cmp		al, bl
	jne		endloop

	inc		rdi
	inc		rsi
	jmp		loop

endloop:
	sub		rax, rbx

returns:
	pop		rbx
	pop		rsi
	pop		rdi
	ret