/*
** EPITECH PROJECT, 2022
** getdata
** File description:
** getdata
*/

#include "include.h"

float ghost_damadge2(int n, game_t *game)
{
    if (game->dif == 2) {
        if (n == 0)
            return 0.01f;
        if (n == 1)
            return 0.02f;
        if (n == 2)
            return 0.03f;
    }
    return 0.0;
}

float ghost_damadge(int n, game_t *game)
{
    if (game->dif == 0) {
        if (n == 0)
            return 0.0004f;
        if (n == 1)
            return 0.0008f;
        if (n == 2)
            return 0.001f;
    }
    else if (game->dif == 1) {
        if (n == 0)
            return 0.004f;
        if (n == 1)
            return 0.007f;
        if (n == 2)
            return 0.01f;
    }
    else return ghost_damadge2(n, game);
    return 0.0;
}

void attack(game_t *game, float elapsed, int i, int n)
{
    sfVector2f h = start_point(sfSprite_getPosition
    (game->hero.hero).x, sfSprite_getPosition(game->hero.hero).y);
    sfVector2f pos_g = start_point(sfSprite_getPosition(game->ghost[n][i].
    ghost).x, sfSprite_getPosition(game->ghost[n][i].ghost).y);
    sfVector2f pos = start_point(h.x - pos_g.x, h.y - pos_g.y);
    sfFloatRect colide = sfSprite_getGlobalBounds(game->ghost[n][i].ghost);
    float spd = set_speed(n, game);

    sfSprite_move(game->ghost[n][i].ghost,
    start_point(pos.x*elapsed*spd, pos.y*elapsed*spd));
    change_ghost_side(game, n, i);
    if (sfFloatRect_contains(&colide, h.x, h.y) &&
    game->ghost[n][i].spawned != 0) {
        if (game->game_time > game->hero.delay_life) {
            game->hero.less_life -= ghost_damadge(n, game);
            game->hero.delay_life += 0.2f;
        }
    }
}

void attacking_ghost(game_t *game, float elapsed)
{
    for (int i = 0; i < MAX_FANTOME_1; i++) {
        if (game->ghost[0][i].spawned == 1)
            attack(game, elapsed, i, 0);
    }
    for (int i = 0; i < MAX_FANTOME_2; i++) {
        if (game->ghost[1][i].spawned == 1)
            attack(game, elapsed, i, 1);
    }
    for (int i = 0; i < MAX_FANTOME_3; i++) {
        if (game->ghost[2][i].spawned == 1)
            attack(game, elapsed, i, 2);
    }
}

void boooom(game_t *game, int i, int n)
{
    sfVector2f pos = start_point(sfSprite_getPosition(game->ghost[n][i].ghost)
    .x,sfSprite_getPosition(game->ghost[n][i].ghost).y);

    sfSprite_setPosition(game->hero.shoot.boom, pos);
    game->hero.shoot.is_boom = 1;
    game->ghost[n][i].spawned = 0;
    gain_exp(game);
}
