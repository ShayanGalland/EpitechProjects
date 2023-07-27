/*
** EPITECH PROJECT, 2023
** project
** File description:
** h file for c project
*/

#ifndef FTP_H_
#define FTP_H_
#define MAX 100
#define PASSIVE_MODE 0
#define ACTIVE_MODE 1
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

struct client
{
    int socket;
    int mode;
    uint16_t active_mode_port;
    char *username;
    int is_logged;
    char *working_directory;
    int uploded_file;
};
typedef struct client client_t;

void handle_command(char *command, client_t *client);
void handle_LIST_command(char *command, client_t *client);
void handle_STOR_command(char *command, client_t *client);
void handle_RETR_command(char *command, client_t *client);
void handle_NOOP_command(char *command, client_t *client);
void handle_HELP_command(char *command, client_t *client);
void handle_PORT_command(char *command, client_t *client);
void handle_PASV_command(char *command, client_t *client);
void handle_PWD_command(char *command, client_t *client);
void handle_DELE_command(char *command, client_t *client);
void handle_QUIT_command(char *command, client_t *client);
void handle_CDUP_command(char *command, client_t *client);
void handle_PASS_command(char *command, client_t *client);
void handle_USER_command(char *command, client_t *client);
void handle_CWD_command(char *command, client_t *client);
void handle_binary_data(char *data, client_t *client);
char *my_strcat_aloc(char *str1, char *str2);
void send_response(client_t *client, int code, const char *message);
void help();
char *param_gestion(int argc, char **argv);
void free_struct(client_t *connections);
int init_socket(uint16_t port);
client_t *init_connection(int socket, char *path);
void initialize_fd_set(fd_set *fd_set_rd, client_t *connections);
void handle_new_connection(int server_socket, client_t *connections);
void handle_existing_connection(client_t *connection, char *read_buffer);
void client_is_connected(int changed_socket, int server_socket,
client_t *connections, fd_set fd_set_rd);
int start_connection(int server_socket, client_t *connections,
fd_set fd_set_rd);

#endif
