global my_strchr
section .text
my_strchr:
        mov rbx, rdi ; RDI is the parameter given by defaut (the str) so we give the str to rbx so we can manipulate it more easily
        mov dil, sil ; SIL is the parameter given by defaut (the char) so we give the char to dil so we can manipulate it more easily
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