#include <stdio.h>

int main()
{
    int bids; 
    double amount[100];
    printf("Enter the number of bids: \n");
    scanf("%d", &bids);
    
    if (bids >= 2) {
        
        for(int i = 0; i < bids; i++) {
            printf("Enter bid %d (Must be at least $100,000): \n", i + 1);
            scanf("%lf", &amount[i]);  // Use %lf to read a double

            if (amount[i] < 100000) {
                printf("Insufficient amount, please try again.\n");
                i--; 
            } else {
                printf("Bid %d: %.2lf\n", i + 1, amount[i]);
            }
        }

        double highest_bid = amount[0];
        for (int i = 1; i < bids; i++) {
            if (amount[i] > highest_bid) {
                highest_bid = amount[i];
            }
        }

        printf("Largest bid = %.2lf\n", highest_bid);

    } else {
        printf("Number of bids must be at least 2, please try again.\n");
    }

    return 0;
}

