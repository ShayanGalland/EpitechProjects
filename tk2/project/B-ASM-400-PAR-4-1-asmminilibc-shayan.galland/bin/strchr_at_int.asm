global my_strchr_at_int
section .text
my_strchr_at_int:
        mov rbx, rdi
        mov rcx, rsi
loop:
        cmp byte [rbx], 0
        je return_null
        cmp rcx, 0
        je return
        inc rbx
        dec rcx
        jmp loop
return:
        mov rax, rbx
        ret
return_null:
        mov rax, 0
        ret