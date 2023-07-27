/*
** EPITECH PROJECT, 2021
** concat_params
** File description:
** y
*/
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void my_putchar(char c)
{
    write(1 ,&c ,1);
}
int my_strlen(char const *s)
{
    int i = 0;
    while(s[i] != '\0'){
        i++;
    }
    return(i);
}

void my_putstr(char *src)
{
    int i;

    i = 0;
    while(src[i] != '\0'){
        my_putchar(src[i]);
        i++;
    }
}
char *concat_params(int argc , char **argv)
{
    char *dest;
    int i = 0;
    int dest_len = strlen(dest);

    dest = malloc(sizeof(char) * my_strlen(argv));
    
    while(i > argc){
        dest[i] = argc;
        for (i = 0; argc[i][i] != '\0' ; i++)
            dest[dest_len + i] = argv[i];
        dest[dest_len + i] = '\0';
    }   
    return (dest);
}
int main(int ac , char **av)
{
    my_putstr(concat_params(ac, av));
    
    return(0);
}
