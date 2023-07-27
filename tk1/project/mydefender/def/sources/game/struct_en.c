/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** main_mydefnder.c
*/

#include "my_defender_game.h"
#include "my.h"


enemies_t *create_enemie()
{
    enemies_t *make_enemies = malloc(sizeof(enemies_t));

    make_enemies->next_frame_o = 1;
    make_enemies->frame_o = 2.0f;
    make_enemies->next_frame_d = 1;
    make_enemies->frame_d = 2.0f;
    make_enemies->next_frame_t = 1;
    make_enemies->frame_t = 2.0f;
    make_enemies->font_coin = sfFont_createFromFile("asset/txt/font.ttf");
    make_enemies->txt_coin = sfText_create();
    make_enemies->font_heart = sfFont_createFromFile("asset/txt/font.ttf");
    make_enemies->txt_heart = sfText_create();
    make_enemies->time_deploy_o = 1;
    make_enemies->time_deploy_d = 1;
    make_enemies->time_deploy_t = 1;
    make_enemies->nbr_en_o = 0;
    make_enemies->nbr_en_d = 0;
    make_enemies->nbr_en_t = 0;
    make_enemies->o = 0;
    make_enemies->d = 0;
    make_enemies->t = 0;
    make_enemies->fen_deploy = malloc(sizeof(int)*MAX_EN_OO);
    make_enemies->sen_deploy = malloc(sizeof(int)*MAX_EN_OD);
    make_enemies->ten_deploy = malloc(sizeof(int)*MAX_EN_OT);
    make_enemies->wich_en = malloc(sizeof(int)*3);
    for (int i = 0; i != MAX_EN_OO; i++)
        make_enemies->fen_deploy[i] = 0;
    for (int i = 0; i != MAX_EN_OD; i++)
        make_enemies->sen_deploy[i] = 0;
    for (int i = 0; i != MAX_EN_OT; i++)
        make_enemies->ten_deploy[i] = 0;
    return make_enemies;
}

fenemie_t *create_fenemie()
{
    fenemie_t *make_fenemie = malloc(sizeof(fenemie_t));

    make_fenemie->ten_o = sfTexture_createFromFile("asset/enemies/en1.png", NULL);
    make_fenemie->en_o = create_sprite(make_fenemie->ten_o);
}

senemie_t *create_senemie()
{
    senemie_t *make_senemie = malloc(sizeof(senemie_t));

    make_senemie->ten_d = sfTexture_createFromFile("asset/enemies/en2.png", NULL);
    make_senemie->en_d = create_sprite(make_senemie->ten_d);
}

tenemie_t *create_tenemie()
{
    tenemie_t *make_tenemie = malloc(sizeof(tenemie_t));

    make_tenemie->ten_t = sfTexture_createFromFile("asset/enemies/en3.png", NULL);
    make_tenemie->en_t = create_sprite(make_tenemie->ten_t);
}