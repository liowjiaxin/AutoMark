#include <stdio.h>

int main(void) {

    int bids, value[100], highest = 0;

    // Prompt for the number of bids
    printf("Enter the number of Bids: ");
    scanf("%d", &bids);

    // Validate that the number of bids is at least 2
    while (bids < 2) {
        printf("Number of bids must be at least 2. Please try again: ");
        scanf("%d", &bids);
    }

    // Inputing the value of bids
    for (int i = 0; i < bids; ++i) { 
        printf("Enter the bid #%d (must be at least $100000): ", i + 1);
        scanf("%d", &value[i]);

        // Validate individual bid amounts
        while (value[i] < 100000) {
            printf("Invalid bid. Please try again (must be at least $100000): ");
            scanf("%d", &value[i]);
        }

        // Update the highest bid if the current bid is greater
        if (highest < value[i]) {
            highest = value[i];
        }
    }

    // Output the highest bid
    printf("The highest bid is: $%d\n", highest);
}
