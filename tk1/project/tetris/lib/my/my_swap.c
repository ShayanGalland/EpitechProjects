/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** swapnap
*/

void my_swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
