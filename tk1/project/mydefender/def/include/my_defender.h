/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** mydefender
*/

#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "SFML/Graphics.h"
#include "SFML/System.h"
#include "SFML/Audio.h"

#ifndef _MY_DEFENDER_H
    #define _MY_DEFENDER_H

struct csfml_data {
    sfRenderWindow *render_window;
};
typedef struct csfml_data csfml_data_t;

struct my_font_s
{
    sfFont *font;
    sfText *text;
};
typedef struct my_font_s my_font_t;

struct music_s {
    sfMusic *music;
};
typedef struct music_s music_t;

struct sound_s {
    sfSound *sound;
    sfSoundBuffer *sound_buff;
};
typedef struct sound_s sound_t;

struct assets_data {
    my_font_t text_bg[6];
    sound_t sound[2];
    music_t musics[3];
    int curent_music;
};
typedef struct assets_data assets_data_t;

struct defender_state {
    csfml_data_t *csfml_data;
    assets_data_t *assets_data;
};
typedef struct defender_state defender_state_t;

#endif /* ! _MAIN_MENU_STATE_H */
