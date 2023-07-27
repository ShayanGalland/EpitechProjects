/*
** EPITECH PROJECT, 2022
** init rooms
** File description:
** init rooms
*/

#include "struct.h"
#include "my.h"
#include "lemin.h"
#include <stdlib.h>

void skip_comment(char ***tab)
{
    while (*tab[0][0] == '#')
        tab[0]++;
}

void fill_start(ants_t *ants, char ***tab)
{
    ants->nbr_ants = my_getnbr(*tab[0]);
    my_printf("#number_of_ants\n%i\n#rooms\n", ants->nbr_ants);
    tab[0]++;
    ants->nbr_rooms = count_rooms(*tab);
    ants->rooms = malloc(sizeof(rooms_t) * ants->nbr_rooms);
}

static void check_start(ants_t *ants, char ***tab)
{
    if (my_strcmp(*tab[0], "##start") == 0) {
        my_printf("##start\n");
        tab[0]++;
        fill_data(&ants->start, *tab[0]);
        my_printf("%i %i %i\n", ants->start.nbr, ants->start.x,
        ants->start.y);
        tab[0]++;
    }
}

static void check_end(ants_t *ants, char ***tab)
{
    if (my_strcmp(*tab[0], "##end") == 0) {
        my_printf("##end\n");
        tab[0]++;
        fill_data(&ants->end, *tab[0]);
        my_printf("%i %i %i\n", ants->end.nbr, ants->end.x, ants->end.y);
        tab[0]++;
    }
}

void init_rooms(ants_t *ants, char ***tab)
{
    for (int i = 0; check_is_tunnel(*tab[0]) == 0; i++) {
        check_start(ants, tab);
        check_end(ants, tab);
        if (*tab[0][0] == '#' && *tab[0][1] != '#')
            skip_comment(tab);
        if (check_is_tunnel(*tab[0]) == 1)
            break;
        fill_data(&ants->rooms[i], *tab[0]);
        my_printf("%i %i %i\n", ants->rooms[i].nbr, ants->rooms[i].x,
        ants->rooms[i].y);
        tab[0]++;
    }
}
