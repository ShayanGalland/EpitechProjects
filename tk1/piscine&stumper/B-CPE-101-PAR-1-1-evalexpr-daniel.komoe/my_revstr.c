/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** y
*/

#include "my_strlen.c"

char *my_revstr(char *str)
{
    char t = 0;
    int i = 0;
    int p = my_strlen(str);

    while(i < p -1)
    {
     	t = str[i];
	str[i] = str[p - 1];
	str[p - 1] = t;
	i = i + 1;
	p = p - 1;
    }
    return(str);
}
