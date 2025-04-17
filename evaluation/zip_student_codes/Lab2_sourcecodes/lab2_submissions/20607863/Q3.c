#include <stdio.h>
#include <stdlib.h>


int main() {
    float *bids;
    int size;
    float max;

    // Prompt user for number of bids
    while (1) {
        printf("Enter the number of bids (N >= 2): ");
        scanf("%d", &size);

        // Input validation
        if (size >= 2) {
            break;
        } else {
            puts("There must be at least 2 bids. Please try again.");
        }
    }

    // Allocate memory for the array
    bids = malloc(size * sizeof(*bids));

    // Prompt user for bids
    puts("Enter the bids (must be at least $100,000):");
    for (int i=0; i<size; i++) {
        while (1) {
            printf("Bid %d: ", i+1);
            scanf("%f",&bids[i]);

            // Input validation
            if (bids[i] >= 100000) {
                break;
            } else {
                puts("Bids must be at least $100,000. Please try again.");
            }
        }
    }

    // Calculates the highest bid
    max = bids[0];
    for (size_t i = 0; i < size; i++) {
        if (bids[i] > max) {
            max = bids[i];
        } 
    }

    printf("The highest bid is %.2f", max);

    return 0;
}