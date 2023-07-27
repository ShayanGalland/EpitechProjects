/*
** EPITECH PROJECT, 2021
** tools
** File description:
** map
*/

#include "my.h"

void fil_tab(game_t *game)
{
    game->map.tab = malloc(sizeof(char*)*40);
    for (int i = 0; i < 40; i++)
        game->map.tab[i] = malloc(sizeof(char)*16);
    for (int j = 0; j < 40; j++) {
        for (int i = 0; i < 14; i++)
            fil_char(j, i, game);
    }
    game->map.dim.x = 14;
    game->map.dim.y = 39;
}

void fil_char(int j, int i, game_t *game)
{
    if (j == 0 && i == 0)
        game->map.tab[j][i] = '+';
    else if (j == 0 && i == 14)
        game->map.tab[j][i] = '+';
    else if (j == 39 && i == 14)
        game->map.tab[j][i] = '+';
    else if (j == 39 && i == 0)
        game->map.tab[j][i] = '+';
    else if (j == 0 && i != 0 && i != 14)
        game->map.tab[j][i] = '-';
    else if (j == 39 && i != 0 && i != 14)
        game->map.tab[j][i] = '-';
    else if (i == 0 && j != 0 && j != 39)
        game->map.tab[j][i] = '|';
    else if (i == 14 && j != 0 && j != 39)
        game->map.tab[j][i] = '|';
    else
        game->map.tab[j][i] = ' ';
}

void fil_char2(int j, int i, game_t *game)
{
    if (j == 0 && i == 0)
        game->map2.tab[j][i] = '+';
    else if (j == 0 && i == 14)
        game->map2.tab[j][i] = '+';
    else if (j == 39 && i == 14)
        game->map2.tab[j][i] = '+';
    else if (j == 39 && i == 0)
        game->map2.tab[j][i] = '+';
    else if (j == 0 && i != 0 && i != 14)
        game->map2.tab[j][i] = '-';
    else if (j == 39 && i != 0 && i != 14)
        game->map2.tab[j][i] = '-';
    else if (i == 0 && j != 0 && j != 39)
        game->map2.tab[j][i] = '|';
    else if (i == 14 && j != 0 && j != 39)
        game->map2.tab[j][i] = '|';
    else
        game->map2.tab[j][i] = ' ';
}

void fil_tab2(game_t *game)
{
    game->map2.tab = malloc(sizeof(char*)*40);
    for (int i = 0; i < 40; i++)
        game->map2.tab[i] = malloc(sizeof(char)*16);
    for (int j = 0; j < 40; j++) {
        for (int i = 0; i < 15; i++)
            fil_char(j, i, game);
    }
    game->map2.dim.x = 14;
    game->map2.dim.y = 39;
}

void merge_map(game_t *game)
{
    for (int j = 39; j > 0; j--) {
        for (int i = 0; i < 15; i++) {
            if (game->map2.tab[j][i] == '*')
                game->map.tab[j][i] = '*';
        }
    }
}