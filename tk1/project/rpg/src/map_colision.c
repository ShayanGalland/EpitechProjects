/*
** EPITECH PROJECT, 2022
** game loop
** File description:
** game loop
*/

#include "include.h"

void check_up(game_t *game, sfVector2f pos, sfImage *col)
{
    sfVector2f up = start_point(0, 0);

    for (int n = pos.x - 28; n <= pos.x + 28; n++) {
        up = start_point(n, pos.y);
        if (check_collide(col, up, game) == 1)
            game->hero.mv_z = 0;
    }
}

void check_down(game_t *game, sfVector2f pos, sfImage *col)
{
    sfVector2f down = start_point(pos.x, pos.y + 30);

    for (int n = pos.x - 28; n <= pos.x + 28; n++) {
        down = start_point(n, pos.y + 30);
        if (check_collide(col, down, game) == 1)
            game->hero.mv_s = 0;
    }
}

void check_left(game_t *game, sfVector2f pos, sfImage *col)
{
    sfVector2f left = start_point(pos.x - 30, pos.y);

    for (int n = pos.y + 2; n <= pos.y + 28; n++) {
        left = start_point(pos.x - 30, n);
        if (check_collide(col, left, game) == 1)
            game->hero.mv_q = 0;
    }
}

void check_right(game_t *game, sfVector2f pos, sfImage *col)
{
    sfVector2f right = start_point(pos.x + 30, pos.y);

    for (int n = pos.y + 2; n <= pos.y + 28; n++) {
        right = start_point(pos.x + 30, n);
        if (check_collide(col, right, game) == 1)
            game->hero.mv_d = 0;
    }
}

int check_collide(sfImage* map, sfVector2f point, game_t *game)
{
    int i = game->map_select-1;

    point.x /= game->map[i].div;
    point.y /= game->map[i].div;
    if (point.x < 0)
        point.x = 0;
    if (point.y < 0)
        point.y = 0;
    if (point.x > game->map[i].res_x)
        point.x = game->map[i].res_x;
    if (point.y > game->map[i].res_y)
        point.y = game->map[i].res_y;
    if (sfImage_getPixel(map, point.x, point.y).a != 0)
        return 1;
    else
        return 0;
}