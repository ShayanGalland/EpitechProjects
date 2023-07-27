/*
** EPITECH PROJECT, 2023
** project
** File description:
** in c
*/

#include "../include/ftp.h"

void handle_PWD_command(char *command, client_t *client)
{
    char response[1000];

    if (!client->is_logged) {
        send_response(client, 530, "Not logged in.");
        return;
    }
    snprintf(response, 1000, "257 \"%s\"", client->working_directory);
    send_response(client, 257, response);
}

void handle_PASV_command(char *command, client_t *client)
{
    command = command;
    client = client;
}

void handle_PORT_command(char *command, client_t *client)
{
    command = command;
    client = client;
}

void handle_HELP_command(char *command, client_t *client)
{
    send_response(client, 214,
    "The following commands are recognized (* =>'s unimplemented).");
    send_response(client, 214,
    "USER    PASS    CWD     CDUP    QUIT    DELE");
    send_response(client, 214,
    "PWD*    PASV*   PORT*   HELP    NOOP    RETR*");
    send_response(client, 214, "STOR*   LIST*");
    send_response(client, 214, "Help OK.");
}

void handle_USER_command(char *command, client_t *client)
{
    char *_username = strtok(command, " ");

    _username = strtok(NULL, " ");
    if (_username == NULL) {
        send_response(client, 501,
        "Syntax error in parameters or arguments.");
        return;
    }
    client->username = strdup(_username);
    send_response(client, 331, "Username OK, need password.");
}
