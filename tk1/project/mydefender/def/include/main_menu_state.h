/*
** EPITECH PROJECT, 2022
** mydefender
** File description:
** mydefender
*/

#ifndef _MAIN_MENU_STATE_H
    #define _MAIN_MENU_STATE_H

#include "states.h"
#include "ui.h"

struct main_menu_state_data {
    my_clock_t clock;
    main_menu_ui_t *ui;
    int quit;
};
typedef struct main_menu_state_data main_menu_state_data_t;

state_t *create_main_menu_state();
void main_menu_state_init(state_t *state, defender_state_t *defender_state);
void main_menu_state_end(state_t *state, defender_state_t *defender_state);
void main_menu_state_handle_event(state_t *state, sfEvent *event);
int main_menu_state_run(state_t *state, defender_state_t *defender_state);
void main_menu_state_draw_state
(state_t *state, defender_state_t *defender_state);
void main_menu_state_draw_ui
(state_t *state, defender_state_t *defender_state);

#endif /* !_MAIN_MENU_STATE_H */