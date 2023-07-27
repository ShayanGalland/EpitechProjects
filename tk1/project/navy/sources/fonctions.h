/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** code c of a programme
*/
#ifndef _FONCTIONS_H
    #define _FONCTIONS_H
    #include <signal.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

typedef struct signal_message_s {
    unsigned int message_data;
    unsigned int current_bit;
} signal_message_t;
extern signal_message_t signal_message;
int my_strlen(const char* str1);
int my_strcmp(const char* str1, const char* str2);
int hit_on_map(int x, int y, char **my_map);
int read_boat_position(const char* boat_filepath, char** my_map);
int my_getnbr(char const *str);
void signal_handler(int signum);
void my_putchar(char c);
int WaitForShootResult(void);
int game_make(char **argv, int argc, int player_id);
void WaitShoot(short otherplayer_pid,char ** my_map);
int isFinish(char ** my_map, char ** their_map);
void print_man(void);
int my_putnbr(int nb);
void Shoot(short otherplayer_pid, char ** their_map);
void WaitForBitsWritten(unsigned int bitsToWait);
void game_des_fin(char**my_map, char** their_map, int player_id, int otherplayer_pid);
unsigned create_bits_mask(unsigned a, unsigned b);
void number_to_signal(short pid, int number, int bits_to_write);
int extract_n_bits(unsigned int data, unsigned a, unsigned b);
void read_player_input(char* x, char* y);
int count_hit_on_map(char ** my_map);
void re_game(int otherplayer_pid, int player_id, char **my_map, char **their_map);
short WaitForEnnemyConnected();
int WaitForConfirmationConnection();
void SendEnnemyConnected(short pid);
void print_map(char ** map);
void SendConfirmationConnection(short pid);
int WaitForShoot(char* x, char* y);
void con_pid(int otherplayer_pid, int player_id, char **my_map, char **their_map);
void print_shoot_result(char x, char y, int result, char ** map);
void SendShootResult(short pid, int result);
void free_map(char** map);
void SendShoot(short pid, char x, char y);
char** create_map();
int boat_pos(char *buffer, int i, char **my_map);
void boat_pos_on_map(int row_start, int row_end, int col_start, int col_end, char **my_map, int boat_number);
#endif
