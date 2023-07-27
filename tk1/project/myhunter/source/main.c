#include "functions.h"

#define DUCK_X_SECOND 100
#define DUCK_Y_SECOND 10

#define MAX_DUCK_X_SECOND 100
#define MAX_DUCK_Y_SECOND 100
#define DUCK_ANIMATION_FRAME_SECOND 6
#define MAX_DUCK 10

sfRenderWindow *create_render_window(int X, int Y, int resolution)
{
    sfRenderWindow *renderWindow = NULL;
    sfVideoMode mode = {X, Y, resolution};
    renderWindow = sfRenderWindow_create(mode, "fenetre", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(renderWindow, 120);
    return renderWindow;
}

struct GameState
{
    sfClock *game_clock;
    Duck *ducks[MAX_DUCK];

    int score;

    int shoot_x;
    int shoot_y;
};

typedef struct GameState GameState;

GameState *create_gamestate(int X, int Y)
{
    GameState *gameState = malloc(sizeof(GameState));
    gameState->game_clock = sfClock_create();

    for (int i = 0; i < MAX_DUCK; i++)
        gameState->ducks[i] = create_duck();

    gameState->shoot_x = -1;
    gameState->shoot_y = -1;

    return gameState;
}

void free_duck_struct(Duck *duck)
{
    sfTexture_destroy(duck->texture);
    sfSprite_destroy(duck->sprite);
    free(duck);
}

void handle_shoot(GameState *game_state)
{
    if (game_state->shoot_x > 0 && game_state->shoot_y > 0) {
        for (int i = 0; i < MAX_DUCK; i++) {
            if (game_state->ducks[i] != NULL) {
                sfFloatRect bounding_box = sfSprite_getGlobalBounds(game_state->ducks[i]->sprite);
                if (sfFloatRect_contains(&bounding_box, game_state->shoot_x, game_state->shoot_y)) {
                    free_duck_struct(game_state->ducks[i]);
                    game_state->ducks[i] = NULL;

                    game_state->shoot_x = -1;
                    game_state->shoot_y = -1;
                    game_state->score++;
                    break;
                }
            }
        }
    }
}

void update_game_state_ducks(GameState *game_state, float elapsed)
{
    for (int i = 0; i < MAX_DUCK; i++) {
        if (game_state->ducks[i] != NULL)
            update_duck(game_state->ducks[i], elapsed);
    }
}

void update_game_state_create_ducks(GameState *game_state, float elapsed)
{
    int duck_created = 0;
    for (int i = 0; i < MAX_DUCK; i++)
    {
        if (!game_state->ducks[i])
        {
            game_state->ducks[i] = create_duck();
            duck_created++;
        }

        if (duck_created > 2)
        {
            break;
        }
    }
}

void update_game_state_handle_oos_ducks(GameState *game_state){
    for (int i = 0; i < MAX_DUCK; i++) {
        sfVector2f pos = sfSprite_getPosition(game_state->ducks[i]->sprite);
        if (pos.x > 800 || pos.y > 600) {
            free_duck_struct(game_state->ducks[i]);
            game_state->ducks[i] = NULL;
        }
    }
}

void update_game_state(GameState *game_state, float elapsed)
{
    // handle shoot
    handle_shoot(game_state);

    // Update ducks
    update_game_state_ducks(game_state, elapsed);

    // Add new ducks
    update_game_state_create_ducks(game_state, elapsed);

    // Handle ducks on out of screen
    update_game_state_handle_oos_ducks(game_state);
}

void shoot(GameState *game_state, int x, int y)
{
    game_state->shoot_x = x;
    game_state->shoot_y = y;
}

void render_game_state(sfRenderWindow* render_window, GameState *game_state)
{
    for (int i = 0; i < MAX_DUCK; i++) {
        if (game_state->ducks[i] != NULL) {
            render_duck(render_window, game_state->ducks[i]);
        }
    }
}

void handle_event(sfRenderWindow *renderWindow, GameState *game_state){
    sfEvent event;
    while (sfRenderWindow_pollEvent(renderWindow, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(renderWindow);

        if (event.type == sfEvtMouseButtonPressed) {
            shoot(game_state, event.mouseButton.x, event.mouseButton.y);
            break;
        }
    }
}

int main(int argc, char **argv)
{
    srand(time(0));

    int X = 800;
    int Y = 600;
    int resolution = 32;
    sfRenderWindow *renderWindow = create_render_window(X, Y, resolution);
    GameState *gameState = create_gamestate(X, Y);

    while (sfRenderWindow_isOpen(renderWindow)) {
        float elapsed = sfTime_asSeconds(sfClock_restart(gameState->game_clock));
        handle_event(renderWindow, gameState);
        update_game_state(gameState, elapsed);
        sfRenderWindow_clear(renderWindow, sfColor_fromRGB(0, 255, 0));
        render_game_state(renderWindow, gameState);
        sfRenderWindow_display(renderWindow);
    }

    return 0;
}
