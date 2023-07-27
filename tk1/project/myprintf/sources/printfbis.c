/*
** EPITECH PROJECT, 2021
** emacs
** File description:
** emacs
*/
#include "my.h"

void printfbis(char const *format, va_list *ap)
{
    if (*format == 's')
        print_s(va_arg(*ap, char*));
    if (*format == 'd')
        print_d(va_arg(*ap, int));
    if (*format == 'i')
        print_d(va_arg(*ap, int));
    if (*format == 'c')
        my_putchar(va_arg(*ap, int));
    if (*format == '%')
        my_putchar('%');
    if (*format == 'b')
        print_b(va_arg(*ap, unsigned int));
    if (*format == 'x')
        print_x(va_arg(*ap, unsigned int));
    if (*format == 'X')
        print_xx(va_arg(*ap, unsigned int));
    if (*format == 'o')
        print_o(va_arg(*ap, unsigned int));
    if (*format == 'S')
        print_S(va_arg(*ap, const char*));
}
