global  ft_strcmp

section .text

ft_strcmp:
    xor rcx, rcx

loop:
	mov al, [rdi + rcx]
    cmp BYTE al, [rsi + rcx]
    jne return
    inc rcx
    jmp loop

return:
    mov bl, [rsi + rcx]
    sub al, bl
    jz  equal
    js  smaller
    jmp more

equal:
    mov rax, 0
    ret

more:
    mov rax, 1
    ret

smaller:
    mov rax, -1
    ret
