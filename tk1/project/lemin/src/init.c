/*
** EPITECH PROJECT, 2022
** init
** File description:
** init
*/

#include "struct.h"
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "lemin.h"

int read_from_redi(char **buf)
{
    *buf = malloc(sizeof(char) * 20000);
    if (read(0, *buf, 20000) == -1)
        return -1;
    return 0;
}

void fill_data(rooms_t *room, char *str)
{
    room->nbr = my_getnbr(str);
    while (str[0] >= '0' && str[0] <= '9')
        str++;
    str++;
    room->x = my_getnbr(str);
    while (str[0] >= '0' && str[0] <= '9')
        str++;
    str++;
    room->y = my_getnbr(str);
}

static void get_tunnel(int *tunnel, int *second, char *str)
{
    *tunnel = my_getnbr(str);
    while (str[0] >= '0' && str[0] <= '9')
        str++;
    str++;
    *second = my_getnbr(str);
    my_printf("%i-%i\n", *tunnel, *second);
}

int init_struct(ants_t *ants)
{
    char *buf = NULL;
    char **tab = NULL;

    if (read_from_redi(&buf) == -1)
        return -1;
    if (error(buf) == -1)
        return -1;
    tab = my_str_to_word_array(tab, buf, '\n');
    fill_start(ants, &tab);
    init_rooms(ants, &tab);
    my_printf("#tunnels\n");
    ants->nbr_tunnel = count_tunnel(tab);
    ants->tunnel = malloc(sizeof(int *) * ants->nbr_tunnel);
    for (int i = 0; i < ants->nbr_tunnel + 1; i++)
        ants->tunnel[i] = malloc(sizeof(int) * 2);
    for (int i = 0; i < ants->nbr_tunnel; i++) {
        if (tab[i][0] == '#' && tab[i][1] == '#')
            skip_comment(&tab);
        get_tunnel(&ants->tunnel[i][0], &ants->tunnel[i][1], tab[i]);
    }
    my_printf("#moves\n");
    return 0;
}
