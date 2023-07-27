/*
** EPITECH PROJECT, 2023
** the .c file
** File description:
** project c file
*/

#include "string.h"

void assign_c(string_t *this , const char *s)
{
    free(this->str);
    this->str = strdup(s);
}

void assign_s(string_t *this , const string_t *str)
{
    assign_c(this, str->str);
}
