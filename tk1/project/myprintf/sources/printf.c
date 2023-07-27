/*
** EPITECH PROJECT, 2021
** printf
** File description:
** y
*/
#include "my.h"

int my_printf(const char *format, ...)
{
    va_list ap;
    va_start (ap, format);
    while (*format != '\0') {
        if (*format == '%') {
            format++;  
        printfbis(format, &ap);
        }
        else
            my_putchar(*format);
        format++;
    }
    va_end(ap);
    return 0;
}
