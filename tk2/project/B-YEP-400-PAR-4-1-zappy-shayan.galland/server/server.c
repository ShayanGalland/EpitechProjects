/*
** EPITECH PROJECT, 2023
** server
** File description:
** server
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "../includes/server.h"

#define BUFFER_SIZE 256

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    return sockfd;
}

struct sockaddr_in setup_server_address(int port) {
    struct sockaddr_in serv_addr;
    memset((char*)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
    return serv_addr;
}

void bind_socket(int sockfd, struct sockaddr_in serv_addr) {
    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
}

int accept_connection(int sockfd, struct sockaddr_in cli_addr) {
    socklen_t clilen = sizeof(cli_addr);
    int newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    return newsockfd;
}

void communicate(int newsockfd) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    int n = read(newsockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("Command received: %s\n", buffer);

    handle_command(buffer);

    n = write(newsockfd, "Command processed", 17);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
}