global my_strpbrk
section .text

my_strpbrk:
        xor rcx, rcx
        xor rbx, rbx
        mov rdx, rdi

        mov al, byte[rsi+rcx]

loop:
        cmp [rdi+rbx], al
        je return
        cmp byte[rdi+rbx], 0
        je next_char

        inc rdx
        inc rbx

        jmp loop

next_char:
        mov rdx, rdi
        xor rbx, rbx


        inc rcx
        cmp byte[rsi+rcx], 0
        je return_null
        mov al, byte[rsi+rcx]
        jmp loop

return:
        mov rax, rdx
        ret
return_null:
        mov eax, 0
        ret