/*
** EPITECH PROJECT, 2023
** project
** File description:
** in c
*/

#include "../include/ftp.h"
#include <stdbool.h>

bool fil_connection(int i, int new_client, client_t *connections)
{
    if (connections[i].socket < 0) {
        connections[i].socket = new_client;
        return true;
    }
    return false;
}

void handle_new_connection(int server_socket, client_t *connections)
{
    struct sockaddr_in new_addr;
    socklen_t addrlen;
    int new_client = accept(server_socket,
    (struct sockaddr *)&new_addr, &addrlen);

    if (new_client >= 0) {
        bool connection_filled = false;
        for (int i = 0; i < MAX && !connection_filled; i++) {
            connection_filled = fil_connection(i, new_client, connections);
        }
    }
}

void handle_existing_connection(client_t *connection, char *read_buffer)
{
    int ret_read = read(connection->socket, read_buffer, 1000);

    if (ret_read > 0)
        handle_command(read_buffer, connection);
    if (ret_read == 0) {
        close(connection->socket);
        connection->socket = -1;
        if (connection->username)
            free(connection->username);
        if (connection->working_directory)
            free(connection->working_directory);
    }
}

void client_is_connected(int changed_socket, int server_socket,
client_t *connections, fd_set fd_set_rd)
{
    char read_buffer[1000];

    if (FD_ISSET(server_socket, &fd_set_rd)) {
        handle_new_connection(server_socket, connections);
        changed_socket--;
    }
    for (int i = 1; i < MAX; i++) {
        if (connections[i].socket >= 0 &&
        FD_ISSET(connections[i].socket, &fd_set_rd)) {
            handle_existing_connection(&connections[i], read_buffer);
            changed_socket--;
        }
        if (!changed_socket) {
            break;
        }
    }
}

int start_connection(int server_socket, client_t *connections,
fd_set fd_set_rd)
{
    int changed_socket = 0;

    while (1) {
        initialize_fd_set(&fd_set_rd, connections);
        changed_socket = select(FD_SETSIZE, &fd_set_rd, NULL, NULL, NULL);
        if (changed_socket >= 0)
            client_is_connected(changed_socket, server_socket,
            connections, fd_set_rd);
    }
}
