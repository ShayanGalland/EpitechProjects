/*
** EPITECH PROJECT, 2022
** game loop
** File description:
** game loop
*/

#include "include.h"

void boss_shooted(game_t *game)
{
    sfFloatRect boss = sfSprite_getGlobalBounds(game->boss.boss);

    if (sfSprite_getPosition(game->hero.shoot.ball).x == -99)
        game->boss.os = 1;
    if (game->boss.os == 1 && sfFloatRect_contains(&boss, sfSprite_getPosition
    (game->hero.shoot.ball).x, sfSprite_getPosition
    (game->hero.shoot.ball).y)) {
        game->boss.size.x += 0.01f;
        game->boss.size.y += 0.01f;
        game->boss.mv += 0.04;
        game->boss.os = 0;
    }
    sfSprite_setScale(game->boss.boss, start_point
    (game->boss.size.x, game->boss.size.y));
    if (sfSprite_getScale(game->boss.boss).x > 2)
        win(game);
}

void rand_pos(sfVector2f pos, game_t *game)
{
    if (pos.x == game->boss.rand_mv.x && pos.y == game->boss.rand_mv.y) {
        game->boss.rand_mv.x = generate_random_number(-900, 900);
        game->boss.rand_mv.y = generate_random_number(-500, 500);
    }
    if (pos.x > 1800) {
        game->boss.rand_mv.x = generate_random_number(-900, 0);
        game->boss.rand_mv.y = generate_random_number(-500, 500);
    }
    if (pos.x < 0) {
        game->boss.rand_mv.x = generate_random_number(0, 900);
        game->boss.rand_mv.y = generate_random_number(-500, 500);
    }
    if (pos.y > 1000) {
        game->boss.rand_mv.x = generate_random_number(-900, 900);
        game->boss.rand_mv.y = generate_random_number(-500, 0);
    }
    if (pos.y < 0) {
        game->boss.rand_mv.x = generate_random_number(-900, 0);
        game->boss.rand_mv.y = generate_random_number(0, 500);
    }
}

void colide_boss(game_t *game)
{
    sfVector2f pos;
    sfFloatRect boss = sfSprite_getGlobalBounds(game->boss.boss);

    pos.x = sfSprite_getPosition(game->hero.hero).x;
    pos.y = sfSprite_getPosition(game->hero.hero).y;
    cloak(game);
    if (sfFloatRect_contains(&boss, pos.x, pos.y) &&
    game->boss.cloak == 0 && game->boss.win_cond != 1) {
        if (game->dif == 0)
            game->hero.less_life -= 0.0005f;
        if (game->dif == 1)
            game->hero.less_life -= 0.001f;
        if (game->dif == 2)
            game->hero.less_life -= 0.01f;
    }

}

void boss_mv(game_t *game, float elapsed)
{
    sfVector2f pos;

    pos.x = sfSprite_getPosition(game->boss.boss).x;
    pos.y = sfSprite_getPosition(game->boss.boss).y;
    rand_pos(pos, game);
    sfSprite_move(game->boss.boss, start_point(game->boss.rand_mv.x*elapsed*
    game->boss.mv, game->boss.rand_mv.y*elapsed*game->boss.mv));
    boss_shooted(game);
    colide_boss(game);
}