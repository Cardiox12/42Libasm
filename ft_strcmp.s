	global _ft_strcmp
	section .text

_ft_strcmp:
loop:
	cmp		byte [rdi], 0
	jz		endloop
	cmp		byte [rsi], 0
	jz		endloop

	mov		al, byte [rdi]
	mov		ah, byte [rsi]
	cmp		al, ah
	jne		endloop

	inc		rdi
	inc		rsi
	jmp		loop

endloop:
	mov		al, byte [rdi]
	mov		ah, byte [rsi]
	cmp		al, ah
	mov		rax, 0
	je		returns
	mov		rax, 1
	jg		returns
	mov		rax, -1
	jl		returns

returns:
	ret