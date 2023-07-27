/*
** EPITECH PROJECT, 2021
** pool
** File description:
** rush3
*/

#include <stdio.h>
#include <unistd.h>

int print_first_line(int x);
int print_edge_line(int y);
int print_edge(int x);
int print_edge2(int x, int y);

void my_putchar(char c)
{
    write(1, &c,1);
}

int print_square2(int x, int y)
{
    int count = 1;

    while(count <= x) {
        if(count == 1)
            my_putchar('C');
        if (count == x)
            my_putchar('C');
        else
            my_putchar('B');
        count++;
    }
    return (0);
}

int print_square(int x, int y)
{
    int count = 1;

    while(count <= x) {
        if(count == 1)
            my_putchar('A');
        if (count == x)
            my_putchar('A');
        else
            my_putchar('B');
        count++;
    }
    return (0);
}

void rush(int x, int y)
{
    int j = x - 1;
    int i = y - 1;

    if (x > 0 && y > 0) {
        if (x == 1 && y == 1)
            write(1, "B\n", 3);
        if (y == 1) {
            print_first_line(x);
        }
        if (x == 1) {
            print_edge_line(y);
        }
        if (x > 1 && y > 1) {
            print_square(j, y);
            print_edge2(j, i);
            print_square2(j, y);
            my_putchar('\n');
        }
    } else
        write(2, "Invalid size\n", 13);
}

int main(void)
{
    rush(1,1);
    return(0);
}