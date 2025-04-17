QUESTION 3)

#include <stdio.h>

int main() {
    int N;
    float bids[100];  // Fixed-size array to store bids (assumes a maximum of 100 bids)
    float highest = 0;

    // Step 1: Input the number of bids and validate
    printf("Enter the number of bids (at least 2): ");
    scanf("%d", &N);
    while (N < 2) {
        printf("Error: Number of bids must be at least 2. Please try again: ");
        scanf("%d", &N);
    }

    // Step 2: Input the bids and validate
    printf("Enter the bids (must be at least $100000):\n");
    for (int i = 0; i < N; i++) {
        printf("Bid %d: ", i + 1);
        scanf("%f", &bids[i]);
        while (bids[i] < 100000) {
            printf("Error: Bid must be at least $100000. Please try again: ");
            scanf("%f", &bids[i]);
        }

        // Step 3: Check if this bid is the highest
        if (bids[i] > highest) {
            highest = bids[i];
        }
    }

    // Step 4: Print the highest bid
    printf("The highest bid is: $%.2f\n", highest);

    return 0;
}
