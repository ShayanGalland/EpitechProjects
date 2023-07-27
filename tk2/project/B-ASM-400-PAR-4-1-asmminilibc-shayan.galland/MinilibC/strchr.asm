BITS 64
global strchr
section .text
strchr:
        mov rbx, rdi
        mov dil, sil
loop:
        cmp byte [rbx], 0
        je return_null
        cmp [rbx], dil
        je return
        inc rbx
        jmp loop
return:
        mov rax, rbx
        ret
return_null:
        mov eax, 0
        ret