/*
** EPITECH PROJECT, 2023
** the .c file
** File description:
** project c file
*/

#include "string.h"

void init_funct(string_t *this)
{
    this->assign_c = &assign_c;
    this->assign_s = &assign_s;
    this->string_destroy = &string_destroy;
    this->string_init = &string_init;
    this->append_c = &append_c;
    this->append_s = &append_s;
    this->find_at_pos = &find_at_pos;
    this->clear = &clear;
}

void string_init(string_t *this , const char *s)
{
    this->str = strdup(s);
    init_funct(this);
}

void string_destroy(string_t *this)
{
    free(this->str);
}
