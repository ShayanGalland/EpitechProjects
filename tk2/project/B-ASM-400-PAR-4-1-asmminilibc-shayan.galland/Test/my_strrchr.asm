global my_strrchr
section .text
my_strrchr:
        mov rbx, rdi
        ;push rbx
        mov dil, sil
        xor rcx, rcx

ln:
        cmp byte [rbx], 0
        je  loop ;data_restor
        inc rcx
        inc rbx
        jmp ln

;data_restor:
        ;pop rbx

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