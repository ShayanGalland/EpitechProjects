#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/select.h>
#include "client.h"
#include "../include/protocol.h"

#include "../libs/myteams/logging_client.h"

int initialize_client(client_t *client, const char *ip, int port)
{
    client->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->socket_fd < 0)
    {
        perror("socket");
        return -1;
    }

    memset(&client->server_address, 0, sizeof(client->server_address));
    client->server_address.sin_family = AF_INET;
    client->server_address.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &client->server_address.sin_addr) <= 0)
    {
        perror("inet_pton");
        return -1;
    }

    client->uuid = NULL;
    client->username = NULL;
    client->team_uuid = NULL;
    client->channel_uuid = NULL;
    client->thread_uuid = NULL;

    return 0;
}
int connect_to_server(client_t *client)
{
    if (connect(client->socket_fd, (struct sockaddr *)&client->server_address, sizeof(client->server_address)) < 0)
    {
        perror("connect");
        return -1;
    }
    return 0;
}
void close_client(client_t *client)
{
    if (client->uuid != NULL)
    {
        free(client->uuid);
        client->uuid = NULL;
    }

    if (client->username != NULL)
    {
        free(client->username);
        client->username = NULL;
    }

    if (client->team_uuid != NULL)
    {
        free(client->team_uuid);
        client->team_uuid = NULL;
    }

    if (client->channel_uuid != NULL)
    {
        free(client->channel_uuid);
        client->channel_uuid = NULL;
    }

    if (client->thread_uuid != NULL)
    {
        free(client->thread_uuid);
        client->thread_uuid = NULL;
    }

    close(client->socket_fd);
}

void run_cli(client_t *client)
{
    fd_set read_fds;

    while (1)
    {
        FD_ZERO(&read_fds);
        FD_SET(STDIN_FILENO, &read_fds);
        FD_SET(client->socket_fd, &read_fds);

        select(client->socket_fd + 1, &read_fds, NULL, NULL, NULL);

        if (FD_ISSET(client->socket_fd, &read_fds) != 0)
        {
            char read_buffer[65536];
            char *message = &read_buffer;
            memset(read_buffer, 0, sizeof(read_buffer));
            int read_buffer_len = read(client->socket_fd, read_buffer, sizeof(read_buffer));

            int read_bytes = 0;

            while (read_bytes < read_buffer_len)
            {
                switch (message[0])
                {
                case ERROR_RESPONSE_PACKET_ID:
                    read_bytes += read_error_response_packet(client, message);
                    break;

                case LOGIN_RESPONSE_PACKET_ID:
                    read_bytes += read_login_response_packet(client, message);
                    break;

                case USERS_RESPONSE_PACKET_ID:
                    read_bytes += read_users_response_packet(client, message);
                    break;

                case USER_RESPONSE_PACKET_ID:
                    read_bytes += read_user_response_packet(client, message);
                    break;

                case PRIVATE_MESSAGE_RECEIVED_RESPONSE_PACKET_ID:
                    read_bytes += read_private_message_received_response_packet(client, message);
                    break;

                case MESSAGES_RESPONSE_PACKET_ID:
                    read_bytes += read_messages_response_packet(client, message);
                    break;

                case CREATE_TEAM_RESPONSE_PACKET_ID:
                    read_bytes += read_create_team_response_packet(client, message);
                    break;
                case CREATE_CHANNEL_RESPONSE_PACKET_ID:
                    read_bytes += read_create_channel_response_packet(client, message);
                    break;
                case CREATE_THREAD_RESPONSE_PACKET_ID:
                    read_bytes += read_create_thread_response_packet(client, message);
                    break;
                case CREATE_REPLY_RESPONSE_PACKET_ID:
                    read_bytes += read_create_reply_response_packet(client, message);
                    break;

                case LIST_TEAMS_RESPONSE_PACKET_ID:
                    read_bytes += read_list_team_response_packet(client, message);
                    break;
                case LIST_CHANNELS_RESPONSE_PACKET_ID:
                    read_bytes += read_list_channel_response_packet(client, message);
                    break;
                case LIST_THREADS_RESPONSE_PACKET_ID:
                    read_bytes += read_list_thread_response_packet(client, message);
                    break;
                case LIST_REPLIES_RESPONSE_PACKET_ID:
                    read_bytes += read_list_reply_response_packet(client, message);
                    break;

                case INFO_USER_RESPONSE_PACKET_ID:
                    read_bytes += read_info_user_response_packet(client, message);
                    break;
                case INFO_TEAM_RESPONSE_PACKET_ID:
                    read_bytes += read_info_team_response_packet(client, message);
                    break;
                case INFO_CHANNEL_RESPONSE_PACKET_ID:
                    read_bytes += read_info_channel_response_packet(client, message);
                    break;
                case INFO_THREAD_RESPONSE_PACKET_ID:
                    read_bytes += read_info_thread_response_packet(client, message);
                    break;

                case SUBSCRIBE_RESPONSE_PACKET_ID:
                    read_bytes += read_subscribe_response_packet(client, message);
                    break;

                case SUBSCRIBED_RESPONSE_PACKET_ID:
                    read_bytes += read_subscribed_response_packet(client, message);
                    break;
                case SUBSCRIBED_USERS_RESPONSE_PACKET_ID:
                    read_bytes += read_subscribed_users_response_packet(client, message);
                    break;

                case UNSUBSCRIBED_RESPONSE_PACKET_ID:
                    read_bytes += read_unsubscribe_response_packet(client, message);
                    break;

                case TEAM_CREATED_RESPONSE_PACKET_ID:
                    read_bytes += read_team_created_response_packet(client, message);
                    break;
                case CHANNEL_CREATED_RESPONSE_PACKET_ID:
                    read_bytes += read_channel_created_response_packet(client, message);
                    break;
                case THREAD_CREATED_RESPONSE_PACKET_ID:
                    read_bytes += read_thread_created_response_packet(client, message);
                    break;
                case REPLY_RECEIVED_RESPONSE_PACKET_ID:
                    read_bytes += read_reply_received_response_packet(client, message);
                    break;
                }

                message += read_bytes;
            }
        }

        if (FD_ISSET(STDIN_FILENO, &read_fds))
        {
            char command[1024];
            memset(command, 0, sizeof(command));
            int len = read(0, command, sizeof(command));
            command[len - 1] = '\0';
            handle_command(command, client);
        }
    }
}

