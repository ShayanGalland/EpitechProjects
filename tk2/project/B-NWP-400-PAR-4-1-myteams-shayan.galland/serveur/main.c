#include "serveur.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void handle_signal(int signal, server_t *server)
{
    if (signal == SIGINT)
    {
        printf("\nCaught SIGINT. Stopping server...\n");
        server_stop(server);
        server_cleanup(server);
        exit(0);
    }
}

void signal_handler(int signal, server_t *server)
{
    static server_t *stored_server = NULL;
    if (signal == 0)
    {
        stored_server = server;
    }
    else
    {
        handle_signal(signal, stored_server);
    }
}

int error_handling(int argc, char **argv, int port)
{
    if (argc != 2)
        exit(84);
    if (strcmp(argv[1], "--help") == 0)
    {
        printf("USAGE:\t./myteams_server port\n\tport\t");
        printf("is the port number on which the server socket listens.");
        exit(0);
    }
    port = atoi(argv[1]);
    if (port <= 0)
    {
        printf("Invalid port number.\n");
        exit(84);
    }
    return port;
}

int main(int argc, char **argv)
{
    int port = 0;
    server_t server;

    port = error_handling(argc, argv, port);

    if (server_init(&server, port) < 0)
    {
        printf("Server initialization failed.\n");
        return 84;
    }
    signal_handler(0, &server);
    signal(SIGINT, signal_handler);
    if (server_start(&server) < 0)
    {
        printf("Server failed to start.\n");
        return 84;
    }
    return 0;
}