global      ft_strdup
extern      malloc
extern      ft_strlen
extern      ft_strcpy

section     .text

section     .text

ft_strdup:
    cmp     rdi, 0
    je      error
    call    ft_strlen
    inc     rax
    ret

.malloc:
    push    rdi
    mov     rdi, rax
    call    malloc
    pop     rdi
    cmp     rax, 0
    je      error
    xor     rcx, rcx

.copy:
    mov     BYTE dl, [rdi + rcx]
    mov     BYTE [rax + rcx], dl
    cmp     dl, 0
    je      return
    inc     rcx

return:
    ret

error:
    xor     rax, rax
    ret
