/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** my_defender
*/

#include "ui.h"

main_menu_ui_t *create_ui_main_menu()
{
    main_menu_ui_t *ui = malloc(sizeof(main_menu_ui_t));
    sfVector2f size = {600, 75};
    sfVector2f pos2 = {690, 600};
    sfVector2f pos3 = {690, 700};
    sfVector2f pos4 = {690, 800};
    sfVector2f pos5 = {0, 0};
    sfColor idle_color = {147,112,219, 255};
    sfColor hover_color = {0, 255, 0, 255};
    sfColor clicked_color = {0, 0, 255, 255};

    ui->colors = malloc(sizeof(button_colors_t));
    ui->colors->idle_color = idle_color;
    ui->colors->hover_color = hover_color;
    ui->colors->clicked_color = clicked_color;
    ui->buttons[0] = create_button((sfVector2f) {690, 500}, size, ui->colors);
    ui->buttons[1] = create_button(pos2, size, ui->colors);
    ui->buttons[2] = create_button(pos3, size, ui->colors);
    ui->buttons[3] = create_button(pos4, size, ui->colors);
    ui->buttons[4] = create_button(pos5, (sfVector2f) {200, 75}, ui->colors);
    return ui;
}

main_setting_ui_t *create_ui_main_setting()
{
    main_setting_ui_t *ui = malloc(sizeof(main_setting_ui_t));
    sfVector2f size = {200, 75};
    sfColor idle_color = {147,112,219, 255};
    sfColor hover_color = {0, 255, 0, 255};
    sfColor clicked_color = {0, 0, 255, 255};

    ui->colors = malloc(sizeof(button_colors_t));
    ui->colors->idle_color = idle_color;
    ui->colors->hover_color = hover_color;
    ui->colors->clicked_color = clicked_color;
    ui->buttons[0] = create_button((sfVector2f) {0, 910}, size, ui->colors);
    ui->buttons[1] = create_button((sfVector2f) {1720, 910}, size, ui->colors);
    ui->buttons[2] = create_button((sfVector2f) {1660, 500}, size, ui->colors);
    ui->buttons[3] = create_button((sfVector2f) {60, 500}, size, ui->colors);
    ui->buttons[4] = create_button((sfVector2f) {300, 500}, size, ui->colors);
    ui->buttons[5] = create_button((sfVector2f) {540, 500}, size, ui->colors);
    ui->buttons[6] = create_button((sfVector2f) {540, 700}, size, ui->colors);
    ui->buttons[7] = create_button((sfVector2f) {1200, 700}, size, ui->colors);
    ui->buttons[8] = create_button((sfVector2f) {865, 700}, size, ui->colors);
    ui->buttons[9] = create_button((sfVector2f) {1430, 500}, size, ui->colors);
    ui->buttons[10] = create_button((sfVector2f) {1200, 500}, size, ui->colors);
    return ui;
}

main_rules_ui_t *create_ui_main_rules()
{
    main_rules_ui_t *ui = malloc(sizeof(main_rules_ui_t));
    sfVector2f size = {200, 75};
    sfColor idle_color = {147,112,219, 255};
    sfColor hover_color = {0, 255, 0, 255};
    sfColor clicked_color = {0, 0, 255, 255};

    ui->colors = malloc(sizeof(button_colors_t));
    ui->colors->idle_color = idle_color;
    ui->colors->hover_color = hover_color;
    ui->colors->clicked_color = clicked_color;
    ui->buttons[0] = create_button((sfVector2f) {0, 910}, size, ui->colors);
    ui->buttons[1] = create_button((sfVector2f) {1720, 910}, size, ui->colors);
    return ui;
}

//scores_ui_t *create_ui_scores()
//{
//    scores_ui_t *scores_ui = malloc(sizeof(scores_ui_t));
//
//    return scores_ui;
//}

scores_ui_t *create_ui_scores()
{
    scores_ui_t *scores_ui = malloc(sizeof(scores_ui_t));

    return scores_ui;
}

game_ui_t *create_ui_game()
{
    game_ui_t *game_ui = malloc(sizeof(game_ui_t));

    return game_ui;
}

game_pause_ui_t *create_ui_game_pause()
{
    game_pause_ui_t *game_pause_ui = malloc(sizeof(game_pause_ui_t));

    return game_pause_ui;
}