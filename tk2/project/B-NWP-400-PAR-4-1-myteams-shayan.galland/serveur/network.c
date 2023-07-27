#include "network.h"

#define USLEEP_TIME 50000

uint16_t read_uint16(char *read_buffer, uint16_t *read_offset)
{
    uint16_t output;
    memcpy(&output, &read_buffer[*read_offset], sizeof(uint16_t));
    *read_offset += sizeof(uint16_t);

    return output;
}
uint32_t read_uint32(char *read_buffer, uint16_t *read_offset)
{
    uint32_t output;
    memcpy(&output, &read_buffer[*read_offset], sizeof(uint32_t));
    *read_offset += sizeof(uint32_t);

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

void write_uint16(char *write_buffer, uint16_t *write_offset, uint16_t value)
{
    memcpy(&write_buffer[*write_offset], &value, sizeof(uint16_t));
    *write_offset += sizeof(uint16_t);
}
void write_uint32(char *write_buffer, uint16_t *write_offset, uint32_t value)
{
    memcpy(&write_buffer[*write_offset], &value, sizeof(uint32_t));
    *write_offset += sizeof(uint32_t);
}
void write_uint64(char *write_buffer, uint16_t *write_offset, uint64_t value)
{
    memcpy(&write_buffer[*write_offset], &value, sizeof(uint64_t));
    *write_offset += sizeof(uint64_t);
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

void write_error_reponse_packet(client_t *connection, int error_code, char *uuid)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t write_size = 1;
    uint16_t write_offset = 1;

    if (uuid != NULL)
    {
        uint16_t uuid_len = strlen(uuid);
        write_size += 2 + uuid_len;
    }

    // HEADER
    write_buffer[0] = ERROR_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    write_buffer[write_offset] = error_code;
    write_offset++;

    if (uuid != NULL)
        write_string(write_buffer, &write_offset, uuid);

    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}

void read_login_packet(server_t *server, client_t *connection, char *read_buffer)
{
    uint16_t read_offset = 1;

    uint16_t write_size = read_uint16(read_buffer, &read_offset);
    connection->username = read_string(read_buffer, &read_offset);
}
void write_login_response_packet(client_t *connection, char *uuid, char *username)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t username_len = strlen(username);
    uint16_t uuid_len = strlen(uuid);
    uint16_t write_size = 2 + uuid_len + 2 + username_len;
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = LOGIN_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    // PAYLOAD
    write_string(write_buffer, &write_offset, uuid);

    write_string(write_buffer, &write_offset, username);

    usleep(USLEEP_TIME);
    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}

void read_logout_packet(server_t *server, client_t *connection, char *read_buffer)
{
    //
}

void read_users_packet(server_t *server, client_t *connection, char *read_buffer)
{
    //
}
void write_users_response_packet(client_t *connection, char *uuid, char *username, int status)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t username_len = strlen(username);
    uint16_t uuid_len = strlen(uuid);
    uint16_t write_size = 2 + uuid_len + 2 + username_len + 1;
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = USERS_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    // PAYLOAD
    write_string(write_buffer, &write_offset, uuid);
    write_string(write_buffer, &write_offset, username);
    write_buffer[write_offset] = status;

    usleep(USLEEP_TIME);
    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}

void read_user_packet(server_t *server, client_t *connection, char *read_buffer)
{
    uint16_t read_offset = 1;

    uint16_t write_size = read_uint16(read_buffer, &read_offset);
    connection->arg1 = read_string(read_buffer, &read_offset);
}
void write_user_response_packet(client_t *connection, char *uuid, char *username, int status)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t username_len = strlen(username);
    uint16_t uuid_len = strlen(uuid);
    uint16_t write_size = 2 + uuid_len + 2 + username_len + 1;
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = USER_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    // PAYLOAD
    write_string(write_buffer, &write_offset, uuid);
    write_string(write_buffer, &write_offset, username);
    write_buffer[write_offset] = status;

    usleep(USLEEP_TIME);
    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}

void read_send_private_message_packet(server_t *server, client_t *connection, char *read_buffer)
{
    uint16_t read_offset = 1;

    uint16_t write_size = read_uint16(read_buffer, &read_offset);
    connection->arg1 = read_string(read_buffer, &read_offset);
    connection->arg2 = read_string(read_buffer, &read_offset);
}
void write_private_message_received_response_packet(client_t *connection, char *uuid, char *body)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t body_len = strlen(body);
    uint16_t uuid_len = strlen(uuid);
    uint16_t write_size = 2 + uuid_len + 2 + body_len + 1;
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = PRIVATE_MESSAGE_RECEIVED_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    // PAYLOAD
    write_string(write_buffer, &write_offset, uuid);
    write_string(write_buffer, &write_offset, body);

    usleep(USLEEP_TIME);
    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}

