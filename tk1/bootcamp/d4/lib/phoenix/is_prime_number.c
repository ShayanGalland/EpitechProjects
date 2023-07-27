/*
** EPITECH PROJECT, 2021
** y
** File description:
** y
*/
int is_prime_number(int nb)
{
    int count = 0;
    if (nb == 0 || nb == 1)
        return 0;
    for (int i = 1;i != nb;i++) {
        if (nb % i == 0)
            count++;
    }
    if (count == 1 || count == 0)
	return 0;
    else
        return 1;
}
