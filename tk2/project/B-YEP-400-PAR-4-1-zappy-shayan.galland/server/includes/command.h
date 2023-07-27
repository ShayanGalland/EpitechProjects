/*
** EPITECH PROJECT, 2023
** h
** File description:
** g
*/

#ifndef COMMAND_H
#define COMMAND_H

typedef struct {
    char *command;
    void (*function)(char *);
} Command;


typedef struct Client {
    int socket_fd;
    struct Client* next;
} Client;


void handle_command(char *command);
void handle_msz_command();
void tna(char *params);
void bct(char *params);
void msz(char *params);
void handle_bct_command();
void handle_tna_command();

#endif
