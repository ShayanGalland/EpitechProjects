/*
** EPITECH PROJECT, 2022
** struct
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct item_s {
    sfClock *clock;
    float timer;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f origin;
    sfVector2f pos;
    sfIntRect rect;
} item_t;

typedef struct pnj_s {
    sfSprite *pnj;
    sfTexture *text_pnj;
    float frame;
    int anim;
    sfSprite *e;
    sfTexture *text_e;
    sfBool chating;
    float press_anim;
    sfTexture *text_box;
    sfSprite *box;
} pnj_t;

typedef struct fkey_s {
    int key1f;
    int key2f;
    int key3f;
    sfTexture *text_key1;
    sfSprite *key1;
    sfTexture *text_key2;
    sfSprite *key2;
    sfTexture *text_key3;
    sfSprite *key3;
} fkey_t;

typedef struct ghost_s {
    sfSprite *ghost;
    sfTexture *text_ghost;
    float frame;
    int anim;
    int spawned;
    float scale;
} ghost_t;

typedef struct shoot_s {
    sfSprite *ball;
    sfTexture *text_ball;
    sfSprite *ball2;
    sfTexture *text_ball2;
    sfSprite *ball3;
    sfTexture *text_ball3;
    sfSprite *cursor;
    sfTexture *text_cursor;
    sfSprite *boom;
    sfTexture *text_boom;
    float frame_hit;
    float frame;
    int animx;
    int animy;
    int is_boom;
    float hero_x;
    float hero_y;
    float dist;
    float x;
    float y;
    float spd;
} shoot_t;

typedef struct math_s {
    float angle;
    float ab;
    float cb;
    float ac;
} math_t;

typedef struct hero_s {
    float frame_hero;
    int anim_hero;
    shoot_t shoot;
    sfSprite *hero;
    sfTexture *text_hero;
    sfSprite *life;
    sfTexture *text_life;
    sfSprite *stamina;
    sfTexture *text_stamina;
    float less_life;
    float less_mana;
    float delay_life;
    float delay_mana;
    int mana_regen;
    float mana_regening;
    float add_mana;
    int no_anim;
    int side;
    int ms_z;
    int ms_q;
    int ms_s;
    int ms_d;
    int mv_z;
    int mv_q;
    int mv_s;
    int mv_d;
} hero_t;

typedef struct map_s {
    sfSprite *map;
    sfTexture *text_map;
    sfSprite *map_hit;
    sfTexture *text_map_hit;
    sfImage* map_collision;
    int res_x;
    int res_y;
    float div;
    sfTexture *text_next;
    sfSprite *next;
    sfTexture *text_key_e;
    sfSprite *key_e;
} map_t;

typedef struct menu_s {
    item_t screen;
    sfText *play;
    sfText *setting;
    sfText *quit;
    sfText *fps;
    item_t black_screen;
    sfText *back;
    sfText *dif;
    item_t empty_vol;
    item_t filled_vol;
} menu_t;

typedef struct chat_s {
    sfText *chat_pnj1;
    sfText *chat_pnj2;
    sfText *chat_pnj3;
    sfText *chat_pnj4;
    sfText *pnj_name;
    sfText *space;
    float chat_time;
    int num_txt;
} chat_t;

typedef struct pause_s {
    sfText *resume;
    sfText *setting;
    sfText *exit;
} pause_t;

typedef struct object_s {
    item_t item;
    int id;
    int used;
    char *name;
    int active;
    int amount;
} object_t;

typedef struct inventory_s {
    object_t *object;
    item_t screen;
    item_t *slots;
    sfText *show_item;
    int is_hover;
    int *in_slots;
} inventory_t;

typedef struct music_s {
    sfMusic *main;
    sfSoundBuffer *car_buf;
    sfSound *car;
    sfSoundBuffer *shoot_buf;
    sfSound *shoot;
} music_t;

typedef struct tuto_s {
    int step;
    char **text;
} tuto_t;

typedef struct hint_s {
    item_t box;
    int elapsed;
    int step;
    item_t mouse;
    item_t button;
} hint_t;

typedef struct boss_s {
    sfSprite *boss;
    sfTexture *text_boss;
    sfSprite *win;
    sfTexture *text_win;
    int is_travel;
    int start;
    sfVector2f rand_mv;
    float timer_shoot;
    sfVector2f size;
    int os;
    float mv;
    int cloak;
    sfText *msg;
    sfText *end_msg;
    int win_cond;
} boss_t;

typedef struct level_s {
    int limit;
    item_t exp_bar;
    int level;
    int exp;
    sfText *txt;
    item_t exp_gui;
    int elapsed;
    sfText *limit_txt;
    sfText *exp_txt;
} level_t;

typedef struct game_s {
    chat_t chat;
    boss_t boss;
    pnj_t pnj;
    ghost_t **ghost;
    map_t *map;
    hero_t hero;
    math_t math;
    menu_t menu;
    item_t cursor;
    fkey_t key;
    sfRenderWindow *window;
    sfEvent event;
    sfClock *game_clock;
    sfTexture *text_over;
    sfSprite *over;
    float game_time;
    int step;
    int fps;
    int dif;
    int vol;
    int map_select;
    int other_world;
    pause_t pause;
    int started;
    int *is_spawned;
    inventory_t items;
    music_t music;
    int delay;
    tuto_t tuto;
    hint_t hint;
    level_t level;
    sfSprite *pluie;
    sfTexture *text_pluie;
} game_t;

#endif