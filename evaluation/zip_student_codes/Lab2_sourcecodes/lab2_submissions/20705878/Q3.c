#include <stdio.h>
#include <stdlib.h>

int main() {
    int N; //Number of bids
    float *bids; //Pointer to dynamically allocated array for bids
    float highest_bid = 0.0; //Variable to store the highest bid

    //Prompt the user to enter the number of bids (N must be >= 2)
    do {
        printf("Enter the number of bids (N >= 2): ");
        scanf("%d", &N);
        if (N < 2) {
            printf("Error: There must be at least 2 bids.\n");
        }
    } while (N < 2); //Repeat until a valid number of bids is provided

    //Allocate memory for the bids dynamically
    bids = (float *)malloc(N * sizeof(float));
    if (bids == NULL) { //Check if memory allocation was successful
        printf("Memory allocation failed.\n");
        return 1; //Exit the program if allocation fails
    }

    //Prompt the user to input each bid and validate it
    for (int i = 0; i < N; i++) {
        do {
            printf("Enter bid %d (at least $100,000): ", i + 1);
            scanf("%f", &bids[i]);
            if (bids[i] < 100000.0) {
                printf("Error: Each bid must be at least $100,000.\n");
            }
        } while (bids[i] < 100000.0); //Repeat until a valid bid is entered

        //Update the highest bid if the current bid is greater
        if (bids[i] > highest_bid) {
            highest_bid = bids[i];
        }
    }

    //Print the highest bid
    printf("The highest bid is: $%.2f\n", highest_bid);

    //Free the allocated memory to prevent memory leaks
    free(bids);

    return 0;
}