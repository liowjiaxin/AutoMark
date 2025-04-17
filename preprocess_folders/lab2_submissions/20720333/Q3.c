#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int bids, max, current_bid;

    do {
        printf("Enter the number of bids (more than 1): ");
        scanf("%d", &bids);

        if (bids < 2) {
            printf("Error: Number of bids must be at least 2.\n");
        }
    } while (bids < 2);

    max = 0;

    printf("Enter the bids (must be at least $100000):\n");

    for (int i = 0; i < bids; i++) {
        printf("Bid %d: ", i + 1);
        scanf("%d", &current_bid);

        while (current_bid < 100000) {
            printf("Error: Bid must be at least $100000. Please enter again: ");
            scanf("%d", &current_bid);
        }

        if (current_bid > max) {
            max = current_bid;
        }
    }

    printf("The highest bid is: $%d\n", max);

    return 0;
}
