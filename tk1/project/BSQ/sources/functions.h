/*
** EPITECH PROJECT, 2021
** function.h
** File description:
** y
*/
#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <unistd.h>

char** read_map(char *map_path, int* lines_count, int* columns_count);
char *read_map_file(char *map_path);
int read_line(char *read_buffer, char *write_buffer);
void read_map_line(int *columns_count, char *current_line, char **map, int i);
void read_lines_count(int *lines_count, char *current_line, char ***map);
void reset_buffer(char *buffer, char val, int size);
int min_three(int a, int b, int c);
void init_matrix(char **M, int **S, int lines, int columns);
void print_square_in_map(char** M, int max_i, int max_j, int max_of_s);
void find_max_square(char **M, int lines, int columns);
void print_map(char** map, int lines, int columns);
void my_putchar(char c);
int my_strlen(char const *str);
int my_getnbr(char const *str);

#endif
