#include <stdio.h>

int largest(int arr[], int number);

int main() {
    int number;

    //Enter number of bids
    printf("Enter the number of bids: ");
    scanf("%d", &number);

    if (number < 2) {
        printf("Error: Number of bids must be at least 2. Please try again.\n");
        return 1; 
    }

    int arr[number];

    //enter into array
    printf("Enter the bids (must be at least $100000):\n");
    for (int i = 0; i < number; i++) {
        do {
            printf("Bid %d: ", i + 1);
            scanf("%d", &arr[i]);
            if (arr[i] < 100000) {
                printf("Error: Bid must be at least $100000. Please enter again.\n");
            }
        } while (arr[i] < 100000);
    }

    //highest bid
    printf("Highest Bid: %d\n", largest(arr, number));

    return 0;
}

int largest(int arr[], int number) {
    int max = arr[0];
    for (int i = 1; i < number; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
