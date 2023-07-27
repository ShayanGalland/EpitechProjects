/*
** EPITECH PROJECT, 2021
** emacs
** File description:
** emacs
*/

#include<unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
