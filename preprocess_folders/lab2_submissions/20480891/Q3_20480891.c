#include <stdio.h>

int main() {
    int N, i;
    int bids[100];

    //Get the number of bids
    printf("Enter the number of bids: ");
    scanf("%d", &N);

    //Validate the number of bids
    if (N < 2) {
        printf("A highest bid cannot be determined with fewer than two bids.\n");
        return 1;
    }

    //Get the bid values
    printf("Enter the bid values:\n");
    for (i = 0; i < N; i++) {
        scanf("%d", &bids[i]);

        //Validate each bid
        if (bids[i] < 100000) {
            printf("Invalid bid amount. Each bid must be at least $100,000.\n");
            return 1;
        }
    }

    //The highest bid
    int highest_bid = bids[0];
    for (i = 1; i < N; i++) {
        if (bids[i] > highest_bid) {
            highest_bid = bids[i];
        }
    }

    //Print the highest bid
    printf("The highest bid is: $%d\n", highest_bid);

    return 0;
}