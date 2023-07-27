/*
** EPITECH PROJECT, 2022
** display
** File description:
** display
*/

#include "include.h"

void draw_ghost(game_t *game)
{
    for (int i = 0; i < MAX_FANTOME_1; i++) {
        if (game->ghost[0][i].spawned == 1 && game->map_select == 2)
            sfRenderWindow_drawSprite(game->window,
            game->ghost[0][i].ghost, NULL);
    }
    for (int i = 0; i < MAX_FANTOME_2; i++) {
        if (game->ghost[1][i].spawned == 1 && game->map_select == 2)
            sfRenderWindow_drawSprite(game->window,
            game->ghost[1][i].ghost, NULL);
    }
    for (int i = 0; i < MAX_FANTOME_3; i++) {
        if (game->ghost[2][i].spawned == 1 && game->map_select == 2)
            sfRenderWindow_drawSprite(game->window,
            game->ghost[2][i].ghost, NULL);
    }
}

void draw_boom(game_t *game)
{
    for (int i = 0; i < MAX_FANTOME_1; i++) {
        if (game->ghost[0][i].spawned == 1 && game->map_select == 2)
            sfRenderWindow_drawSprite(game->window,
            game->hero.shoot.boom, NULL);
    }
    for (int i = 0; i < MAX_FANTOME_2; i++) {
        if (game->ghost[1][i].spawned == 1 && game->map_select == 2)
            sfRenderWindow_drawSprite(game->window,
            game->hero.shoot.boom, NULL);
    }
    for (int i = 0; i < MAX_FANTOME_3; i++) {
        if (game->ghost[2][i].spawned == 1 && game->map_select == 2)
            sfRenderWindow_drawSprite(game->window,
            game->hero.shoot.boom, NULL);
    }
}

void draw_map2(game_t *game)
{
    if (game->map_select == 2) {
        sfRenderWindow_drawSprite(game->window, game->map[1].map, NULL);
        sfRenderWindow_drawSprite(game->window, game->map[1].map_hit, NULL);
        if (game->key.key1f == 0)
            sfRenderWindow_drawSprite(game->window, game->key.key1, NULL);
        if (game->key.key2f == 0)
        sfRenderWindow_drawSprite(game->window, game->key.key2, NULL);
        if (game->key.key3f == 0)
        sfRenderWindow_drawSprite(game->window, game->key.key3, NULL);
    }
}

void draw_game_utils(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->hero.shoot.cursor, NULL);
    sfRenderWindow_drawSprite(game->window, game->hero.hero, NULL);
    sfRenderWindow_drawSprite(game->window, game->hero.shoot.ball, NULL);
    sfRenderWindow_drawSprite(game->window, game->hero.life, NULL);
    sfRenderWindow_drawSprite(game->window, game->hero.stamina, NULL);
    if (game->hero.shoot.is_boom == 1)
        draw_boom(game);
    if (game->other_world == 1 && game->boss.start == 1)
        sfRenderWindow_drawSprite(game->window, game->boss.boss, NULL);
    if (game->boss.win_cond == 1)
        sfRenderWindow_drawSprite(game->window, game->boss.win, NULL);
    draw_ghost(game);
}

void draw_sprites(game_t *game)
{
    if (game->other_world == 1) {
        sfRenderWindow_drawSprite(game->window, game->map[5].map, NULL);
        sfRenderWindow_drawSprite(game->window, game->map[5].map_hit, NULL);
    }
    if (game->map_select == 1) {
        sfRenderWindow_drawSprite(game->window, game->map[0].map, NULL);
        sfRenderWindow_drawSprite(game->window, game->map[0].map_hit, NULL);
        sfRenderWindow_drawSprite(game->window, game->pnj.pnj, NULL);
        sfRenderWindow_drawSprite(game->window, game->pluie, NULL);
    }
    draw_map2(game);
    draw_game_utils(game);
}
