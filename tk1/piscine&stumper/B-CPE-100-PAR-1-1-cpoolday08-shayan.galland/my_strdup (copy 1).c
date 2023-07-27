/*
** EPITECH PROJECT, 2021
** concat_params
** File description:
** y
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(char const *s)
{
    int i = 0;
    while(s[i] != '\0')
        i++;
    return(i);
}
void  my_putchar(char c)
{
    write(1 ,&c ,1);
}

void my_putstr(char *src)
{
    int i;

    i = 0;
    while(src[i] != '\0'){
        my_putchar(src[i]);
        i = i + 1;
    }
}

char *my_strdup(char const *src)
{
    char *dest;
    int i;
    
    dest = malloc(sizeof(char) * my_strlen(src));
    i = 0;
    while(i < my_strlen(src)){
    dest[i] = src[i];
    i++;
    }
    return(dest);
}

int main(void)
{   
    my_putstr(my_strdup("je suis un mamifere"));
    
    return(0);
}
