/*
** EPITECH PROJECT, 2022
** game loop
** File description:
** game loop
*/

#include "include.h"

void display_chat(game_t *game)
{
    sfText_setColor(game->chat.pnj_name, sfRed);
    sfRenderWindow_drawText(game->window, game->chat.pnj_name, NULL);
    sfText_setColor(game->chat.space, sfBlue);
    sfRenderWindow_drawText(game->window, game->chat.space, NULL);
    if (game->chat.num_txt == 0)
        sfRenderWindow_drawText(game->window, game->chat.chat_pnj1, NULL);
    if (game->chat.num_txt == 1)
        sfRenderWindow_drawText(game->window, game->chat.chat_pnj2, NULL);
    if (game->chat.num_txt == 2)
        sfRenderWindow_drawText(game->window, game->chat.chat_pnj3, NULL);
    if (game->chat.num_txt == 3)
        sfRenderWindow_drawText(game->window, game->chat.chat_pnj4, NULL);
    if (game->chat.num_txt > 3)
        game->chat.num_txt = 3;
    if (sfKeyboard_isKeyPressed(sfKeySpace) && game->chat.chat_time > 0.4f) {
        game->chat.num_txt++;
        game->chat.chat_time = 0;
    }
}

void chat(game_t *game)
{
    if (distance(game->hero.hero, game->pnj.pnj) > 150) {
        game->pnj.chating = sfFalse;
        game->chat.num_txt = 0;
    }
    if (distance(game->hero.hero, game->pnj.pnj) < 150) {
        if (!sfKeyboard_isKeyPressed(sfKeyE))
            sfRenderWindow_drawSprite(game->window, game->pnj.e, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            game->pnj.chating = sfTrue;
            add_to_inventory(game, &game->items.object[SCROLL]);
        }
    }
    if (game->pnj.chating && distance(game->hero.hero, game->pnj.pnj) < 150) {
        sfRenderWindow_drawSprite(game->window, game->pnj.box, NULL);
        display_chat(game);
    }
}

void uhd(game_t *game)
{
    if (sfSprite_getScale(game->hero.life).x > 0)
        sfSprite_setScale(game->hero.life,
        start_point(0.5f+game->hero.less_life, 0.035f));
    if (sfSprite_getScale(game->hero.stamina).x > 0
    || game->hero.mana_regen == 1)
        sfSprite_setScale(game->hero.stamina,
        start_point(0.6f+game->hero.less_mana, 0.10f));
    else
        game->hero.mana_regen = 1;
    if (game->hero.mana_regen == 1) {
        if (game->game_time > game->hero.mana_regening) {
            game->hero.less_mana += 0.0004f;
            game->hero.mana_regening += 0.004f;
        }
        if (sfSprite_getScale(game->hero.stamina).x > 0.6f) {
            game->hero.mana_regen = 0;
            game->hero.less_mana = 0;
        }
    }
}

void change_gun(game_t *game)
{
    if (game->key.key2f == 1) {
        game->hero.shoot.ball = game->hero.shoot.ball3;
        game->hero.shoot.spd = 4;
    }
    if (game->key.key3f == 1) {
        game->hero.shoot.ball = game->hero.shoot.ball2;
        game->hero.shoot.spd = 8;
    }
}