/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** why must you const antly torture me with this?
*/

void my_putchar(char c);

void my_putstr(char const *str)
{
    for (int n = 0; str[n] != '\0'; n++)
        my_putchar(str[n]);
}
