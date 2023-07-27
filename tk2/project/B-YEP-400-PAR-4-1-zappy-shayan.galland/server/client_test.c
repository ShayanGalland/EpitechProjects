/*
** EPITECH PROJECT, 2023
** e
** File description:
** e
*/

#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/server.h"
#include "../includes/command.h"

Client* clients = NULL;

void add_client(int socket_fd) {
    Client* new_client = (Client*)malloc(sizeof(Client));
    new_client->socket_fd = socket_fd;
    new_client->next = clients;
    clients = new_client;
}

void send_message_to_all_clients(char* message) {
    Client* current = clients;
    while (current != NULL) {
        if (send(current->socket_fd, message, strlen(message), 0) == -1) {
            perror("send");
        }
        current = current->next;
    }
}
