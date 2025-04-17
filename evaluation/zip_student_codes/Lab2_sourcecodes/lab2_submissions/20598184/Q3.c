#include <stdio.h>

int main (void) {
    int N;

    // Do while loop for data validation
    do {
        printf("Enter the number of bids: ");
        scanf("%d", &N);
        if (N < 2 ) {
            printf("Error: Number of bids must be atleast 2. Please try again: ");
        }
    } while (N < 2);

    float bids[N]; // Declare array

    // Looping for assigning bids
    for (int i = 0; i < N; i++) {
        do {
            printf("Bid %d: ", i + 1);
            scanf("%f", &bids[i]);

            if (bids[i] < 100000) {
                printf("Error: Bid must be atleast $100,000. Please try again: ");
            }
        } while (bids[i] < 100000);
    }

    // Checking for highest bid
    float highestbid = bids[0];
    for (int i = 1 ; i < N; i++) {
        if (bids[i] > highestbid) {
            highestbid = bids[i];
        }
    }

    printf("The highest bid is : $%.2f \n", highestbid); // Prints final output

    return 0;
}