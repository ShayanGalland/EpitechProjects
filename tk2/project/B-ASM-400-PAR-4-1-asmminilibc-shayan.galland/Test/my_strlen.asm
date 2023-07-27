
global my_strlen
section .text
my_strlen:
        mov rbx, rdi ; RDI is the parameter given by defaut (the str) so we give the str to rbx so we can manipulate it
        xor rax, rax ; it's like an int used to find the len of RDI and it setted to 0 with xor

loop:
        cmp byte [rbx], byte 0 ; compare rbx if it end of str (null byte)
        jz  return ; if it's the end of str go to the return "etiquette"
        inc rax ; rax increment to 1 (rax += 1)
        inc rbx ; increment to the next character of the string
        jmp loop ; loop til the "je" condition is not met

return:
        ret ; return RAX parameter returned by default
