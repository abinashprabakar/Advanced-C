section .bss
	digitspace resb 100
	digitspacePos resb 8

section .text
	global _start
_start:
	mov rax,0
	mov rbx,0
	loop:
	add rax,rbx
	add rbx,1
	cmp rbx,10
	jne loop

	call _printRAX

	mov rax,60
	mov rdi,0
	syscall


_printRAX:
	mov rcx,digitspace
	mov rbx,10
	mov [rcx],rbx
	inc rcx
	mov [digitspacePos],rcx
printRAXLoop:
	mov rdx,0
	mov rbx,10
	div rbx
	push rax
	add rdx,48
	mov rcx,[digitspacePos]
	mov[rcx],dl
	inc rcx
	mov[digitspacePos],rcx
	pop rax
	cmp rax,0
	jne printRAXLoop

printRAXLoop2:
	mov rcx,[digitspacePos]
	mov rax,1
	mov rdi,1
	mov rsi,rcx
	mov rdx,1
	syscall
	mov rcx,[digitspacePos]
	dec rcx
	mov[digitspacePos],rcx
	cmp rcx,digitspace
	jge printRAXLoop2

	ret
