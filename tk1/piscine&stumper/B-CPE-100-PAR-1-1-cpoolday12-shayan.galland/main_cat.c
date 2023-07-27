/*
** EPITECH PROJECT, 2021
** main_cat
** File description:
** y
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void my_putchar(char c)
{
    write(1 ,&c ,1);
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
int main(int argc, char **argv)
{
    int fd;
    char buffer[1000001];
    int size;
    
    fd = open("lib/my/my_strcpy.c", O_RDONLY);
    if (fd == -1)
    {
        my_putstr("Error with opn\n");
        return(1);
    }
    size = read(fd, buffer, 1000000);
    my_putstr(buffer);
    close(fd);
    return(0);
}
