#include <stdio.h>
#include <stdlib.h>
#include "client.h"
#include "myteams.h"

void print_usage()
{
    printf("USAGE: ./myteams_cli ip port\n");
    printf("ip is the server ip address on which the server socket listens\n");
    printf("port is the port number on which the server socket listens\n");
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }
    const char *ip = argv[1];
    int port = atoi(argv[2]);
    client_t *client;
    if (initialize_client(&client, ip, port) != 0)
    {
        return EXIT_FAILURE;
    }
    if (connect_to_server(&client) != 0)
    {
        close_client(&client);
        return EXIT_FAILURE;
    }
    run_cli(&client);
    close_client(&client);
    return EXIT_SUCCESS;
}
