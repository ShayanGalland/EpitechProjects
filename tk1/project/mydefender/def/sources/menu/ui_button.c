/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** my_defender
*/

#include "ui_button.h"

button_t *create_button
(sfVector2f position, sfVector2f size, button_colors_t *colors)
{
    button_t *button = malloc(sizeof(button_t));

    button->colors = colors;
    button->shape = sfRectangleShape_create();
    sfRectangleShape_setFillColor(button->shape, colors->idle_color);
    sfRectangleShape_setPosition(button->shape, position);
    sfRectangleShape_setSize(button->shape, size);
    return button;
}

ButtonState button_handle_event(button_t *button, sfEvent *event)
{
    button->current_button_state = IDLE;
    switch (event->type) {
        case sfEvtMouseMoved: {
            sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->shape);
            if (sfFloatRect_contains
            (&rect, event->mouseMove.x, event->mouseMove.y) == sfTrue)
                button->current_button_state = HOVER;
        }
        break;
        case sfEvtMouseButtonPressed: {
            if (event->mouseButton.button == sfMouseLeft) {
                sfFloatRect rect = sfRectangleShape_getGlobalBounds
                (button->shape);
                if (sfFloatRect_contains
                (&rect, event->mouseButton.x, event->mouseButton.y) == sfTrue)
                    button->current_button_state = CLICKED;
            }
        }
        break;
    }
}

void draw_button(sfRenderWindow *render_window, button_t *button)
{
    switch (button->current_button_state) {
        case IDLE:
            sfRectangleShape_setFillColor
            (button->shape, button->colors->idle_color);
            break;
        case HOVER:
            sfRectangleShape_setFillColor
            (button->shape, button->colors->hover_color);
            break;
        case CLICKED:
            sfRectangleShape_setFillColor
            (button->shape, button->colors->clicked_color);
            break;
    }
    sfRenderWindow_drawRectangleShape(render_window, button->shape, NULL);
}
