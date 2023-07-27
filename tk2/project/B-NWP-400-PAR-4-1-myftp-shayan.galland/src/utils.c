/*
** EPITECH PROJECT, 2023
** project
** File description:
** in c
*/

#include "../include/ftp.h"

char *my_strcat_aloc(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int new_len = len1+len2+1;
    char *str = malloc(sizeof(char)*new_len);
    int offset_str = 0;

    for (int i = 0; i < new_len-1; i++) {
        if (i < len1) {
            str[i] = str1[i];
            offset_str++;
        } else
            str[i] = str2[i-offset_str];
    }
    str[new_len-1] = '\0';
    return str;
}

void send_response(client_t *client, int code, const char *message)
{
    char response[1000];

    snprintf(response, 1000, "%d %s\r\n", code, message);
    send(client->socket, response, strlen(response), 0);
}

void help()
{
    printf("USAGE: ./myftp port path\n\t");
    printf("port is the port number on which the server socket listens\n\t");
    printf("path is the path to the home directory for the Anonymous user\n");
    exit(0);
}

char *param_gestion(int argc, char **argv)
{
    if (argc == 2) {
        if (!strcmp(argv[1], "-h"))
            help();
    }
    if (argc != 3)
        exit(84);
    if (access(argv[2], F_OK) == -1) {
        printf("Path %s does not exist.\n", argv[2]);
        exit(84);
    }
    else
        return argv[2];
}

void free_struct(client_t *connections)
{
    for (int i = 0; i < MAX; i++) {
        if (connections[i].socket > 0)
            close(connections[i].socket);
        if (connections[i].username != NULL)
            free(connections[i].username);
        if (connections[i].working_directory != NULL)
            free(connections[i].working_directory);
    }
    free(connections);
}
