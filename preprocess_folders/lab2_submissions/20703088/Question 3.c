#include <stdio.h>

void findLargest(int arr[], int N) {
    int max = arr[0]; // Initialize max with the first element
    //loop through the array, assume first number = maximum number
    for (int i = 1; i < N; i++) {
        //if first number is not max, max will be shifted one number every iteration
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("The largest bid is: %d\n", max);
}

int main() {
    int N; //number of bids to be placed
    printf("Enter the number of bids you want to place: ");
    scanf("%d", &N);

    // Validate the number of bids
    while (N < 2) {
        printf("Number of bids must be at least 2, please try again: ");
        scanf("%d", &N);
    }
    //array for storing the bids 
    int bids[N];
    for (int i = 0; i < N; i++) {
        printf("Enter bid %d (Must be over $100000): ", i + 1);
        scanf("%ld", &bids[i]); // Use %ld for long int
        while (bids[i] < 100000) {
            printf("The bids must be over $100000, try again: ");
            scanf("%ld", &bids[i]);
        }
    }

    findLargest(bids, N);
}