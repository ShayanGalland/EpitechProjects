/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** main_mydefnder.c
*/

#include "my_defender_game.h"
#include "my.h"

void putpls_o(game_t *d, map_t *map_t)
{
    for (int i = 0; i < MAX_PLAT_O; i++) {
        render_plat(d, map_t, i);
    }
}

void prt_mp(game_t *d, map_t *map_t)
{
    sfRenderWindow_drawSprite(d->window, map_t->mp_o, NULL);
    sfRenderWindow_drawSprite(d->window, map_t->mp_bo, NULL);
    sfRenderWindow_drawSprite(d->window, map_t->life, NULL);
    sfRenderWindow_drawSprite(d->window, map_t->coin, NULL);
}

void prt_tur(game_t *d, map_t *map_t)
{
    for (int i = 0; i != MAX_PLAT_O;i++) {
        sfRenderWindow_drawSprite(d->window, map_t->ftur_t[i], NULL);
        sfRenderWindow_drawSprite(d->window, map_t->stur_t[i], NULL);
        sfRenderWindow_drawSprite(d->window, map_t->ttur_t[i], NULL);
        sfRenderWindow_drawSprite(d->window, map_t->qtur_t[i], NULL);
    }
}

void prt_portal(game_t *d, map_t *map_t, float elapsed, sfSprite *portal)
{
    sfIntRect rect;

    map_t->move_t->time_animation_r += elapsed;
    if (map_t->move_t->time_animation_r > map_t->move_t->frame_r) {
        map_t->move_t->next_frame_r += 1;
        if (map_t->move_t->next_frame_r == 6)
            map_t->move_t->next_frame_r = 1;
        map_t->move_t->frame_r += 0.10f;
    }
    rect.left = (1100/6)*map_t->move_t->next_frame_r;
    rect.top = 0;
    rect.height = 178;
    rect.width = 1100/6;
    sfSprite_setTextureRect(portal, rect);
    sfSprite_setScale(portal, start_point(0.8f, 0.8f));
    sfRenderWindow_drawSprite(d->window, portal, NULL);
}

void prt_en(game_t *d, map_t *map_t, float elapsed)
{
    for (int i = 0; i != MAX_EN_OO ;i++)
        sfRenderWindow_drawSprite(d->window, map_t->fenemie_t[i], NULL);
    for (int i = 0; i != MAX_EN_OD ;i++)
        sfRenderWindow_drawSprite(d->window, map_t->senemie_t[i], NULL);
    for (int i = 0; i != MAX_EN_OT ;i++)
        sfRenderWindow_drawSprite(d->window, map_t->tenemie_t[i], NULL);
}