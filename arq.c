#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // For sleep function

int n, r;
struct frame {
char ack;
int data;
};

struct frame Frm[10];

void sender(void);
void recvack(void);
void resend_sr(void);
void goback(void);
void resend_gb(void);
void selective(void);

int main() {
int choice;
do {
printf("\n1. Selective Repeat ARQ\n2. Go-back ARQ\n3. Exit");
printf("\nEnter your choice: ");
scanf("%d", &choice);

switch(choice) {
case 1: 
selective();
break;
case 2: 
goback();
break;
case 3:  
exit(0);
break;
default:
printf("Invalid choice. Try again.\n");
}
} while(choice >= 1 && choice <= 3);

return 0;
}

void goback() {
sender();
recvack();
resend_gb();
printf("\nAll frames sent successfully.\n");
}

void selective() {
sender();
recvack();
resend_sr();
printf("\nAll frames sent successfully.\n");
}

void sender() {
int i;
printf("\nEnter the number of frames to be sent: ");
scanf("%d", &n);

for(i = 0; i < n; i++) {
printf("\nEnter data for frame %d: ", i + 1);
scanf("%d", &Frm[i].data);
Frm[i].ack = 'y'; // Initially assume the frame is acknowledged
}
}

void recvack() {
int i;
r = rand() % n;  // Simulate random packet loss
Frm[r].ack = 'n'; // Simulate no acknowledgment for this frame

printf("\nThe frame number %d is not received.\n", r + 1);
}

void resend_sr() {
printf("\nResending frame %d...\n", r + 1);
sleep(2);
Frm[r].ack = 'y';  // Acknowledge the frame after resend
printf("The received frame is %d.\n", Frm[r].data);
}

void resend_gb() {
int i;
printf("\nResending from frame %d...\n", r + 1);
for(i = r; i < n; i++) {
sleep(2);
Frm[i].ack = 'y';  // Acknowledge each frame in sequence
printf("Received data of frame %d is %d.\n", i + 1, Frm[i].data);
}
}
