#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#define LIMIT 1024

int main(int argc, char *argv[]) {
    char *ip;
    ip = argv[1];
    char message_client[1024] = "This is a message from the client!";
    char server_response[256];

    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = inet_addr(ip);

    int connection_status = connect(network_socket, (struct sockaddr * ) &server_address, sizeof(server_address));

    if(connection_status == -1) {
        printf("there was an error: %i\n", connection_status);
        return 0;
    }

    while(1) {
        fprintf(stderr, ": ");
        fgets(message_client, LIMIT, stdin);

        recv(network_socket, &server_response, sizeof(server_response), 0);
        send(network_socket, message_client, sizeof(message_client), 0);

        printf("The server sent the data: %s\n", server_response);
        close(network_socket);
    }

    return 0;
}
