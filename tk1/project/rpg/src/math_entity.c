/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "include.h"

static float cardrant(double add, game_t *game)
{
    float angle = 0;

    game->math.ab = (float)sqrt((game->math.ac *
    game->math.ac) + (game->math.cb * game->math.cb));
    angle = (float)asinf(game->math.cb/game->math.ab) + add;
    return angle;
}

static void sum_cadr(int abscb, int absac, game_t *game)
{
    game->math.cb = abs(abscb);
    game->math.ac = abs(absac);
}

float angle_sprt(sfSprite *sprite1, sfSprite *sprite2, game_t *game)
{
    sfVector2f P_sprite1 = sfSprite_getPosition(sprite1);
    sfVector2f P_sprite2 = sfSprite_getPosition(sprite2);

    if (P_sprite2.y > P_sprite1.y && P_sprite2.x > P_sprite1.x) {
        sum_cadr(P_sprite1.y - P_sprite2.y, P_sprite1.x - P_sprite2.x, game);
        game->math.angle = cardrant(0, game);
    }
    if (P_sprite2.y > P_sprite1.y && P_sprite2.x < P_sprite1.x) {
        sum_cadr(P_sprite1.x - P_sprite2.x, P_sprite1.y - P_sprite2.y, game);
        game->math.angle = cardrant(T_PI/2, game);
    }
    if (P_sprite2.y < P_sprite1.y && P_sprite2.x < P_sprite1.x) {
        sum_cadr(P_sprite1.y - P_sprite2.y, P_sprite1.x - P_sprite2.x, game);
        game->math.angle = cardrant(T_PI, game);
    }
    if (P_sprite2.y < P_sprite1.y && P_sprite2.x > P_sprite1.x) {
        sum_cadr(P_sprite1.x - P_sprite2.x, P_sprite1.y - P_sprite2.y, game);
        game->math.angle = cardrant((T_PI + T_PI/2), game);
    }
    return game->math.angle*180/T_PI;
}