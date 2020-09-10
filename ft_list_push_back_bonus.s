section .text

global	_ft_list_push_back

_ft_list_push_back:
	cmp		BYTE [rdi], 0
	je		error
	cmp		rsi, 0
	je		error

	mov		rdx, [rdi]

loop:
	cmp		BYTE [rdx+8], 0
	je		exit
	mov		rdx, [rdx+8]
	jmp		loop

exit:
	mov		[rdx+8], rsi
	ret

error:
	xor rax, rax
	ret

