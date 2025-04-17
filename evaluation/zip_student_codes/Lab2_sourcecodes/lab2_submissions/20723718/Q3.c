#include <stdio.h>

int main(void) {
    int N;
    double bids[N];

    printf("Enter the number of bids: ");
    scanf("%d", &N);

    if (N >= 2) {
        puts("Enter the bids (must be at least $100,000):");
        for (int i = 0; i < N; i++) {
            printf("Bid %d: ", i + 1);
            scanf("%lf", &bids[i]);
            if (bids[i] < 100000) {
                printf("Error: Bid must be at least $100,000. Please try again.\n");
                i--;
            }
        }
    } else {
        printf("Error: Number of bids must be at least 2. Please try again.\n");
    }
    
    double max = 0;

    for (int i = 0; i < N; i++) {
        if (max < (bids[i])) {
            max = bids[i];
        }
    }
    
    printf("The highest bid is $%lf", max);
    return 0;
        
}