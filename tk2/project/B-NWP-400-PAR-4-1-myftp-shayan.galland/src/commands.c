/*
** EPITECH PROJECT, 2023
** project
** File description:
** in c
*/

#include "../include/ftp.h"

static int handle_command_p(char *command, client_t *client)
{
    if (strstr(command, "USER") != NULL) {
        handle_USER_command(command, client);
        return 0;
    }
    if (strstr(command, "PASS") != NULL) {
        handle_PASS_command(command, client);
        return 0;
    }
    if (strstr(command, "CWD") != NULL) {
        handle_CWD_command(command, client);
        return 0;
    }
    if (strstr(command, "CDUP") != NULL) {
        handle_CDUP_command(command, client);
        return 0;
    }
    return 1;
}

static int handle_command_pp(char *command, client_t *client)
{
    if (strstr(command, "QUIT") != NULL) {
        handle_QUIT_command(command, client);
        return 0;
    }
    if (strstr(command, "DELE") != NULL) {
        handle_DELE_command(command, client);
        return 0;
    }
    if (strstr(command, "PWD") != NULL) {
        handle_PWD_command(command, client);
        return 0;
    }
    if (strstr(command, "PASV") != NULL) {
        handle_PASV_command(command, client);
        return 0;
    }
    return 1;
}

static int handle_command_ppp(char *command, client_t *client)
{
    if (strstr(command, "PORT") != NULL) {
        handle_PORT_command(command, client);
        return 0;
    }
    if (strstr(command, "HELP") != NULL) {
        handle_HELP_command(command, client);
        return 0;
    }
    if (strstr(command, "NOOP") != NULL) {
        handle_NOOP_command(command, client);
        return 0;
    }
    if (strstr(command, "RETR") != NULL) {
        handle_RETR_command(command, client);
        return 0;
    }
    return 1;
}

static int handle_command_pppp(char *command, client_t *client)
{
    if (strstr(command, "STOR") != NULL) {
        handle_STOR_command(command, client);
        return 0;
    }
    if (strstr(command, "LIST") != NULL) {
        handle_LIST_command(command, client);
        return 0;
    }
    return 1;
}

void handle_command(char *command, client_t *client)
{
    if (!handle_command_p(command, client))
        return;
    if (!handle_command_pp(command, client))
        return;
    if (!handle_command_ppp(command, client))
        return;
    if (!handle_command_pppp(command, client))
        return;
    handle_binary_data(command, client);
}
