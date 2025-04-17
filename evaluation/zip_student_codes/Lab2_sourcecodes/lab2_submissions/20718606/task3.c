#include <stdio.h>

int main() {

    //1) The user should be able to enter the number of bids (N). Perform validation that N ≥ 2. If there are fewer than two valid bids, the program should display an appropriate message indicating that a highest bid cannot be determined.
    int N;
    do {
        printf("Enter the number of bids (N >= 2): "); //so long as N is less than 2 it will ask for appropriate number of bids 
        scanf("%d", &N);
    } while (N < 2);

    //2) The user should then enter the values of the N bid one by one. Perform validation of user inputs to ensure each bid is at least $100,000.
    int bids[N];
    for (int i = 0; i < N; i++) {
        do {
            printf("Enter the value of bid %d: ", i + 1); //we need the bids to be of the amount specific by N 
            scanf("%d", &bids[i]);
        } while (bids[i] < 100000); //cheeck bids are greater than 100,000 if not then run the looop and ask again
    }

    //3) The program will determine the highest bid from the entered values.
    int highestBid = bids[0];
    for (int i = 1; i < N; i++) {
        if (bids[i] > highestBid) { //if the current bid > the original bid then that is the new highest bid 
            highestBid = bids[i];
        }
    }

    //4) The program should output the value of the highest bid.
    printf("The highest bid is: $%d\n", highestBid);

    return 0;
}