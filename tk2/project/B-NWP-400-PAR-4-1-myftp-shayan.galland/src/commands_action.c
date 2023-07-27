/*
** EPITECH PROJECT, 2023
** project
** File description:
** in c
*/

#include "../include/ftp.h"

void handle_PASS_command(char *command, client_t *client)
{
    char *password = strtok(command, " ");

    password = strtok(NULL, " ");
    if (password == NULL) {
        send_response(client, 501,
        "Syntax error in parameters or arguments.");
        return;
    }
    if (strcmp(client->username, "anonymous") == 0) {
        client->is_logged = 1;
        send_response(client, 230, "User logged in, proceed.");
    } else {
        send_response(client, 530,
        "Not logged in, user or password incorrect.");
    }
}

void handle_CWD_command(char *command, client_t *client)
{
    char *new_directory = NULL;

    if (!client->is_logged) {
        send_response(client, 530, "Not logged in.");
        return;
    }
    new_directory = strtok(command, " ");
    new_directory = strtok(NULL, " ");
    if (new_directory == NULL) {
        send_response(client, 501,
        "Syntax error in parameters or arguments.");
        return;
    }
    send_response(client, 250, "Requested file action okay, completed.");
}

void handle_CDUP_command(char *command, client_t *client)
{
    if (!client->is_logged) {
        send_response(client, 530, "Not logged in.");
        return;
    }
    send_response(client, 200, "Command okay.");
}

void handle_QUIT_command(char *command, client_t *client)
{
    send_response(client, 221, "Service closing control connection.");
    close(client->socket);
    client->socket = -1;
}

void handle_DELE_command(char *command, client_t *client)
{
    char *file_to_delete = NULL;

    if (!client->is_logged) {
        send_response(client, 530, "Not logged in.");
        return;
    }
    file_to_delete = strtok(command, " ");
    file_to_delete = strtok(NULL, " ");
    if (file_to_delete == NULL) {
        send_response(client, 501,
        "Syntax error in parameters or arguments.");
        return;
    }
    send_response(client, 250, "Requested file action okay, completed.");
}
