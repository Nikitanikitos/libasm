section     .text
global      _ft_read
extern      ___error

_ft_read:
	mov     rax, 0x2000003
	syscall
	cmp     rax, 9
	je      error_exit
	ret

error_exit:
    mov     rax, -1
    push    rax
    call    ___error
    mov     rax, -1
    pop     rax
    ret