void handle_command(const char *command, client_t *client)
{
    if (command != NULL)
    {
        parse_and_call_command(command, client);
    }
    else
    {
        write(client->socket_fd, "Invalid command. Type /help for available commands.\n", 53);
    }
}

void handle_help(client_t *client)
{
}

void handle_login_command(const char *username, client_t *client)
{
    write_login_packet(client, username);
}

void handle_logout(client_t *client)
{
    write_logout_packet(client);
    close(client->socket_fd);
    if (client->uuid != NULL && client->username != NULL)
        client_event_logged_out(client->uuid, client->username);
    exit(0);
}

void handle_users(client_t *client)
{
    write_users_packet(client);
}

void handle_user(const char *user_uuid, client_t *client)
{
    write_user_packet(client, user_uuid);
}

void handle_send(const char *user_uuid, const char *message_body, client_t *client)
{
    write_send_private_message_packet(client, user_uuid, message_body);
}

void handle_messages(const char *user_uuid, client_t *client)
{
    write_messages_request_packet(client, user_uuid);
}

void handle_subscribe(const char *team_uuid, client_t *client)
{
    write_subscribe_request_packet(client, team_uuid);
}

void handle_subscribed(const char *team_uuid, client_t *client)
{
    write_subscribed_request_packet(client, team_uuid);
}

void handle_unsubscribe(const char *team_uuid, client_t *client)
{
    write_unsubscribe_request_packet(client, team_uuid);
}

void handle_use(const char *team_uuid, const char *channel_uuid, const char *thread_uuid, client_t *client)
{
    if (client->team_uuid != NULL)
    {
        free(client->team_uuid);
        client->team_uuid = NULL;
    }

    if (client->channel_uuid != NULL)
    {
        free(client->channel_uuid);
        client->channel_uuid = NULL;
    }

    if (client->thread_uuid != NULL)
    {
        free(client->thread_uuid);
        client->thread_uuid = NULL;
    }

    if (team_uuid != NULL)
        client->team_uuid = strdup(team_uuid);

    if (channel_uuid != NULL)
        client->channel_uuid = strdup(channel_uuid);

    if (thread_uuid != NULL)
        client->thread_uuid = strdup(thread_uuid);
}

