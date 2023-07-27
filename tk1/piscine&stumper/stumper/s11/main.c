/*
** EPITECH PROJECT, 2022
** the
** File description:
** main
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c ,1);
}

int space(int n, int l, char *str)
{
    int i = 0;

    if (l == 1) {
        if (n == 1) {
            my_putchar('-');
            return 0;
        }
        else
            return 0;
    }
    else
        while (str[i] != '\0')
            i++;
    return i;
}

int end (char *str, int i, int n)
{
    int z = space(n, 2, str);
    int l = 0;

    while (str[l] != '\0') {
        if (str[z-1] >= 32 && str[z-1] <= 47)
            z--;
        else
            break;
    }
    return z;
}

int bf (char *str, int i)
{
    if (str[i-1] <= 48 && str[i-1] >= 57 || str[i+1] >= 48 && str[i+1] <= 57) {
        my_putchar('-');
        my_putchar(str[i]);
        return 0;
    }
    if (str[i-1] >= 48 && str[i-1] <= 57) {
        my_putchar(str[i]);
        return 0;
    }
    if (str[i+1] <= 48 && str[i+1] >= 57) {
        my_putchar(str[i]);
        return 0;
    }
    return 0;
}

void conv(char *str, int l)
{
    int n = 0;

    for (int i = l;str[i] != '\0';i++) {
        n++;
        if (str[i] >= 65 && str[i] <= 90) {
            my_putchar(str[i]+32);
            n = 0;
        }
        else if (i == end(str, i, n))
            break;
        else if (str[i] >= 32 && str[i] <= 47)
            space(n, 1, str);
        else if (str[i] <= 65 && str[i] >= 90) {
            my_putchar(str[i]);
            n = 0;
        }
        else if (str[i] >= 48 && str[i] <= 57)
            n = bf(str, i);
        else {
            my_putchar(str[i]);
            n = 0;
        }
    }
}

int main(int argc, char **argv)
{
    int l = 0;

    if (argc != 2)
        return 84;
    if (argv[1][0] == '\0') {
        my_putchar('\n');
        return 0;
    }
    while (argv[1][l] >= 32 && argv[1][l] <= 47)
        l++;
    conv(argv[1], l);
    write(1, '\n', 1);
    return 0;
}
