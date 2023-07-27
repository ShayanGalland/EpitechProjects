/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** my_defender
*/

#ifndef _SETTING_STATE_H_
    #define _SETTING_STATE_H_

#include "states.h"
#include "ui.h"

struct main_setting_state_data {
    my_clock_t clock;
    main_setting_ui_t *ui;
    int quit;
};
typedef struct main_setting_state_data main_setting_state_data_t;
sfVector2f get_offset(float x, float y);
sfIntRect move_sprite(sfIntRect rect, int max_value, int incrementaion);
state_t *create_main_setting_state();
void main_setting_state_init(state_t *state, defender_state_t *defender_state);
void main_setting_state_end(state_t *state, defender_state_t *defender_state);
void main_setting_state_handle_event(state_t *state, sfEvent *event);
int main_setting_state_run(state_t *state, defender_state_t *defender_state);
void main_setting_state_draw_state
(state_t *state, defender_state_t *defender_state);
void main_setting_state_draw_ui
(state_t *state, defender_state_t *defender_state);

#endif /* !_SETTING_STATE_H_ */
