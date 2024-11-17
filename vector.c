#include <stdio.h>
#define MAX_NODES 10
#define INF 9999

void distanceVectorRouting(int nodes, int costMatrix[MAX_NODES][MAX_NODES]) {
int cost[MAX_NODES][MAX_NODES], from[MAX_NODES][MAX_NODES];
int i, j, k;

for (i = 0; i < nodes; i++) {
for (j = 0; j < nodes; j++) {
cost[i][j] = costMatrix[i][j];
from[i][j] = j;
}
}

int updated;
do {
updated = 0;
for (i = 0; i < nodes; i++) {
for (j = 0; j < nodes; j++) {
for (k = 0; k < nodes; k++) {
if (cost[i][j] > cost[i][k] + cost[k][j]) {
cost[i][j] = cost[i][k] + cost[k][j];
from[i][j] = k;
updated = 1;
}
}
}
}
} while (updated);

for (i = 0; i < nodes; i++) {
printf("Routing Table for Node %d:\n", i + 1);
printf("Dest\tNext Hop\tCost\n");
for (j = 0; j < nodes; j++) {
printf("%d\t%d\t\t%d\n", j + 1, from[i][j] + 1, cost[i][j]);
}
printf("\n");
}
}

int main() {
int nodes, i, j;
int costMatrix[MAX_NODES][MAX_NODES];

printf("Enter the number of nodes: ");
scanf("%d", &nodes);

printf("Enter the cost matrix (enter %d for infinity):\n", INF);
for (i = 0; i < nodes; i++) {
for (j = 0; j < nodes; j++) {
scanf("%d", &costMatrix[i][j]);
if (i == j) {
costMatrix[i][j] = 0; 
}
}
}

distanceVectorRouting(nodes, costMatrix);
return 0;
}
