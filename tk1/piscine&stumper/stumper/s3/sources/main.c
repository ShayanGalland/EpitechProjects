/*
** EPITECH PROJECT, 2022
** yes
** File description:
** yess
*/

#include "functions.h"

void prt_fizzbuzz(int number_count, int number_end)
{
    for (int i = number_count;i <= number_end;i++) {
        if (i == 0)
            printf("%d\n", i);
        if (i % 3 == 0 && i % 5 != 0 && i != 0)
            printf("Fizz\n");
        if (i % 5 == 0 && i % 3 != 0 && i != 0)
            printf("Buzz\n");
        if (i % 3 == 0 && i % 5 == 0 && i != 0)
            printf("FizzBuzz\n");
        if (i % 3 != 0 && i % 5 != 0 && i != 0)
            printf("%d\n", i);
    }
}

int main(int argc, char **argv)
{
    int	number_count = 0;
    int number_end = 0;

    if (argc != 3)
        return 84;
    number_count = atoi(argv[1]);
    number_end = atoi(argv[2]);
    if (number_count > number_end) {
        printf("Error: the second parameter must be greater than the first one.\n");
        return 84;
    }
    prt_fizzbuzz(number_count, number_end);
}
