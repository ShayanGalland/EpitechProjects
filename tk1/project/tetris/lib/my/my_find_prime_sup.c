/*
** EPITECH PROJECT, 2021
** my_find_prime_sup
** File description:
** seeker prime go!!
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    for (int n = nb; n >= nb; n++)
        if (my_is_prime(n) == 1)
            return n;
    return 0;
}
