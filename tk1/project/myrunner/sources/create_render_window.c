/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** project in c
*/
#include "function.h"

sfRenderWindow *create_render_window(int X, int Y, int resolution)
{
    sfRenderWindow *renderWindow = NULL;
    sfVideoMode mode = {X, Y, resolution};
    renderWindow = sfRenderWindow_create(mode, "fenetre", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(renderWindow, 200);
    return renderWindow;
}
