section     .text
global      _ft_list_push_front

_ft_list_push_front:
    cmp     [rdi], 0
    je      error
    cmp     rsi, 0
    je      error

    mov     rdx, [rdi]
    mov     [rdi], rsi
    mov     [rdi+8], rdx
    ret

error:
    xor rax, rax
    ret