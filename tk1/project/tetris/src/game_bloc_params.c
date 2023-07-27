/*
** EPITECH PROJECT, 2021
** tools
** File description:
** help
*/

#include "my.h"

int collision(game_t *game)
{
    for (int j = 39; j > 1; j--) {
        for (int i = 0; i < 14; i++) {
            if (game->map2.tab[j][i] == '*' && game->map.tab[j+1][i] == '*')
                return 1;
            if (game->map2.tab[j][i] == '*' && game->map.tab[j+1][i] == '-')
                return 1;
        }
    }
    return 0;
}

int lose(game_t *game)
{
    for (int i = 0; i < 14; i++) {
        if (game->map.tab[0][i] == '*')
            return 1;
    }
    return 0;
}

int bord_col(game_t *game)
{
    for (int j = 39; j > 1; j--) {
        for (int i = 0; i < 14; i++) {
            if (game->map2.tab[j][i] == '*' && game->map.tab[j][i+1] == '|')
                return 1;
            if (game->map2.tab[j][i] == '*' && game->map.tab[j][i-1] == '|')
                return 1;
        }
    }
    return 0;
}

void sup_line(game_t *game, int n)
{
    game->score += 100;
    for (int i = 0; i < 14; i++)
        game->map.tab[n][i] = ' ';
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < 14; i++) {
            if (game->map.tab[j][i] = '*') {
                game->map.tab[j+1][i] = '*';
                game->map.tab[j][i] = ' ';
            }
        }
    }
}

void chk_lines(game_t *game)
{
    int count = 0;
    int ret_j = 0;

    for (int j = 39; j > 1; j--) {
        for (int i = 0; i < 14; i++) {
            if (game->map.tab[j][i] == '*')
                count++;
        if (count == 14)
            ret_j = j;
        count = 0;
        }
    }
    if (ret_j != 0)
        sup_line(game, ret_j);
}