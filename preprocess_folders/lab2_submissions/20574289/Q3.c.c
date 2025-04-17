// Library Pull & Definition Establishment
#include <stdio.h>
#define Minimum_Bid 100000

// Main Code Block
int main() {
    
    // Variable Declaration
    int n;
    int i;
    double bids[100], highest_bid = 0;
    
    // Bid Calculation & Validaton using do/while statement
    printf("Please enter the number of bids [Minimum amount of 2]:\n");
    do {
        scanf("%d", &n);
        if (n < 2) {
            printf("Please try again, the minimum number of bids is two.\n");
        }
    } while (n < 2);
    
    // Bid Value Calculation & Validation using for loop & do/while statement
    // For the n [Number of bids], run the following code.
    for (i=0; i < n; i++) {
        do {
            printf("Enter bid #%d [The minimum bid is $100,000]: $", i+1);
            scanf("%lf", &bids[i]);
            
            if (bids[i] < Minimum_Bid) {
                printf("Please try again, reminder that the minimum bid must be atleast $100,000.\n");
            }                            // Validation Check
            
        } while (bids[i] < Minimum_Bid); //  While the calculated bid is less than the minimum bid, run the do/while statement.
    }
    
    // Allocation of highest bid using for loop
    for (i = 0; i < n; i++) {
        if (bids[i] > highest_bid) {
            highest_bid = bids[i];
        }
    }
    
    // Result Display & End
    printf("\nThe highest recorded bid is $%.2f\n", highest_bid);
}

