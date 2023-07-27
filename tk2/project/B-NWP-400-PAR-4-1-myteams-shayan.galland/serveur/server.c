#include "serveur.h"
#include "../include/protocol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/select.h>

#include "database.h"
#include "network.h"

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
client_t *init_connection(int socket)
{
    client_t *connections = malloc(sizeof(client_t) * MAX_CLIENT);

    for (int i = 0; i < MAX_CLIENT; i++)
    {
        connections[i].socket = -1;
        connections[i].username = NULL;
        connections[i].uuid = NULL;
        connections[i].arg1 = NULL;
        connections[i].arg2 = NULL;
        connections[i].arg3 = NULL;
        connections[i].arg4 = NULL;
        connections[i].arg5 = NULL;
    }
    connections[0].socket = socket;
    return connections;
}
void initialize_fd_set(fd_set *fd_set_rd, client_t *connections)
{
    FD_ZERO(fd_set_rd);
    for (int i = 0; i < MAX_CLIENT; i++)
    {
        if (connections[i].socket >= 0)
        {
            FD_SET(connections[i].socket, fd_set_rd);
        }
    }
}
void handle_new_connection(server_t *server, client_t *connections)
{
    struct sockaddr_in new_addr;
    memset(&new_addr, 0, sizeof(struct sockaddr_in));
    socklen_t addrlen;
    memset(&addrlen, 0, sizeof(socklen_t));

    int new_client = accept(server->server_socket, (struct sockaddr *)&new_addr, &addrlen);

    if (new_client >= 0)
    {
        for (int i = 0; i < MAX_CLIENT; i++)
        {
            if (connections[i].socket < 0)
            {
                connections[i].socket = new_client;
                break;
            }
        }
    }
}

void handle_command(server_t *server, client_t *connection, char *read_buffer)
{
    if (connection->uuid == NULL && read_buffer[0] != LOGIN_REQUEST_PACKET_ID)
        return write_error_reponse_packet(connection, ERROR_CODE_UNAUTHORIZED, NULL);

    switch (read_buffer[0])
    {
    case LOGIN_REQUEST_PACKET_ID:
        handle_login(server, connection, read_buffer);
        break;

    case LOGOUT_REQUEST_PACKET_ID:
        handle_logout(server, connection, read_buffer);
        break;

    case USERS_REQUEST_PACKET_ID:
        handle_users(server, connection, read_buffer);
        break;

    case USER_REQUEST_PACKET_ID:
        handle_user(server, connection, read_buffer);
        break;

    case SEND_PRIVATE_MESSAGE_REQUEST_PACKET_ID:
        handle_send(server, connection, read_buffer);
        break;

    case MESSAGES_REQUEST_PACKET_ID:
        handle_messages(server, connection, read_buffer);
        break;

    case SUBSCRIBE_REQUEST_PACKET_ID:
        handle_subscribe(server, connection, read_buffer);
        break;

    case SUBSCRIBED_REQUEST_PACKET_ID:
        handle_subscribed(server, connection, read_buffer);
        break;

    case UNSUBSCRIBED_REQUEST_PACKET_ID:
        handle_unsubscribe(server, connection, read_buffer);
        break;

    case CREATE_REQUEST_PACKET_ID:
        handle_create(server, connection, read_buffer);
        break;

    case LIST_REQUEST_PACKET_ID:
        handle_list(server, connection, read_buffer);
        break;

    case INFO_REQUEST_PACKET_ID:
        handle_info(server, connection, read_buffer);
        break;
    }

    if (connection->arg1 != NULL)
    {
        free(connection->arg1 = NULL);
        connection->arg1 = NULL;
    }

    if (connection->arg2 != NULL)
    {
        free(connection->arg2 = NULL);
        connection->arg2 = NULL;
    }

    if (connection->arg3 != NULL)
    {
        free(connection->arg3 = NULL);
        connection->arg3 = NULL;
    }

    if (connection->arg4 != NULL)
    {
        free(connection->arg4 = NULL);
        connection->arg4 = NULL;
    }

    if (connection->arg5 != NULL)
    {
        free(connection->arg5 = NULL);
        connection->arg5 = NULL;
    }
}

