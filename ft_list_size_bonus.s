section .text

global  _ft_list_size

_ft_list_size:
    xor rax, rax

.list_size:
    cmp rdi, 0
    je  exit
    inc rax
    mov rdi, [rdi+8]
    jmp list_size

.error:
    xor rax, rax
    ret
