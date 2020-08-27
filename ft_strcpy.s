global  ft_strcpy

section .text

ft_strcpy:
    xor rcx, rcx

loop:
    cmp BYTE [rsi + rcx], 0     ; dst = rdi, src = rsi
    je  return
    mov dl, BYTE [rsi + rcx]
    mov BYTE [rdi + rcx], dl
    inc rcx
    jmp loop

return:
    mov BYTE [rdi + rcx], 0
    mov rax, rdi
    ret
