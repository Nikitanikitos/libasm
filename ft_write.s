section     .text
global      _ft_write
extern      ___error

_ft_write:
	mov     rax, 0x2000004
	syscall
	cmp    rax, 9
	je     error_exit
	ret

error_exit:
    mov     rax, -1
    push    rax
    call    ___error
    mov     rax, -1
    pop     rax
    ret
