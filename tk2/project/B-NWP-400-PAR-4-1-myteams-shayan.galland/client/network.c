#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/select.h>
#include "network.h"
#include "client.h"
#include "../include/protocol.h"

#include "../libs/myteams/logging_client.h"

uint16_t read_uint16(char *read_buffer, uint16_t *read_offset)
{
    uint16_t output;
    memcpy(&output, &read_buffer[*read_offset], sizeof(uint16_t));
    *read_offset += sizeof(uint16_t);

    return output;
}
uint64_t read_uint64(char *read_buffer, uint16_t *read_offset)
{
    uint64_t output;
    memcpy(&output, &read_buffer[*read_offset], sizeof(uint64_t));
    *read_offset += sizeof(uint64_t);

    return output;
}
char *read_string(char *read_buffer, uint16_t *read_offset)
{
    uint16_t len = read_uint16(read_buffer, read_offset);
    char *output_string = NULL;

    if (len > 0)
    {
        output_string = malloc(sizeof(char) * len + 1);
        strncpy(output_string, &read_buffer[*read_offset], len);
        output_string[len] = '\0';
        *read_offset += len;
    }
    return output_string;
}

void write_uint64(char *write_buffer, uint16_t *write_offset, uint64_t value)
{
    memcpy(&write_buffer[*write_offset], &value, sizeof(uint64_t));
    *write_offset += sizeof(uint64_t);
}
void write_uint16(char *write_buffer, uint16_t *write_offset, uint16_t value)
{
    memcpy(&write_buffer[*write_offset], &value, sizeof(uint16_t));
    *write_offset += sizeof(uint16_t);
}
void write_string(char *write_buffer, uint16_t *write_offset, char *value)
{
    if (value != NULL)
    {
        uint16_t len = strlen(value);
        write_uint16(write_buffer, write_offset, len);
        memcpy(&write_buffer[*write_offset], value, len);
        *write_offset += len;
    }
    else
    {
        write_uint16(write_buffer, write_offset, 0);
    }
}

int read_error_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;
    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    uint16_t error_code = read_buffer[read_offset];
    read_offset++;

    char *uuid = NULL;

    switch (error_code)
    {
    case ERROR_CODE_UNKNOWN_TEAM:
        uuid = read_string(read_buffer, &read_offset);
        client_error_unknown_team(uuid);
        free(uuid);
        break;

    case ERROR_CODE_UNKNOWN_CHANNEL:
        uuid = read_string(read_buffer, &read_offset);
        client_error_unknown_channel(uuid);
        free(uuid);
        break;

    case ERROR_CODE_UNKNOWN_THREAD:
        uuid = read_string(read_buffer, &read_offset);
        client_error_unknown_thread(uuid);
        free(uuid);
        break;

    case ERROR_CODE_UNKNOWN_USER:
        uuid = read_string(read_buffer, &read_offset);
        client_error_unknown_user(uuid);
        free(uuid);
        break;

    case ERROR_CODE_UNAUTHORIZED:
        client_error_unauthorized();
        break;

    case ERROR_CODE_ALREADY_EXISTS:
        client_error_already_exist();
        break;
    }

    return 1 + 2 + write_size;
}

void write_login_packet(client_t *client, char *username)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t write_size = 2 + strlen(username);
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = LOGIN_REQUEST_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    write_string(write_buffer, &write_offset, username);

    write(client->socket_fd, write_buffer, 1 + 2 + write_size);
}
int read_login_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;

    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    client->uuid = read_string(read_buffer, &read_offset);
    client->username = read_string(read_buffer, &read_offset);

    client_event_logged_in(client->uuid, client->username);

    return 1 + 2 + write_size;
}

void write_logout_packet(client_t *client)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t write_size = 0;
    uint16_t write_offset = 1;

    write_buffer[0] = LOGOUT_REQUEST_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    write(client->socket_fd, write_buffer, 1 + 2 + write_size);
}

void write_users_packet(client_t *client)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t write_size = 0;
    uint16_t write_offset = 1;

    write_buffer[0] = USERS_REQUEST_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    write(client->socket_fd, write_buffer, 1 + 2 + write_size);
}
int read_users_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;

    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    char *uuid = read_string(read_buffer, &read_offset);
    char *username = read_string(read_buffer, &read_offset);
    int status = read_buffer[read_offset];

    client_print_users(uuid, username, status);

    return 1 + 2 + write_size;
}

void write_user_packet(client_t *client, char *uuid)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t write_size = 2 + strlen(uuid);
    uint16_t write_offset = 1;

    write_buffer[0] = USER_REQUEST_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    write_string(write_buffer, &write_offset, uuid);

    write(client->socket_fd, write_buffer, 1 + 2 + write_size);
}
int read_user_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;

    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    char *uuid = read_string(read_buffer, &read_offset);
    char *username = read_string(read_buffer, &read_offset);
    int status = read_buffer[read_offset];

    client_print_user(uuid, username, status);

    return 1 + 2 + write_size;
}

