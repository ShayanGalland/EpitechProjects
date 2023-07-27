global my_memset

section .text
my_memset:
        xor rcx, rcx
loop:
        cmp rcx, rdx
        je return
        mov byte [rdi+rcx], sil
        inc rcx
        jmp loop


return:
        mov rax, rdi
        ret