void read_messages_packet(server_t *server, client_t *connection, char *read_buffer)
{
    uint16_t read_offset = 1;

    uint16_t write_size = read_uint16(read_buffer, &read_offset);
    connection->arg1 = read_string(read_buffer, &read_offset);
}
void write_messages_response_packet(client_t *connection, char *uuid, char *body, time_t timestamp)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t uuid_len = strlen(uuid);
    uint16_t body_len = strlen(body);
    uint16_t write_size = 2 + uuid_len + 2 + body_len + sizeof(time_t);
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = USER_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    // PAYLOAD
    write_string(write_buffer, &write_offset, uuid);
    write_string(write_buffer, &write_offset, body);
    write_uint64(write_buffer, &write_offset, timestamp);

    usleep(USLEEP_TIME);
    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}

void read_subscribe_request_packet(server_t *server, client_t *connection, char *read_buffer)
{
    uint16_t read_offset = 1;

    uint16_t write_size = read_uint16(read_buffer, &read_offset);
    connection->arg1 = read_string(read_buffer, &read_offset);
}
void write_subscribe_response_packet(client_t *connection, char *user_uuid, char *team_uuid)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t user_uuid_len = strlen(user_uuid);
    uint16_t team_uuid_len = strlen(team_uuid);
    uint16_t write_size = 2 + user_uuid_len + 2 + team_uuid_len;
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = SUBSCRIBE_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    // PAYLOAD
    write_string(write_buffer, &write_offset, user_uuid);
    write_string(write_buffer, &write_offset, team_uuid);

    usleep(USLEEP_TIME);
    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}

void read_subscribed_request_packet(server_t *server, client_t *connection, char *read_buffer)
{
    uint16_t read_offset = 1;

    uint16_t write_size = read_uint16(read_buffer, &read_offset);
    connection->arg1 = read_string(read_buffer, &read_offset);
}
void write_subscribed_response_packet(client_t *connection, char *team_uuid, char *team_name, char *team_description)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t uuid_len = strlen(team_uuid);
    uint16_t name_len = strlen(team_name);
    uint16_t description_len = strlen(team_description);

    uint16_t write_size = 2 + uuid_len + 2 + name_len + 2 + description_len;
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = SUBSCRIBED_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    // PAYLOAD
    write_string(write_buffer, &write_offset, team_uuid);
    write_string(write_buffer, &write_offset, team_name);
    write_string(write_buffer, &write_offset, team_description);

    usleep(USLEEP_TIME);
    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}
void write_subscribed_users_response_packet(client_t *connection, char *uuid, char *username, int status)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t username_len = strlen(username);
    uint16_t uuid_len = strlen(uuid);
    uint16_t write_size = 2 + uuid_len + 2 + username_len + 1;
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = SUBSCRIBED_USERS_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    // PAYLOAD
    write_string(write_buffer, &write_offset, uuid);
    write_string(write_buffer, &write_offset, username);
    write_buffer[write_offset] = status;

    usleep(USLEEP_TIME);
    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}

void read_unsubscribe_request_packet(server_t *server, client_t *connection, char *read_buffer)
{
    uint16_t read_offset = 1;

    uint16_t write_size = read_uint16(read_buffer, &read_offset);
    connection->arg1 = read_string(read_buffer, &read_offset);
}
void write_unsubscribe_response_packet(client_t *connection, char *user_uuid, char *team_uuid)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t user_uuid_len = strlen(user_uuid);
    uint16_t team_uuid_len = strlen(team_uuid);
    uint16_t write_size = 2 + user_uuid_len + 2 + team_uuid_len;
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = UNSUBSCRIBED_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    // PAYLOAD
    write_string(write_buffer, &write_offset, user_uuid);
    write_string(write_buffer, &write_offset, team_uuid);

    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}

