#include <stdio.h>

#define MAX_NUM 100

int main() {
    //define variables
    int num_bids;
    int array[MAX_NUM];
    int highest = 0;

    // ask user to input the number of bids
    printf("Enter the number of bids: ");
    while (1) {
        // error handling
        if (scanf("%d", &num_bids) != 1 || num_bids < 2) {
            printf("Error: Number of bids must be at least 2. Please try again: ");
        }
        else {
            break;
        }
    }
    
    // ask user to input bids
    printf("Enter the bids (must be at least $100000): \n");
    int num;
    for (size_t i = 0; i < num_bids; i++) {
        printf("Bid %d: ", i + 1);
        // while loop for error handling
        while (1) {
            if (scanf("%d", &num) != 1 || num < 100000) {
            printf("Error: Bid must be at least $100000. Please try again: ");
            while(getchar() != '\n');
        }
        else {
            // if bid is valid, then find the maximum
            array[i] = num;
            if (array[i] > highest) {
                highest = array[i];
            }
            break;
            }
        }
    }
    
    // printing the highest bid
    printf("The highest bid is: $%d", highest);
    
    return 0;
}