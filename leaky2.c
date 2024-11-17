#include <stdio.h>
#include <stdlib.h>

int main() {
int n, bsize, bfilled = 0, outrate, i = 0, k = 0;

printf("Enter the number of packets: ");
scanf("%d", &n);

int ptime[n], psize[n];

printf("Enter packets (time and size):\n");
for (i = 0; i < n; i++) {
scanf("%d %d", &ptime[i], &psize[i]);
}

printf("Enter bucket size: ");
scanf("%d", &bsize);

printf("Enter output rate: ");
scanf("%d", &outrate);

int m = ptime[n - 1];
i = 1;

while (i <= m || bfilled != 0) {
printf("\nAt time %d", i);

if (ptime[k] == i) {
if (bfilled + psize[k] <= bsize) {
bfilled += psize[k];
printf("\n%d byte packet inserted", psize[k]);
} else {
printf("\n%d byte packet discarded", psize[k]);
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
