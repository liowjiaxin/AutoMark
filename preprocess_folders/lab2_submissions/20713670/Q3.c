#include <stdio.h>

int main() {
    int n;

  
    printf("Enter the number of bids: ");// Get the number of bids
    scanf("%d", &n);
    while (n < 2) {
        printf("Error: Number of bids must be at least 2. Please try again: ");
        scanf("%d", &n);
    }
    
    int bids[n];
    printf("Enter the bids (must be at least $100000):\n");// array to store bids

    // make sure the bids 
    for (int i = 0; i < n; i++) {
        printf("Bid %d: ", i + 1);
        scanf("%d", &bids[i]);
        while (bids[i] < 100000) {
            printf("Error: Bid must be at least $100000. Please try again: ");
            scanf("%d", &bids[i]);
        }
    }

    // find the highest bid
    int highest = bids[0];
    for (int i = 1; i < n; i++) {
        if (bids[i] > highest) {
            highest = bids[i];
        }
    }

    // this is the highest bid
    printf("The highest bid is: $%d\n", highest);

    return 0;
}
