/*
** EPITECH PROJECT, 2023
** main
** File description:
** m
*/

#include <stdlib.h>
#include <unistd.h>
#include "../includes/server.h"
#include "stdio.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    int sockfd = create_socket();
    struct sockaddr_in serv_addr = setup_server_address(port);

    bind_socket(sockfd, serv_addr);

    listen(sockfd, 5);

    struct sockaddr_in cli_addr;
    int newsockfd = accept_connection(sockfd, cli_addr);

    communicate(newsockfd);

    close(newsockfd);
    close(sockfd);

    return 0;
}
