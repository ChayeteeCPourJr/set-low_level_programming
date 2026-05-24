global main
extern printf

section .data
	msg db "Hello, Holberton", 10, 0

section .text
main:
	push rbp
	mov rbp, rsp

	lea rdi, [rel msg]
	xor eax, eax
	call printf

	xor eax, eax
	pop rbp
	ret

section .note.GNU-stack noalloc noexec nowrite progbits
