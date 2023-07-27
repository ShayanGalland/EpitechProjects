/*
** EPITECH PROJECT, 2022
** get index
** File description:
** get index
*/

#include "../../include/my.h"
#include <stddef.h>
#include "asm.h"

static int get_nbr_adress(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ',')
            count++;
    count++;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '%')
            count++;
    return count;
}

static int get_last(char **tab, char *label)
{
    int count = 0;

    count++;
    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i], label) == 0) {
            count++;
            break;
        }
    }
    return count;
}

int get_label_adress(char **instruct, char *label, int line)
{
    int count = 0;
    char **tab = NULL;

    for (int i = line + 1; instruct[i] != NULL; i++) {
        tab = my_str_to_word_array(tab, instruct[i], ' ');
        if (my_strncmp(label, tab[0], my_strlen(label)) == 0) {
            count += get_last(tab, label);
            break;
        }
        if (is_except(tab[0]) == 1) {
            count++;
            count += get_nbr_adress(tab[1]);
        } else {
            count += 2;
            count += get_nbr_adress(tab[1]);
        }
    }
    return count;
}