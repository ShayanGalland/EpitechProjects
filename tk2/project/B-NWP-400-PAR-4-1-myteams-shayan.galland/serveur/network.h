#ifndef _NETWORK_H
#define _NETWORK_H

#include "serveur.h"
#include "../include/protocol.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/select.h>

uint16_t read_uint16(char *read_buffer, uint16_t *read_offset);
uint32_t read_uint32(char *read_buffer, uint16_t *read_offset);
uint64_t read_uint64(char *read_buffer, uint16_t *read_offset);
char *read_string(char *read_buffer, uint16_t *read_offset);

void write_uint16(char *write_buffer, uint16_t *write_offset, uint16_t value);
void write_uint32(char *write_buffer, uint16_t *write_offset, uint32_t value);
void write_uint64(char *write_buffer, uint16_t *write_offset, uint64_t value);
void write_string(char *write_buffer, uint16_t *write_offset, char *value);

void write_error_reponse_packet(client_t *connection, int error_code, char *uuid);

void read_login_packet(server_t *server, client_t *connection, char *read_buffer);
void write_login_response_packet(client_t *connection, char *uuid, char *username);

void read_logout_packet(server_t *server, client_t *connection, char *read_buffer);

void read_users_packet(server_t *server, client_t *connection, char *read_buffer);
void write_users_response_packet(client_t *connection, char *uuid, char *username, int status);

void read_user_packet(server_t *server, client_t *connection, char *read_buffer);
void write_user_response_packet(client_t *connection, char *uuid, char *username, int status);

void read_send_private_message_packet(server_t *server, client_t *connection, char *read_buffer);
void write_private_message_received_response_packet(client_t *connection, char *uuid, char *body);

void read_messages_packet(server_t *server, client_t *connection, char *read_buffer);
void write_messages_response_packet(client_t *connection, char *uuid, char *body, time_t timestamp);

void read_subscribe_request_packet(server_t *server, client_t *connection, char *read_buffer);
void write_subscribe_response_packet(client_t *connection, char *user_uuid, char *team_uuid);

void read_subscribed_request_packet(server_t *server, client_t *connection, char *read_buffer);
void write_subscribed_response_packet(client_t *connection, char *team_uuid, char *team_name, char *team_description);
void write_subscribed_users_response_packet(client_t *connection, char *uuid, char *username, int status);

void read_unsubscribe_request_packet(server_t *server, client_t *connection, char *read_buffer);
void write_unsubscribe_response_packet(client_t *connection, char *user_uuid, char *team_uuid);

void read_create_request_packet(server_t *server, client_t *connection, char *read_buffer);
void write_create_team_response_packet(client_t *connection, char *team_uuid, char *team_name, char *team_description);
void write_create_channel_response_packet(client_t *connection, char *channel_uuid, char *channel_name, char *channel_description);
void write_create_thread_response_packet(client_t *connection, char *thread_uuid, char *user_uuid, time_t timestamp, char *thread_title, char *thread_body);
void write_create_reply_response_packet(client_t *connection, char *thread_uuid, char *user_uuid, time_t timestamp, char *body);

void read_list_request_packet(server_t *server, client_t *connection, char *read_buffer);
void write_list_team_response_packet(client_t *connection, char *team_uuid, char *team_name, char *team_description);
void write_list_channel_response_packet(client_t *connection, char *channel_uuid, char *channel_name, char *channel_description);
void write_list_thread_response_packet(client_t *connection, char *thread_uuid, char *user_uuid, time_t timestamp, char *thread_title, char *thread_body);
void write_list_reply_response_packet(client_t *connection, char *thread_uuid, char *user_uuid, time_t timestamp, char *body);

void read_info_request_packet(server_t *server, client_t *connection, char *read_buffer);
void write_info_user_response_packet(client_t *connection, char *uuid, char *username, int status);
void write_info_team_response_packet(client_t *connection, char *team_uuid, char *team_name, char *team_description);
void write_info_channel_response_packet(client_t *connection, char *channel_uuid, char *channel_name, char *channel_description);
void write_info_thread_response_packet(client_t *connection, char *thread_uuid, char *user_uuid, time_t timestamp, char *thread_title, char *thread_body);

void write_team_created_response_packet(client_t *connection, char *team_uuid, char *team_name, char *team_description);
void write_channel_created_response_packet(client_t *connection, char *channel_uuid, char *channel_name, char *channel_description);
void write_thread_created_response_packet(client_t *connection, char *thread_uuid, char *user_uuid, time_t timestamp, char *thread_title, char *thread_body);
void write_reply_received_response_packet(client_t *connection, char *team_uuid, char *thread_uuid, char *user_uuid, char *body);

#endif