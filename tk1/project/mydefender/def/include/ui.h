/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** my_defender
*/

#include "ui_button.h"
#include "main_menu_state.h"
#include "main_setting_state.h"
#include "main_rules_state.h"
#include "scores_state.h"

#ifndef _UI_H
    #define _UI_H

struct sprite_s {
    sfSprite *sprite;
    sfTexture *txtr;
    sfIntRect rect;
    sfVector2f vector;
};
typedef struct sprite_s sprite_t;

struct main_menu_ui {
    button_t *buttons[10];
    button_colors_t *colors;
    sprite_t bg;
    sprite_t back;
    sprite_t volume_level;
    sprite_t volume_button;
    int volume;
};
typedef struct main_menu_ui main_menu_ui_t;
main_menu_ui_t *create_ui_main_menu();

struct main_setting_ui {
    button_t *buttons[11];
    my_font_t text[12];
    button_colors_t *colors;
    sprite_t bg;
    sprite_t volume_level;
    int level_sound;
    int nbr_frames;
    sprite_t music;
    sprite_t frame;
};
typedef struct main_setting_ui main_setting_ui_t;
main_setting_ui_t *create_ui_main_setting();

struct main_rules_ui {
    button_t *buttons[2];
    my_font_t text[2];
    button_colors_t *colors;
    sprite_t bg;
    sprite_t book;
    sprite_t title;
};
typedef struct main_rules_ui main_rules_ui_t;
main_rules_ui_t *create_ui_rules_setting();

struct scores_ui {
};
typedef struct scores_ui scores_ui_t;
scores_ui_t *create_ui_scores();

struct game_ui {
};
typedef struct game_ui game_ui_t;

game_ui_t *create_ui_game();

struct game_pause_ui {
};
typedef struct game_pause_ui game_pause_ui_t;
game_pause_ui_t *create_ui_game_pause();

#endif /* ! _UI_H */