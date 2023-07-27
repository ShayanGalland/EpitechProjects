/*
** EPITECH PROJECT, 2022
** hint
** File description:
** hint
*/

#include "include.h"

void create_hint(hint_t *hint)
{
    hint->box = get_new_item("asset/hint/box.png", (sfVector2f){1180, 0},
    0, get_rects(0, 0, 230, 620));
    hint->elapsed = 0;
    hint->step = 0;
    hint->mouse = get_new_item("asset/hint/mouse_img.png",
    (sfVector2f){1180, 0}, 0, get_rects(0, 0, 60, 60));
    hint->button = get_new_item("asset/sprites/e.png",
    (sfVector2f){1180, 0}, 0, get_rects(0, 0, 128, 128));
}

void display_hint(game_t *game, item_t img, sfText *msg, sfVector2f scale)
{
    if (game->hint.elapsed > 2500) {
        game->hint.step = -1;
        game->hint.elapsed = 0;
        return;
    }
    game->hint.elapsed++;
    display_sprites(game->hint.box, game->window);
    sfSprite_setScale(img.sprite, scale);
    img.pos = (sfVector2f){1230, 100};
    display_sprites(img, game->window);
    sfRenderWindow_drawText(game->window, msg, NULL);
}