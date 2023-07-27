global my_strcspn
section .text

my_strcspn:
        xor rcx, rcx
        xor rdx, rdx


        xor rbx, rbx
ln:
        cmp byte[rdi+rbx], 0
        je loop
        inc rbx
        jmp ln

loop:
        cmp byte[rsi+rdx], 0
        je return_len
        cmp byte[rdi+rcx], 0
        je inc
        mov al, byte[rsi,rdx]
        cmp al, byte[rdi,rcx]
        je return
        inc rcx
        jmp loop

inc:
        inc rdx
        xor rcx, rcx
        jmp loop

return:
        mov rax, rcx
        ret

return_len
        mov rax, rbx
        ret