/*
** EPITECH PROJECT, 2021
** y
** File description:
** y
*/
int recursive_power(int nb, int p)
{
    int result = 0;

    p = p - 1;
    if (p != 0) {
        result = nb * nb;
        recursive_power(nb, p);
    }
    return result;
}
