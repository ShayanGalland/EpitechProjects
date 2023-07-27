/*
** EPITECH PROJECT, 2022
** game loop
** File description:
** game loop
*/

#include "include.h"

void create_game_texture(game_t *game)
{
    game->hero.shoot.text_ball = sfTexture_createFromFile
    ("asset/sprites/balls.png", NULL);
    game->hero.shoot.text_ball2 = sfTexture_createFromFile
    ("asset/sprites/energetic_bulet.png", NULL);
    game->hero.shoot.text_ball3 = sfTexture_createFromFile
    ("asset/sprites/yellow_bulet.png", NULL);
    game->hero.shoot.text_cursor = sfTexture_createFromFile
    ("asset/sprites/attack.png", NULL);
    game->hero.shoot.text_boom = sfTexture_createFromFile
    ("asset/sprites/boom.png", NULL);
    game->pnj.text_e = sfTexture_createFromFile
    ("asset/sprites/e.png", NULL);
    game->pnj.text_box = sfTexture_createFromFile
    ("asset/sprites/dialogue_box.png", NULL);
    game->key.text_key1 = sfTexture_createFromFile
    ("asset/sprites/key.png", NULL);
    game->key.text_key2 = sfTexture_createFromFile
    ("asset/sprites/key.png", NULL);
    game->key.text_key3 = sfTexture_createFromFile
    ("asset/sprites/key.png", NULL);
}

void create_game_sprite(game_t *game)
{
    create_game_texture(game);
    game->hero.shoot.ball = init_sprite(game->hero.shoot.text_ball);
    game->hero.shoot.ball2 = init_sprite(game->hero.shoot.text_ball2);
    game->hero.shoot.ball3 = init_sprite(game->hero.shoot.text_ball3);
    game->hero.shoot.cursor = init_sprite(game->hero.shoot.text_cursor);
    game->pnj.e = init_sprite(game->pnj.text_e);
    game->pnj.box = init_sprite(game->pnj.text_box);
    game->hero.shoot.boom = init_sprite(game->hero.shoot.text_boom);
    game->key.key1 = init_sprite(game->key.text_key1);
    game->key.key2 = init_sprite(game->key.text_key2);
    game->key.key3 = init_sprite(game->key.text_key3);
}

void create_map_sprite(game_t *game)
{
    game->map[0].text_map = sfTexture_createFromFile
    ("asset/map/Map001.png", NULL);
    game->map[0].text_map_hit = sfTexture_createFromFile
    ("asset/map/col1p.png", NULL);
    game->map[0].text_next = sfTexture_createFromFile
    ("asset/map/Black.png", NULL);
    game->map[0].text_key_e = sfTexture_createFromFile
    ("asset/sprites/e.png", NULL);
    game->map[0].map = init_sprite(game->map[0].text_map);
    game->map[0].map_hit = init_sprite(game->map[0].text_map_hit);
    game->map[0].next = init_sprite(game->map[0].text_next);
    game->map[0].key_e = init_sprite(game->map[0].text_key_e);
}

void create_map2_sprite(game_t *game)
{
    game->map[1].text_map = sfTexture_createFromFile
    ("asset/map/map3.png", NULL);
    game->map[1].text_map_hit = sfTexture_createFromFile
    ("asset/map/door1.png", NULL);
    game->map[1].text_next = sfTexture_createFromFile
    ("asset/map/Black.png", NULL);
    game->map[1].text_key_e = sfTexture_createFromFile
    ("asset/sprites/e.png", NULL);
    game->text_pluie = sfTexture_createFromFile
    ("asset/sprites/pluie.png", NULL);
    game->map[1].map = init_sprite(game->map[1].text_map);
    game->map[1].map_hit = init_sprite(game->map[1].text_map_hit);
    game->map[1].next = init_sprite(game->map[1].text_next);
    game->map[1].key_e = init_sprite(game->map[1].text_key_e);
    game->pluie = init_sprite(game->text_pluie);
}

void create_character_sprite(game_t *game)
{
    game->ghost = malloc(sizeof(ghost_t*)*4);
    game->ghost[0] = malloc(sizeof(ghost_t)*MAX_FANTOME_1);
    game->ghost[1] = malloc(sizeof(ghost_t)*MAX_FANTOME_2);
    game->ghost[2] = malloc(sizeof(ghost_t)*MAX_FANTOME_3);
    game->boss.text_win = sfTexture_createFromFile
    ("asset/sprites/win.jpg", NULL);
    game->boss.text_boss = sfTexture_createFromFile
    ("asset/character/boss_final.png", NULL);
    game->hero.text_life = sfTexture_createFromFile
    ("asset/character/life.png", NULL);
    game->hero.text_stamina = sfTexture_createFromFile
    ("asset/character/stamina.jpg", NULL);
    game->pnj.text_pnj = sfTexture_createFromFile
    ("asset/character/dumb_pnj.png", NULL);
    game->hero.text_hero = sfTexture_createFromFile
    ("asset/character/h.png", NULL);
    game->text_over = sfTexture_createFromFile
    ("asset/sprites/game_over.png", NULL);
}