/*
** EPITECH PROJECT, 2022
** init
** File description:
** init
*/

#include "include.h"

void default_value(game_t *game)
{
    game->step = 0;
    game->dif = 1;
    game->fps = 60;
    game->vol = 50;
    game->started = 0;
    game->delay = 0;
    game->tuto.step = 0;
    game->boss.is_travel = 1;
    game->boss.rand_mv.x = generate_random_number(-900, 900);
    game->boss.rand_mv.y = generate_random_number(-500, 500);
    game->boss.size.x = 0.5f;
    game->boss.size.y = 0.5f;
    game->boss.mv = 0.005f;
    game->boss.cloak = 0;
}

void init_values(game_t *game)
{
    game->map = malloc(sizeof(map_t)*6);
    game->other_world = 0;
    game->map_select = 1;
    game->game_clock = sfClock_create();
    game->step = 0;
    game->dif = 1;
    game->fps = 60;
    game->vol = 50;
    game->hero.less_life = 0;
    game->hero.less_mana = 0;
    game->hero.mana_regen = 0;
    game->hero.shoot.is_boom = 0;
    game->key.key1f = 0;
    game->key.key2f = 0;
    game->key.key3f = 0;
    game->hero.shoot.spd = 1.4f;
    game->is_spawned = malloc(sizeof(int)*31);
    for (int i = 0; i < 31; i++)
        game->is_spawned[i] = 0;
}

void create_sprites(game_t *game)
{
    create_game_sprite(game);
    create_map_sprite(game);
    create_map2_sprite(game);
    create_character_sprite(game);
    create_text_ghost(game);
    create_image(game);
    create_txt(game);
    create_other_map(game);
    init_character_sprite(game);
}