#ifndef SERVEUR_H_
#define SERVEUR_H_

#include <netinet/in.h>
#include <stdio.h>
#include <signal.h>
#include "../libs/myteams/logging_server.h"

#include "database.h"

#define MAX_CLIENT 256

struct client
{
    int socket;

    char *uuid;
    char *username;

    char *arg1;
    char *arg2;
    char *arg3;
    char *arg4;
    char *arg5;
};
typedef struct client client_t;

struct server
{
    int server_socket;
    fd_set fd_set_rd;
    client_t *connected_clients;

    database_t *database;
};
typedef struct server server_t;

void server_cleanup(server_t *server);
void server_stop(server_t *server);
int server_start(server_t *server);
int server_init(server_t *server, uint16_t port);
void read_logout_packet(server_t *server, client_t *connection, char *read_buffer);
void write_login_response_packet(client_t *connection, char *uuid, char *username);
void read_login_packet(server_t *server, client_t *connection, char *read_buffer);
void free_struct(client_t *connections);
void client_is_connected(server_t *server, int changed_socket, client_t *connections, fd_set fd_set_rd);
void handle_existing_connection(server_t *server, client_t *connection, char *read_buffer);
void handle_command(server_t *server, client_t *connection, char *read_buffer);
void handle_new_connection(server_t *server, client_t *connections);
void initialize_fd_set(fd_set *fd_set_rd, client_t *connections);
client_t *init_connection(int socket);
int init_socket(uint16_t port);

#endif