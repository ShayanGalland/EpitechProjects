/*
** EPITECH PROJECT, 2022
** setting
** File description:
** setting
*/

#include "main_rules_state.h"

void main_rules_stat_init_font(main_rules_state_data_t *main_rules_data)
{
    for (int i = 0; i < 2; i++) {
        main_rules_data->ui->text[i].text = sfText_create();
        main_rules_data->ui->text[i].font = sfFont_createFromFile
        ("asset/fonts/menu.ttf");
        sfText_setFont(main_rules_data->ui->text[i].text
        , main_rules_data->ui->text[i].font);
        sfText_setCharacterSize(main_rules_data->ui->
        text[i].text, 70);
        sfText_setFillColor(main_rules_data->ui->text[i].text
        , sfBlue);
        sfText_setOutlineThickness(main_rules_data->ui->text[i].text
        , 3);
        sfText_setFont(main_rules_data->ui->text[i].text
        , main_rules_data->ui->text[i].font);
    }
    sfText_setPosition(main_rules_data->ui->text[0].text, get_offset(1750, 910));
    sfText_setPosition(main_rules_data->ui->text[1].text, get_offset(40, 910));
    sfText_setString(main_rules_data->ui->text[0].text, "Quit");
    sfText_setString(main_rules_data->ui->text[1].text, "Back");
}

void inite_rect(main_rules_state_data_t *main_rules_state_data)
{
    main_rules_stat_init_font(main_rules_state_data);
    main_rules_state_data->ui->book.rect.top = 0;
    main_rules_state_data->ui->book.rect.left = 0;
    main_rules_state_data->ui->book.rect.height = 800;
    main_rules_state_data->ui->book.rect.width = 1024;
    main_rules_state_data->ui->bg.rect.top = 0;
    main_rules_state_data->ui->bg.rect.left = 0;
    main_rules_state_data->ui->bg.rect.height = 1080;
    main_rules_state_data->ui->bg.rect.width = 1920;
    main_rules_state_data->clock.clock = sfClock_create();
    sfSprite_setTextureRect(main_rules_state_data->ui->bg.sprite,
    main_rules_state_data->ui->bg.rect);
    sfSprite_setPosition(main_rules_state_data->ui->title.sprite, (sfVector2f) {750, 0});
    sfSprite_setPosition(main_rules_state_data->ui->book.sprite, (sfVector2f) {600, 170});
    sfSprite_setScale(main_rules_state_data->ui->title.sprite, get_offset(1.5, 1.5));
    sfSprite_setScale(main_rules_state_data->ui->book.sprite, get_offset(0.8, 0.8));
}

void inite_sprite(main_rules_state_data_t *main_rules_state_data)
{
    main_rules_state_data->ui->title.sprite = sfSprite_create();
    main_rules_state_data->ui->title.txtr =
    sfTexture_createFromFile("asset/background/title.png", NULL);
    sfSprite_setTexture(main_rules_state_data->ui->title.sprite
    , main_rules_state_data->ui->title.txtr, sfFalse);
    main_rules_state_data->ui->bg.sprite = sfSprite_create();
    main_rules_state_data->ui->bg.txtr =
    sfTexture_createFromFile("asset/background/bg_bleu.png", NULL);
    sfSprite_setTexture(main_rules_state_data->ui->bg.sprite
    , main_rules_state_data->ui->bg.txtr, sfFalse);
    main_rules_state_data->ui->book.sprite = sfSprite_create();
    main_rules_state_data->ui->book.txtr =
    sfTexture_createFromFile("asset/background/book.png", NULL);
    sfSprite_setTexture(main_rules_state_data->ui->book.sprite
    , main_rules_state_data->ui->book.txtr, sfFalse);
    inite_rect(main_rules_state_data);
}

void main_rules_state_init(state_t *state, defender_state_t *defender_state)
{
    main_rules_state_data_t *main_rules_state_data;

    if (state->init_done == 0) {
        main_rules_state_data->quit = 0;
        main_rules_state_data = malloc(sizeof(main_rules_state_data_t));
        main_rules_state_data->ui = create_ui_main_rules();
        main_rules_stat_init_font(main_rules_state_data);
        inite_sprite(main_rules_state_data);
        state->state_data = main_rules_state_data;
        state->init_done = 1;
    }
}

void main_rules_state_handle_event(state_t *state, sfEvent *event)
{
    main_rules_state_data_t *main_rules_data =
    ((main_rules_state_data_t *)state->state_data);

    for (int i = 0; i < 2; i++) {
        button_handle_event(main_rules_data->ui->buttons[i], event);
        if (main_rules_data->ui->buttons[1]->current_button_state == CLICKED)
            state->quit = 1;
    }
}

int main_rules_state_run(state_t *state, defender_state_t *defender_state)
{
    main_rules_state_data_t *main_rules_data =
    ((main_rules_state_data_t *)state->state_data);

    if (main_rules_data->ui->buttons[0]->current_button_state == CLICKED)
        return BACK;
    return NONE;
}

void main_rules_state_draw_ui(state_t *state, defender_state_t *defender_state)
{
    main_rules_state_data_t *main_rules_data = ((main_rules_state_data_t *)
    state->state_data);

    main_rules_data->clock.time = sfClock_getElapsedTime
    (main_rules_data->clock.clock);
    main_rules_data->clock.seconds = main_rules_data->
    clock.time.microseconds / 100000;
    if (main_rules_data->clock.seconds > 0.1) {
        sfClock_restart(main_rules_data->clock.clock);
        main_rules_data->ui->bg.rect = move_sprite
        (main_rules_data->ui->bg.rect, (3 * 1920), 1920);
        sfSprite_setTextureRect
        (main_rules_data->ui->bg.sprite, main_rules_data->ui->bg.rect);
    }
    sfRenderWindow_drawSprite(defender_state->csfml_data->
    render_window, main_rules_data->ui->bg.sprite, NULL);
    sfRenderWindow_drawSprite(defender_state->csfml_data->
    render_window, main_rules_data->ui->book.sprite, NULL);
    sfRenderWindow_drawSprite(defender_state->csfml_data->
    render_window, main_rules_data->ui->title.sprite, NULL);
    for (int i = 0; i < 2; i++)
        draw_button(defender_state->csfml_data->render_window
        , main_rules_data->ui->buttons[i]);
    for (int i = 0; i < 2; i++) {
        sfRenderWindow_drawText(defender_state->csfml_data->render_window
        , main_rules_data->ui->text[i].text, NULL);
    }
}

state_t *create_main_rules_state()
{
    state_t *main_rules_state = malloc(sizeof(state_t));

    main_rules_state->init_done = 0;
    main_rules_state->next = malloc(sizeof(state_t *) * 2);
    main_rules_state->ix_next = -1;
    main_rules_state->previous = NULL;
    main_rules_state->ix_previous = -1;
    main_rules_state->init = &main_rules_state_init;
    main_rules_state->end = 0;
    main_rules_state->handle_event = &main_rules_state_handle_event;
    main_rules_state->run = &main_rules_state_run;
    main_rules_state->draw_state = 0;
    main_rules_state->draw_ui = &main_rules_state_draw_ui;
    return main_rules_state;
}
