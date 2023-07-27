global my_strpbrk
section .text

my_strpbrk:
sort_rsi_alpha:
        xor rcx, rcx
        xor r8, r8
        xor r9, r9
        mov rbx, rsi
fil_bigger:
        mov al, byte[rbx+rcx]
        mov r9, rcx
        inc rcx
firt_alpha:
        cmp byte[rbx+rcx], 0
        je transit_alpha
        cmp al, byte[rbx+rcx]
        jge fil_bigger
        jne inc_rcx
        jmp firt_alpha
transit_alpha:
        cmp rcx, r8
        je return

        xor rcx, rcx
        mov byte[rdx+r8], al
        mov byte[rbx+r9], 1
        inc r8
        jmp fil_bigger


inc_rcx:
        inc rcx
        jmp firt_alpha
return:
        mov rax, rdx
        ret






;strchr_perchar:
;        xor rcx, rcx
;        xor rbx, rbx
;        mov rdx, rdi
;
;        mov al, byte[rsi+rcx]
;
;loop:
;        cmp [rdi+rbx], al
;        je return
;        cmp byte[rdi+rbx], 0
;        je next_char
;
;        inc rdx
;        inc rbx
;
;        jmp loop
;
;next_char:
;        mov rdx, rdi
;        xor rbx, rbx
;        jmp loop
;
;return:
;        mov rax, rdx
;        ret
;return_null:
;        mov eax, 0
;        ret