void read_create_request_packet(server_t *server, client_t *connection, char *read_buffer)
{
    uint16_t read_offset = 1;

    uint16_t write_size = read_uint16(read_buffer, &read_offset);
    connection->arg1 = read_string(read_buffer, &read_offset); // use_team_uuid
    connection->arg2 = read_string(read_buffer, &read_offset); // use_channel_uuid
    connection->arg3 = read_string(read_buffer, &read_offset); // use_thread_uuid
    connection->arg4 = read_string(read_buffer, &read_offset); // arg1
    connection->arg5 = read_string(read_buffer, &read_offset); // arg2
}
void write_create_team_response_packet(client_t *connection, char *team_uuid, char *team_name, char *team_description)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t uuid_len = strlen(team_uuid);
    uint16_t name_len = strlen(team_name);
    uint16_t description_len = strlen(team_description);

    uint16_t write_size = 2 + uuid_len + 2 + name_len + 2 + description_len;
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = CREATE_TEAM_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    // PAYLOAD
    write_string(write_buffer, &write_offset, team_uuid);
    write_string(write_buffer, &write_offset, team_name);
    write_string(write_buffer, &write_offset, team_description);

    usleep(USLEEP_TIME);
    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}
void write_create_channel_response_packet(client_t *connection, char *channel_uuid, char *channel_name, char *channel_description)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t uuid_len = strlen(channel_uuid);
    uint16_t name_len = strlen(channel_name);
    uint16_t description_len = strlen(channel_description);

    uint16_t write_size = 2 + uuid_len + 2 + name_len + 2 + description_len;
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = CREATE_CHANNEL_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    // PAYLOAD
    write_string(write_buffer, &write_offset, channel_uuid);
    write_string(write_buffer, &write_offset, channel_name);
    write_string(write_buffer, &write_offset, channel_description);

    usleep(USLEEP_TIME);
    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}
void write_create_thread_response_packet(client_t *connection, char *thread_uuid, char *user_uuid, time_t timestamp, char *thread_title, char *thread_body)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t uuid_len = strlen(thread_uuid);
    uint16_t user_uuid_len = strlen(user_uuid);
    uint16_t title_len = strlen(thread_title);
    uint16_t body_len = strlen(thread_body);

    uint16_t write_size = 2 + uuid_len + 2 + title_len + 2 + body_len + 2 + user_uuid_len + sizeof(time_t);
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = CREATE_THREAD_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    // PAYLOAD
    write_string(write_buffer, &write_offset, thread_uuid);
    write_string(write_buffer, &write_offset, user_uuid);
    write_uint64(write_buffer, &write_offset, timestamp);
    write_string(write_buffer, &write_offset, thread_title);
    write_string(write_buffer, &write_offset, thread_body);

    usleep(USLEEP_TIME);
    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}
void write_create_reply_response_packet(client_t *connection, char *thread_uuid, char *user_uuid, time_t timestamp, char *body)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t uuid_len = strlen(thread_uuid);
    uint16_t user_uuid_len = strlen(user_uuid);
    uint16_t body_len = strlen(body);

    uint16_t write_size = 2 + uuid_len + 2 + body_len + 2 + user_uuid_len + sizeof(time_t);
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = CREATE_REPLY_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    // PAYLOAD
    write_string(write_buffer, &write_offset, thread_uuid);
    write_string(write_buffer, &write_offset, user_uuid);
    write_uint64(write_buffer, &write_offset, timestamp);
    write_string(write_buffer, &write_offset, body);

    usleep(USLEEP_TIME);
    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}

void read_list_request_packet(server_t *server, client_t *connection, char *read_buffer)
{
    uint16_t read_offset = 1;

    uint16_t write_size = read_uint16(read_buffer, &read_offset);
    connection->arg1 = read_string(read_buffer, &read_offset); // use_team_uuid
    connection->arg2 = read_string(read_buffer, &read_offset); // use_channel_uuid
    connection->arg3 = read_string(read_buffer, &read_offset); // use_thread_uuid
}
void write_list_team_response_packet(client_t *connection, char *team_uuid, char *team_name, char *team_description)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t uuid_len = strlen(team_uuid);
    uint16_t name_len = strlen(team_name);
    uint16_t description_len = strlen(team_description);

    uint16_t write_size = 2 + uuid_len + 2 + name_len + 2 + description_len;
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = LIST_TEAMS_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    // PAYLOAD
    write_string(write_buffer, &write_offset, team_uuid);
    write_string(write_buffer, &write_offset, team_name);
    write_string(write_buffer, &write_offset, team_description);

    usleep(USLEEP_TIME);
    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}
