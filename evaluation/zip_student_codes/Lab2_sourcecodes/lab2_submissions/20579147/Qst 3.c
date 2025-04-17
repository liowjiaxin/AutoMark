#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>





int main() {
    int N=0;//Initialization

    // prompt user to enter bids
    printf("Enter the number of bids(must be at least $100000): ");
    scanf("%d", &N);

    while (N < 2) {// check if number of bids is not less than two
        printf("Number of bids must be at least 2. Please try again: ");
        scanf("%d", &N);
    }

    int bids[N];//array

    // loop through number of bids
    for (int i = 0; i < N; i++) {
        printf("Bid %d: ", i + 1);
        scanf("%d", &bids[i]);// get output

        while (bids[i] < 100000) {
            printf("Error: Bid must be at least $100000. Please try again: ");
            scanf("%d", &bids[i]);//output
        }
    }

    //
    int highest_bid = bids[0];
    for (int i = 1; i < N; i++) {
        if (bids[i] > highest_bid) {
            highest_bid = bids[i];
        }
    }

    // Step 4: print the highest bid
    printf("The highest bid is: $%d\n", highest_bid);






return 0;//end program

}
