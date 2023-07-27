/*
** EPITECH PROJECT, 2021
** infin_add
** File description:
** y
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char const *s)
{
    int i = 0;
    while(s[i] != '\0')
        i++;
    return(i);
}

char *my_strcpy(char *dest, char const *src)
{
    int b = 0;
    
    while(src[b] != '\0'){
        dest[b] = src[b];
        b++;
    }
    return(dest);
}

int my_putnbr(int nb)
{
    if (nb < 0){
        my_putchar('-');
        nb = -1 * nb;
    }
    if (nb/10) {
        my_putnbr(nb/10);
        my_putchar(nb % 10 + '0');
    }
    if (nb < 10)
        my_putchar(nb + '0');
    return (0);
}

char *my_revstr(char *str)
{
    int b = 0;
    
    while(str[b] != 0){
        str[b] = b--;
    }
    return(str);
}

char *infin_add(char *nbr1, char *nbr2)
{
    char *res;
    char *ret;
    int n = 0;
    
    res = malloc(sizeof(char) * (my_strlen(nbr1) + (my_strlen(nbr2))));
    
    my_revstr(nbr1);
    my_revstr(nbr2);
    
    while(res[n] <= '9' && nbr1[n] != '\0' && nbr2[n] != '\0'){
        res[n] = nbr1[n] + nbr2[n] - '0';
        n++;
        if(res[n] > '9' && nbr1[n] != '\0' && nbr2[n] != '\0'){
            res[n] = '9';
            n++;
            res[n] = nbr1[n] + nbr2[n] - '9';
        }
    }
    my_revstr(res);
    return (res);
}

int main(int ac, char **av)
{
    ac = ac;
    printf("'%s'\n",infin_add(av[1] ,av[2]));
}
