section     .text
global      _ft_list_push_front

_ft_list_push_front:
    push    rsi
    push    rdx
    cmp     qword [rdi], 0
    je      error
    cmp     rsi, 0
    je      error

    mov     rdx, [rdi]

    mov     [rsi+8], rdx
    
    mov     [rdi], rsi
    pop     rdx
    pop     rsi
    ret

error:
    xor rax, rax
    pop     rdx
    pop     rsi
    ret
