/*
** EPITECH PROJECT, 2022
** s4
** File description:
** in c
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void prt_case(char wrd)
{
    if (wrd > 65 && wrd < 90)
        my_putchar(wrd+32);
    else if (wrd > 97 && wrd < 122)
        my_putchar(wrd-32);
    else
        my_putchar(wrd);
}

void prt(char wrd)
{
    if (wrd == 'o')
        my_putchar('0');
    else if (wrd == 'i' || wrd == 'I')
        my_putchar('1');
    else if (wrd == 'u' || wrd == 'U')
        my_putchar('2');
    else if (wrd == 'e' || wrd == 'E')
        my_putchar('3');
    else if (wrd == 'a' || wrd == 'A')
        my_putchar('4');
    else if (wrd == 'y' || wrd == 'Y')
        my_putchar('5');
    else
        prt_case(wrd);
}
int main(int argc, char **argv)
{
    if (argc != 2)
        return 84;
    for (int i = 0; argv[1][i] != '\0';i++)
        prt(argv[1][i]);
    my_putchar('\n');
    return 0;
}
