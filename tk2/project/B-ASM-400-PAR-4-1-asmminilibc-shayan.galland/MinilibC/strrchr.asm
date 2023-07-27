BITS 64
global strrchr
section .text
strrchr:
        mov rbx, rdi
        mov dil, sil
        xor rcx, rcx
ln:
        cmp byte [rbx], 0
        je  loop
        inc rcx
        inc rbx
        jmp ln
loop:
        dec rcx
        cmp rcx, 0
        je return_null
        dec rbx
        cmp [rbx], dil
        je return
        jmp loop
return:
        mov rax, rbx
        ret
return_null:
        mov rax, 0
        ret