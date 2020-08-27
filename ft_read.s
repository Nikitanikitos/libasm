SYS_READ    equ 0

global      ft_read
section     .text

ft_read:
	mov     rax, SYS_READ
	syscall
	ret
