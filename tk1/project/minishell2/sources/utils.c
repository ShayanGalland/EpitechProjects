/*
** EPITECH PROJECT, 2022
** project
** File description:
** in c
*/

#include "../include/functions.h"

void my_memcpy(const char *src, char *dst, size_t size)
{
    for (size_t i = 0; i < size;i++)
        dst[i] = src[i];
}

void my_memset(char *dst, char v, size_t size)
{
    for (size_t i = 0; i < size;i++)
        dst[i] = v;
}

void *my_realloc(void *ptr, size_t size_ptr, size_t new_size)
{
    void *ptr_int = NULL;

    ptr_int = malloc(new_size);
    if (ptr) {
        my_memset(ptr_int, 0, new_size);
        my_memcpy(ptr, ptr_int, size_ptr);
        free(ptr);
    }
    return ptr_int;
}

int my_getnbr(char const *str)
{
    int dest = 0;
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if ((str[i] >= '0' && str[i] <= '9')
        || (str[i] != '+' && str[i] != '-'))
            break;
        if (str[i] == '-')
            j++;
        i++;
    }
    while (str[i] != '\0') {
        while (str[i] >= '0' && str[i] <= '9')  {
            dest = dest * 10 + (str[i] - '0');
            i++;
        }
        return (j % 2 == 1) ? dest * (-1) : dest;
    }
    return 0;
}

int is_same_str(const char *token, const char *str, int i, int token_len)
{
    for (int j = 0; j < token_len;j++) {
        if (str[i+j] != token[j]) {
            return 0;
            break;
        }
    }
    return 1;
}
