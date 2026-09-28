; hello world

section .text

	global _start

	_start:
		; hello to the world
		mov rax, 1
		mov rdi, 1
		mov rsi, msg
		mov rdx, 772
		syscall
		jmp .write_msg

	.write_msg:
		mov rax, 1
		mov rdi, 1
		push 96
		mov rsi, rsp
		mov rdx, 1
		syscall
		mov r12, msg
		jmp .loop

	.loop:
		cmp byte [r12], 0
		je .exit
		cmp byte [r12], 10
		je .write_nl
		mov rax, 1
		mov rdi, 1
		mov rsi, r12
		mov rdx, 1
		syscall
		inc r12
		jmp .loop

	.write_nl:
		mov rax, 1
		mov rdi, 1
		push 0x6E5C
		mov rsi, rsp
		mov rdx, 2
		syscall
		inc r12
		jmp .loop

	.exit:
		mov rax, 1
		mov rdi, 1
		push 96
		mov rsi, rsp
		mov rdx, 1
		syscall
		mov rax, 1
		mov rdi, 1
		mov rsi, end
		mov rdx, 3
		syscall
		mov rax, 60
		mov rdi, 0
		syscall

section .data
	end db ", 0"
	msg db `; hello world\n\nsection .text\n\n	global _start\n\n	_start:\n		; hello to the world\n		mov rax, 1\n		mov rdi, 1\n		mov rsi, msg\n		mov rdx, 772\n		syscall\n		jmp .write_msg\n\n	.write_msg:\n		mov rax, 1\n		mov rdi, 1\n		push 96\n		mov rsi, rsp\n		mov rdx, 1\n		syscall\n		mov r12, msg\n		jmp .loop\n\n	.loop:\n		cmp byte [r12], 0\n		je .exit\n		cmp byte [r12], 10\n		je .write_nl\n		mov rax, 1\n		mov rdi, 1\n		mov rsi, r12\n		mov rdx, 1\n		syscall\n		inc r12\n		jmp .loop\n\n	.write_nl:\n		mov rax, 1\n		mov rdi, 1\n		push 0x6E5C\n		mov rsi, rsp\n		mov rdx, 2\n		syscall\n		inc r12\n		jmp .loop\n\n	.exit:\n		mov rax, 1\n		mov rdi, 1\n		push 96\n		mov rsi, rsp\n		mov rdx, 1\n		syscall\n		mov rax, 1\n		mov rdi, 1\n		mov rsi, end\n		mov rdx, 3\n		syscall\n		mov rax, 60\n		mov rdi, 0\n		syscall\n\nsection .data\n	end db ", 0"\n	msg db `, 0