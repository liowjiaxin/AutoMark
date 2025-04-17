/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;               // Number of bids
    float *bids;        
    int i;
    float highest_bid = 0; 

    // Prompt user to enter the number of bids and check the validation
    do {
        printf("Enter the number of bids: ");
        scanf("%d", &N);
        if (N < 2) {
            printf("Error: Number of bids must be at least 2. Please try again: ");
            scanf("%d", &N);
        }
    } while (N < 2);

    // Allocate the memory to store the bids
    bids = (float *)malloc(N * sizeof(float));
    if (bids == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input each bid and check the validation
    printf("Enter the bids (must be at least $100000):\n");
    for (i = 0; i < N; i++) {
            printf("Bid %d: ", i + 1);
            scanf("%f", &bids[i]);
            while (bids[i] < 100000) {
                printf("Error: Bid must be at least $100000. Please try again: ");
                scanf("%f", &bids[i]);
            }
    }

    // Determine the highest bid
    highest_bid = bids[0];
    for (i = 1; i < N; i++) {
        if (bids[i] > highest_bid) {
            highest_bid = bids[i];
        }
    }

    // Display the highest bid
    printf("The highest bid is: $%.0f\n", highest_bid);

    return 0;
}

