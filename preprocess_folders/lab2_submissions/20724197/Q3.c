#include <stdio.h>

int main() {
    int numbers[20];     // Array to hold the numbers being read
    int unique[20];      // Array to store unique numbers
    int count = 1;       // Counter for the number of unique numbers
    int isDuplicate;     // Flag to check if a number is a duplicate
    int bidsN;

    printf("Enter the number of bids: ");
    scanf("%d", &bidsN);

     while(bidsN<2){
        printf("Error: Number of bids must be at least 2. Please try again:\n");
        scanf("%d", &bidsN);

    }

    printf("Enter the bids (must be at least $100000):\n");

    for (int i = 0; i < bidsN; i++) {  //user can input 20 times with valid numbers
        printf("Bid %d :", count);
        scanf("%d", &numbers[i]);
        count++;

        // Check if the number is in the valid range
        if (numbers[i] < 100000) {
            printf("Bid must be at least $100000. Please try again: ");
            i--; // Decrement i to re-enter the number
            count--;
        }
        

        }

       return 0; 

    }

    
