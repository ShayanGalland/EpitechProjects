global my_strstr
section .text

my_strstr:
    xor rcx, rcx
    xor rdx, rdx

compare_loop:
    cmp byte [rdi + rcx], 0
    je return_null
    cmp byte [rsi + rdx], 0
    je match_found

    mov al, [rdi + rcx]
    cmp al, [rsi + rdx]
    jne next_char

    inc rcx
    inc rdx
    jmp compare_loop

next_char:
    inc rcx
    xor rdx, rdx
    jmp compare_loop

match_found:
    sub rcx, rdx
    mov rax, rdi
    add rax, rcx
    ret

return_null:
    xor rax, rax
    ret
