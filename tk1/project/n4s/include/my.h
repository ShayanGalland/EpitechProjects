/*
** EPITECH PROJECT, 2022
** include
** File description:
** n4s
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char **my_str_to_word_array(char const *str, char n);
void direction(float left, float right, float dist);
int get_nb_line(char const *str, char delim);
char *get_word(char const *str, char delim);
char **my_str_to_word_array(char const *str, char n);
int my_strlen(char const *str, char delim);
void speed(float dist);
void free_arr(char **arr);
void start_n4s(void);
int main(void);
