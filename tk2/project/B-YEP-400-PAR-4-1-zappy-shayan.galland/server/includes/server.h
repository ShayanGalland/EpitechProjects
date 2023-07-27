/*
** EPITECH PROJECT, 2023
** h
** File description:
** h
*/

#ifndef SERVER_H
#define SERVER_H

#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>

typedef struct Server {
    // les champs du serveur...
    int map_width;
    int map_height;
    int** map;
    char* team_name;
    // autres champs...
} Server;

extern Server server;

void send_message_to_all_clients(char* message);

int create_socket();
struct sockaddr_in setup_server_address(int port);
void bind_socket(int sockfd, struct sockaddr_in serv_addr);
int accept_connection(int sockfd, struct sockaddr_in cli_addr);
void communicate(int newsockfd);
void handle_command(char* command);

#endif

