/*
** EPITECH PROJECT, 2021
** printf
** File description:
** printf
*/

#include <stdarg.h>
#include "my.h"
#include <stdio.h>

static int display_format(char *format, int i)
{
    i += 1;
    if (format[i] == '%' && format[i + 1] == '%')
        i -= 1;
    my_putchar(format[i]);
    return i;
}

static void run_format(char *format, va_list arg, int i)
{
    if (format[i + 1] == 'i' || format[i + 1] == 'd'
        || format[i + 1] == 'u')
        my_put_nbr(va_arg(arg, int));
    if (format[i + 1] == 's') {
        my_putstr(va_arg(arg, char*));
    }
    if (format[i + 1] == 'c')
        my_putchar(va_arg(arg, int));
    if (format[i + 1] == 'o')
        my_put_octal(va_arg(arg, int));
    if (format[i + 1] == 'b')
        my_put_bin(va_arg(arg, int));
    if (format[i + 1] == '%')
        my_putchar('%');
}

void my_printf(char *format, ...)
{
    va_list arg;

    va_start(arg, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            run_format(format, arg, i);
            i++;
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(arg);
}
