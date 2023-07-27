/*
** EPITECH PROJECT, 2023
** the .c file
** File description:
** project c file
*/

#include "string.h"

void append_c(string_t *this, const char *ap)
{
    int len = strlen(this->str) + strlen(ap);
    char *temp = NULL;

    temp = malloc(sizeof(char) * (len + 1));
    temp = strcpy(temp, this->str);
    free(this->str);
    this->str = strcat(temp, ap);
}

void append_s(string_t *this, const string_t *ap)
{
    append_c(this, ap->str);
}
