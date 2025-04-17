#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

    // 1) Prompt and check if N>=2
    do {
        printf("Enter the number of bids (minimum 2): ");
        scanf("%d", &N);

        if (N < 2) {
            printf("Invalid number of bids. There must be at least two bids.\n");
        }
    } while (N < 2);

    // Check if there are fewer than two valid bids
    if (N < 2) {
        printf("Not enough bids to determine the highest bid.\n");
        return 0;
    }

    // Allocate memory
    int *bids = (int *)malloc(N * sizeof(int));
    if (bids == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // 2) Enter 1 by 1 
    // Check is each is at least 100,000
    for (int i = 0; i < N; i++) {
        int valid = 0;
        do {
            printf("Enter bid #%d (minimum $100000): ", i + 1);
            if (scanf("%d", &bids[i]) != 1) {
                printf("Invalid input. Please enter a numeric value.\n");
                // Clear invalid input from buffer
                while (getchar() != '\n');
                continue;
            }

            if (bids[i] < 100000) {
                printf("Bid must be at least $100,000. Please enter again.\n");
            } else {
                valid = 1;
            }
        } while (!valid);
    }

    // 3) The program will determine the highest bid from the entered values.
    int highest_bid = bids[0];
    for (int i = 1; i < N; i++) {
        if (bids[i] > highest_bid) {
            highest_bid = bids[i];
        }
    }

    // 4) The program should output the value of the highest bid.
    printf("The highest bid is $%d.\n", highest_bid);

    // Free the allocated memory
    free(bids);

    return 0;
}
