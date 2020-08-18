global  ft_strcpy

section .text

ft_strcpy:
    xor rcx, rcx

loop:
    cmp BYTE [rdi + rcx], 0
    je  return
    mov rdx, [rdi + rcx]
    mov [rsi + rcx], rdx
    inc rcx
    jmp loop

return:
    mov rax, rsi
    ret
