/*
** EPITECH PROJECT, 2021
** y
** File description:
** y
*/
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void my_putchar(char c)
{
    write (1, &c, 1);
}

int main(int argc, char **argv)
{
    int i = 0;
    int n = 0;
    int m = 0;
    int sort_len = argc;
    for (int l = 0;l != sort_len-m;) {
        while (i != sort_len-1) {
            if (argv[i][0] > argv[i+1][0])
                n = i+1;
            i++;
        }
        for (int w = 0;argv[n][w] != '\0';w++)
            my_putchar(argv[n][w]);
        my_putchar('\n');
        argv[n] = argv[sort_len-m];
        m++;
    }
    return 0;
}