void handle_login(server_t *server, client_t *connection, char *read_buffer)
{
    read_login_packet(server, connection, read_buffer);

    user_t *user = find_user(server->database, connection->username);
    if (user == NULL)
    {
        user = create_user(server->database, connection->username);
        server_event_user_created(user->uuid, user->username);
    }

    user->status = 1;
    connection->uuid = strdup(user->uuid);
    server_event_user_logged_in(connection->uuid);

    write_login_response_packet(connection, user->uuid, user->username);
}
void handle_logout(server_t *server, client_t *connection, char *read_buffer)
{
    read_logout_packet(server, connection, read_buffer);
    server_event_user_logged_out(connection->uuid);

    user_t *user = find_user(server->database, connection->uuid);
    user->status = 0;

    if(connection->uuid != NULL)
    {
        free(connection->uuid);
        connection->uuid = NULL;
    }
}
void handle_users(server_t *server, client_t *connection, char *read_buffer)
{
    read_users_packet(server, connection, read_buffer);

    int users_count = count_null_array(server->database->users) - 1;
    for (int i = 0; i < users_count; i++)
    {
        write_users_response_packet(connection, server->database->users[i]->uuid, server->database->users[i]->username, server->database->users[i]->status);
    }
}
void handle_user(server_t *server, client_t *connection, char *read_buffer)
{
    read_user_packet(server, connection, read_buffer);

    user_t *user = find_user(server->database, connection->arg1);
    if (user == NULL)
        return write_error_reponse_packet(connection, ERROR_CODE_UNKNOWN_USER, connection->arg1);

    write_user_response_packet(connection, user->uuid, user->username, user->status);
}
void handle_send(server_t *server, client_t *connection, char *read_buffer)
{
    read_send_private_message_packet(server, connection, read_buffer);
    user_t *user = find_user(server->database, connection->arg1);
    if (user == NULL)
        return write_error_reponse_packet(connection, ERROR_CODE_UNKNOWN_USER, connection->arg1);

    server_event_private_message_sended(connection->uuid, connection->arg1, connection->arg2);
    create_private_message(server->database, connection->uuid, connection->arg1, connection->arg2);

    for (int i = 0; i < MAX_CLIENT; i++)
    {
        if (server->connected_clients[i].uuid != NULL)
        {
            if (strcmp(server->connected_clients[i].uuid, connection->arg1) == 0)
            {
                write_private_message_received_response_packet(&server->connected_clients[i], server->connected_clients[i].uuid, connection->arg2);
                break;
            }
        }
    }
}
void handle_messages(server_t *server, client_t *connection, char *read_buffer)
{
    read_messages_packet(server, connection, read_buffer);

    int private_messages_count = count_null_array(server->database->private_messages) - 1;
    for (int i = 0; i < private_messages_count; i++)
    {
        private_message_t *private_message = server->database->private_messages[i];

        if ((strcmp(private_message->sender_uuid, connection->uuid) == 0 && strcmp(private_message->receiver_uuid, connection->arg1) == 0) ||
            (strcmp(private_message->sender_uuid, connection->arg1) == 0 && strcmp(private_message->receiver_uuid, connection->uuid) == 0))
        {
            write_messages_response_packet(connection, private_message->receiver_uuid, private_message->message, private_message->timestamp);
        }
    }
}

