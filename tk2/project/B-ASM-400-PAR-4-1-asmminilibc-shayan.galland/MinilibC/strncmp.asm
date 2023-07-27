BITS 64
global strncmp
section .text
strncmp:
	xor rcx, rcx
loop:
    cmp rcx, rdx
    je return_null
	mov al, byte[rdi+rcx]
	mov bl, byte[rsi+rcx]
    inc rcx
	cmp al, bl
	je end_of_string
    jmp return_acsii
end_of_string:
	cmp al, 0
	je return_null
    jmp loop
return_acsii:
	movsx eax, al
	movsx ebx, bl
	sub eax, ebx
    ret
return_null:
    xor eax, eax
	ret