/*
** EPITECH PROJECT, 2022
** setting
** File description:
** setting
*/

#include "main_setting_state.h"

void main_setting_stat_init_font(main_setting_state_data_t *main_setting_data)
{
    for (int i = 0; i < 11; i++) {
        main_setting_data->ui->text[i].text = sfText_create();
        main_setting_data->ui->text[i].font = sfFont_createFromFile
        ("asset/fonts/menu.ttf");
        sfText_setFont(main_setting_data->ui->text[i].text
        , main_setting_data->ui->text[i].font);
        sfText_setCharacterSize(main_setting_data->ui->
        text[i].text, 70);
        sfText_setFillColor(main_setting_data->ui->text[i].text
        , sfBlue);
        sfText_setOutlineThickness(main_setting_data->ui->text[i].text
        , 3);
        sfText_setFont(main_setting_data->ui->text[i].text
        , main_setting_data->ui->text[i].font);
    }
    sfText_setPosition(main_setting_data->ui->text[0].text, get_offset(1750, 910));
    sfText_setPosition(main_setting_data->ui->text[1].text, get_offset(40, 910));
    sfText_setPosition(main_setting_data->ui->text[2].text, get_offset(1740, 480));
    sfText_setPosition(main_setting_data->ui->text[3].text, get_offset(120, 500));
    sfText_setPosition(main_setting_data->ui->text[4].text, get_offset(355, 500));
    sfText_setPosition(main_setting_data->ui->text[5].text, get_offset(590, 500));
    sfText_setPosition(main_setting_data->ui->text[6].text, get_offset(540, 700));
    sfText_setPosition(main_setting_data->ui->text[7].text, get_offset(1200, 700));
    sfText_setPosition(main_setting_data->ui->text[8].text, get_offset(865, 700));
    sfText_setPosition(main_setting_data->ui->text[9].text, get_offset(1450, 500));
    sfText_setPosition(main_setting_data->ui->text[10].text, get_offset(1298, 490));
    sfText_setString(main_setting_data->ui->text[0].text, "Quit");
    sfText_setString(main_setting_data->ui->text[1].text, "Back");
    sfText_setString(main_setting_data->ui->text[2].text, "+");
    sfText_setString(main_setting_data->ui->text[3].text, "30");
    sfText_setString(main_setting_data->ui->text[4].text, "60");
    sfText_setString(main_setting_data->ui->text[5].text, "120");
    sfText_setString(main_setting_data->ui->text[6].text, "Music 1");
    sfText_setString(main_setting_data->ui->text[7].text, "Music 3");
    sfText_setString(main_setting_data->ui->text[8].text, "Music 2");
    sfText_setString(main_setting_data->ui->text[9].text, "Mute");
    sfText_setString(main_setting_data->ui->text[10].text, "-");
}

void inite_rect_volume(main_setting_state_data_t *main_setting_state_data)
{
    main_setting_stat_init_font(main_setting_state_data);
    main_setting_state_data->ui->level_sound = 10;
    main_setting_state_data->ui->nbr_frames = 60;
    main_setting_state_data->ui->volume_level.rect.top = 0;
    main_setting_state_data->ui->volume_level.rect.left =  7968 - (498 * 10);
    main_setting_state_data->ui->volume_level.rect.height = 498;
    main_setting_state_data->ui->volume_level.rect.width = 498;
    main_setting_state_data->ui->music.rect.top = 0;
    main_setting_state_data->ui->music.rect.left = 0;
    main_setting_state_data->ui->music.rect.height = 480;
    main_setting_state_data->ui->music.rect.width = 480;
    main_setting_state_data->ui->frame.rect.top = 0;
    main_setting_state_data->ui->frame.rect.left = 497;
    main_setting_state_data->ui->frame.rect.height = 497;
    main_setting_state_data->ui->frame.rect.width = 497;
    main_setting_state_data->ui->bg.rect.top = 0;
    main_setting_state_data->ui->bg.rect.left = 0;
    main_setting_state_data->ui->bg.rect.height = 1080;
    main_setting_state_data->ui->bg.rect.width = 1920;
    sfSprite_setPosition(main_setting_state_data->ui->music.sprite, (sfVector2f) {715, 250});
    sfSprite_setPosition(main_setting_state_data->ui->frame.sprite, (sfVector2f) {155, 50});
    sfSprite_setPosition(main_setting_state_data->ui->volume_level.sprite, (sfVector2f) {1280, 50});
    sfSprite_setTextureRect(main_setting_state_data->ui->music.sprite
    , main_setting_state_data->ui->music.rect);
    sfSprite_setTextureRect(main_setting_state_data->ui->frame.sprite
    , main_setting_state_data->ui->frame.rect);
    sfSprite_setTextureRect(main_setting_state_data->ui->volume_level.sprite
    , main_setting_state_data->ui->volume_level.rect);
    sfSprite_setTextureRect(main_setting_state_data->ui->bg.sprite
    , main_setting_state_data->ui->bg.rect);
}

