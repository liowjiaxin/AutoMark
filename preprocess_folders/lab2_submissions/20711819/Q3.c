#include <stdio.h>
#include <stdlib.h> // library for malloc

int main(){
    // number of bids
    int bids = 0;
    // *money for storing each bid money
    // hold for holding the bid money before validate and put int array
    // highest to record highest
    long long *money, hold, highest = 0;
    
    // ask the user to enter the amount of bids
    printf("Enter the number of bids: ");
    scanf("%d", &bids);
    // loop until the bids are >= 2
    while(bids < 2){
        printf("Error: Number of bids msust be at least 2.\n");
        printf("Please try again: ");
        scanf("%d", &bids);
    }
    // allocate array for storing each bid amount
    money = malloc(bids * sizeof(hold));
    
    // ask user to enter bid money
    printf("Enter the bids (must be at least $100000):\n");
    // for each bid store into the array
    for (int i = 0; i < bids; i++){
        printf("Bid %d: ", i+1);
        scanf("%lld", &hold);
        // ask the user to enter again if it is less than 100000
        while (hold < 100000){
            printf("Error: Bid must be at least $100000.\n");
            printf("Please try again: $");
            scanf("%lld", &hold);
        }
        // store it into the array
        *money = hold;
        // increase the array address
        money++;
    }
    // reset the array address
    money -= bids;
    
    // let the highest be the first bid first
    highest = *money;
    // loop through the array
    for (int i = 1; i < bids; i++){
        money++;
        // if the current bid is higher, change the highest
        if (*money > highest){
            highest = *money;
        }
    }
    
    // print the highest
    printf("The highest bid is: $%lld", highest);
}