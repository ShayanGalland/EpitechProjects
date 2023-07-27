#include "functions.h"

#define DUCK_X_SECOND 100
#define DUCK_Y_SECOND 10

#define MAX_DUCK_X_SECOND 100
#define MAX_DUCK_Y_SECOND 100
#define DUCK_ANIMATION_FRAME_SECOND 6

#define MAX_DUCK 10

unsigned int generate_random_number(int minInterval, int maxInterval)
{
    return rand() %     ((maxInterval + 1) - minInterval) + minInterval;
}

sfVector2f generate_random_point(float x)
{
    sfVector2f point;
    point.x = x;
    point.y = generate_random_number(2, 8) * 60;
    return point;
}
sfVector2f normalize_vector(sfVector2f start, sfVector2f end)
{
    sfVector2f norm;
    norm.x = end.x - start.x;
    norm.y = end.y - start.y;

    // normalize vector
    float length = sqrt(norm.x * norm.x + norm.y * norm.y);
    norm.x /= length;
    norm.y /= length;
    return norm;
}

Duck *create_duck()
{
    Duck *duck = malloc(sizeof(Duck));
    char* textures[2] = { "assets/duck-blue.png", "assets/duck-red.png"};

    duck->texture = create_texture(textures[generate_random_number(0,1)]);
    duck->sprite = create_sprite(duck->texture);

    sfVector2f scale;
    scale.x = scale.y = 1;
    sfSprite_setScale(duck->sprite, scale);

    sfVector2f start = generate_random_point(0);
    sfSprite_setPosition(duck->sprite, start);

    sfVector2f arrival = generate_random_point(800);
    duck->norm = normalize_vector(start, arrival);

    init_animation(duck);

    duck->x_speed = generate_random_number(50, MAX_DUCK_X_SECOND);
    duck->y_speed = generate_random_number(50, MAX_DUCK_Y_SECOND);

    float angle = (float)180 * (atan2(duck->norm.y, duck->norm.x)) / M_PI;
    sfSprite_setRotation(duck->sprite, angle);
    return duck;
}

void update_duck(Duck *duck, float elapsed)
{
    sfVector2f offset;
    offset.x = duck->norm.x * duck->x_speed * elapsed;
    offset.y = duck->norm.y * duck->y_speed * elapsed;
    sfSprite_move(duck->sprite, offset);

    duck->next_frame_time = duck->next_frame_time - (elapsed * 1000);
    if (duck->next_frame_time <= 0) {
        animation_next_frame(duck);
        duck->next_frame_time = 1000 / DUCK_ANIMATION_FRAME_SECOND;
    }
}
void render_duck(sfRenderWindow *window, Duck *duck)
{
    sfRenderWindow_drawSprite(window, duck->sprite, NULL);
}

void init_animation(Duck *duck)
{
    duck->current_frame = 1;
    duck->frame_interval = 110;
    duck->max_frame = 3;
    duck->next_frame_time = 1000 / DUCK_ANIMATION_FRAME_SECOND;
    set_animation_frame(duck->current_frame, duck);
}
void set_animation_frame(int frame, Duck *duck)
{
    sfIntRect rect;
    rect.left = duck->frame_interval * frame - duck->frame_interval;
    rect.top = 0;
    rect.height = duck->frame_interval;
    rect.width = duck->frame_interval;
    sfSprite_setTextureRect(duck->sprite, rect);
}
void animation_next_frame(Duck *duck)
{
    if (duck->current_frame >= duck->max_frame)
        duck->current_frame = 1;
    else
        duck->current_frame++;
    set_animation_frame(duck->current_frame, duck);
}
