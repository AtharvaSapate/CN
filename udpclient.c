#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
int client_socket;
char message[BUFFER_SIZE] = "Hello from client";
char response[BUFFER_SIZE];
struct sockaddr_in server_address;

client_socket = socket(AF_INET, SOCK_DGRAM, 0);

server_address.sin_family = AF_INET;
server_address.sin_port = htons(PORT);
server_address.sin_addr.s_addr = INADDR_ANY;

sendto(client_socket, message, strlen(message), 0, (struct sockaddr *)&server_address, sizeof(server_address));

int server_address_length = sizeof(server_address);
int n = recvfrom(client_socket, response, BUFFER_SIZE, 0, (struct sockaddr *)&server_address, &server_address_length);

response[n] = '\0'; 

printf("Server response: %s\n", response);

close(client_socket);
return 0;
}
