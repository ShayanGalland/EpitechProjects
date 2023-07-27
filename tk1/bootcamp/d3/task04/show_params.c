/*
** EPITECH PROJECT, 2021
** y
** File description:
** y
*/
#include <unistd.h>

void my_putchar(char c)
{
    write (1, &c, 1);
}

void show_params(char *write)
{
    for (int i = 0;write[i] != '\0';i++) {
        if (write[i] == '"')
            i++;
        if (write[i] == '\0')
            break;
        my_putchar(write[i]);
    }
}
int main(int argc, char **argv)
{
    for (int e = 0;e != argc;e++) {
        show_params(argv[e]);
        my_putchar('\n');
    }
    return 0;
}
    
