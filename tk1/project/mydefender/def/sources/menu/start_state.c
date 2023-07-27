/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** my_defender
*/

#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include "states.h"

void play_music(sfMusic *music, sfMusic *music2)
{
    if (music2 != NULL)
        sfMusic_stop(music2);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
}

void start_state_init(state_t *state, defender_state_t *defender_state)
{
    if (state->init_done == 0) {
        state->init_done = 1;
    }
    sfSound_play(defender_state->assets_data->sound[0].sound);
}

int start_state_run(state_t *state, defender_state_t *defender_state)
{
    return 1;
}

state_t *create_start_state()
{
    state_t *start_state = malloc(sizeof(state_t));

    start_state->init_done = 0;
    start_state->next = malloc(sizeof(state_t *));
    start_state->ix_next = 0;
    start_state->previous = NULL;
    start_state->ix_previous = -1;
    start_state->init = &start_state_init;
    start_state->end = 0;
    start_state->handle_event = 0;
    start_state->run = &start_state_run;
    start_state->draw_state = 0;
    start_state->draw_ui = 0;
    return start_state;
}