/*
** EPITECH PROJECT, 2022
** emaccss
** File description:
** sol8
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int fb(char **argv, int len)
{
    int one = 0;
    int two = 0;
    int tree = 0;
    int i = 1;
    int n = 1;

    while (i != len) {
        one = atoi(argv[i]);
        i++;
        two = atoi(argv[i]);
        if (i+1 == len)
            return n;
        i++;
        tree = atoi(argv[i]);
        if (one + two != tree)
            n = 2;
        i--;
    }
    return n;
}

int main(int argc, char **argv)
{
    int l = 0;

    if (argc == 1)
        return 84;
    if (argc == 2 || argc == 3) {
        write(1, "Not a Fibonacci sequence\n", 25);
        return 0;
    }
    l = fb(argv, argc);
    if (l == 2)
        write(1, "Not a Fibonacci sequence\n", 25);
    if (l == 1)
        write(1, "OK\n", 3);
    return 0;
}
