section     .text
global      _ft_write
extern      ___error

_ft_write:
	mov     rax, 0x2000004
	syscall
	jc     error_exit
	ret

error_exit:
    mov     rbx, rax
    call    ___error
    mov     [rax], rbx
    ret
