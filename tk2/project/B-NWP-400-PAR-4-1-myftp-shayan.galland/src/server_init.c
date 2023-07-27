/*
** EPITECH PROJECT, 2023
** project
** File description:
** in c
*/

#include "../include/ftp.h"

int init_socket(uint16_t port)
{
    int fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    struct sockaddr_in adress;

    adress.sin_family = AF_INET;
    adress.sin_port = htons(port);
    adress.sin_addr.s_addr = INADDR_ANY;
    bind(fd, (struct sockaddr *)&adress, sizeof(struct sockaddr_in));
    listen(fd, 5);
    return fd;
}

client_t *init_connection(int socket, char *path)
{
    client_t *connections = malloc(sizeof(client_t) * MAX);

    for (int i = 0; i < MAX; i++) {
        connections[i].socket = -1;
        connections[i].mode = PASSIVE_MODE;
        connections[i].active_mode_port = 0;
        connections[i].username = NULL;
        connections[i].is_logged = 0;
        connections[i].working_directory = path;
    }
    connections[0].socket = socket;
    connections[0].mode = PASSIVE_MODE;
    connections[0].active_mode_port = 0;
    connections[0].username = NULL;
    connections[0].is_logged = 0;
    connections[0].working_directory = path;
    return connections;
}

void initialize_fd_set(fd_set *fd_set_rd, client_t *connections)
{
    FD_ZERO(fd_set_rd);
    for (int i = 0; i < MAX; i++) {
        if (connections[i].socket >= 0) {
            FD_SET(connections[i].socket, fd_set_rd);
        }
    }
}
