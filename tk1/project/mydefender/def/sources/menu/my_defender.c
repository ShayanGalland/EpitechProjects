/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** my_defender
*/

#include <stdlib.h>
#include "my_defender_game.h"
#include "my_defender.h"
#include "main_menu_state.h"
#include "main_setting_state.h"
#include "main_rules_state.h"
#include "states.h"
#include <stdio.h>
#include "my_defender_game.h"

state_t *create_main_rules_state();
sfRenderWindow *create_render_window(int X, int Y, int resolution) {
    sfRenderWindow *renderWindow = NULL;
    sfVideoMode mode = {X, Y, resolution};

    renderWindow = sfRenderWindow_create
    (mode, "#####____MY_DEFENDER____#####", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(renderWindow, 60);
    return renderWindow;
}

void music()
{
    sfMusic *music = sfMusic_createFromFile("asset/musics/music2.ogg");
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    return (music);
}

sfSound *init_sound(char *sound_name)
{
    sfSound *sound = sfSound_create();
    sfSoundBuffer *sound_buff = sfSoundBuffer_createFromFile(sound_name);
    sfSound_setBuffer(sound, sound_buff);
    return (sound);
}

sfSound *inite(defender_state_t *defender_state)
{
    defender_state->assets_data = malloc(sizeof(assets_data_t));
}

int main(int argc, char **argv) {
    defender_state_t defender_state;
    sfColor clr = {255, 255, 255, 255};
    state_t *start_state = create_start_state();
    state_t *main_menu_state = create_main_menu_state();
    state_t *main_setting_state = create_main_setting_state();
    state_t *main_rules_state = create_main_rules_state();
    sfEvent event;
    state_t *current_state;
    map_t *map = create_map();
    int ret_code = 0;
    sfSound *swap = init_sound("asset/musics/swap.ogg");

    inite(&defender_state);
    music();
    defender_state.csfml_data = malloc(sizeof(csfml_data_t));
    defender_state.assets_data = malloc(sizeof(assets_data_t));
    defender_state.csfml_data->render_window = create_render_window
    (1920, 1080, 32);
    start_state->next[0] = start_state;
    start_state->next[0] = main_menu_state;
    current_state = start_state;
    sfRenderWindow_setFramerateLimit(defender_state.csfml_data->render_window, 60);
    while (sfRenderWindow_isOpen(defender_state.csfml_data->render_window)) {
        while (sfRenderWindow_pollEvent
        (defender_state.csfml_data->render_window, &event)) {
            if (event.type == sfEvtClosed  || current_state->quit == 1)
                sfRenderWindow_close(defender_state.csfml_data->render_window);
            else if (current_state->handle_event)
                current_state->handle_event(current_state, &event);
        }
        ret_code = current_state->run(current_state, &defender_state);
        if (ret_code != 0) {
            if (ret_code == GAME_PLAY) {
                sfSound_play(swap);
                my_defender(map, defender_state.csfml_data->render_window);
            }
            if (ret_code == HOW_TO_Play)
                current_state = main_rules_state;
            if (ret_code == SETTING)
                current_state = main_setting_state;
            if (ret_code == BACK)
                current_state = main_menu_state;
            if (ret_code == 1)
                current_state = current_state->next[current_state->ix_next];
            else if (ret_code == 0)
                current_state = current_state->previous
                [current_state->ix_previous];
            if (current_state->init)
                current_state->init(current_state, &defender_state);
        }
        sfRenderWindow_clear(defender_state.csfml_data->render_window, clr);
        if (current_state->draw_state)
            current_state->draw_state(current_state, &defender_state);
        if (current_state->draw_ui)
            current_state->draw_ui(current_state, &defender_state);
        sfRenderWindow_display(defender_state.csfml_data->render_window);
    }
    sfRenderWindow_destroy(defender_state.csfml_data->render_window);
    return 0;
}
