BITS 64
global memset
section .text
memset:
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
