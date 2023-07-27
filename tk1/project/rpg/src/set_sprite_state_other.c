/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "include.h"

void set_origin(game_t *game)
{
    sfSprite_setOrigin(game->hero.shoot.cursor, start_point(480, 480));
    sfSprite_setOrigin(game->hero.shoot.boom, start_point(128, 128));
    sfSprite_setOrigin(game->hero.shoot.ball3, start_point(300, 300));
    sfSprite_setOrigin(game->hero.shoot.ball2, start_point(500, 500));
    for (int i = 0; i < MAX_FANTOME_1; i++)
        sfSprite_setOrigin(game->ghost[0][i].ghost, start_point(85, 82));
    for (int i = 0; i < MAX_FANTOME_2; i++)
        sfSprite_setOrigin(game->ghost[1][i].ghost, start_point(78, 65));
    for (int i = 0; i < MAX_FANTOME_3; i++)
        sfSprite_setOrigin(game->ghost[2][i].ghost, start_point(59, 70));
}

void set_color(game_t *game)
{
    sfText_setColor(game->chat.chat_pnj1, sfBlack);
    sfText_setColor(game->chat.chat_pnj2, sfBlack);
    sfText_setColor(game->chat.chat_pnj3, sfBlack);
    sfText_setColor(game->chat.chat_pnj4, sfBlack);
}