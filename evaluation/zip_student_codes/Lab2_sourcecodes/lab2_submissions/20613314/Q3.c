#include <string.h>
#include <stdio.h>

int main(){
    int n = 0; // number of bids
    int max = 99999; // for the highest bid

    while (1){
        // Entering
        printf("Enter the number of Bids:");
        scanf("%d", &n);

        // if the input is wrong
        if (n < 2) printf("Number of Bids must be at least 2. Try again.\n");
        else break; // if the input is correct , exit the infinite loop
    }

    int bids[n]; // create an array for bids

    printf("Enter the bids. Must be at least $100000.\n");

    // Entering bids cycle
    for (int i = 0; i < n; i++){

        while (1){
            // Enter one bid
            printf("Bid %d: ", i + 1);
            scanf("%d", &bids[i]);

            // if the input is wrong
            if (bids[i] < 100000) printf("Error: Bid must be at least 100000. Try again.\n");
            else break; // if the input is correct , exit the infinite loop
        }
    }

    // calculate the highest bid
    for (int i = 0; i < n; i++){
        if (max < bids[i]) max = bids[i];
    }


    printf("The highest bid is: $%d", max); // output the highest bid

    return 0;
}