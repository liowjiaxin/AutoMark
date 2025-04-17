#include <stdio.h>

int main() {
    int N;

    printf("Enter the number of bids: ");
    scanf("%d", &N);

    if (N < 2) {
        printf("Error: You need at least two bids.\n");
        return 0;
    }
    // If N is valid, proceed to enter the bids
    float highest_bid, bid;

    printf("Enter bid (minimum $100,000): ");
    for (int i = 1; i <= N; i++) {
        printf("Enter bid #%d (minimum $100,000): ", i);
        scanf("%f", &bid);

        // Check if the entered bid is valid
        while (bid < 100000) {
            printf("Invalid bid! The bid must be at least $100,000. Enter bid #%d again: ", i);
            scanf("%f", &bid);
        }
        printf("The highest bid is: %.2f\n", highest_bid);
    }
    return 0;
}
