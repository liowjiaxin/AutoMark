#include <stdio.h>



int main() {
    int n;
    int highestBid = 0;
    int *bids;
    int min=100000; //at least $100,000

    //Prompt enter the number of bids (N) and validate that N ≥ 2
    printf("Enter the number of bids (N >= 2): ");
    
    scanf("%d", &n);
    if (n < 2) {
        printf("Must be more than two bids.\n");
        return 1;
    }

    //Dynamically allocate memory for array
    bids = (int *)malloc(n * sizeof(int));
    if (bids == NULL) {
        printf("error.\n");
        return 1;
    }

    // Prompt enter the values of the N bids 
    
    int i;
    printf("bids must be at least: $%d):\n", min);
    for (i = 0; i < n; i++) {
        printf("Enter bid %d):", i);
        scanf("%d", &bids[i]);
        
        while (bids[i] < min) {
            printf("Invalid bid. At least $%d.\n", min);
            printf("Enter bid %d: ", i + 1);
            scanf("%d", &bids[i]);
        }
        
        if (i == 0 || bids[i] > highestBid) {
            highestBid = bids[i];
        }
    }

    // Output the value of the highest bid
    printf("The highest bid is: $%d\n", highestBid);

    
    free(bids);

    return 0;
}