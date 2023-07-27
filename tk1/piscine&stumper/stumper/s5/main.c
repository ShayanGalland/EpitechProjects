/*
** EPITECH PROJECT, 2022
** y
** File description:
** y
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
void my_putchar(char c)
{
    write(1, &c ,1);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

char *clean_space(char *str)
{
    int count = 0;
    int n = 0;
    int p = 0;
    char *cop_str = malloc(sizeof(char)*my_strlen(str));

    for (int i = 0;str[i] != '\0';i++) {
        while (str[i] == ' ') {
            count++;
            i++;
            if (p == 0 && str[0] == ' ' && str[i] == '\0')
                count = 0;
        }
        p++;
        if (count >= 1) {
            cop_str[n] = ' ';
            n++;
            count = 0;
        }   
        if (count == 0) {
            cop_str[n] = str[i];
            n++;
            count = 0;
        }
    }
    return cop_str;
}

void prt(char *or_str)
{
    int count = 0;
    char *str = malloc(sizeof(char)*my_strlen(or_str));
    
    str = clean_space(or_str);
    for (int i = 0;str[i] != ' ';i++)
        count++;
    count++;
    for (;str[count] != '\0';count++)
        my_putchar(str[count]);
    my_putchar(' ');
    for	(int i = 0;str[i] != ' ';i++)
        my_putchar(str[i]);
}

int main(int argc, char **argv)
{
    if (argc > 2)
        return 84;
    if (argc == 1) {
        return 0;
    }
    prt(argv[1]);
    my_putchar('\n');
    return 0;
}
