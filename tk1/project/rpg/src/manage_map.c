/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "include.h"

void manage_colide2(game_t *game)
{
    if (game->other_world == 1) {
        game->map_select = 6;
        game->map[5].div = 4;
        game->map[5].res_x = 599;
        game->map[5].res_y = 383;
        stop_colision(game, game->map[5].map, game->map[5].map_collision);
        out_of_map(game, 5);
    }
}

void manage_colide(game_t *game)
{
    if (game->map_select == 1 && game->other_world != 1) {
        game->map[0].div = 1.5f;
        game->map[0].res_x = 959;
        game->map[0].res_y = 959;
        stop_colision(game, game->map[0].map, game->map[0].map_collision);
        out_of_map(game, 0);
    }
    if (game->map_select == 2 && game->other_world != 1) {
        game->map[1].div = 7;
        game->map[1].res_x = 2399;
        game->map[1].res_y = 2399;
        stop_colision(game, game->map[1].map, game->map[1].map_collision);
        out_of_map(game, 1);
    }
    manage_colide2(game);
}

void move_all(game_t *game)
{
    if (game->map_select == 1) {
        move_player(game, game->pnj.pnj);
        move_player(game, game->pnj.e);
        move_player(game, game->map[0].map);
        move_player(game, game->map[0].map_hit);
        move_player(game, game->map[0].next);
        move_player(game, game->map[0].key_e);
    }
    if (game->map_select == 2) {
        move_player(game, game->key.key1);
        move_player(game, game->key.key2);
        move_player(game, game->key.key3);
        move_ghost(game);
    }
    if (game->other_world == 1) {
        move_player(game, game->map[5].map);
        move_player(game, game->map[5].map_hit);
    }
}

void manage_animation(game_t *game)
{
    for (int i = 0; i < MAX_FANTOME_1; i++)
        create_and_anim_ghost1(game, i);
    for (int i = 0; i < MAX_FANTOME_2; i++)
        create_and_anim_ghost2(game, i);
    for (int i = 0; i < MAX_FANTOME_3; i++)
        create_and_anim_ghost3(game, i);
    create_and_anim_pnj(game);
    create_and_anim_hero(game);
    if (game->hero.shoot.is_boom == 1)
        create_and_anim_boom(game);
    no_anim(game);
}