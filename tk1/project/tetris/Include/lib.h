/*
** EPITECH PROJECT, 2021
** lib.h
** File description:
** here we find the wild prototypes in their natural habitat
*/

#ifndef LIB_H_
    #define LIB_H_

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char *str);
int my_isneg(int n);
int my_is_prime(int nb);
void my_putchar(char c);
void my_putnbr(int nb);
void my_putstr(char *str);
void my_put_octal(int nb);
void my_put_maj_s_tr(char const *str);
void my_printf(char *str, ...);
char *my_revstr(char *str);
int my_showmem(char *str, int size);
int my_showstr(char *str);
int *my_sort_int_array(int *tab, int size);
int my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char *s1, char *s2);
char *my_strcpy(char *dest, char *src);
int my_str_isalpha(char *str);
int my_str_islower(char *str);
int my_str_isnum(char *str);
int my_str_isprintable(char *str);
int my_str_isupper(char *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char *src, int nb);
int my_strncmp(void);
char *my_strncpy(char *dest, char const *src, int n);
int my_strstr(void);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
int my_show_word_array(char * const *tab);
char **my_str_to_word_array(char const *str);
char **my_split(char **tab, char *str, char c);
int count_word(char *word, char *str);
void display_tab(char **tab);
int my_tablen(char **tab);
void my_free(char **tab);

#endif /* LIB_H_ */
