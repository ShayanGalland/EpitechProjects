/*
** EPITECH PROJECT, 2021
** pool
** File description:
** rush1
*/

#include <unistd.h>
#include <stdio.h>

void my_putchar(char c);

int print_first_line(int x)
{
    int count = 1;

    while (count <= x) {
        if (count == 1 || count == x)
            my_putchar('o');
        else
            my_putchar('-');
        count = count + 1;        
    }
    my_putchar('\n');
    return (0);        
}


int print_square(int x, int y)
{
    int count = 1;
    
    if (y >= 2) {
            while (count <= x) {
            if (count == 1 || count == x) {
                my_putchar('|');
            }
            else {
                my_putchar(' ');
            }
            count++;
        }
        my_putchar('\n');
        return (0);
    } 
}


void rush(int x, int y)
{
    int i = 1;
    
    if (x > 0 && y > 0) {
        while (i <= y){
            if (i == 1 || i == y) {
                print_first_line(x);
            } else {
                print_square(x, y);
            }
            i++;
        }
    } else 
            write(2, "Invalid size\n", 13);
}