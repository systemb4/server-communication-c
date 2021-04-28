#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int networkSocket; 
    int connection; 
    printf("Hello World");

    char *ip;
    ip = argv[1];

    int port;
    port = atoi(argv[2]);

    struct sockaddr_in ack;

    while(1) {
        networkSocket = socket(AF_INET, SOCK_STREAM, 0);
        ack.sin_family = AF_INET;
        ack.sin_port = htons(port);
        ack.sin_addr.s_addr = inet_addr(ip);

        connection = connect(networkSocket, (struct sockaddr *) &ack, sizeof ack);
        printf("%i\n", connection);
        if(connection == 0) {
            printf("Attacking %s at port %i\n", ip, port);
        } else {
            printf("%s at %i not available\nConnection status: %i\n", ip, port, connection);
            return 0;
        }
    }

    close(connection);
    close(networkSocket);

    return 0;
}
