/*
** EPITECH PROJECT, 2023
** project
** File description:
** in c
*/

#include "functions.h"
#include "print.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    for (int i = strlen(str) - 1; i > 0 ; i--)
        printf("%c", str[i]);
    printf("\n");
}

void print_upper(const char *str)
{
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] <= 122 && str[i] >= 97)
            printf("%c", str[i] - 32);
        else
            printf("%c", str[i]);
    }
    printf("\n");
}

void print_42(const char *str)
{
    str = str;
    printf("42\n");
}

void do_action(action_t action , const char *str)
{
    void (*ptr)(const char *str);
    void (*ptr2)(const char *str);
    void (*ptr3)(const char *str);
    void (*ptr4)(const char *str);

    ptr = &print_normal;
    ptr2 = &print_reverse;
    ptr3 = &print_upper;
    ptr4 = &print_42;
    if (action == PRINT_NORMAL)
        (*ptr)(str);
    if (action == PRINT_REVERSE)
        (*ptr2)(str);
    if (action == PRINT_UPPER)
        (*ptr3)(str);
    if (action == PRINT_42)
        (*ptr4)(str);
}
