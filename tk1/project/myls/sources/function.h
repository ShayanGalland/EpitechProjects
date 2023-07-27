/*
** EPITECH PROJECT, 2021
** y
** File description:
** y
*/

#ifndef _FUNCTION_H
    #define _FUNCTION_H
    #include <dirent.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
void my_putchar(char c);
int ls_d(void);
int ls_l(void);
int ls_a(void);
int ls_r(void);
int ls(void);
void ls_br(int count);
int my_putnbr(int nb);
void my_putstr(char const *str);
void ls_flags(char **argv, int i);
#endif
