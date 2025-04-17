#include <stdio.h>
#include <stdlib.h>

int main () {
    int bid_number = 0;
    int *bid_amount = malloc(bid_number * sizeof(int));
    int highest_bid;

    printf("Enter the number of bids: ");
    scanf("%d", &bid_number);
    getchar();
    while (bid_number < 2) {
        printf("\nError: Number of bids must be at least 2. Please try again: ");
        scanf("%d", &bid_number);
        getchar();
    }

    printf("\nEnter the bids (must be at least $100,000): ");
    for (int i = 0; i < bid_number; i++) {
        printf("\nBid %d: ", i+1);
        scanf("%d", &bid_amount[i]);
        getchar();
        while (bid_amount[i] < 100000) {
            printf("\nError: bids must be at least $100,000. Please try again: ");
            scanf("%d", &bid_amount[i]);
            getchar();
        }
    }

    for (int i = 0; i < bid_number; i++) {
        if (highest_bid < bid_amount[i]) {
            highest_bid = bid_amount[i];
        }
    }

    printf("\nThe highest bid is: $%d", highest_bid);

    free(bid_amount);
    return 0;
}