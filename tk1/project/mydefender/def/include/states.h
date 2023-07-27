/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** my_defender
*/

#include "my_defender.h"
#include "start_state.h"
#include "scores_state.h"

#ifndef _STATE_H_
    #define _STATE_H_

//#define PREVIOUS_STATE -1
//#define NEXT_STATE 1
#define NONE -1
#define BACK 10
#define PLAY 30
#define HOW_TO_Play 40
#define SETTING 50
#define GAME_PLAY 60

struct clock_s {
    sfClock *clock;
    sfTime time;
    float seconds;
};
typedef struct clock_s my_clock_t;

typedef struct state_s state_t;
struct state_s {
    state_t **next;
    state_t **previous;
    int init_done;
    int ix_next;
    int ix_previous;
    void (*init)(state_t*, defender_state_t*);
    void (*end)(state_t*, defender_state_t*);
    void (*handle_event)(state_t*, sfEvent*);
    int (*run)(state_t*, defender_state_t*);
    void (*draw_state)(state_t*, defender_state_t*);
    void (*draw_ui)(state_t*, defender_state_t*);
    void *state_data;
    int quit;
};

#endif /* ! _STATE_H_ */
