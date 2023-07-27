global my_strcmp
section .text
my_strcmp:
	xor rcx, rcx
loop:
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
	re