void handle_subscribe(server_t *server, client_t *connection, char *read_buffer)
{
    read_subscribe_request_packet(server, connection, read_buffer);

    team_t *team = find_team(server->database, connection->arg1);
    if (team == NULL)
        return write_error_reponse_packet(connection, ERROR_CODE_UNKNOWN_TEAM, connection->arg1);

    if (!is_subscribed(server->database, connection->uuid, connection->arg1))
        add_subscribed_team_to_user(server->database, connection->uuid, team->uuid);

    server_event_user_subscribed(team->uuid, connection->uuid);
    write_subscribe_response_packet(connection, connection->uuid, team->uuid);
}
void handle_subscribed(server_t *server, client_t *connection, char *read_buffer)
{
    read_subscribed_request_packet(server, connection, read_buffer);

    if (connection->arg1 == NULL)
    {
        int teams_count = count_null_array(server->database->teams) - 1;
        for (int i = 0; i < teams_count; i++)
        {
            team_t *team = server->database->teams[i];

            if (is_subscribed(server->database, connection->uuid, team->uuid))
                write_subscribed_response_packet(connection, team->uuid, team->name, team->description);
        }
    }
    else
    {
        team_t *team = find_team(server->database, connection->arg1);
        if (team == NULL)
            return write_error_reponse_packet(connection, ERROR_CODE_UNKNOWN_TEAM, connection->arg1);

        if (!is_subscribed(server->database, connection->uuid, connection->arg1))
            return write_error_reponse_packet(connection, ERROR_CODE_UNAUTHORIZED, NULL);

        int users_count = count_null_array(server->database->users) - 1;
        for (int i = 0; i < users_count; i++)
        {
            user_t *user = server->database->users[i];
            if (is_subscribed(server->database, user->uuid, connection->arg1))
            {
                write_subscribed_users_response_packet(connection, user->uuid, user->username, user->status);
            }
        }
    }
}

void handle_unsubscribe(server_t *server, client_t *connection, char *read_buffer)
{
    read_unsubscribe_request_packet(server, connection, read_buffer);

    team_t *team = find_team(server->database, connection->arg1);
    if (team == NULL)
        return write_error_reponse_packet(connection, ERROR_CODE_UNKNOWN_TEAM, connection->arg1);

    if (!is_subscribed(server->database, connection->uuid, connection->arg1))
        return write_error_reponse_packet(connection, ERROR_CODE_UNAUTHORIZED, NULL);

    remove_subscribed_team_to_user(server->database, connection->uuid, team->uuid);
    server_event_user_unsubscribed(team->uuid, connection->uuid);
    write_unsubscribe_response_packet(connection, connection->uuid, team->uuid);
}

