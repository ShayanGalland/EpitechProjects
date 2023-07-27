/*
** EPITECH PROJECT, 2021
** include
** File description:
** navy
*/

#ifndef STUMP
    #define STUMP
    #include "my.h"

unsigned int generate_random_number(int min, int max);
void display_file(char *buff);
char *load_file_in_mem(char const *filepath);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
char **my_str_to_word_array(char *str);
void init_displ(char *star, int tries);
void end_disp(int tries);
void extend_dis(char *my_string, char **tab, char *star, int numbers);
int dis_cond(char **tab, char *my_string, int tries, int numbers);
int find_letter(char *str, char c, int n);
void my_free(char **tab);
void display_start(void);
int display_word(char *my_string, char *tab);
char *my_star(char *star, int len);
int win(char *str, int len, int lose);
int my_end(char *star, int len, int tries);
void display_incond(char **tab, char *star, char *my_string, int numbers);
void display_init(char **tab, int numbers, int tries, char *star);

#endif /* !STUMP */
