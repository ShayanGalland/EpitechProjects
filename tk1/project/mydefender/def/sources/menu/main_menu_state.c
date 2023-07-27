/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** my_defendr
*/

#include "main_menu_state.h"

sfVector2f get_offset(float x, float y)
{
    sfVector2f offset;

    offset.x = x;
    offset.y = y;
    return offset;
}

void main_menu_stat_init_font(state_t *state, defender_state_t *defender_state
, main_menu_state_data_t *main_menu_state_data)
{
    for (int i = 0; i < 4; i++) {
        defender_state->assets_data->text_bg[i].text = sfText_create();
        defender_state->assets_data->text_bg[i].font = sfFont_createFromFile
        ("asset/fonts/menu.ttf");
        sfText_setFont(defender_state->assets_data->text_bg[i].text
        , defender_state->assets_data->text_bg[i].font);
        sfText_setCharacterSize(defender_state->assets_data->
        text_bg[i].text, 70);
        sfText_setFillColor(defender_state->assets_data->text_bg[i].text
        , sfBlue);
        sfText_setOutlineThickness(defender_state->assets_data->text_bg[i].text
        , 3);
        sfText_setFont(defender_state->assets_data->text_bg[i].text
        , defender_state->assets_data->text_bg[i].font);
    }
    sfText_setPosition
    (defender_state->assets_data->text_bg[0].text, get_offset(710, 480));
    sfText_setString(defender_state->assets_data->text_bg[0].text, "Play");
    sfText_setPosition
    (defender_state->assets_data->text_bg[1].text, get_offset(710, 580));
    sfText_setString(defender_state->assets_data->text_bg[1].
    text, "How to play");
    sfText_setPosition
    (defender_state->assets_data->text_bg[2].text, get_offset(710, 680));
    sfText_setString(defender_state->assets_data->text_bg[2].text, "Setting");
    sfText_setPosition
    (defender_state->assets_data->text_bg[3].text, get_offset(710, 780));
    sfText_setString(defender_state->assets_data->text_bg[3].text, "Quit");
}

void main_menu_state_init(state_t *state, defender_state_t *defender_state)
{
    main_menu_state_data_t *main_menu_state_data;

    if (state->init_done == 0) {
        state->init_done = 1;
        main_menu_state_data->quit = 0;
        main_menu_state_data = malloc(sizeof(main_menu_state_data_t));
        main_menu_state_data->ui = create_ui_main_menu();
        state->state_data = main_menu_state_data;
        state->init_done = 1;
        main_menu_state_data->ui->bg.sprite = sfSprite_create();
        main_menu_state_data->ui->bg.txtr = sfTexture_createFromFile
        ("asset/background/bg0.png", NULL);
        main_menu_state_data->ui->bg.rect.top = 0;
        main_menu_state_data->ui->bg.rect.left = 0;
        main_menu_state_data->ui->bg.rect.height = 1080;
        main_menu_state_data->ui->bg.rect.width = 1920;
        main_menu_state_data->clock.clock = sfClock_create();
        main_menu_stat_init_font(state, defender_state, main_menu_state_data);
        sfSprite_setTextureRect(main_menu_state_data->ui->bg.sprite,
        main_menu_state_data->ui->bg.rect);
        sfSprite_setTexture(main_menu_state_data->ui->bg.sprite,
        main_menu_state_data->ui->bg.txtr, sfFalse);
    }
}

void main_menu_state_handle_event(state_t *state, sfEvent *event)
{
    main_menu_state_data_t *main_menu_data = ((main_menu_state_data_t *)
    state->state_data);

    for (int i = 0; i < 5; i++) {
        button_handle_event(main_menu_data->ui->buttons[i], event);
        if (main_menu_data->ui->buttons[3]->current_button_state == CLICKED)
            state->quit = 1;
    }
}

int main_menu_state_run(state_t *state, defender_state_t *defender_state)
{
    main_menu_state_data_t *main_menu_data = ((main_menu_state_data_t *)
    state->state_data);

    if (main_menu_data->ui->buttons[0]->current_button_state == CLICKED)
        main_menu_data->quit = 1;
    if (main_menu_data->ui->buttons[1]->current_button_state == CLICKED)
        return HOW_TO_Play;
    if (main_menu_data->ui->buttons[2]->current_button_state == CLICKED)
        return SETTING;
    if (main_menu_data->ui->buttons[0]->current_button_state == CLICKED)
        return GAME_PLAY;
    return NONE;
}

sfIntRect move_sprite(sfIntRect rect, int max_value, int incrementaion)
{
    rect.left += incrementaion;
    if (rect.left >= max_value) {
        rect.left = 0;
    }
    return (rect);
}

void main_menu_state_draw_ui(state_t *state, defender_state_t *defender_state)
{
    main_menu_state_data_t *main_menu_data = ((main_menu_state_data_t *)
    state->state_data);
    main_menu_data->clock.time = sfClock_getElapsedTime
    (main_menu_data->clock.clock);
    main_menu_data->clock.seconds = main_menu_data->
    clock.time.microseconds / 100000;
    if (main_menu_data->clock.seconds > 0.1) {
        sfClock_restart(main_menu_data->clock.clock);
        main_menu_data->ui->bg.rect = move_sprite
        (main_menu_data->ui->bg.rect, (8 * 1920), 1920);
        sfSprite_setTextureRect
        (main_menu_data->ui->bg.sprite, main_menu_data->ui->bg.rect);
    }
    sfRenderWindow_drawSprite(defender_state->csfml_data->
    render_window, main_menu_data->ui->bg.sprite, NULL);
    for (int i = 0; i < 4; i++)
        draw_button(defender_state->
        csfml_data->render_window, main_menu_data->ui->buttons[i]);
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawText(defender_state->csfml_data->render_window
        , defender_state->assets_data->text_bg[i].text, NULL);
    }
}

state_t *create_main_menu_state()
{
    state_t *main_menu_state = malloc(sizeof(state_t));

    main_menu_state->init_done = 0;
    main_menu_state->next = malloc(sizeof(state_t *) * 2);
    main_menu_state->ix_next = 0;
    main_menu_state->previous = NULL;
    main_menu_state->ix_previous = 0;
    main_menu_state->init = &main_menu_state_init;
    main_menu_state->end = 0;
    main_menu_state->handle_event = &main_menu_state_handle_event;
    main_menu_state->run = &main_menu_state_run;
    main_menu_state->draw_state = 0;
    main_menu_state->draw_ui = &main_menu_state_draw_ui;
    return main_menu_state;
}
