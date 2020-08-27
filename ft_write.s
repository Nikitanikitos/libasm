SYS_WRITE	equ 1

global ft_write
section .text

ft_write:
	mov rax, SYS_WRITE
	syscall
	ret

