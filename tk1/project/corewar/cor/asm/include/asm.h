/*
** EPITECH PROJECT, 2022
** asm
** File description:
** asm
*/

#ifndef ASM_H_
    #define ASM_H_
    #include "op.h"
    #include "../../include/my.h"

typedef struct asm_s {
    char *buffer;
    char **instruct;
    char **ori_instruct;
    int nbr_adress;
} asm_t;

int handle_error(char *filename);
int do_asm(char *filename);
int create_cor_file(char *filename);
void init_header(char **tab, header_t *header);
int write_instruction(asm_t *inst, int fd);
int get_label_adress(char **instruct, char *label, int line);

// UTILS //
char **reading_file(char const *filepath);
int is_last_path(char *str);
int get_program_size(char **array);
int convert(int nbr);
int is_except(char *str);

// GET DATA //
int nbr_arg(char *str);
int get_instruct_size(char *str);
char *skip_str(char *str, char param);

#endif