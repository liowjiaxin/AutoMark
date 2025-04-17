#include <stdio.h>

int main () {
    int N;

    printf("Enter the number of bids: ");
    scanf("%d", &N);

    if (N < 2) {
        printf("Number of bids must be at least 2. Please try again.\n ");
        return 1;
    }

    printf("Enter the bids (must be at least $100000):\n");

    int bid[N];
    for (int i = 0; i < N; i++) {
        printf("Bid %d: ", i + 1);
        scanf("%d", &bid[i]);

        if (bid[i] < 100000) {
            printf("Error: Bid must be at least $100000. Please try again: ");
            i--;
        }
    }

    int highestBid = bid[0];
    
    for (int i = 1; i < N; i++) {
        if (bid[i] > highestBid) {
            highestBid = bid[i]; 
        }
    }

    printf("The highest bid is: $%d\n", highestBid);

    return 0;
}