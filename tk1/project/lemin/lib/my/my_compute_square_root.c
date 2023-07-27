/*
** EPITECH PROJECT, 2021
** my_compute_square_root
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    int i = 0;

    while (i <= nb) {
        if (nb == i * i) {
            return (i);
        }
        i += 1;
    }
    return (0);
}
