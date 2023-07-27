/*
** EPITECH PROJECT, 2021
** my_compute_square_root
** File description:
** aka minecraft tree
*/

int my_compute_square_root(int nb)
{
    for (int n = 0; n <= nb; n++)
        if ((n * n) == nb)
            return (n);
    return (0);
}
