/*
** EPITECH PROJECT, 2023
** project
** File description:
** in c
*/

#include "../include/ftp.h"

void handle_NOOP_command(char *command, client_t *client)
{
    command = command;
    send_response(client, 200, "Command okay.");
}

void handle_RETR_command(char *command, client_t *client)
{
    command = command;
    client = client;
}

void handle_STOR_command(char *command, client_t *client)
{
    command = command;
    client = client;
}

void handle_binary_data(char *data, client_t *client)
{
    data = data;
    client = client;
}

void handle_LIST_command(char *command, client_t *client)
{
    command = command;
    client = client;
}
