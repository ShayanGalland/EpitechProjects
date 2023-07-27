/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** my_struct.h
*/

#include <time.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/System/Vector2.h>
#include <math.h>
#include <unistd.h>

#ifndef _MY_STRUCT_H_
    #define _MY_STRUCT_H_
    #define MAX_PLAT_O 23
    #define MAX_EN_OO 80
    #define MAX_EN_OD 50
    #define MAX_EN_OT 25
    #define T_PI 3.1416

struct game_s {
    sfRenderWindow *window;
    sfEvent event;
    sfClock *game_clock;
    int fix_time;
    float time_animation_o;
    float time_animation_d;
    float time_animation_t;
};
typedef struct game_s game_t;

struct tour_s {
    sfVector2f tracking;
    int validate_o;
    int validate_d;
    int validate_t;
    int validate_q;
    int *fturet_posed;
    int *sturet_posed;
    int *tturet_posed;
    int *qturet_posed;
    int time_t;
    sfFont *fprice;
    sfText *price;
    int set;
    int *set_o;
    int *set_d;
    int *set_t;
    int *set_q;
    int one;
    int two;
    int tree;
    int four;
};
typedef struct tour_s tour_t;

struct enemies_s {
    int o;
    int d;
    int t;
    int next_frame_o;
    int next_frame_d;
    int next_frame_t;
    float frame_o;
    float frame_d;
    float frame_t;
    sfFont *font_coin;
    sfFont *font_heart;
    sfText *txt_coin;
    sfText *txt_heart;
    sfVector2f move;
    int *wich_en;
    float time_coin;
    float time_deploy_o;
    float time_deploy_d;
    float time_deploy_t;
    int nbr_en_o;
    int nbr_en_d;
    int nbr_en_t;
    int *fen_deploy;
    int *sen_deploy;
    int *ten_deploy;
    int *killo;
    int *killd;
    int *killt;
};
typedef struct enemies_s enemies_t;

struct fbulet_s {
    sfSprite *fbultet;
    sfTexture *ftbulet;
};
typedef struct fbulet_s fbulet_t;

struct sbulet_s {
    sfSprite *sbultet;
    sfTexture *stbulet;
};
typedef struct sbulet_s sbulet_t;

struct tbulet_s {
    sfSprite *tbultet;
    sfTexture *ttbulet;
};
typedef struct tbulet_s tbulet_t;

struct qbulet_s {
    sfSprite *qbultet;
    sfTexture *qtbulet;
};
typedef struct qbulet_s qbulet_t;

struct fenemie_s {
    sfTexture *ten_o;
    sfSprite *en_o;
};
typedef struct fenemie_s fenemie_t;

struct senemie_s {
    sfTexture *ten_d;
    sfSprite *en_d;
};
typedef struct senemie_s senemie_t;

struct tenemie_s {
    sfTexture *ten_t;
    sfSprite *en_t;
};
typedef struct tenemie_s tenemie_t;

struct ftur_s {
    sfTexture *tt_o;
    sfSprite *t_o;
};
typedef struct ftur_s ftur_t;

struct stur_s {
    sfTexture *tt_d;
    sfSprite *t_d;
};
typedef struct stur_s stur_t;

struct ttur_s {
    sfTexture *tt_t;
    sfSprite *t_t;
};
typedef struct ttur_s ttur_t;

struct qtur_s {
    sfTexture *tt_q;
    sfSprite *t_q;
};
typedef struct qtur_s qtur_t;

struct platform_s {
    sfTexture *tplt;
    sfSprite *plt;
};
typedef struct platform_s platform_t;

struct move_s {
    int ***mv;
    float frame_r;
    float next_frame_r;
    float time_animation_r;
    sfTexture *tgp;
    sfSprite * gp;
    sfTexture *trp;
    sfSprite * rp;
};
typedef struct move_s move_t;

struct map_s {
    float time_en;
    int in;
    float ret_rand;
    sfTexture *tlife;
    sfSprite *life;
    sfTexture *tcoin;
    sfSprite *coin;
    int coin_count;
    int life_count;
    sfTexture *tmp_o;
    sfSprite *mp_o;
    sfTexture *tmp_d;
    sfSprite *mp_d;
    sfTexture *tmp_t;
    sfSprite *mp_t;
    sfTexture *tmp_bo;
    sfSprite *mp_bo;
    sfVector2f mouse;
    sfFloatRect box_o;
    sfFloatRect box_d;
    sfFloatRect box_t;
    sfFloatRect box_q;
    tour_t *tour_t;
    move_t *move_t;
    sfSound *sound_tir;
    sfSound *sound_bolet;
    platform_t *platform_t[MAX_PLAT_O];
    enemies_t *enemies_t;
    fenemie_t *fenemie_t[MAX_EN_OO];
    senemie_t *senemie_t[MAX_EN_OD];
    tenemie_t *tenemie_t[MAX_EN_OT];
    ftur_t *ftur_t[MAX_PLAT_O];
    stur_t *stur_t[MAX_PLAT_O];
    ttur_t *ttur_t[MAX_PLAT_O];
    qtur_t *qtur_t[MAX_PLAT_O];
    fbulet_t *fbulet_t[MAX_EN_OO];
    sbulet_t *sbulet_t[MAX_EN_OO];
    tbulet_t *tbulet_t[MAX_EN_OO];
    qbulet_t *qbulet_t[MAX_EN_OO];

    float cb;
    float ac;
    float ab;
    float angle;
};
typedef struct map_s map_t;

#endif /* !_MY_STRUCT_H_ */