void inite_voume(main_setting_state_data_t *main_setting_state_data)
{
    main_setting_state_data->ui->bg.sprite = sfSprite_create();
    main_setting_state_data->ui->bg.txtr =
    sfTexture_createFromFile("asset/background/bg_red.png", NULL);
    sfSprite_setTexture(main_setting_state_data->ui->bg.sprite
    , main_setting_state_data->ui->bg.txtr, sfFalse);
    main_setting_state_data->ui->volume_level.sprite = sfSprite_create();
    main_setting_state_data->ui->volume_level.txtr = sfTexture_createFromFile
    ("asset/background/volume_level.png", NULL);
    sfSprite_setTexture(main_setting_state_data->ui->volume_level.sprite
    , main_setting_state_data->ui->volume_level.txtr, sfFalse);
    main_setting_state_data->ui->music.sprite = sfSprite_create();
    main_setting_state_data->ui->frame.sprite = sfSprite_create();
    main_setting_state_data->ui->music.txtr = sfTexture_createFromFile
    ("asset/background/music.png", NULL);
    main_setting_state_data->ui->frame.txtr = sfTexture_createFromFile
    ("asset/background/frame.png", NULL);
    sfSprite_setTexture(main_setting_state_data->ui->music.sprite
    , main_setting_state_data->ui->music.txtr, sfFalse);
    sfSprite_setTexture(main_setting_state_data->ui->frame.sprite
    , main_setting_state_data->ui->frame.txtr, sfFalse);
    inite_rect_volume(main_setting_state_data);
}

void main_setting_state_init(state_t *state, defender_state_t *defender_state)
{
    main_setting_state_data_t *main_setting_state_data;

    if (state->init_done == 0) {
        main_setting_state_data->quit = 0;
        main_setting_state_data = malloc(sizeof(main_setting_state_data_t));
        main_setting_state_data->ui = create_ui_main_setting();
        inite_voume(main_setting_state_data);
        state->state_data = main_setting_state_data;
        state->init_done = 1;
    }
    sfRenderWindow_setFramerateLimit(defender_state->csfml_data->render_window
    , 2);//main_setting_state_data->ui->nbr_frames);
}

void main_setting_state_handle_event(state_t *state, sfEvent *event)
{
    main_setting_state_data_t *main_setting_data =
    ((main_setting_state_data_t *)state->state_data);

    for (int i = 0; i < 11; i++)
        button_handle_event(main_setting_data->ui->buttons[i], event);
    if (main_setting_data->ui->buttons[1]->current_button_state == CLICKED)
        state->quit = 1;
    if (main_setting_data->ui->buttons[3]->current_button_state == CLICKED){
        main_setting_data->ui->frame.rect.left = 0;
        main_setting_data->ui->nbr_frames = 30;
    }
    if (main_setting_data->ui->buttons[4]->current_button_state == CLICKED) {
        main_setting_data->ui->frame.rect.left = 497;
        main_setting_data->ui->nbr_frames = 60;
    }
    if (main_setting_data->ui->buttons[5]->current_button_state == CLICKED){
        main_setting_data->ui->frame.rect.left = 497 * 2;
        main_setting_data->ui->nbr_frames = 120;
    }
    if (main_setting_data->ui->buttons[9]->current_button_state == CLICKED)
        main_setting_data->ui->level_sound = 0;
    if (main_setting_data->ui->buttons[2]->current_button_state == CLICKED) {
        if (main_setting_data->ui->level_sound != 16)
            main_setting_data->ui->level_sound++;
    }
    if (main_setting_data->ui->buttons[10]->current_button_state == CLICKED) {
        if (main_setting_data->ui->level_sound != 0)
            main_setting_data->ui->level_sound--;
    }
    main_setting_data->ui->volume_level.rect.left =  7968 - (498 * main_setting_data->ui->level_sound);
    sfSprite_setTextureRect(main_setting_data->ui->volume_level.sprite
    , main_setting_data->ui->volume_level.rect);
    sfSprite_setTextureRect(main_setting_data->ui->frame.sprite
    , main_setting_data->ui->frame.rect);
    sfSprite_setTextureRect(main_setting_data->ui->music.sprite
    , main_setting_data->ui->music.rect);
}

