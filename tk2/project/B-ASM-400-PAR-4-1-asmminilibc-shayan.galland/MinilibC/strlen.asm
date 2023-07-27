BITS 64; start strlen code
global strlen
section .text
strlen:
        mov rbx, rdi
        xor rax, rax
loop:
        cmp byte [rbx], 0
        jz  return
        inc rax
        inc rbx
        jmp loop

return:
        ret