void write_list_channel_response_packet(client_t *connection, char *channel_uuid, char *channel_name, char *channel_description)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t uuid_len = strlen(channel_uuid);
    uint16_t name_len = strlen(channel_name);
    uint16_t description_len = strlen(channel_description);

    uint16_t write_size = 2 + uuid_len + 2 + name_len + 2 + description_len;
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = LIST_CHANNELS_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    // PAYLOAD
    write_string(write_buffer, &write_offset, channel_uuid);
    write_string(write_buffer, &write_offset, channel_name);
    write_string(write_buffer, &write_offset, channel_description);

    usleep(USLEEP_TIME);
    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}
void write_list_thread_response_packet(client_t *connection, char *thread_uuid, char *user_uuid, time_t timestamp, char *thread_title, char *thread_body)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t uuid_len = strlen(thread_uuid);
    uint16_t user_uuid_len = strlen(user_uuid);
    uint16_t title_len = strlen(thread_title);
    uint16_t body_len = strlen(thread_body);

    uint16_t write_size = 2 + uuid_len + 2 + title_len + 2 + body_len + 2 + user_uuid_len + sizeof(time_t);
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = LIST_THREADS_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    // PAYLOAD
    write_string(write_buffer, &write_offset, thread_uuid);
    write_string(write_buffer, &write_offset, user_uuid);
    write_uint64(write_buffer, &write_offset, timestamp);
    write_string(write_buffer, &write_offset, thread_title);
    write_string(write_buffer, &write_offset, thread_body);

    usleep(USLEEP_TIME);
    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}
void write_list_reply_response_packet(client_t *connection, char *thread_uuid, char *user_uuid, time_t timestamp, char *body)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t uuid_len = strlen(thread_uuid);
    uint16_t user_uuid_len = strlen(user_uuid);
    uint16_t body_len = strlen(body);

    uint16_t write_size = 2 + uuid_len + 2 + body_len + 2 + user_uuid_len + sizeof(time_t);
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = LIST_REPLIES_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    // PAYLOAD
    write_string(write_buffer, &write_offset, thread_uuid);
    write_string(write_buffer, &write_offset, user_uuid);
    write_uint64(write_buffer, &write_offset, timestamp);
    write_string(write_buffer, &write_offset, body);

    usleep(USLEEP_TIME);
    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}

void read_info_request_packet(server_t *server, client_t *connection, char *read_buffer)
{
    uint16_t read_offset = 1;

    uint16_t write_size = read_uint16(read_buffer, &read_offset);
    connection->arg1 = read_string(read_buffer, &read_offset); // use_team_uuid
    connection->arg2 = read_string(read_buffer, &read_offset); // use_channel_uuid
    connection->arg3 = read_string(read_buffer, &read_offset); // use_thread_uuid
}
void write_info_user_response_packet(client_t *connection, char *uuid, char *username, int status)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t username_len = strlen(username);
    uint16_t uuid_len = strlen(uuid);
    uint16_t write_size = 2 + uuid_len + 2 + username_len + 1;
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = INFO_USER_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    // PAYLOAD
    write_string(write_buffer, &write_offset, uuid);
    write_string(write_buffer, &write_offset, username);
    write_buffer[write_offset] = status;

    usleep(USLEEP_TIME);
    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}
void write_info_team_response_packet(client_t *connection, char *team_uuid, char *team_name, char *team_description)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t uuid_len = strlen(team_uuid);
    uint16_t name_len = strlen(team_name);
    uint16_t description_len = strlen(team_description);

    uint16_t write_size = 2 + uuid_len + 2 + name_len + 2 + description_len;
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = INFO_TEAM_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    // PAYLOAD
    write_string(write_buffer, &write_offset, team_uuid);
    write_string(write_buffer, &write_offset, team_name);
    write_string(write_buffer, &write_offset, team_description);

    usleep(USLEEP_TIME);
    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}
void write_info_channel_response_packet(client_t *connection, char *channel_uuid, char *channel_name, char *channel_description)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t uuid_len = strlen(channel_uuid);
    uint16_t name_len = strlen(channel_name);
    uint16_t description_len = strlen(channel_description);

    uint16_t write_size = 2 + uuid_len + 2 + name_len + 2 + description_len;
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = INFO_CHANNEL_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    // PAYLOAD
    write_string(write_buffer, &write_offset, channel_uuid);
    write_string(write_buffer, &write_offset, channel_name);
    write_string(write_buffer, &write_offset, channel_description);

    usleep(USLEEP_TIME);
    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}
