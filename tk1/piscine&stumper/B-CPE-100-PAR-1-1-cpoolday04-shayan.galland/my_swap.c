/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** 
*/

int my_putchar(char c);

int my_swap(int *a, int *b)
{
    int ptr;
    int ptr2;
    
    ptr = *a;
    ptr2 = *b;

    *b = ptr;
    *a = ptr2;

    return(0);
}