void write_send_private_message_packet(client_t *client, char *uuid, char *message)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t write_size = 2 + strlen(uuid) + 2 + strlen(message);
    uint16_t write_offset = 1;

    write_buffer[0] = SEND_PRIVATE_MESSAGE_REQUEST_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    write_string(write_buffer, &write_offset, uuid);
    write_string(write_buffer, &write_offset, message);

    write(client->socket_fd, write_buffer, 1 + 2 + write_size);
}
int read_private_message_received_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;

    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    char *uuid = read_string(read_buffer, &read_offset);
    char *body = read_string(read_buffer, &read_offset);

    client_event_private_message_received(uuid, body);

    free(uuid);
    free(body);

    return 1 + 2 + write_size;
}

void write_messages_request_packet(client_t *client, char *uuid)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t write_size = 2 + strlen(uuid);
    uint16_t write_offset = 1;

    write_buffer[0] = MESSAGES_REQUEST_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    write_string(write_buffer, &write_offset, uuid);

    write(client->socket_fd, write_buffer, 1 + 2 + write_size);
}
int read_messages_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;

    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    char *uuid = read_string(read_buffer, &read_offset);
    char *body = read_string(read_buffer, &read_offset);
    time_t timestamp = read_uint64(read_buffer, &read_offset);

    client_private_message_print_messages(uuid, timestamp, body);

    free(uuid);
    free(body);

    return 1 + 2 + write_size;
}

void write_subscribe_request_packet(client_t *client, char *team_uuid)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t write_size = 2 + strlen(team_uuid);
    uint16_t write_offset = 1;

    write_buffer[0] = SUBSCRIBE_REQUEST_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    write_string(write_buffer, &write_offset, team_uuid);

    write(client->socket_fd, write_buffer, 1 + 2 + write_size);
}
int read_subscribe_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;
    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    char *user_uuid = read_string(read_buffer, &read_offset);
    char *team_uuid = read_string(read_buffer, &read_offset);

    client_print_subscribed(user_uuid, team_uuid);

    free(user_uuid);
    free(team_uuid);

    return 1 + 2 + write_size;
}

void write_subscribed_request_packet(client_t *client, char *team_uuid)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t write_size = 2;
    if (team_uuid != NULL)
        write_size += strlen(team_uuid);
    uint16_t write_offset = 1;

    write_buffer[0] = SUBSCRIBED_REQUEST_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    write_string(write_buffer, &write_offset, team_uuid);

    write(client->socket_fd, write_buffer, 1 + 2 + write_size);
}
int read_subscribed_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;
    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    char *team_uuid = read_string(read_buffer, &read_offset);
    char *team_name = read_string(read_buffer, &read_offset);
    char *team_description = read_string(read_buffer, &read_offset);

    client_print_teams(team_uuid, team_name, team_description);

    free(team_uuid);
    free(team_name);
    free(team_description);

    return 1 + 2 + write_size;
}
int read_subscribed_users_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;
    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    char *user_uuid = read_string(read_buffer, &read_offset);
    char *username = read_string(read_buffer, &read_offset);
    int status = read_buffer[read_offset];

    client_print_users(user_uuid, username, status);

    free(user_uuid);
    free(username);

    return 1 + 2 + write_size;
}

void write_unsubscribe_request_packet(client_t *client, char *team_uuid)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t write_size = 2 + strlen(team_uuid);
    uint16_t write_offset = 1;

    write_buffer[0] = UNSUBSCRIBED_REQUEST_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    write_string(write_buffer, &write_offset, team_uuid);

    write(client->socket_fd, write_buffer, 1 + 2 + write_size);
}
int read_unsubscribe_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;
    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    char *user_uuid = read_string(read_buffer, &read_offset);
    char *team_uuid = read_string(read_buffer, &read_offset);

    client_print_unsubscribed(user_uuid, team_uuid);

    free(user_uuid);
    free(team_uuid);

    return 1 + 2 + write_size;
}

