/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** my_defender
*/

#ifndef _START_STATE_H
    #define _START_STATE_H

#include "states.h"

state_t *create_start_state();

void start_state_init(state_t *state, defender_state_t *defender_state);
void start_state_end(state_t *state, defender_state_t *defender_state);
void start_state_handle_event(state_t *state, sfEvent *event);
int start_state_run(state_t *state, defender_state_t *defender_state);
void start_state_draw_state(state_t *state, defender_state_t *defender_state);
void start_state_draw_ui(state_t *state, defender_state_t *defender_state);

#endif /* !_START_STATE_H */