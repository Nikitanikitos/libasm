SYS_WRITE	equ 1

extern error

global ft_write
section .text

ft_write:
	mov rax, SYS_WRITE
	syscall
	ret
	call error

