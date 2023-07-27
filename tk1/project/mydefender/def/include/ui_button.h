/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** my_defender
*/

#include "my_defender.h"

#ifndef _UI_BUTTON_H
    #define _UI_BUTTON_H

typedef enum {
    IDLE,
    HOVER,
    CLICKED
} ButtonState;

struct button_colors {
    sfColor idle_color;
    sfColor hover_color;
    sfColor clicked_color;
};
typedef struct button_colors button_colors_t;

struct button {
    sfRectangleShape *shape;
    sfText *label;
    ButtonState prev_button_state;
    ButtonState current_button_state;
    button_colors_t *colors;
};
typedef struct button button_t;

button_t *create_button
(sfVector2f position, sfVector2f size, button_colors_t *colors);
ButtonState button_handle_event(button_t *button, sfEvent *event);
void draw_button(sfRenderWindow *render_window, button_t *button);

#endif /* !_UI_BUTTON_H */