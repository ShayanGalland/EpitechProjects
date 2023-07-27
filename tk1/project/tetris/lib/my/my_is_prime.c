/*
** EPITECH PROJECT, 2021
** my_is_prime
** File description:
** or IS IT??
*/

int my_is_prime(int nb)
{
    if (nb <= 1)
        return 0;
    for (int n = 2; n < nb; n++)
        if (nb % n == 0)
            return 0;
    return 1;
}
