/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** 
*/
#include <unistd.h>

void  my_putchar(char c)
{
    write(1 ,&c ,1)
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
char *my_strncpy(char *dest, char const *src, int n)
{
    int b = 0;
    
    while(b != n){
        dest[b] = src[b];
        b++;
    }
    return(dest);
}

int main(void)
{
    char source[] = "jour";
    char dest[3];

    my_strcpy(dest, source, n);
    my_putstr(dest);

    return(0);
}
