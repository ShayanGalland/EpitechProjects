/*
** EPITECH PROJECT, 2021
** pool
** File description:
** print_edge
*/

#include <unistd.h>

void my_putchar(char c);

int print_edge(int x)
{
    int count = 1;

        while(count <= x) {
            if(count == 1 || count == x){
                my_putchar('B');
            }
            my_putchar(' ');
        count++;
    }
    return (0);
}

int print_edge2(int x, int y)
{
    int count = 1;
    
    while (count <= y){
        if (count >= 2)
            print_edge(x);
        my_putchar('\n');
        count++;
    }
    return(0);
}