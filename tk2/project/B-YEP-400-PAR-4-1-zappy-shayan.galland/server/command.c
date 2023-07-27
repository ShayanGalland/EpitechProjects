/*
** EPITECH PROJECT, 2023
** c
** File description:
** c
*/

#include <string.h>
#include "command.h"
#include <unistd.h>
#include "../includes/server.h"


Server server;

void msz(char *params)
{
    printf("Map size: %s\n", params);
}

void bct(char *params)
{
    printf("Tile content: %s\n", params);
}

void tna(char *params)
{
    printf("Team names: %s\n", params);
}

Command commands[] = {
    {"msz", msz},
    {"bct", bct},
    {"tna", tna},

};

void handle_msz_command() {
    char message[256];
    snprintf(message, sizeof(message), "msz %d %d", server.map_width, server.map_height);
    send_message_to_all_clients(message);
}

void handle_bct_command() {
    int x = atoi(strtok(NULL, " "));
    int y = atoi(strtok(NULL, " "));
    char message[256];
    snprintf(message, sizeof(message), "bct %d %d %d", x, y, server.map[x][y]);
    send_message_to_all_clients(message);
}

void handle_tna_command() {
    char message[256];
    snprintf(message, sizeof(message), "tna %s", server.team_name);
    send_message_to_all_clients(message);
}

void handle_command(char* command) {
    char* command_name = strtok(command, " ");  // get the command name

    if (strcmp(command_name, "msz") == 0) {
        handle_msz_command();
    } else if (strcmp(command_name, "bct") == 0) {
        handle_bct_command();
    } else if (strcmp(command_name, "tna") == 0) {
        handle_tna_command();
    } else {
        // TODO: handle other commands
    }
}
