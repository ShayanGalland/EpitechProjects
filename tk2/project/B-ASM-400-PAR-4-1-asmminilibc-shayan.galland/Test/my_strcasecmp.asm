global my_strcasecmp
section .text

my_strcasecmp:
        xor rcx, rcx
loop_str1: ; i replace upercase by lowercase for str1
        cmp byte[rdi+rcx], 0
        je transit_other_str
        mov al, [rdi+rcx]
        cmp al, 'A'
        jge pass_str1
        inc rcx
        jmp loop_str1
pass_str1:
        cmp al, 'Z'
        jle upper_str1
        inc rcx
        jmp loop_str1
upper_str1:
        add al, 32
        mov byte[rdi+rcx], al
        inc rcx
        jmp loop_str1
transit_other_str:
        xor rcx, rcx
        jmp loop_str2
loop_str2: ; i replace upercase by lowercase for str2
        cmp byte[rsi+rcx], 0
        je transit_strcmp
        mov al, [rsi+rcx]
        cmp al, 'A'
        jge pass_str2
        inc rcx
        jmp loop_str2
pass_str2:
        cmp al, 'Z'
        jle upper_str2
        inc rcx
        jmp loop_str2
upper_str2:
        add al, 32
        mov byte[rsi+rcx], al
        inc rcx
        jmp loop_str2
transit_strcmp: ; transit to the original strcmp code
        xor rcx, rcx
        jmp loop
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
	ret