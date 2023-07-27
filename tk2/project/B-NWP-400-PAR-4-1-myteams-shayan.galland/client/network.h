#ifndef _NETWORK_H
#define _NETWORK_H

#include "../include/protocol.h"
#include "client.h"

int read_error_response_packet(client_t *client, char *read_buffer);

void write_login_packet(client_t *client, char *username);
int read_login_response_packet(client_t *client, char *read_buffer);

void write_logout_packet(client_t *client);

void write_users_packet(client_t *client);
int read_users_resp_packet(client_t *client, char *read_buffer);

void write_user_packet(client_t *client, char *uuid);
int read_user_response_packet(client_t *client, char *read_buffer);

void write_send_private_message_packet(client_t *client, char *uuid, char *message);
int read_private_message_received_response_packet(client_t *client, char *read_buffer);

void write_messages_request_packet(client_t *client, char *uuid);
int read_messages_response_packet(client_t *client, char *read_buffer);

void write_subscribe_request_packet(client_t *client, char *team_uuid);
int read_subscribe_response_packet(client_t *client, char *read_buffer);

void write_subscribed_request_packet(client_t *client, char *team_uuid);
int read_subscribed_response_packet(client_t *client, char *read_buffer);
int read_subscribed_users_response_packet(client_t *client, char *read_buffer);

void write_unsubscribe_request_packet(client_t *client, char *team_uuid);
int read_unsubscribe_response_packet(client_t *client, char *read_buffer);

void write_create_request_packet(client_t *client, char *use_team_uuid, char *use_channel_uuid, char *use_thread_uuid, char *arg1, char *arg2);
int read_create_team_response_packet(client_t *client, char *read_buffer);
int read_create_channel_response_packet(client_t *client, char *read_buffer);
int read_create_thread_response_packet(client_t *client, char *read_buffer);
int read_create_reply_response_packet(client_t *client, char *read_buffer);

void write_list_request_packet(client_t *client, char *use_team_uuid, char *use_channel_uuid, char *use_thread_uuid);
int read_list_team_response_packet(client_t *client, char *read_buffer);
int read_list_channel_response_packet(client_t *client, char *read_buffer);
int read_list_thread_response_packet(client_t *client, char *read_buffer);
int read_list_reply_response_packet(client_t *client, char *read_buffer);

void write_info_request_packet(client_t *client, char *use_team_uuid, char *use_channel_uuid, char *use_thread_uuid);
int read_info_user_response_packet(client_t *client, char *read_buffer);
int read_info_team_response_packet(client_t *client, char *read_buffer);
int read_info_channel_response_packet(client_t *client, char *read_buffer);
int read_info_thread_response_packet(client_t *client, char *read_buffer);

int read_team_created_response_packet(client_t *client, char *read_buffer);
int read_channel_created_response_packet(client_t *client, char *read_buffer);
int read_thread_created_response_packet(client_t *client, char *read_buffer);
int read_reply_received_response_packet(client_t *client, char *read_buffer);

#endif