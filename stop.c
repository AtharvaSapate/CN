#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <unistd.h>
#include <time.h>

bool receive_ack() {
return rand() % 2 == 0;
}

int main() {
int frames[] = {1, 2, 3};
int sequence_number = 0;

srand(time(0));

for (int i = 0; i < 3; i++) {
bool ack_received = false;
while (!ack_received) {
printf("Sending frame %d with sequence number %d\n", frames[i], sequence_number);
sleep(1);
ack_received = receive_ack();
if (ack_received) {
printf("ACK received\n");
sequence_number = 1 - sequence_number;
} else {
printf("ACK not received. Retransmitting...\n");
}
}
}

printf("All frames sent!\n");
return 0;
}
