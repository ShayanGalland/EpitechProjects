#ifndef _CLIENT_H
#define _CLIENT_H

#include <arpa/inet.h>

typedef struct
{
    int socket_fd;
    struct sockaddr_in server_address;

    char *uuid;
    char *username;

    char *team_uuid;
    char *channel_uuid;
    char *thread_uuid;
} client_t;

void parse_and_call_command(const char *command, client_t *client);
int get_args_with_quotes(const char *command, char *cmd, char *arg1, char *arg2, char *arg3);

void handle_info(client_t *client);
void handle_list(client_t *client);
void handle_create(const char *arg1, const char *arg2, client_t *client);
void handle_use(const char *team_uuid, const char *channel_uuid, const char *thread_uuid, client_t *client);
void handle_unsubscribe(const char *team_uuid, client_t *client);
void handle_subscribed(const char *team_uuid, client_t *client);
void handle_messages(const char *user_uuid, client_t *client);
void handle_send(const char *user_uuid, const char *message_body, client_t *client);
void handle_user(const char *user_uuid, client_t *client);
void handle_users(client_t *client);
void handle_logout(client_t *client);
void handle_login_command(const char *username, client_t *client);
void handle_help(client_t *client);
void handle_command(const char *command, client_t *client);

void run_cli(client_t *client);
int connect_to_server(client_t *client);
int connect_to_server(client_t *client);
int initialize_client(client_t *client, const char *ip, int port);

#endif // CLIENT_H
