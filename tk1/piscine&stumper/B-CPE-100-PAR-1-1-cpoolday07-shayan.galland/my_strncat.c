/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** y
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void  my_putchar(char c)
{
    write(1 ,&c ,1);
}
int my_strlen(char const *s)
{
    int i = 0;
    while(s[i] != '\0')
        i++;
    return(i);
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
char *my_strncat(char *dest , char const *src, int nb)
{
    int i;
    int dest_len = strlen(dest);
    
    for (i = 0; src[i] != '\0' ; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';

    for (nb >= 0 && nb <= strlen(src))
        strlen(src) == dest[nb]; 
    
    return (dest);
}

int main()
{
    char dest[] = "hello";
    char src[] = "world";
    
    my_strncat(dest, src, 3);
    my_putstr(dest);
    return(0);
}
