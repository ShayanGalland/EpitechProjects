/*
** EPITECH PROJECT, 2021
** pool
** File description:
** print_line
*/

#include <unistd.h>

void my_putchar(char c);

int print_first_line(int x)
{
    int count = 1;

    if (x > 1){
        while (count <= x) {
            my_putchar('*');
            count++;
        }
        my_putchar('\n');
        return (0);
    }
}

int print_edge_line(int y)
{
    int count = 1;    

    if (y > 1){
        while (count <= y) {
            my_putchar('*');
            my_putchar('\n');
            count++;
        }
    }
    return (0);
}