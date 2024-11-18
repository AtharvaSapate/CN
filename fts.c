#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);
    char buffer[BUFFER_SIZE];
    FILE *file;

    file = fopen("server_text.txt", "r");

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    listen(server_socket, 3);

    printf("Waiting for connections...\n");

    client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);

    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        send(client_socket, buffer, strlen(buffer), 0);
    }
    printf("File content sent to client\n");

    fclose(file);
    close(client_socket);
    close(server_socket);

    return 0;
}
