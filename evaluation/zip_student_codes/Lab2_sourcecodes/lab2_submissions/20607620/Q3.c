#include <stdio.h>

int main() {
    int N;


    do {
        printf("Enter the number of bids (N ≥ 2): ");
        scanf("%d", &N);
        if (N < 2) {
            printf("Error: At least two bids are required to determine the highest bid.\n");
        }
    } while (N < 2);


    int bids[100]; 


    for (int i = 0; i < N; i++) {
        do {
            printf("Enter bid %d (at least $100,000): ", i + 1);
            scanf("%d", &bids[i]);
            if (bids[i] < 100000) {
                printf("Error: Each bid must be at least $100,000. Please try again.\n");
            }
        } while (bids[i] < 100000);
    }


    int highest_bid = bids[0];
    for (int i = 1; i < N; i++) {
        if (bids[i] > highest_bid) {
            highest_bid = bids[i];
        }
    }


    printf("\nThe highest bid is: $%d\n", highest_bid);

    return 0;
}
