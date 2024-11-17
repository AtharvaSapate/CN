#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
int sockfd;
char buffer[BUFFER_SIZE];
struct sockaddr_in servaddr, cliaddr;

sockfd = socket(AF_INET, SOCK_DGRAM, 0);

servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = INADDR_ANY;
servaddr.sin_port = htons(PORT);

bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

int len = sizeof(cliaddr);
recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&cliaddr, &len);

sendto(sockfd, "Hello from server", 17, 0, (struct sockaddr *)&cliaddr, len);

close(sockfd);
return 0;
}
