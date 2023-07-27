/*
** EPITECH PROJECT, 2021
** my_compute_power_rec
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    int a = nb;
    int b = 1;

    if (b <= p - 1) {
        a = a * my_compute_power_rec(nb, p - 1);
    }
    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    if (a > 2147483647 || a < -2147483647)
        return (0);
    return (a);
}
