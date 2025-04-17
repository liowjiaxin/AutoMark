#include<stdio.h>
#include<stdlib.h>

float findhighestbid (const float bids[], int count);
int main() {
    int N;
    printf("Enter the number of bids: ");
    scanf("%d", &N);
    if (N < 2) {
        printf("Error: Number of bids must be at least 2. Please try again: ");
        scanf("%d", &N);
    }
    float *bids = (float* )malloc(N * sizeof(float));
    if (bids == NULL) {
        printf("Error: Memroy allocated failed.\n");
        return 1;
    }
    printf("Enter the bids (must be at least $100000): \n");
    for (int i = 0; i < N; i++) {
        printf("Enter bid %d: $", i + 1);
        scanf("%f", &bids[i]);
        while (bids[i] < 100000) {
            printf("Error: bids must be at least $100000. Please try again: ");
            scanf("%f", &bids[i]);
        }
    }
    float highestbid = findhighestbid (bids, N);
    printf("The highest bid is $%.f\n", highestbid);
    free(bids);
    return 0;
}

float findhighestbid (const float bids[], int count) {
    float highest = bids[0];
    for (int i = 1; i < count; i++) {
        if (bids[i] > highest) {
            highest = bids[i];
        }
    }
    return highest;
}
