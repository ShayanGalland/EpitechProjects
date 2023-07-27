/*
** EPITECH PROJECT, 2022
** fonction
** File description:
** fonction
*/

#include "necessary.h"
#include <string.h>

void char_count(char_t *mem_char, char *str, int place)
{
    if (mem_char->status == 0)
        basic(mem_char, str, place);
}

int analyse_char(int j, int i, char *str)
{
    int count = 0;

    if (str[i] == str[j])
        count++;
    return count;
}

void prt_recount(char_t *mem_char, char *str, int u)
{
    int smaller = mem_char->count[u];
    int small = 0;
    int valide = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (smaller <= mem_char->count[i]) {
            smaller = mem_char->count[i];
            small = i;
        }
    }
    mem_char->count[small] = -1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == str[small])
            valide++;
        if (valide == 1 && i == small)
            printf("%c:%d\n", str[small], smaller);
    }
}


int cond_cmp(int j, int i, char *str1, char *str2)
{
    int count = 0;
    if (str2[i] == str1[j])
        count++;
    return count;
}