void write_info_thread_response_packet(client_t *connection, char *thread_uuid, char *user_uuid, time_t timestamp, char *thread_title, char *thread_body)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t uuid_len = strlen(thread_uuid);
    uint16_t user_uuid_len = strlen(user_uuid);
    uint16_t title_len = strlen(thread_title);
    uint16_t body_len = strlen(thread_body);

    uint16_t write_size = 2 + uuid_len + 2 + title_len + 2 + body_len + 2 + user_uuid_len + sizeof(time_t);
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = INFO_THREAD_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    // PAYLOAD
    write_string(write_buffer, &write_offset, thread_uuid);
    write_string(write_buffer, &write_offset, user_uuid);
    write_uint64(write_buffer, &write_offset, timestamp);
    write_string(write_buffer, &write_offset, thread_title);
    write_string(write_buffer, &write_offset, thread_body);

    usleep(USLEEP_TIME);
    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}

void write_team_created_response_packet(client_t *connection, char *team_uuid, char *team_name, char *team_description)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t uuid_len = strlen(team_uuid);
    uint16_t name_len = strlen(team_name);
    uint16_t description_len = strlen(team_description);

    uint16_t write_size = 2 + uuid_len + 2 + name_len + 2 + description_len;
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = TEAM_CREATED_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    // PAYLOAD
    write_string(write_buffer, &write_offset, team_uuid);
    write_string(write_buffer, &write_offset, team_name);
    write_string(write_buffer, &write_offset, team_description);

    usleep(USLEEP_TIME);
    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}
void write_channel_created_response_packet(client_t *connection, char *channel_uuid, char *channel_name, char *channel_description)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t uuid_len = strlen(channel_uuid);
    uint16_t name_len = strlen(channel_name);
    uint16_t description_len = strlen(channel_description);

    uint16_t write_size = 2 + uuid_len + 2 + name_len + 2 + description_len;
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = CHANNEL_CREATED_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    // PAYLOAD
    write_string(write_buffer, &write_offset, channel_uuid);
    write_string(write_buffer, &write_offset, channel_name);
    write_string(write_buffer, &write_offset, channel_description);

    usleep(USLEEP_TIME);
    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}
void write_thread_created_response_packet(client_t *connection, char *thread_uuid, char *user_uuid, time_t timestamp, char *thread_title, char *thread_body)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t uuid_len = strlen(thread_uuid);
    uint16_t user_uuid_len = strlen(user_uuid);
    uint16_t title_len = strlen(thread_title);
    uint16_t body_len = strlen(thread_body);

    uint16_t write_size = 2 + uuid_len + 2 + title_len + 2 + body_len + 2 + user_uuid_len + sizeof(time_t);
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = THREAD_CREATED_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    // PAYLOAD
    write_string(write_buffer, &write_offset, thread_uuid);
    write_string(write_buffer, &write_offset, user_uuid);
    write_uint64(write_buffer, &write_offset, timestamp);
    write_string(write_buffer, &write_offset, thread_title);
    write_string(write_buffer, &write_offset, thread_body);

    usleep(USLEEP_TIME);
    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}
void write_reply_received_response_packet(client_t *connection, char *team_uuid, char *thread_uuid, char *user_uuid, char *body)
{
    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, sizeof(char) * MAX_PACKET_SIZE);

    uint16_t team_uuid_len = strlen(team_uuid);
    uint16_t thread_uuid_len = strlen(thread_uuid);
    uint16_t user_uuid_len = strlen(user_uuid);
    uint16_t body_len = strlen(body);

    uint16_t write_size = 2 + team_uuid_len + 2 + thread_uuid_len + 2 + user_uuid_len + 2 + body_len;
    uint16_t write_offset = 1;

    // HEADER
    write_buffer[0] = REPLY_RECEIVED_RESPONSE_PACKET_ID;
    write_uint16(write_buffer, &write_offset, write_size);

    // PAYLOAD
    write_string(write_buffer, &write_offset, team_uuid);
    write_string(write_buffer, &write_offset, thread_uuid);
    write_string(write_buffer, &write_offset, user_uuid);
    write_string(write_buffer, &write_offset, body);

    usleep(USLEEP_TIME);
    write(connection->socket, write_buffer, HEADER_SIZE + write_size);
}