void handle_create(server_t *server, client_t *connection, char *read_buffer)
{
    read_create_request_packet(server, connection, read_buffer);

    if (connection->arg1 == NULL)
    {
        // Team creation
        if (find_team_by_name(server->database, connection->arg4))
            return write_error_reponse_packet(connection, ERROR_CODE_ALREADY_EXISTS, NULL);

        team_t *new_team = create_team(server->database, connection->arg4, connection->arg5);
        add_subscribed_team_to_user(server->database, connection->uuid, new_team->uuid);

        write_create_team_response_packet(connection, new_team->uuid, new_team->name, new_team->description);
        server_event_team_created(new_team->uuid, new_team->name, connection->uuid);

        for (int i = 0; i < MAX_CLIENT; i++)
        {
            if (server->connected_clients[i].uuid != NULL)
            {
                if (server->connected_clients[i].uuid != NULL)
                {
                    write_team_created_response_packet(&server->connected_clients[i], new_team->uuid, new_team->name, new_team->description);
                }
            }
        }
    }
    else if (connection->arg2 == NULL)
    {
        // Channel creation
        team_t *team = find_team(server->database, connection->arg1);
        if (team == NULL)
            return write_error_reponse_packet(connection, ERROR_CODE_UNKNOWN_TEAM, connection->arg1);

        if (find_channel_by_name(server->database, connection->arg4))
            return write_error_reponse_packet(connection, ERROR_CODE_ALREADY_EXISTS, NULL);

        if (!is_subscribed(server->database, connection->uuid, connection->arg1))
            return write_error_reponse_packet(connection, ERROR_CODE_UNAUTHORIZED, NULL);

        channel_t *new_channel = create_channel(server->database, team, connection->arg4, connection->arg5);

        write_create_channel_response_packet(connection, new_channel->uuid, new_channel->name, new_channel->description);

        server_event_channel_created(team->uuid, new_channel->uuid, new_channel->name);

        for (int i = 0; i < MAX_CLIENT; i++)
        {
            if (server->connected_clients[i].uuid != NULL)
            {
                if (server->connected_clients[i].uuid != NULL && is_subscribed(server->database, connection->uuid, connection->arg1))
                {
                    write_channel_created_response_packet(&server->connected_clients[i], new_channel->uuid, new_channel->name, new_channel->description);
                }
            }
        }
    }
    else if (connection->arg3 == NULL)
    {
        // Thread creation
        team_t *team = find_team(server->database, connection->arg1);
        if (team == NULL)
            return write_error_reponse_packet(connection, ERROR_CODE_UNKNOWN_TEAM, connection->arg1);

        channel_t *channel = find_channel(server->database, connection->arg2);
        if (channel == NULL)
            return write_error_reponse_packet(connection, ERROR_CODE_UNKNOWN_CHANNEL, connection->arg2);

        if (find_thread_by_title(server->database, connection->arg4))
            return write_error_reponse_packet(connection, ERROR_CODE_ALREADY_EXISTS, NULL);

        if (!is_subscribed(server->database, connection->uuid, connection->arg1))
            return write_error_reponse_packet(connection, ERROR_CODE_UNAUTHORIZED, NULL);

        thread_t *new_thread = create_thread(server->database, connection->uuid, channel, connection->arg4, connection->arg5);

        write_create_thread_response_packet(connection, new_thread->uuid, connection->uuid, new_thread->timestamp, new_thread->title, new_thread->body);

        server_event_thread_created(channel->uuid, new_thread->uuid, connection->uuid, new_thread->title, new_thread->body);

        for (int i = 0; i < MAX_CLIENT; i++)
        {
            if (server->connected_clients[i].uuid != NULL)
            {
                if (server->connected_clients[i].uuid != NULL && is_subscribed(server->database, connection->uuid, connection->arg1))
                {
                    write_thread_created_response_packet(&server->connected_clients[i], new_thread->uuid, connection->uuid, new_thread->timestamp, new_thread->title, new_thread->body);
                }
            }
        }
    }
    else
    {
        // Reply creation
        team_t *team = find_team(server->database, connection->arg1);
        if (team == NULL)
            return write_error_reponse_packet(connection, ERROR_CODE_UNKNOWN_TEAM, connection->arg1);

        channel_t *channel = find_channel(server->database, connection->arg2);
        if (channel == NULL)
            return write_error_reponse_packet(connection, ERROR_CODE_UNKNOWN_CHANNEL, connection->arg2);

        thread_t *thread = find_thread(server->database, connection->arg3);
        if (thread == NULL)
            return write_error_reponse_packet(connection, ERROR_CODE_UNKNOWN_THREAD, connection->arg3);

        if (!is_subscribed(server->database, connection->uuid, connection->arg1))
            return write_error_reponse_packet(connection, ERROR_CODE_UNAUTHORIZED, NULL);

        reply_t *new_reply = create_reply(server->database, connection->uuid, thread, connection->arg4);

        server_event_reply_created(thread->uuid, connection->uuid, new_reply->body);

        for (int i = 0; i < MAX_CLIENT; i++)
        {
            if (server->connected_clients[i].uuid != NULL)
            {
                if (server->connected_clients[i].uuid != NULL && is_subscribed(server->database, connection->uuid, connection->arg1))
                {
                    write_reply_received_response_packet(&server->connected_clients[i], team->uuid, thread->uuid, connection->uuid, new_reply->body);
                }
            }
        }
    }
}
void handle_list(server_t *server, client_t *connection, char *read_buffer)
{
    read_list_request_packet(server, connection, read_buffer);

    if (connection->arg1 == NULL)
    {
        int teams_count = count_null_array(server->database->teams) - 1;
        for (int i = 0; i < teams_count; i++)
        {
            team_t *team = server->database->teams[i];
            write_list_team_response_packet(connection, team->uuid, team->name, team->description);
        }
    }
    else if (connection->arg2 == NULL)
    {
        team_t *team = find_team(server->database, connection->arg1);
        if (team == NULL)
            return write_error_reponse_packet(connection, ERROR_CODE_UNKNOWN_TEAM, connection->arg1);

        if (!is_subscribed(server->database, connection->uuid, connection->arg1))
            return write_error_reponse_packet(connection, ERROR_CODE_UNAUTHORIZED, NULL);

        int channels_count = count_null_array(server->database->channels) - 1;
        for (int i = 0; i < channels_count; i++)
        {
            channel_t *channel = server->database->channels[i];
            if (strcmp(channel->team_uuid, team->uuid) == 0)
            {
                write_list_channel_response_packet(connection, channel->uuid, channel->name, channel->description);
            }
        }
    }
    else if (connection->arg3 == NULL)
    {
        team_t *team = find_team(server->database, connection->arg1);
        if (team == NULL)
            return write_error_reponse_packet(connection, ERROR_CODE_UNKNOWN_TEAM, connection->arg1);

        channel_t *channel = find_channel(server->database, connection->arg2);
        if (channel == NULL)
            return write_error_reponse_packet(connection, ERROR_CODE_UNKNOWN_CHANNEL, connection->arg2);

        if (!is_subscribed(server->database, connection->uuid, connection->arg1))
            return write_error_reponse_packet(connection, ERROR_CODE_UNAUTHORIZED, NULL);

        int threads_count = count_null_array(server->database->threads) - 1;
        for (int i = 0; i < threads_count; i++)
        {
            thread_t *thread = server->database->threads[i];
            if (strcmp(thread->channel_uuid, channel->uuid) == 0)
            {
                write_list_thread_response_packet(connection, thread->uuid, thread->user_uuid, thread->timestamp, thread->title, thread->body);
            }
        }
    }
    else
    {
        team_t *team = find_team(server->database, connection->arg1);
        if (team == NULL)
            return write_error_reponse_packet(connection, ERROR_CODE_UNKNOWN_TEAM, connection->arg1);

        channel_t *channel = find_channel(server->database, connection->arg2);
        if (channel == NULL)
            return write_error_reponse_packet(connection, ERROR_CODE_UNKNOWN_CHANNEL, connection->arg2);

        thread_t *thread = find_thread(server->database, connection->arg3);
        if (thread == NULL)
            return write_error_reponse_packet(connection, ERROR_CODE_UNKNOWN_THREAD, connection->arg3);

        if (!is_subscribed(server->database, connection->uuid, connection->arg1))
            return write_error_reponse_packet(connection, ERROR_CODE_UNAUTHORIZED, NULL);

        int replies_count = count_null_array(server->database->replies) - 1;
        for (int i = 0; i < replies_count; i++)
        {
            reply_t *reply = server->database->replies[i];
            if (strcmp(thread->uuid, reply->thread_uuid) == 0)
            {
                write_list_reply_response_packet(connection, thread->uuid, reply->user_uuid, reply->timestamp, reply->body);
            }
        }
    }
}
void handle_info(server_t *server, client_t *connection, char *read_buffer)
{
    read_info_request_packet(server, connection, read_buffer);

    if (connection->arg1 == NULL)
    {
        user_t *user = find_user(server->database, connection->uuid);
        if (user == NULL)
            return write_error_reponse_packet(connection, ERROR_CODE_UNKNOWN_USER, connection->arg1);

        write_user_response_packet(connection, user->uuid, user->username, user->status);
    }
    else if (connection->arg2 == NULL)
    {
        team_t *team = find_team(server->database, connection->arg1);
        if (team == NULL)
            return write_error_reponse_packet(connection, ERROR_CODE_UNKNOWN_TEAM, connection->arg1);

        write_info_team_response_packet(connection, team->uuid, team->name, team->description);
    }
    else if (connection->arg3 == NULL)
    {
        team_t *team = find_team(server->database, connection->arg1);
        if (team == NULL)
            return write_error_reponse_packet(connection, ERROR_CODE_UNKNOWN_TEAM, connection->arg1);

        channel_t *channel = find_channel(server->database, connection->arg2);
        if (channel == NULL)
            return write_error_reponse_packet(connection, ERROR_CODE_UNKNOWN_CHANNEL, connection->arg2);

        if (!is_subscribed(server->database, connection->uuid, connection->arg1))
            return write_error_reponse_packet(connection, ERROR_CODE_UNAUTHORIZED, NULL);

        write_info_channel_response_packet(connection, channel->uuid, channel->name, channel->description);
    }
    else
    {
        team_t *team = find_team(server->database, connection->arg1);
        if (team == NULL)
            return write_error_reponse_packet(connection, ERROR_CODE_UNKNOWN_TEAM, connection->arg1);

        channel_t *channel = find_channel(server->database, connection->arg2);
        if (channel == NULL)
            return write_error_reponse_packet(connection, ERROR_CODE_UNKNOWN_CHANNEL, connection->arg2);

        thread_t *thread = find_thread(server->database, connection->arg3);
        if (thread == NULL)
            return write_error_reponse_packet(connection, ERROR_CODE_UNKNOWN_THREAD, connection->arg3);

        if (!is_subscribed(server->database, connection->uuid, connection->arg1))
            return write_error_reponse_packet(connection, ERROR_CODE_UNAUTHORIZED, NULL);

        write_info_thread_response_packet(connection, thread->uuid, thread->user_uuid, thread->timestamp, thread->title, thread->body);
    }
}

