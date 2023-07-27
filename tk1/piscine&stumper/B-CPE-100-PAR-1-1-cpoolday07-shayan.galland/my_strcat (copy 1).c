/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** y
*/
#include <unistd.h>
#include <string.h>

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
char *my_strcat(char *dest , char const *src)
{
    int i;
    int dest_len = strlen(dest);
    
    for (i = 0; src[i] != '\0' ; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';
    
    return (dest);
}

int main()
{
    char dest[] = "hello";
    char src[] = "world";
    
    my_strcat(dest, src);
    my_putstr(dest);
    return(0);
}
