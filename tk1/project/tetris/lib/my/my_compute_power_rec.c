/*
** EPITECH PROJECT, 2021
** my_compute_power_rec
** File description:
** get rect
*/

int my_compute_power_rec(int nb, int p)
{
    long n;
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    if (n > 2147483647 || n < -2147483647)
        return 0;
    return (nb * my_compute_power_rec(nb, p - 1));
}
