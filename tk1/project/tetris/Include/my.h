/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** EVERYONE IS HERE *smash bros theme start playing*
*/

#ifndef MY_H_
    #define MY_H_

    #include "lib.h"
    #include "libs.h"
    #include "struct.h"
    #include "macro.h"

int help(int ac, char **av);
void get_dim_array(game_t *game, int file, char **block_array);
void array_block(game_t *game, int file, char *str);
void fil_str(game_t *game, int file);
void find_block(game_t *game, char *path);
void count_block(char *path, game_t *game);
void my_memcpy(char *src, char *dst, size_t size);
void my_memset(char *dst, char v, size_t size);
void *my_realloc(void *ptr, size_t size_ptr, size_t new_size);
int open_read(char *file_path, char **data_buffer, int *data_buffer_length);
char *my_strcatt(char *str1, char *str2);
void merge_map(game_t *game);
void fil_tab(game_t *game);
void fil_char(int j, int i, game_t *game);
void fil_tab2(game_t *game);
void fil_char2(int j, int i, game_t *game);
int count_bs(char *str);
void rotate(game_t *game);
void array_comb(game_t *game, int mx, int my);
piece_t *generate_new_piece(game_t *game);
void chk_lines(game_t *game);
void sup_line(game_t *game, int n);
int bord_col(game_t *game);
int lose(game_t *game);
int collision(game_t *game);
int main(int ac, char **av);
void tetris();
void gameplay(game_t *game);
void key_control(game_t *game, int key);
void setup(game_t *game);
void delay(int del);
void prt_map(game_t *game);
void map_mid(int j, int i, game_t *game);
unsigned int generate_random_number(int min, int max);
void level(game_t *game);
int is_lose(game_t *game, int mx, int my);

#endif /* MY_H_ */
