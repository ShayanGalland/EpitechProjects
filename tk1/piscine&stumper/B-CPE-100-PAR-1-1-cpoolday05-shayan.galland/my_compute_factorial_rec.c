/*
** EPITECH PROJECT, 2021
** my_compute_factorial_rec
** File description:
** 
*/
#include <stdio.h>

int my_compute_factorial_rec(int nb)
{
    int result;

    if(nb == 0)
        return(0);
    if(nb == 1)
        return(0);

    else result = nb *  my_compute_factorial_rec(nb - 1);

    return(result);
}

int main(void)
{
    my_compute_factorial_it(5);

    printf("%d\n" ,my_compute_factorial_it(5));

    return(0);
}


