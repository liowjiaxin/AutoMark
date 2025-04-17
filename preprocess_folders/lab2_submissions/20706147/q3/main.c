/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main() {
    int N;
    float MIN_BID = 100000;  
    
    // Get the number of bids from 
    printf("Enter the number of bids (N): ");
    scanf("%d", &N);
    
    // Validate N is at least 2
    if (N < 2) {
        printf("Error: There must be at least 2 bids to determine the highest bid.\n");
        return 1;  // Exit the program if not valid
    }

    // Declare an array to store the bids
    float bids[N];

    // Get the bids from the user with validation
    for (int i = 0; i < N; i++) {
        do {
            printf("Enter bid %d (at least $%.0f): ", i + 1, MIN_BID);
            scanf("%f", &bids[i]);
            
            // Validate the bid
            if (bids[i] < MIN_BID) {
                printf("Bid must be at least $%.0f. Please enter a valid bid.\n", MIN_BID);
            }
        } while (bids[i] < MIN_BID);  // Repeat until a valid bid is entered
    }
    
    //Determine the highest bid
    float highestBid = bids[0];  
    for (int i = 1; i < N; i++) {
        if (bids[i] > highestBid) {
            highestBid = bids[i];  
        }
    }
    //Output the highest bid
    printf("The highest bid is: $%.2f\n", highestBid);
    return 0;
}
