/*
** EPITECH PROJECT, 2021
** my_is_prime
** File description:
** my_is_prime
*/

static int loop(int x, int i, int nb)
{
    int y = 1;

    while (y < nb) {
        y += 1;
        i = x * y;
        if (i == nb) {
            return (0);
        }
    }
    return (1);
}

int my_is_prime(int nb)
{
    int x = 1;
    int y = 1;
    int i = 2;

    if (nb < 2) {
        return (0);
    }
    while (x < nb) {
        x += 1;
        if (loop(x, i, nb) == 0)
            return (0);
    }
    y = 1;
    return (1);
}
