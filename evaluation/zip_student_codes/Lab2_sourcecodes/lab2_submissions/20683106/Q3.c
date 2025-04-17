#include <stdio.h>

int main(void){
    int size;

    // Prompt user for the total number of bids
    printf("Enter the number of bids N (N >= 2): ");
    scanf("%d", &size);
    // Validate if the number of bids are at least 2. If not, prompt for re-input and display error message
    while(1){
        if(size < 2){
            printf("N is lesser than 2. A highest bid cannot be determied. Please enter again.\n");
            scanf("%d", &size);
        } else {
            break;
        }

    }

    // Using user's number of bids to declare array with respective size
    int bids[size];
    int highest = 0; // Variable to record highest bid. Since bids starts from at least $100,000, initializing it 
                     // to 0 will ensure that the first bid input will always be larger than this variable and replaces it

    // Populate the array with bid amounts from the user
    printf("Enter the bids (Amount must be at least $100,000):\n");
    for(int x = 0; x<size; x++){
        printf("Bid %d: ", x+1);
        scanf("%d", &bids[x]);
        // Validate bid amount, if amount is less than $100,000 prompt user for re-input
        while(bids[x]<100000){
            printf("Bid amount must be at least $100,000. Please enter again: ");
            scanf("%d", &bids[x]);
        }
        // Setting the highest bid amount while looping - replaces variable "highest" with current amount if it is larger
        if(bids[x] > highest){
            highest = bids[x];
        }
        printf("\n");
    }

    // Print final highest bid
    printf("The highest bid is: %d", highest);


    return 0;
}