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

int main(int argc, char **argv)
{
    int fd;
    char buffer[1000001];
    int size;
    int n = 0;
    
    if (fd == -1)
    {
        my_putstr("Error with opn\n");
        return(1);
    }
    
    while (n < argc){
        fd = open(argv[n], O_RDWR);
        n++;
        my_putchar('\n');
        size = read(fd, buffer, 1000000);
        my_putstr(buffer);    
        close(fd);
    }
    return(0);
}