int main_setting_state_run(state_t *state, defender_state_t *defender_state)
{
    main_setting_state_data_t *main_setting_data =
    ((main_setting_state_data_t *)state->state_data);

    if (main_setting_data->ui->buttons[0]->current_button_state == CLICKED)
        return (BACK);
    if (main_setting_data->ui->buttons[6]->current_button_state == CLICKED)
        main_setting_data->ui->music.rect.left = 0;
    if (main_setting_data->ui->buttons[7]->current_button_state == CLICKED)
        main_setting_data->ui->music.rect.left = 497 * 2;
    if (main_setting_data->ui->buttons[8]->current_button_state == CLICKED)
        main_setting_data->ui->music.rect.left = 497;
    return NONE;
}

void main_setting_state_draw_ui(state_t *state, defender_state_t *defender_state)
{
    main_setting_state_data_t *main_setting_data = ((main_setting_state_data_t *)
    state->state_data);

    main_setting_data->clock.time = sfClock_getElapsedTime
    (main_setting_data->clock.clock);
    main_setting_data->clock.seconds = main_setting_data->
    clock.time.microseconds / 100000;
    if (main_setting_data->clock.seconds > 0.1) {
        sfClock_restart(main_setting_data->clock.clock);
        main_setting_data->ui->bg.rect = move_sprite
        (main_setting_data->ui->bg.rect, (3 * 1920), 1920);
        sfSprite_setTextureRect
        (main_setting_data->ui->bg.sprite, main_setting_data->ui->bg.rect);
    }
    sfRenderWindow_drawSprite(defender_state->csfml_data->
    render_window, main_setting_data->ui->bg.sprite, NULL);
    sfRenderWindow_drawSprite(defender_state->csfml_data->
    render_window, main_setting_data->ui->volume_level.sprite, NULL);
    sfRenderWindow_drawSprite(defender_state->csfml_data->
    render_window, main_setting_data->ui->music.sprite, NULL);
    sfRenderWindow_drawSprite(defender_state->csfml_data->
    render_window, main_setting_data->ui->frame.sprite, NULL);
    for (int i = 0; i < 11; i++)
        draw_button(defender_state->
        csfml_data->render_window, main_setting_data->ui->buttons[i]);
    for (int i = 0; i < 11; i++) {
        sfRenderWindow_drawText(defender_state->csfml_data->render_window
        , main_setting_data->ui->text[i].text, NULL);
    }
}

state_t *create_main_setting_state()
{
    state_t *main_setting_state = malloc(sizeof(state_t));

    main_setting_state->init_done = 0;
    main_setting_state->next = malloc(sizeof(state_t*) * 2);
    main_setting_state->ix_next = -1;
    main_setting_state->previous = NULL;
    main_setting_state->ix_previous = -1;
    main_setting_state->init = &main_setting_state_init;
    main_setting_state->end = 0;
    main_setting_state->handle_event = &main_setting_state_handle_event;
    main_setting_state->run = &main_setting_state_run;
    main_setting_state->draw_state = 0;
    main_setting_state->draw_ui = &main_setting_state_draw_ui;
    return main_setting_state;
}
