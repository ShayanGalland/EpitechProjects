/*
** EPITECH PROJECT, 2021
** putnbr
** File description:
** y
*/

int my_putnbr(int nb)
{
    if (nb < 0){
        my_putchar('-');
        nb = -1 * nb;
    }
    if (nb/10) {
	my_putnbr(nb/10);
        my_putchar(nb % 10 + '0');
    }
    if (nb < 10)
        my_putchar(nb + '0');
    return (0);
}
