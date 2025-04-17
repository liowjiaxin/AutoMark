#include <stdio.h>
#include <stdlib.h>

int main() {

    int bidsCount = 0;
    int* bids = malloc(bidsCount * sizeof(int));
    
    int max = 0;

    printf("Enter the number of bids: ");
    scanf("%d", &bidsCount);
    
    while(bidsCount < 2) {
        printf("Error: Number of bids must be at least 2. Please try again: ");
        scanf("%d", &bidsCount);
    }

    printf("Enter the bids (must be at least $100,000):\n");

    for (int i = 0; i < bidsCount; i++) {

        printf("Bid %d: ", i + 1);
        scanf("%d", (bids + i));

        while(*(bids + i) < 100000) {
            
            printf("Error: Bid must be at least $100,000. Please try again: ");
            scanf("%d", (bids + i));
        }
    }


    for (int i = 0; i < bidsCount; i++) {
        if (max < bids[i]) {
            max = bids[i];
        }
    }
    
    printf("The highest bid is: %d", max);

    return 0;
}