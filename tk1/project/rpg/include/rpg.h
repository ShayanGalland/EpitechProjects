/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** rpg
*/

#ifndef RPG_H_
    #define RPG_H_

void init_game(game_t *game);
void my_rpg(void);
void create_sprites(game_t *game);
sfSprite *init_sprite(sfTexture *texture);
int generate_random_number(int min, int max);
sfVector2f start_point(float x, float y);
void draw_sprites(game_t *game);
void set_sprite(game_t *game);
void create_and_anim_hero(game_t *game);
sfIntRect get_rects(int left, int top, int height, int width);
sfText *set_txt(char *text, int x, int y, float scale);
void create_menu(game_t *game);
item_t get_new_item(char *path, sfVector2f pos,
float refresh_rate, sfIntRect rect);
void menu_events(game_t *game);
float angle_sprt(sfSprite *sprite1, sfSprite *sprite2, game_t *game);
float distance(sfSprite *sprite1, sfSprite *sprite2);
void handle_shoot(game_t *game, float elapsed);
void handle_shoot(game_t *game, float elapsed);
void display_all(game_t *game);
void display_game(game_t *game);
void display_menu(game_t *game);
void stop_colision(game_t *game, sfSprite *map, sfImage *col);
void out_of_map(game_t *game, int map);
void init_mv(game_t *game);
int check_collide(sfImage* map, sfVector2f point, game_t *game);
void no_anim(game_t *game);
void play_button(game_t *game);
void create_text_ghost(game_t *game);
void init_values(game_t *game);
void exit_button(game_t *game);
void create_character_sprite(game_t *game);
void handle_shoot(game_t *game, float elapsed);
void default_value(game_t *game);
void setting_button(game_t *game);
void setting_back(game_t *game);
void difficulty_button(game_t *game);
int check_text(sfIntRect rect, sfVector2f pos,
sfVector2f mouse, sfText **text);
void fps_button(game_t *game);
void volume_bar(game_t *game);
void move_player(game_t *game, sfSprite *map);
void no_anim(game_t *game);
void create_and_anim_ghost1(game_t *game, int i);
void create_and_anim_ghost2(game_t *game, int i);
void create_and_anim_ghost3(game_t *game, int i);
void check_up(game_t *game, sfVector2f pos, sfImage *col);
void check_down(game_t *game, sfVector2f pos, sfImage *col);
void check_left(game_t *game, sfVector2f pos, sfImage *col);
void check_right(game_t *game, sfVector2f pos, sfImage *col);
void create_and_anim_pnj(game_t *game);
void my_itoa(char *buffer, int number);
void prt_chat(game_t *game, char *buffer, sfVector2f pos);
void set_origin(game_t *game);
char *my_restrcat(char *str1, char *str2);
void set_color(game_t *game);
void boss(game_t *game, float elapsed);
void create_txt(game_t *game);
void create_image(game_t *game);
void pause_events(game_t *game, sfEvent event);
void display_pause(game_t *game);
void create_pause(game_t *game);
void pause_exit(game_t *game, sfEvent event, sfVector2f mouse);
void pause_settings(game_t *game, sfEvent event, sfVector2f mouse);
void resume_button(game_t *game, sfEvent event, sfVector2f mouse);
void create_other_map(game_t *game);
void create_character_sprite(game_t *game);
void create_map2_sprite(game_t *game);
void create_map_sprite(game_t *game);
void create_game_sprite(game_t *game);
void ghost_attack(game_t *game);
int spawning_in_zone1(game_t *game, int i, int count, sfVector2f cord);
int spawning_in_zone2(game_t *game, int i, int count, sfVector2f cord);
int spawning_in_zone3(game_t *game, int i, int count, sfVector2f cord);
void create_and_anim_boom(game_t *game);
void my_itoa(char *buffer, int number);
void game_events(game_t *game);
void manage_events(game_t *game);
void manage_colide(game_t *game);
void move_ghost(game_t *game);
void move_all(game_t *game);
void display_chat(game_t *game);
void chat(game_t *game);
void select_map(game_t *game);
void win(game_t *game);
void boss_shooted(game_t *game);
void rand_pos(sfVector2f pos, game_t *game);
void cloak(game_t *game);
void colide_boss(game_t *game);
void boss_mv(game_t *game, float elapsed);
int next(game_t *game, sfSprite *the_next, sfSprite *key);
void select_map(game_t *game);
void other_world(game_t *game);
void switch_doors(game_t *game, int num, int key);
void manage_animation(game_t *game);
float set_speed(int i, game_t *game);
void change_ghost_side(game_t *game, int n, int i);
void attack(game_t *game, float elapsed, int i, int n);
void attacking_ghost(game_t *game, float elapsed);
void uhd(game_t *game);
void boooom(game_t *game, int i, int n);
void dead_ghost(game_t *game);
void kill_ghost(game_t *game);
void key_door(game_t *game);
void change_gun(game_t *game);
void init_character_sprite(game_t *game);
void manage_fps(menu_t *menu, int *fps);
void manage_dif(menu_t *menu, int *dif);
void display_sprites(item_t item, sfRenderWindow *window);

// INVENTORY && ITEMS //
void display_inventory(game_t *game);
void inventory_events(game_t *game);
void create_inventory(game_t *game);
void create_items(game_t *game);
void display_items_hover(game_t *game);
void add_to_inventory(game_t *game, object_t *item);

// TUTO //
void display_tuto(game_t *game);
void tuto_events(game_t *game);
void create_tuto(game_t *game);

// HINT //
void create_hint(hint_t *hint);
void display_hint(game_t *game, item_t img, sfText *msg, sfVector2f scale);

void create_music(music_t *songs);

// LEVEL //
void create_level(level_t *level);
void display_lvl_bar(game_t *game);
void level_up(game_t *game);
void gain_exp(game_t *game);

#endif
