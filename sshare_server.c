#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

#define MLIMIT 1024

int main() {
    char server_message[MLIMIT];
    char client_response[MLIMIT];
    int server_socket;
    int client_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = inet_addr(10.0.0.59);

    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    listen(server_socket, 4);

    client_socket = accept(server_socket, NULL, NULL);
    send(client_socket, server_message, sizeof(server_message), 0);
    recv(client_socket, &client_response, sizeof(client_response), 0);
    printf("%s\n", client_response);
    close(server_socket);

    return 0;
}
