/*
** EPITECH PROJECT, 2023
** the .h file
** File description:
** typical .h file
*/

#ifndef _STRING_H
    #define _STRING_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stddef.h>

typedef struct string_t {
    char *str;
    void (*assign_s)(struct string_t *, struct string_t const *);
    void (*assign_c)(struct string_t *, const char *);
    void (*string_init)(struct string_t *, const char *);
    void (*string_destroy)(struct string_t *);
    char (*find_at_pos)(struct string_t const *, size_t);
    void (*append_c)(struct string_t *, struct string_t const *);
    void (*append_s)(struct string_t *, const char *);
    void (*clear)(struct string_t *);
    int (*length)(struct string_t const *);
} string_t;

int length(const string_t *this);
void clear(string_t *this);
void init_funct(string_t *this);
void string_init(string_t *this , const char *s);
void string_destroy(string_t *this);
void assign_c(string_t *this , const char *s);
void assign_s(string_t *this , const string_t *str);
void append_s(string_t *this , const string_t *ap);
void append_c(string_t *this , const char *ap);
char find_at_pos(const string_t *this , size_t pos);
int my_strlen(char const *str);

#endif