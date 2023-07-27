/*
** EPITECH PROJECT, 2022
** error handling
** File description:
** error handling
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"
#include <unistd.h>

int check_commands(char **tab)
{
    int count_start = 0;
    int count_end = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i], "##start") == 0)
            count_start++;
        if (my_strcmp(tab[i], "##end") == 0)
            count_end++;
    }
    if (count_end + count_start != 2)
        return -1;
    return 0;
}

int check_nbr_tunnel(char **tab)
{
    int count = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        if (tab[i][1] == '-')
            count++;
    }
    return count;
}

int check_rooms(char **tab)
{
    int ret = 0;

    skip_comment(&tab);
    for (int i = 0; tab[0][i] != '\0'; i++) {
        if (tab[0][i] == '#')
            break;
        if (tab[0][i] < '0' || tab[0][i] > '9') {
            write(2, "Number of ants is only with numbers\n", 37);
            return -1;
        }
    }
    for (int i = 0; tab[i] != NULL; i++) {
        if (check_is_room(tab[i]) == 1)
            ret = check_in_rooms(tab[i]);
        if (ret == -1)
            return -1;
    }
    return 0;
}

int check_in_file(char *buf)
{
    char **tab = NULL;

    tab = my_str_to_word_array(tab, buf, '\n');
    if (check_commands(tab) == -1) {
        write(2, "File must have 1 start and 1 end\n", 34);
        return -1;
    }
    if (check_nbr_tunnel(tab) == 0) {
        write(2, "File must have at least one tunnel\n", 36);
        return -1;
    }
    if (check_rooms(tab) == -1)
        return -1;
    if (check_error_tunnel(tab) == -1)
        return -1;
    return 0;
}

int error(char *buf)
{
    if (check_in_file(buf) == -1) {
        close(0);
        return -1;
    }
    close(0);
    return 0;
}