void write_create_request_packet(client_t *client, char *use_team_uuid, char *use_channel_uuid, char *use_thread_uuid, char *arg1, char *arg2)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t write_size = 10;
    if (use_team_uuid != NULL)
        write_size += strlen(use_team_uuid);
    if (use_channel_uuid != NULL)
        write_size += strlen(use_channel_uuid);
    if (use_thread_uuid != NULL)
        write_size += strlen(use_thread_uuid);
    if (arg1 != NULL)
        write_size += strlen(arg1);
    if (arg2 != NULL)
        write_size += strlen(arg2);

    uint16_t write_offset = 1;

    write_buffer[0] = CREATE_REQUEST_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    write_string(write_buffer, &write_offset, use_team_uuid);
    write_string(write_buffer, &write_offset, use_channel_uuid);
    write_string(write_buffer, &write_offset, use_thread_uuid);
    write_string(write_buffer, &write_offset, arg1);
    write_string(write_buffer, &write_offset, arg2);

    write(client->socket_fd, write_buffer, 1 + 2 + write_size);
}
int read_create_team_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;
    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    char *team_uuid = read_string(read_buffer, &read_offset);
    char *team_name = read_string(read_buffer, &read_offset);
    char *team_description = read_string(read_buffer, &read_offset);

    client_print_team_created(team_uuid, team_name, team_description);

    free(team_uuid);
    free(team_name);
    free(team_description);

    return 1 + 2 + write_size;
}
int read_create_channel_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;
    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    char *channel_uuid = read_string(read_buffer, &read_offset);
    char *channel_name = read_string(read_buffer, &read_offset);
    char *channel_description = read_string(read_buffer, &read_offset);

    client_print_channel_created(channel_uuid, channel_name, channel_description);

    free(channel_uuid);
    free(channel_name);
    free(channel_description);

    return 1 + 2 + write_size;
}
int read_create_thread_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;
    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    char *thread_uuid = read_string(read_buffer, &read_offset);
    char *user_uuid = read_string(read_buffer, &read_offset);
    time_t timestamp = read_uint64(read_buffer, &read_offset);
    char *thread_title = read_string(read_buffer, &read_offset);
    char *thread_body = read_string(read_buffer, &read_offset);

    client_print_thread_created(thread_uuid, user_uuid, timestamp, thread_title, thread_body);

    free(thread_uuid);
    free(user_uuid);
    free(thread_title);
    free(thread_body);

    return 1 + 2 + write_size;
}
int read_create_reply_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;
    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    char *thread_uuid = read_string(read_buffer, &read_offset);
    char *user_uuid = read_string(read_buffer, &read_offset);
    time_t timestamp = read_uint64(read_buffer, &read_offset);
    char *body = read_string(read_buffer, &read_offset);

    client_print_reply_created(thread_uuid, user_uuid, timestamp, body);

    free(thread_uuid);
    free(user_uuid);
    free(body);

    return 1 + 2 + write_size;
}

void write_list_request_packet(client_t *client, char *use_team_uuid, char *use_channel_uuid, char *use_thread_uuid)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t write_size = 6;
    if (use_team_uuid != NULL)
        write_size += strlen(use_team_uuid);
    if (use_channel_uuid != NULL)
        write_size += strlen(use_channel_uuid);
    if (use_thread_uuid != NULL)
        write_size += strlen(use_thread_uuid);
    uint16_t write_offset = 1;

    write_buffer[0] = LIST_REQUEST_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    write_string(write_buffer, &write_offset, use_team_uuid);
    write_string(write_buffer, &write_offset, use_channel_uuid);
    write_string(write_buffer, &write_offset, use_thread_uuid);

    write(client->socket_fd, write_buffer, 1 + 2 + write_size);
}
int read_list_team_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;
    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    char *team_uuid = read_string(read_buffer, &read_offset);
    char *team_name = read_string(read_buffer, &read_offset);
    char *team_description = read_string(read_buffer, &read_offset);

    client_print_teams(team_uuid, team_name, team_description);

    free(team_uuid);
    free(team_name);
    free(team_description);

    return 1 + 2 + write_size;
}
int read_list_channel_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;
    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    char *channel_uuid = read_string(read_buffer, &read_offset);
    char *channel_name = read_string(read_buffer, &read_offset);
    char *channel_description = read_string(read_buffer, &read_offset);

    client_team_print_channels(channel_uuid, channel_name, channel_description);

    free(channel_uuid);
    free(channel_name);
    free(channel_description);

    return 1 + 2 + write_size;
}
int read_list_thread_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;
    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    char *thread_uuid = read_string(read_buffer, &read_offset);
    char *user_uuid = read_string(read_buffer, &read_offset);
    time_t timestamp = read_uint64(read_buffer, &read_offset);
    char *thread_title = read_string(read_buffer, &read_offset);
    char *thread_body = read_string(read_buffer, &read_offset);

    client_channel_print_threads(thread_uuid, user_uuid, timestamp, thread_title, thread_body);

    free(thread_uuid);
    free(user_uuid);
    free(thread_title);
    free(thread_body);

    return 1 + 2 + write_size;
}
int read_list_reply_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;
    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    char *thread_uuid = read_string(read_buffer, &read_offset);
    char *user_uuid = read_string(read_buffer, &read_offset);
    time_t timestamp = read_uint64(read_buffer, &read_offset);
    char *body = read_string(read_buffer, &read_offset);

    client_thread_print_replies(thread_uuid, user_uuid, timestamp, body);

    free(thread_uuid);
    free(user_uuid);
    free(body);

    return 1 + 2 + write_size;
}

