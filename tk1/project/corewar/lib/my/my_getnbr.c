/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** my_getnbr
*/

int is_neg(char *str)
{
    int i = 0;
    int mult = 1;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            mult *= -1;
        if (str[i] == '+')
            mult *= 1;
        i += 1;
    }
    if (mult == -1)
        return 1;
    return 0;
}

int my_getnbr(char *str)
{
    int i = 0;
    long res = 0;

    while (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            res = res + str[i] - '0';
            res = res * 10;
        }
        if (str[i] < '0' || str[i] > '9')
            break;
        i += 1;
    }
    res /= 10;
    if (is_neg(str) == 1)
        res *= -1;
    return res;
}
