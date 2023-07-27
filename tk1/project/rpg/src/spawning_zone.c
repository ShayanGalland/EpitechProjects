/*
** EPITECH PROJECT, 2022
** game loop
** File description:
** game loop
*/

#include "include.h"

int spawning_in_zone1(game_t *game, int i, int count, sfVector2f cord)
{
    sfVector2f rand;
    sfVector2f pos_u;
    sfVector2f pos = start_point(sfSprite_getPosition
    (game->map[1].map).x, sfSprite_getPosition(game->map[1].map).y);
    sfVector2f h_pos = start_point(sfSprite_getPosition
    (game->hero.hero).x, sfSprite_getPosition(game->hero.hero).y);

    rand = start_point(generate_random_number(-200, 200)
    , generate_random_number(-200, 200));
    pos_u = start_point(h_pos.x + fabs(cord.x - pos.x) + rand.x
    , h_pos.y + fabs(cord.y - pos.y) + rand.y);
    if (game->ghost[0][i].spawned == 0) {
        game->ghost[0][i].spawned = 1;
        sfSprite_setPosition(game->ghost[0][i].ghost, pos_u);
        count++;
    }
    return count;
}

int spawning_in_zone2(game_t *game, int i, int count, sfVector2f cord)
{
    sfVector2f rand;
    sfVector2f pos_u;
    sfVector2f pos = start_point(sfSprite_getPosition
    (game->map[1].map).x, sfSprite_getPosition(game->map[1].map).y);
    sfVector2f h_pos = start_point(sfSprite_getPosition
    (game->hero.hero).x, sfSprite_getPosition(game->hero.hero).y);

    rand = start_point(generate_random_number(-200, 200)
    , generate_random_number(-200, 200));
    pos_u = start_point(h_pos.x + fabs(cord.x - pos.x) + rand.x
    , h_pos.y + fabs(cord.y - pos.y) + rand.y);
    if (game->ghost[1][i].spawned == 0) {
        game->ghost[1][i].spawned = 1;
        sfSprite_setPosition(game->ghost[1][i].ghost, pos_u);
        count++;
    }
    return count;
}

int spawning_in_zone3(game_t *game, int i, int count, sfVector2f cord)
{
    sfVector2f rand;
    sfVector2f pos_u;
    sfVector2f pos = start_point(sfSprite_getPosition
    (game->map[1].map).x, sfSprite_getPosition(game->map[1].map).y);
    sfVector2f h_pos = start_point(sfSprite_getPosition
    (game->hero.hero).x, sfSprite_getPosition(game->hero.hero).y);

    rand = start_point(generate_random_number(-200, 200)
    , generate_random_number(-200, 200));
    pos_u = start_point(h_pos.x + fabs(cord.x - pos.x) + rand.x
    , h_pos.y + fabs(cord.y - pos.y) + rand.y);
    if (game->ghost[2][i].spawned == 0) {
        game->ghost[2][i].spawned = 1;
        sfSprite_setPosition(game->ghost[2][i].ghost, pos_u);
        count++;
    }
    return count;
}