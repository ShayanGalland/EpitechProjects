/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** my_strncpy
*/

void my_putchar(char c);

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i <= n - 1) {
        dest[i] = src[i];
        i += 1;
    }
    if (n > my_strlen(dest)) {
        dest[i] = '\0';
    }
    return (dest);
}
