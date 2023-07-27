#ifndef _GAME_OBJECTS_H
#define _GAME_OBJECTS_H

#include "SFML/Graphics.h"

#define MAX_DUCK_X_SECOND 100
#define MAX_DUCK_Y_SECOND 100
#define DUCK_ANIMATION_FRAME_SECOND 6

struct Duck
{
    // Sprite
    sfTexture *texture;
    sfSprite *sprite;

    // Animation data
    int frame_interval;
    int current_frame;
    int max_frame;
    int next_frame_time;

    int x_speed;
    int y_speed;
    sfVector2f norm;
    sfIntRect rect;
};
typedef struct Duck Duck;

Duck *create_duck();

void update_duck(Duck *duck, float elapsed);
void render_duck(sfRenderWindow *window, Duck *duck);

void init_animation(Duck * duck);
void animation_next_frame(Duck *duck);
void set_animation_frame(int frame, Duck *duck);

#endif