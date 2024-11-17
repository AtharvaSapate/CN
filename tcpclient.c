#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
int client_socket;
struct sockaddr_in server_address;
char buffer[BUFFER_SIZE];

client_socket = socket(AF_INET, SOCK_STREAM, 0);

server_address.sin_family = AF_INET;
server_address.sin_port = htons(PORT);
server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address));

read(client_socket, buffer, BUFFER_SIZE);
printf("Message from server: %s\n", buffer);

close(client_socket);

return 0;
}
