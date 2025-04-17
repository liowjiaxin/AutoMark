#include <stdio.h>

int main(void) {
    int N, i;
    double highbid = 0;

    //Input number of bids 
    printf("Enter the number of bids: ");
    scanf("%d", &N);

    while (N < 2) {
        printf("Error: Number of bids must be at least 2. Please try again: ");
        scanf("%d", &N);
    }

    //Array to store the bids
    double bids[N];

    printf("Enter the bids (must be at least $100000):\n");

    for (i = 0; i < N; i++) {
        double bid;
        printf("Bid %d: ", i + 1);
        scanf("%lf", &bid);

        //Validate each bid
        while (bid < 100000) {
            printf("Error: Bid must be at least $100000. Please try again: ");
            scanf("%lf", &bid);
        }

        bids[i] = bid;

        //highest bid
        if (bid > highbid) {
            highbid = bid;
        }
    }

    //Output the highest bid
    printf("The highest bid is: $%.0lf\n", highbid);

}
