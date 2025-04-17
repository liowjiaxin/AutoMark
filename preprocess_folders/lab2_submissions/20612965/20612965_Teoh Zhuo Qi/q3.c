//lab 2 question 3 
#include <stdio.h>

int main() {
    int N;

    printf("Enter the number of bids: ");
    while(1) {
        scanf("%d", &N);
        if (N >= 2) {
            break;
        }
        printf("Error: Number of bids must be at least 2. Please try again: ");
    }

    float bids[100];

    for (int i = 0; i < N; ++i) {
        while(1) {
            printf("Bid %d: ", i + 1);
            scanf("%f", &bids[i]);
            if (bids[i] >= 100000) {
                break;
            }
            printf("Error: Bid must be at least $100000. Please try again: ");
        }
    }

    float highestBid = bids[0];
    for (int i = 1; i < N; ++i) {
        if (bids[i] > highestBid) {
            highestBid = bids[i];
        }
    }

    printf("The highest bid is: $%.2f\n", highestBid);

    return 0;
}