void write_info_request_packet(client_t *client, char *use_team_uuid, char *use_channel_uuid, char *use_thread_uuid)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t write_size = 6;
    if (use_team_uuid != NULL)
        write_size += strlen(use_team_uuid);
    if (use_channel_uuid != NULL)
        write_size += strlen(use_channel_uuid);
    if (use_thread_uuid != NULL)
        write_size += strlen(use_thread_uuid);
    uint16_t write_offset = 1;

    write_buffer[0] = INFO_REQUEST_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    write_string(write_buffer, &write_offset, use_team_uuid);
    write_string(write_buffer, &write_offset, use_channel_uuid);
    write_string(write_buffer, &write_offset, use_thread_uuid);

    write(client->socket_fd, write_buffer, 1 + 2 + write_size);
}
int read_info_user_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;

    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    char *uuid = read_string(read_buffer, &read_offset);
    char *username = read_string(read_buffer, &read_offset);
    int status = read_buffer[read_offset];

    client_print_user(uuid, username, status);

    free(uuid);
    free(username);

    return 1 + 2 + write_size;
}
int read_info_team_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;
    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    char *team_uuid = read_string(read_buffer, &read_offset);
    char *team_name = read_string(read_buffer, &read_offset);
    char *team_description = read_string(read_buffer, &read_offset);

    client_print_team(team_uuid, team_name, team_description);

    free(team_uuid);
    free(team_name);
    free(team_description);

    return 1 + 2 + write_size;
}
int read_info_channel_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;
    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    char *channel_uuid = read_string(read_buffer, &read_offset);
    char *channel_name = read_string(read_buffer, &read_offset);
    char *channel_description = read_string(read_buffer, &read_offset);

    client_print_channel(channel_uuid, channel_name, channel_description);

    free(channel_uuid);
    free(channel_name);
    free(channel_description);

    return 1 + 2 + write_size;
}
int read_info_thread_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;
    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    char *thread_uuid = read_string(read_buffer, &read_offset);
    char *user_uuid = read_string(read_buffer, &read_offset);
    time_t timestamp = read_uint64(read_buffer, &read_offset);
    char *thread_title = read_string(read_buffer, &read_offset);
    char *thread_body = read_string(read_buffer, &read_offset);

    client_print_thread(thread_uuid, user_uuid, timestamp, thread_title, thread_body);

    free(thread_uuid);
    free(user_uuid);
    free(thread_title);
    free(thread_body);

    return 1 + 2 + write_size;
}

int read_team_created_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;
    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    char *team_uuid = read_string(read_buffer, &read_offset);
    char *team_name = read_string(read_buffer, &read_offset);
    char *team_description = read_string(read_buffer, &read_offset);

    client_event_team_created(team_uuid, team_name, team_description);

    free(team_uuid);
    free(team_name);
    free(team_description);

    return 1 + 2 + write_size;
}
int read_channel_created_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;
    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    char *channel_uuid = read_string(read_buffer, &read_offset);
    char *channel_name = read_string(read_buffer, &read_offset);
    char *channel_description = read_string(read_buffer, &read_offset);

    client_event_channel_created(channel_uuid, channel_name, channel_description);

    free(channel_uuid);
    free(channel_name);
    free(channel_description);

    return 1 + 2 + write_size;
}
int read_thread_created_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;
    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    char *thread_uuid = read_string(read_buffer, &read_offset);
    char *user_uuid = read_string(read_buffer, &read_offset);
    time_t timestamp = read_uint64(read_buffer, &read_offset);
    char *thread_title = read_string(read_buffer, &read_offset);
    char *thread_body = read_string(read_buffer, &read_offset);

    client_event_thread_created(thread_uuid, user_uuid, timestamp, thread_title, thread_body);

    free(thread_uuid);
    free(user_uuid);
    free(thread_title);
    free(thread_body);

    return 1 + 2 + write_size;
}
int read_reply_received_response_packet(client_t *client, char *read_buffer)
{
    uint16_t read_offset = 1;
    uint16_t write_size = read_uint16(read_buffer, &read_offset);

    char *team_uuid = read_string(read_buffer, &read_offset);
    char *thread_uuid = read_string(read_buffer, &read_offset);
    char *user_uuid = read_string(read_buffer, &read_offset);
    char *reply_body = read_string(read_buffer, &read_offset);

    client_event_thread_reply_received(team_uuid, thread_uuid, user_uuid, reply_body);

    free(team_uuid);
    free(thread_uuid);
    free(user_uuid);
    free(reply_body);

    return 1 + 2 + write_size;
}