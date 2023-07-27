/*
** EPITECH PROJECT, 2021
** rush-1-1
** File description:
** y
*/
#include "rush3"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    if (nb < 0){
        my_putchar('-');
        nb = -1 * nb;
    }
    if (nb/10) {
        my_put_nbr(nb/10);
        my_putchar(nb % 10 + '0');
    }
    if (nb < 10)
        my_putchar(nb + '0');
    return (0);
}

char rush1(char *res)
{
    int a = 0;
    int b = 0;
    int c = 0;
    
    char **tabl1 = malloc(sizeof(char) * strlen(res));

    tabl1[a][b] = res[c];

    
    while(tabl1[a][b] != '\0'){
        while(tabl1[a][b] != '\n'){
            b++;
        }
        a++
            }
    my_put_nbr(a);
    my_put_nbr(b);
}
