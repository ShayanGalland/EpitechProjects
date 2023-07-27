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
char *infin_add(char *nbr1, char *nbr2)
{
    char *res;
    
    res = malloc(sizeof(char) * (my_strlen(nbr1) + (my_strlen(nbr2))));
       
    for(int n = 0; nbr1[n] != '\0' && nbr2[n] != '\0';n++){
        res[n] = nbr1[n] + nbr2[n] - '0';
        
    }
    return(res);
}

int main(int ac, char **av)
{
	ac = ac;
    printf("'%s'\n",infin_add(av[1] ,av[2]));
}
