#include <stdio.h>
#include <stdlib.h>

struct packet {
int time;
int size;
} p[50];

int main() {
int n, bsize, bfilled = 0, outrate, i = 0, k = 0;

printf("Enter the number of packets: ");
scanf("%d", &n);

printf("Enter packets (time and size):\n");
for (i = 0; i < n; i++) {
scanf("%d %d", &p[i].time, &p[i].size);
}

printf("Enter bucket size: ");
scanf("%d", &bsize);

printf("Enter output rate: ");
scanf("%d", &outrate);

int m = p[n - 1].time; // Last packet time
i = 1;

while (i <= m || bfilled != 0) {
printf("\nAt time %d", i);

if (p[k].time == i) {
if (bfilled + p[k].size <= bsize) {
bfilled += p[k].size;
printf("\n%d byte packet inserted", p[k].size);
} else {
printf("\n%d byte packet discarded", p[k].size);
}
k++;
}

if (bfilled == 0) {
printf("\nNo packets to transfer");
} else {
int transferred = (bfilled >= outrate) ? outrate : bfilled;
bfilled -= transferred;
printf("\n%d bytes transferred", transferred);
}

printf("\nPackets in bucket: %d bytes", bfilled);
i++;
}

return 0;
}
