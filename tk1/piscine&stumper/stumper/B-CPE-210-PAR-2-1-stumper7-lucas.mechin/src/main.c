/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "necessary.h"
#include "string.h"

void basic(char_t *mem_char, char *str, int place)
{
    int valide = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == str[place])
            valide++;
        if (valide == 1 && i == place)
            printf("%c:%d\n", str[place], mem_char->count[place]);
    }
}

void double_str(char *str1, char *str2, char_t *mem_char)
{
    mem_char->status = 0;
    mem_char->count = malloc(sizeof(int)*(my_strlen(str1)+my_strlen(str2)));
    for (int i = 0; str1[i] != '\0'; i++) {
	for (int j = 0; str1[j] != '\0'; j++) {
            mem_char->count[i] += cond_cmp(j, i, str1, str2);
        }
        char_count(mem_char, str2, i);
    }
}

void count_char(char *str, char_t *mem_char)
{
    mem_char->count = malloc(sizeof(int)*my_strlen(str));
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; str[j] != '\0'; j++)
            mem_char->count[i] += analyse_char(j, i, str);
        char_count(mem_char, str, i);
    }
    if (mem_char->status == 2) {
        for (int i = 0; str[i] != '\0'; i++)
            prt_recount(mem_char, str, i);
    }
}

int main(int ac, char **av)
{
    char_t mem_char;

    if (ac == 1)
        return 84;
    if (ac > 4)
        return 84;
    flags(ac, av, &mem_char);
    return (0);
}
