/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#include "function.h"

void oos_un(back_t *back_t, sfVector2f offset)
{
    sfVector2f pos;
    sfSprite_move(back_t->sprite_un, offset);
    pos = sfSprite_getPosition(back_t->sprite_un);
    if(pos.x < -800)
        sfSprite_setPosition(back_t->sprite_un, start_point(1600, 0));
    sfSprite_move(back_t->sprite_deux, offset);
    pos = sfSprite_getPosition(back_t->sprite_deux);
    if(pos.x < -800)
        sfSprite_setPosition(back_t->sprite_deux, start_point(1600, 0));
    sfSprite_move(back_t->sprite_trois, offset);
    pos = sfSprite_getPosition(back_t->sprite_trois);
    if(pos.x < -800)
        sfSprite_setPosition(back_t->sprite_trois, start_point(1600, 0));
}

void oos_deux(back_t *back_t, sfVector2f offset)
{
    sfVector2f pos;
    sfSprite_move(back_t->sprite_quatre, offset);
    pos = sfSprite_getPosition(back_t->sprite_quatre);
    if(pos.x < -3500)
        sfSprite_setPosition(back_t->sprite_quatre, start_point(3500, 75));
    sfSprite_move(back_t->sprite_cinq, offset);
    pos = sfSprite_getPosition(back_t->sprite_cinq);
    if(pos.x < -3500)
        sfSprite_setPosition(back_t->sprite_cinq, start_point(3500, 75));
}
void oos_trois(back_t *back_t, sfVector2f offset)
{
    sfVector2f pos;
    sfSprite_move(back_t->sprite_sept, offset);
    pos = sfSprite_getPosition(back_t->sprite_sept);
    if(pos.x < -470)
        sfSprite_setPosition(back_t->sprite_sept, start_point(940, 500));
    sfSprite_move(back_t->sprite_huit, offset);
    pos = sfSprite_getPosition(back_t->sprite_huit);
    if(pos.x < -470)
        sfSprite_setPosition(back_t->sprite_huit, start_point(940, 500));
    sfSprite_move(back_t->sprite_neuf, offset);
    pos = sfSprite_getPosition(back_t->sprite_neuf);
    if(pos.x < -470)
        sfSprite_setPosition(back_t->sprite_neuf, start_point(940, 500));
}

void move_spr(float elapsed, back_t *back_t, game_t *game_t)
{
    sfVector2f offset_un;
    sfVector2f offset_deux;
    sfVector2f offset_trois;
    offset_un.x = game_t->all_par.x*30*elapsed;
    offset_un.y = game_t->all_par.y*0*elapsed;
    offset_deux.x = game_t->all_par.x*58*elapsed;
    offset_deux.y = game_t->all_par.y*0*elapsed;
    offset_trois.x = game_t->all_par.x*70*elapsed;
    offset_trois.y = game_t->all_par.y*0*elapsed;
    oos_un(back_t, offset_un);
    oos_deux(back_t, offset_deux);
    oos_trois(back_t, offset_trois);
}
void parallax(sfRenderWindow *window, float elapsed, back_t *back_t, game_t *game_t)
{
    move_spr(elapsed, back_t, game_t);
    sfRenderWindow_drawSprite(window, back_t->sprite_un, NULL);
    sfRenderWindow_drawSprite(window, back_t->sprite_deux, NULL);
    sfRenderWindow_drawSprite(window, back_t->sprite_trois, NULL);
    sfRenderWindow_drawSprite(window, back_t->sprite_quatre, NULL);
    sfRenderWindow_drawSprite(window, back_t->sprite_cinq, NULL);
    sfRenderWindow_drawSprite(window, back_t->sprite_sept, NULL);
    sfRenderWindow_drawSprite(window, back_t->sprite_huit, NULL);
    sfRenderWindow_drawSprite(window, back_t->sprite_neuf, NULL);
}