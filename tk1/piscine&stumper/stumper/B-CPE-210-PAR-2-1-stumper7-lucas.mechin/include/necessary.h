/*
** EPITECH PROJECT, 2021
** include
** File description:
** navy
*/

#ifndef STUMP
    #define STUMP
    #include "my.h"
    #include "stdlib.h"
    #include "stdio.h"

typedef struct char_s {
    int *count;
    int status;
} char_t;

void flags(int ac, char **av, char_t *mem_char);
void count_char(char *str, char_t *mem_char);
void char_count(char_t *mem_char, char *str, int place);
int analyse_char(int j, int i, char *str);
void prt_recount(char_t *mem_char, char *str, int u);
int cond_cmp(int j, int i, char *str1, char *str2);
void double_str(char *str1, char *str2, char_t *mem_char);
void basic(char_t *mem_char, char *str, int place);

#endif /* !STUMP */
