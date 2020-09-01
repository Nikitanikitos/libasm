section.text:
	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy

_ft_strdup:
	cmp rdi, 0x0
	jz _error

.strlen_call:
	call _ft_strlen
	inc rax

.malloc_call:
	push rdi
	mov rdi, rax
	call _malloc
	cmp rax, 0x0
	jz _error

.strcpy_copy:
	pop rdi
	mov rsi, rdi
	mov rdi, rax
	call _ft_strcpy
	ret

_error:
	mov rax, 0x0
	ret