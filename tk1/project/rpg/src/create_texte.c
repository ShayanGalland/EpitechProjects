/*
** EPITECH PROJECT, 2022
** game loop
** File description:
** game loop
*/

#include "include.h"

void create_txt(game_t *game)
{
    char buf0[40] = "Hello, ive been camping for 2 month.\n";
    char buf1[40] = "And i studied this scary place";
    char buf2[40] = "This castle in the north is haunted.\n";
    char buf3[40] = "I am scared to go check if my friend";
    char buf4[40] = "Is still alive, we visited this place\n";
    char buf5[40] = "Together but strange things happened";
    char buf6[40] = "And i ran out, i never saw him again\n";
    char buf7[40] = "\t\t\t\tPlease... find him";
    char buf8[40] = "Press f to clock";
    char buf9[40] = "Press escape to quit";

    game->boss.msg = set_txt(buf8, 640, 100, 1.5f);
    game->chat.pnj_name = set_txt("????", 440, 670, 1);
    game->chat.space = set_txt("press space", 1350, 910, 0.6f);
    game->chat.chat_pnj1 = set_txt(my_restrcat(buf0, buf1), 310, 785, 1.1f);
    game->chat.chat_pnj2 = set_txt(my_restrcat(buf2, buf3), 310, 770, 1.1f);
    game->chat.chat_pnj3 = set_txt(my_restrcat(buf4, buf5), 280, 770, 1.1f);
    game->chat.chat_pnj4 = set_txt(my_restrcat(buf6, buf7), 310, 770, 1.1f);
    game->boss.end_msg = set_txt(buf9, 640, 100, 1.5f);
}

void create_image(game_t *game)
{
    game->map[0].map_collision = sfImage_createFromFile("asset/map/col1.png");
    game->map[1].map_collision =
    sfImage_createFromFile("asset/map/door1.png");
    game->map[2].map_collision =
    sfImage_createFromFile("asset/map/door2.png");
    game->map[3].map_collision =
    sfImage_createFromFile("asset/map/door3.png");
    game->map[4].map_collision =
    sfImage_createFromFile("asset/map/door4.png");
    game->map[5].map_collision =
    sfImage_createFromFile("asset/map/endmap_hit.png");
}

void create_text_ghost(game_t *game)
{
    for (int i = 0; i < MAX_FANTOME_1; i++)
        game->ghost[0][i].text_ghost = sfTexture_createFromFile
        ("asset/character/ghost1.png", NULL);
    for (int i = 0; i < MAX_FANTOME_2; i++)
        game->ghost[1][i].text_ghost = sfTexture_createFromFile
        ("asset/character/ghost2.png", NULL);
    for (int i = 0; i < MAX_FANTOME_3; i++)
        game->ghost[2][i].text_ghost = sfTexture_createFromFile
        ("asset/character/ghost3.png", NULL);
}

void init_character_sprite(game_t *game)
{
    for (int i = 0; i < MAX_FANTOME_1; i++)
        game->ghost[0][i].ghost = init_sprite(game->ghost[0][i].text_ghost);
    for (int i = 0; i < MAX_FANTOME_2; i++)
        game->ghost[1][i].ghost = init_sprite(game->ghost[1][i].text_ghost);
    for (int i = 0; i < MAX_FANTOME_3; i++)
        game->ghost[2][i].ghost = init_sprite(game->ghost[2][i].text_ghost);
    game->hero.life = init_sprite(game->hero.text_life);
    game->hero.stamina = init_sprite(game->hero.text_stamina);
    game->pnj.pnj = init_sprite(game->pnj.text_pnj);
    game->hero.hero = init_sprite(game->hero.text_hero);
    game->boss.boss = init_sprite(game->boss.text_boss);
    game->boss.win = init_sprite(game->boss.text_win);
    game->over = init_sprite(game->text_over);
}

void create_other_map(game_t *game)
{
    game->map[2].text_map_hit = sfTexture_createFromFile
    ("asset/map/door2.png", NULL);
    game->map[3].text_map_hit = sfTexture_createFromFile
    ("asset/map/door3.png", NULL);
    game->map[4].text_map_hit = sfTexture_createFromFile
    ("asset/map/door4.png", NULL);
    game->map[5].text_map = sfTexture_createFromFile
    ("asset/map/endmap.png", NULL);
    game->map[5].text_map_hit = sfTexture_createFromFile
    ("asset/map/endmap_hit.png", NULL);
    game->map[5].map = init_sprite(game->map[5].text_map);
    game->map[5].map_hit = init_sprite(game->map[5].text_map_hit);
}