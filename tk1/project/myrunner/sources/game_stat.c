/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** project in c
*/
#include "function.h"

void init_sound(game_t *game_mod) {
    sfSoundBuffer* buffer1 = sfSoundBuffer_createFromFile("assets/music.ogg");
    sfSoundBuffer* buffer2 = sfSoundBuffer_createFromFile("assets/jump.wav");
    game_mod->music_sound = sfSound_create();
    sfSound_setBuffer(game_mod->music_sound, buffer1);
    sfSound_setLoop(game_mod->music_sound, 1);
    sfSound_play(game_mod->music_sound);
    sfSound_setVolume(game_mod->music_sound, 25);
    game_mod->jump_sound = sfSound_create();
    sfSound_setBuffer(game_mod->jump_sound, buffer2);
}
void init_text(game_t *game_mod){
    game_mod->font = sfFont_createFromFile("assets/arial.ttf");
    game_mod->score_text = sfText_create();
}

game_t *game_stat()
{
    game_t *game_mod = malloc(sizeof(game_t));
    for(int i = 0; i < 5;i++){
        game_mod->enemies[i].texture = sfTexture_createFromFile("assets/enemis.png", NULL);
        game_mod->enemies[i].sprite = create_sprite(game_mod->enemies[i].texture);
        sfSprite_setScale(game_mod->enemies[i].sprite, start_point(0.13f, 0.13f));
        game_mod->enemies[i].is_active = 0;
    }
    game_mod->game_clock = sfClock_create();
    game_mod->all_par.x = -1;
    game_mod->all_par.y = 0;
    game_mod->fram_e = 2.0f;
    game_mod->n = 0;
    game_mod->m = 0;
    game_mod->score = 0;
    game_mod->hero_vlc = start_point(0, 0);
    game_mod->tex_hero = sfTexture_createFromFile("assets/hero.png", NULL);
    game_mod->hero_spr = create_sprite(game_mod->tex_hero);
    game_mod->her_scl = start_point(0.35f, 0.35f);
    sfSprite_setScale(game_mod->hero_spr, game_mod->her_scl);
    game_mod->pos_her = start_point(100, 400);
    sfSprite_setPosition(game_mod->hero_spr, game_mod->pos_her);
    init_sound(game_mod);
    init_text(game_mod);
    return game_mod;
}
