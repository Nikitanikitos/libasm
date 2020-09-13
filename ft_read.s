section     .text
global      _ft_read
extern      ___error

_ft_read:
	mov     rax, 0x2000003
	syscall
	jc     error_exit
	ret

error_exit:
    mov     rbx, rax
    call    ___error
    mov     [rax], rbx
    ret
