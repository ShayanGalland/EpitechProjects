/*
** EPITECH PROJECT, 2021
** include
** File description:
** function h
*/

#ifndef INCLUDE_H_
    #define INCLUDE_H_

typedef struct palindrome_s {
    int imax;
    int imin;
    char *pnum;
    int base;
    int iter;
    int no_result;
} palindrome_t;
int my_strlen(char const *str);
int my_strcmp(const char *str1, const char *str2);
char *my_revstr(char *str);
void my_itoa(char *buffer, int number, int base);
int is_palindrome(char *num);
void fil_buffer(char *num, char *buffer);
void check_if_already_palindrome(int flag,
int count, char *buffer, palindrome_t *palindrome);
int in_palindrome(char *num, int flag, palindrome_t *palindrome);
int all_palindrome(char *num, palindrome_t *palindrome);
int commands_parse(int argc, char **argv, palindrome_t *palindrome);
int all_palindrome(char *num, palindrome_t *palindrome);
int in_palindrome(char *num, int flag, palindrome_t *palindrome);
void check_number(char *str);
int result_palindrome(long count, char *buffer, int mode, palindrome_t *pal);

#endif
