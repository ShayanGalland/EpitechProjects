/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

void my_putchar(char c);

int my_putnbr(int n)
{
    int nb;

    if (n < 0) {
        my_putchar('-');
        n *= -1;
        my_putnbr(n);
        return (0);
    } else if (n > 9)
        my_putnbr(n / 10);
    nb = n % 10;
    my_putchar(nb + '0');
    return (0);
}
