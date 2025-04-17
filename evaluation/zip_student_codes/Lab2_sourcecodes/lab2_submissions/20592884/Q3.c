#include <stdio.h>

#define MAX_BIDS 100 //Define the maximum number of bids for the program

int main() {
    int N, i;                  //N: means Number of bids and i: Loop counter
    double bids[MAX_BIDS];     //Array to keep the values of the bids

    //Ask the user for the number of bids and validate it
    do {
        printf("Enter the number of bids (N >= 2): ");
        scanf("%d", &N);
        if (N < 2) {
            printf("Error: There must be at least 2 bids.\n");
        }
    } while (N < 2); //Repeat previous part until user has entered the minimum amount of bids

    //Gather the values of the bids from the user, to ensure it is at least $100000
    for (i = 0; i < N; i++) {
        do {
            printf("Enter bid %d (must be at least $100,000): ", i + 1);
            scanf("%lf", &bids[i]);
            if (bids[i] < 100000) {
                printf("Error: Bid must be at least $100,000.\n");
            }
        } while (bids[i] < 100000); //Repeat until the user gives the minimum requested value of bid
    }

    //Determine the highest bid from the above values
    double highestBid = bids[0]; //Initialize with the first bid
    for (i = 1; i < N; i++) {    //Continue from the second bid
        if (bids[i] > highestBid) {
            highestBid = bids[i]; //change if a higher bid is found
        }
    }

    //Show the highest bid to the user
    printf("The highest bid is: $%.2f\n", highestBid);

    return 0;
}