void handle_existing_connection(server_t *server, client_t *connection, char *read_buffer)
{
    int ret_read = read(connection->socket, read_buffer, 1024);
    if (ret_read > 0)
        handle_command(server, connection, read_buffer);

    if (ret_read == 0)
    {
        if (connection->uuid != NULL)
        {
            server_event_user_logged_out(connection->uuid);
        }

        close(connection->socket);
        connection->socket = -1;

        if (connection->uuid != NULL)
        {
            free(connection->uuid);
            connection->uuid = NULL;
        }

        if (connection->username != NULL)
        {
            free(connection->username);
            connection->username = NULL;
        }

        if (connection->arg1 != NULL)
        {
            free(connection->arg1);
            connection->arg1 = NULL;
        }

        if (connection->arg2 != NULL)
        {
            free(connection->arg2);
            connection->arg2 = NULL;
        }

        if (connection->arg3 != NULL)
        {
            free(connection->arg3);
            connection->arg3 = NULL;
        }
    }
}
void client_is_connected(server_t *server, int changed_socket, client_t *connections, fd_set fd_set_rd)
{
    char read_buffer[1024];

    if (FD_ISSET(server->server_socket, &fd_set_rd))
    {
        handle_new_connection(server, connections);
        changed_socket--;
    }
    for (int i = 1; i < MAX_CLIENT; i++)
    {
        if (connections[i].socket >= 0 && FD_ISSET(connections[i].socket, &fd_set_rd))
        {
            memset(read_buffer, 0, 1024);
            handle_existing_connection(server, &connections[i], read_buffer);
            changed_socket--;
        }
        if (!changed_socket)
        {
            break;
        }
    }
}
void free_struct(client_t *connections)
{
    for (int i = 0; i < MAX_CLIENT; i++)
    {
        if (connections[i].socket > 0)
            close(connections[i].socket);
    }
    free(connections);
}

int server_init(server_t *server, uint16_t port)
{
    server->server_socket = init_socket(port);
    server->connected_clients = init_connection(server->server_socket);
    server->database = create_database();

    load_database(server->database);

    return 0;
}
int server_start(server_t *server)
{
    int changed_socket = 0;

    while (1)
    {
        initialize_fd_set(&server->fd_set_rd, server->connected_clients);
        changed_socket = select(FD_SETSIZE, &server->fd_set_rd, NULL, NULL, NULL);
        if (changed_socket >= 0)
            client_is_connected(server, changed_socket, server->connected_clients, server->fd_set_rd);
    }
}
void server_stop(server_t *server)
{
    close(server->server_socket);
    save_database(server->database);
}
void server_cleanup(server_t *server)
{
    free_struct(server->connected_clients);
}