void handle_create(const char *arg1, const char *arg2, client_t *client)
{
    write_create_request_packet(client, client->team_uuid, client->channel_uuid, client->thread_uuid, arg1, arg2);
}

void handle_list(client_t *client)
{
    write_list_request_packet(client, client->team_uuid, client->channel_uuid, client->thread_uuid);
}

void handle_info(client_t *client)
{
    write_info_request_packet(client, client->team_uuid, client->channel_uuid, client->thread_uuid);
}

int extract_arg(char* start, char* arg)
{
    char* first_quote = strchr(start, '"');
    if(first_quote == NULL)
        return -1;

    char* second_quote = strchr(first_quote+1, '"');
    if(second_quote == NULL)
        return -1;

    strncpy(arg, first_quote+1, second_quote-first_quote-1);

    return second_quote-first_quote+2;
}
int get_args_with_quotes(const char *command, char *cmd, char *arg1, char *arg2, char *arg3)
{
    int arg_count = 0;
    const char *start = command;
    char *end;

    cmd[0] = arg1[0] = arg2[0] = arg3[0] = '\0';

    end = strchr(start, ' ');
    if (end == NULL)
    {
        strcpy(cmd, start);
        return arg_count;
    }

    strncpy(cmd, start, end-start);

    int extact_ret = extract_arg(end, arg1);
    if(extact_ret == -1)
        return -1;
    
    arg_count++;
    
    end += extact_ret;
    if(strlen(end) < 2)
        return arg_count;

    extact_ret = extract_arg(end, arg2);
    if(extact_ret == -1)
        return -1;
    
    arg_count++;
    
    end += extact_ret;
    if(strlen(end) < 2)
        return arg_count;

    extact_ret = extract_arg(end, arg3);
    if(extact_ret == -1)
        return -1;
    
    arg_count++;
    return arg_count;
}

void parse_and_call_command(const char *command, client_t *client)
{
    char cmd[MAX_BODY_LENGTH], arg1[MAX_BODY_LENGTH], arg2[MAX_BODY_LENGTH], arg3[MAX_BODY_LENGTH];
    memset(cmd, 0, MAX_BODY_LENGTH);
    memset(arg1, 0, MAX_BODY_LENGTH);
    memset(arg2, 0, MAX_BODY_LENGTH);
    memset(arg3, 0, MAX_BODY_LENGTH);

    int arg_count = get_args_with_quotes(command, cmd, arg1, arg2, arg3);

    if (strcmp(cmd, "/help") == 0)
    {
        handle_help(client);
    }
    else if (strcmp(cmd, "/login") == 0 && arg_count == 1)
    {
        handle_login_command(arg1, client);
    }
    else if (strcmp(cmd, "/logout") == 0 && arg_count == 0)
    {
        handle_logout(client);
    }
    else if (strcmp(cmd, "/users") == 0 && arg_count == 0)
    {
        handle_users(client);
    }
    else if (strcmp(cmd, "/user") == 0 && arg_count == 1)
    {
        handle_user(arg1, client);
    }
    else if (strcmp(cmd, "/send") == 0 && arg_count == 2)
    {
        handle_send(arg1, arg2, client);
    }
    else if (strcmp(cmd, "/messages") == 0 && arg_count == 1)
    {
        handle_messages(arg1, client);
    }
    else if (strcmp(cmd, "/subscribe") == 0 && arg_count == 1)
    {
        handle_subscribe(arg1, client);
    }
    else if (strcmp(cmd, "/subscribed") == 0 && arg_count <= 1)
    {
        handle_subscribed(arg1, client);
    }
    else if (strcmp(cmd, "/unsubscribe") == 0 && arg_count == 1)
    {
        handle_unsubscribe(arg1, client);
    }
    else if (strcmp(cmd, "/use") == 0 && arg_count <= 3)
    {
        handle_use(arg1, arg2, arg3, client);
    }
    else if (strcmp(cmd, "/create") == 0 && arg_count > 0 & arg_count <= 2)
    {
        handle_create(arg1, arg2, client);
    }
    else if (strcmp(cmd, "/list") == 0 && arg_count == 0)
    {
        handle_list(client);
    }
    else if (strcmp(cmd, "/info") == 0 && arg_count == 0)
    {
        handle_info(client);
    }
    else
    {
        printf("Invalid arguments. Type /help for available commands.\n");
    }
}
