section     .text
global      _ft_list_push_front

_ft_list_push_front:
    cmp     BYTE [rdi], 0
    je      error
    cmp     rsi, 0
    je      error

    mov     rdx, [rdi]

    mov     [rsi+8], rdx
    
    mov     [rdi], rsi
    ret

error:
    xor rax, rax
    ret
