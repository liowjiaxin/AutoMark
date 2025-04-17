#include <stdio.h>

int main() {

    int num_bids = 0;
    int arr[100];

    printf("Enter the number of bids: ");
    scanf("%d", &num_bids);
    for (size_t i = 1; i < num_bids + 1; i++)
    {
        printf("Bid %d: ", i);
        scanf("%d", &arr);

        if (arr[i] <= 100000) {
            printf("Error: Bid must be at least $100000. Please try again:");
            scanf("%d", &arr);
        }
    }

        // storing the largest number to arr[0]
    for (int j = 1; j < num_bids; ++j) {
        if (arr[0] < arr[j]) {
        arr[0] = arr[j];
        }
    }

     printf("The highest bid is: %d", arr[0]);

    return 0;
}