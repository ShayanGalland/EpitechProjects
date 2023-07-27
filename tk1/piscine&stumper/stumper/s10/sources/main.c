/*
** EPITECH PROJECT, 2022
** yes
** File description:
** yess
*/

#include <stdio.h>
#include <stdlib.h>

void prt_fazzbizz(int number_count, int number_end)
{
    for (int i = number_count; i <= number_end; i++) {
        if (i == 0)
            printf("%d\n", i);
        if (i % 10 == 0 && i % 9 != 0 && i != 0)
            printf("Fazz\n");
        if (i % 9 == 0 && i % 10 != 0 && i != 0)
            printf("Bizz\n");
        if (i % 9 == 0 && i % 10 == 0 && i != 0)
            printf("FazzBizz\n");
        if (i % 9 != 0 && i % 10 != 0 && i != 0)
            printf("%d\n", i);
    }
}

int main(int argc, char **argv)
{
    int number_count = 0;
    int number_end = 0;

    if (argc != 3)
        return 84;
    number_count = atoi(argv[1]);
    number_end = atoi(argv[2]);
    if (number_count > number_end) {
        printf("Error: the second parameter must ");
        printf("be greater than the first one.\n");
        return 84;
    }
    prt_fazzbizz(number_count, number_end);
    return 0;
}
