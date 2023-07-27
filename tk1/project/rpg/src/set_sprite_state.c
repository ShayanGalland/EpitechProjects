/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "include.h"

static void set_pos2(game_t *game)
{
    sfSprite_setPosition(game->map[5].map, start_point(800, -300));
    sfSprite_setPosition(game->map[5].map_hit, start_point(825, -300));
    sfSprite_setPosition(game->boss.boss, start_point(1000, 300));
    sfSprite_setPosition(game->pluie, start_point(0, -3000));
}

static void set_pos(game_t *game)
{
    sfSprite_setPosition(game->pnj.pnj, start_point(1000, 280));
    sfSprite_setPosition(game->hero.hero, start_point(sfWindow_getSize
    ((sfWindow*)game->window).x/2.2f, sfWindow_getSize((sfWindow*)
    game->window).y / 2.4f));
    sfSprite_setPosition(game->hero.shoot.ball, start_point(-99, -99));
    sfSprite_setPosition(game->hero.shoot.cursor, start_point(-99, -99));
    sfSprite_setPosition(game->map[0].map, start_point(750, -750));
    sfSprite_setPosition(game->map[0].map_hit, start_point(750, -750));
    sfSprite_setPosition(game->pnj.e, start_point(960, 300));
    sfSprite_setPosition(game->pnj.box, start_point(200, 620));
    sfSprite_setPosition(game->map[0].next, start_point(1380, -620));
    sfSprite_setPosition(game->map[1].map, start_point(1400, -750));
    sfSprite_setPosition(game->map[1].map_hit, start_point(1400, -750));
    sfSprite_setPosition(game->map[1].next, start_point(-15865, -6222));
    sfSprite_setPosition(game->hero.life, start_point(70, 930));
    sfSprite_setPosition(game->hero.stamina, start_point(70, 887));
    sfSprite_setPosition(game->key.key1, start_point(800, 1450));
    sfSprite_setPosition(game->key.key2, start_point(8450, 520));
    sfSprite_setPosition(game->key.key3, start_point(4450, 4350));
}

static void set_size2(game_t *game)
{
    sfSprite_setScale(game->key.key1, start_point(0.2f, 0.2f));
    sfSprite_setScale(game->key.key2, start_point(0.2f, 0.2f));
    sfSprite_setScale(game->key.key3, start_point(0.2f, 0.2f));
    sfSprite_setScale(game->hero.shoot.ball2, start_point(0.1f, 0.1f));
    sfSprite_setScale(game->hero.shoot.ball3, start_point(0.15f, 0.15f));
    sfSprite_setScale(game->map[5].map, start_point(4, 4));
    sfSprite_setScale(game->map[5].map_hit, start_point(4, 4));
    sfSprite_setScale(game->boss.boss, start_point(0.5f, 0.5f));
    sfSprite_setScale(game->boss.win, start_point(3, 3));
    sfSprite_setScale(game->over, start_point(3, 3));
    sfSprite_setScale(game->pluie, start_point(4.2f, 6));
}

static void set_size(game_t *game)
{
    sfSprite_setScale(game->pnj.box, start_point(0.6f, 0.6f));
    sfSprite_setScale(game->pnj.e, start_point(0.4f, 0.4f));
    sfSprite_setScale(game->pnj.pnj, start_point(0.08f, 0.08f));
    sfSprite_setScale(game->hero.hero, start_point(2, 2));
    sfSprite_setScale(game->hero.shoot.ball, start_point(0.04f, 0.04f));
    sfSprite_setScale(game->hero.shoot.cursor, start_point(0.07f, 0.07f));
    sfSprite_setScale(game->map[0].next, start_point(0.23f, 0.23f));
    sfSprite_setScale(game->map[0].key_e, start_point(0.4f, 0.4f));
    sfSprite_setScale(game->map[0].map_hit, start_point(1.5f, 1.5f));
    sfSprite_setScale(game->map[0].map, start_point(1.5f, 1.5f));
    sfSprite_setScale(game->map[1].map_hit, start_point(1.5f, 1.5f));
    sfSprite_setScale(game->map[1].map, start_point(7, 7));
    sfSprite_setScale(game->map[1].map_hit, start_point(7, 7));
    sfSprite_setScale(game->map[1].next, start_point(0.23f, 0.23f));
    sfSprite_setScale(game->map[1].key_e, start_point(0.4f, 0.4f));
    sfSprite_setScale(game->hero.life, start_point(0.5f, 0.035f));
    sfSprite_setScale(game->hero.stamina, start_point(0.6f, 0.10f));
    for (int i = 0; i < MAX_FANTOME_3; i++)
        sfSprite_setScale(game->ghost[2][i].ghost, start_point(0.7f, 0.7f));
}

void set_sprite(game_t *game)
{
    set_origin(game);
    set_pos(game);
    set_pos2(game);
    set_size(game);
    set_size2(game);
    set_color(game);
}