#include <stdio.h>

#define BUCKET_SIZE 5
#define LEAK_RATE 1

void leaky_bucket(int packets[], int n) {
    int bucket = 0;
    
    for (int i = 0; i < n; i++) {
        if (packets[i] + bucket > BUCKET_SIZE) {
            printf("Bucket overflow! Packet of size %d is discarded.\n", packets[i]);
        } else {
            bucket += packets[i];
            printf("Packet of size %d added to the bucket.\n", packets[i]);
        }

        if (bucket > 0) {
            bucket -= LEAK_RATE;
            if (bucket < 0) bucket = 0;
            printf("Leaked 1 packet. Remaining in bucket: %d\n", bucket);
        }
    }

    while (bucket > 0) {
        bucket -= LEAK_RATE;
        if (bucket < 0) bucket = 0;
        printf("Leaked 1 packet. Remaining in bucket: %d\n", bucket);
    }
}

int main() {
    int packets[] = {2, 4, 1, 3, 5, 2};
    int n = sizeof(packets) / sizeof(packets[0]);
    leaky_bucket(packets, n);
    return 0;
}
