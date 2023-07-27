global my_strrchr_to_bin
section .text
my_strrchr_to_bin:
        mov rbx, rdi
        push rbx
        mov dil, sil
        xor rcx, rcx

ln:
        cmp byte [rbx], 0
        je  data_restor
        inc rcx
        inc rbx
        jmp ln

data_restor:
        pop rbx
        je loop

loop:
        cmp rcx, 0
        je return_null
        cmp [rbx], dil
        je return
        dec rcx
        dec rbx
        jmp loop
return:
        mov rax, rbx
        ret
return_null:
        mov rax, 0
        ret