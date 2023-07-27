/*
** EPITECH PROJECT, 2022
** game loop
** File description:
** game loop
*/

#include "include.h"

void win(game_t *game)
{
    game->boss.win_cond = 1;
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(game->window);
    game->boss.msg = game->boss.end_msg;
}

void cloak(game_t *game)
{
    sfColor transp = sfColor_fromRGBA(255, 255, 255, 50);
    sfColor base = sfColor_fromRGBA(255, 255, 255, 255);

    if (sfKeyboard_isKeyPressed(sfKeyF)) {
        game->boss.cloak = 1;
        sfSprite_setColor(game->hero.hero, transp);
    }
    else {
        game->boss.cloak = 0;
        sfSprite_setColor(game->hero.hero, base);
    }
}

void boss(game_t *game, float elapsed)
{
    sfVector2f scl = sfSprite_getScale(game->boss.boss);

    if (sfSprite_getPosition(game->map[5].map).x < -250)
        game->boss.start = 1;
    sfSprite_setOrigin(game->boss.boss, start_point(300*scl.x, 250*scl.y));
    sfRenderWindow_drawText(game->window, game->boss.msg, NULL);
    if (game->boss.start == 1) {
        if (scl.x < 0)
            scl.x *= -1;
        if (sfSprite_getPosition(game->boss.boss).x > 900)
            sfSprite_setScale(game->boss.boss,
            start_point(-1*scl.x, 1*scl.y));
        else
            sfSprite_setScale(game->boss.boss, scl);
        boss_mv(game, elapsed);
    }
}
