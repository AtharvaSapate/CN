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
const char *message = "Hello from server!";

server_socket = socket(AF_INET, SOCK_STREAM, 0);

server_address.sin_family = AF_INET;
server_address.sin_addr.s_addr = INADDR_ANY;
server_address.sin_port = htons(PORT);

bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));
listen(server_socket, 3);

printf("Waiting for connections...\n");

client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);

send(client_socket, message, strlen(message), 0);
printf("Message sent to client\n");

close(client_socket);
close(server_socket);

return 0;
}
