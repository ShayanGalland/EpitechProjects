/*
** EPITECH PROJECT, 2021
** y
** File description:
** y
*/
#ifndef _MY_H
#define _MY_H
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

void print_b(unsigned int number);
void print_d(int m);
int my_printf(const char *format, ...);
void print_o(unsigned int nb);
void print_s(char* f);
void print_S(const char *str);
void print_x(unsigned int number);
void print_xx(unsigned int number);
void printfbis(char const *format, va_list *ap);
void my_putchar(char c);
void my_putstr(char const *str);
int my_putnbr(int nb);
unsigned int my_compute_power_it(int nb, int p);
void print_x_bis(long x, unsigned int number, char *hexa, int n);
void print_xx_bis(long x, unsigned int number, char *hexa, int n);
#endif
