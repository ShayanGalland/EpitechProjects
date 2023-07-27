/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** gotta get them all
*/

int my_getnbr(char *str)
{
    long x = 0;
    int is_number = 0;

    for (int n = 0; str[n] != '\0'; n++) {
        if (str[n] != '-' && str[n] != '+' && (str[n] < '0' || str[n] > '9'))
            break;
        if (str[n] >= '0' && str[n] <= '9') {
            is_number = 1;
            x *= 10;
            x += (str[n] - '0');
        }
        if ((str[n] < '0' || str[n] > '9') && is_number == 1)
            break;
        if (x > 2147483647)
            return 0;
    }
    for (int n = 0; str[n] == '-' || str[n] == '+'; n++)
        if (str[n] == '-')
            x *= -1;
    return x;
}
