/*
** EPITECH PROJECT, 2022
** init
** File description:
** init
*/

#include "include.h"

void out_of_map(game_t *game, int map)
{
    if (sfSprite_getPosition(game->map[map].map).x <
    (900-(game->map[map].res_x*game->map[map].div)-20))
        game->hero.ms_d = 0;
    else
        game->hero.ms_d = 1;
    if (sfSprite_getPosition(game->map[map].map).x > 830)
        game->hero.ms_q = 0;
    else
        game->hero.ms_q = 1;
    if (sfSprite_getPosition(game->map[map].map).y > 460)
        game->hero.ms_z = 0;
    else
        game->hero.ms_z = 1;
    if (sfSprite_getPosition(game->map[map].map).y <
    (500-(game->map[map].res_y*game->map[map].div)+30))
        game->hero.ms_s = 0;
    else
        game->hero.ms_s = 1;
}

void init_mv(game_t *game)
{
    game->hero.mv_d = 1;
    game->hero.mv_z = 1;
    game->hero.mv_q = 1;
    game->hero.mv_s = 1;
}

void stop_colision(game_t *game, sfSprite *map, sfImage *col)
{
    sfVector2f map_pos = start_point(sfSprite_getPosition
    (map).x, sfSprite_getPosition(map).y);
    sfVector2f h_pos = start_point(sfSprite_getPosition
    (game->hero.hero).x, sfSprite_getPosition(game->hero.hero).y);
    sfVector2f pos = start_point(h_pos.x - map_pos.x + 38,
    h_pos.y - map_pos.y + 70);

    check_up(game, pos, col);
    check_down(game, pos, col);
    check_left(game, pos, col);
    check_right(game, pos, col);
}