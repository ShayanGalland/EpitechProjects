/*
** EPITECH PROJECT, 2021
** tools
** File description:
** main
*/

#include <stdarg.h>

void my_putchar(char c);

void my_putstr(char *str);

void my_putnbr(int nb);

void my_put_octal(int nb);

void my_put_maj_s_tr(char *str);

static void display1(char *str, int n, va_list args)
{
    if (str[n] == 'i' || str[n] == 'd')
        my_putnbr(va_arg(args, int));
    if (str[n] == 'c')
        my_putchar(va_arg(args, int));
    if (str[n] == 's')
        my_putstr(va_arg(args, char *));
}

static void display2(char *str, int n, va_list args)
{
    if (str[n] == 'o')
        my_put_octal(va_arg(args, int));
    if (str[n] == 'S')
        my_put_maj_s_tr(va_arg(args, char *));
    if (str[n] == '%')
        my_putchar('%');
}

void my_printf(char *str, ...)
{
    va_list args;

    va_start(args, str);
    for (int n = 0; str[n]; n++) {
        if (str[n] == '%') {
            n++;
            display1(str, n, args);
            display2(str, n, args);
        } else
            my_putchar(str[n]);
    }
    va_end(args);
}
