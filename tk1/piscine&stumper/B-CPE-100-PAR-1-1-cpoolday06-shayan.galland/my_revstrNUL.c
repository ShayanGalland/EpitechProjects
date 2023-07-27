/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** 
*/

#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
}    

char *my_strcpy(char *dest, char const *src)
{
    int b = 0;
    
    while(src[b] != '\0'){
        my_putchar(src[b]);
    b ++;
    }
}

int main(void)
{
    char source[] = "ruoj";
    char dest[4];
    
    my_strcpy(dest, source);
    my_putstr(dest);
    
    return(0);
}
