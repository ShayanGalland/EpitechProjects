BITS 64
global memcpy
section .text
memcpy:
        xor rcx, rcx
loop:
        cmp rcx, rdx
        je return
        mov al, byte [rsi+rcx]
        mov byte [rdi+rcx], al
        inc rcx
        jmp loop
return:
        mov rax, rdi
        ret
