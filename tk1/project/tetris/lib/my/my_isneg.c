/*
** EPITECH PROJECT, 2021
** my_isneg
** File description:
** or is it??
*/

int my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    return (0);
}
