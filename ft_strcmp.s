global  _ft_strcmp

section .text

_ft_strcmp:
    xor rcx, rcx

loop:
    mov al, byte [rdi + rcx]
    mov bl, byte [rsi + rcx]
    cmp al, 0
	je return
	cmp bl, 0
	je return
    cmp al, bl
    jne return
    inc rcx
    jmp loop

return:
    cmp al, bl
    je  equal
    jl  smaller
    jg more

equal:
    mov rax, 0
    ret

more:
    mov rax, 1
    ret

smaller:
    mov rax, -1
    ret
