/*
** EPITECH PROJECT, 2023
** project
** File description:
** in c
*/

#include "../include/ftp.h"

int main(int argc, char **argv)
{
    int server_socket = init_socket(atoi(argv[1]));
    char *directory_path = param_gestion(argc, argv);
    client_t *connections = init_connection(server_socket, directory_path);
    fd_set fd_set_rd;

    if (argc != 3) {
        free_struct(connections);
        return 84;
    }
    if (start_connection(server_socket, connections, fd_set_rd) == 84)
        return 84;
    free_struct(connections);
    return 0;
}
