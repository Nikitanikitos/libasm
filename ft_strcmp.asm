global  ft_strcmp

section .text

ft_strcmp:
    xor rcx, rcx
    cmp [rdi + rcx], [rsi + rcx]
    jne return
    inc rcx

return:
    mov rdx, [rdi + rcx]
    sub rdx, [rsi + rcx]
    mov rax, rdx
    ret
