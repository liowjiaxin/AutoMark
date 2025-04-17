#include <stdio.h>
#include <stdlib.h>


int main() {
    printf("Enter the number of bids: ");
    int N;
    scanf("%d", &N);

    while (N < 2){
        printf("Error: Number of bids must be at least 2. Please try again:");
        scanf("%d", &N);
    }

    int bids[N];
    int highest = 0;
    
    for (int i = 0; i < N; i++){
        printf("Bid %d:", i + 1);
        int temp;
        scanf("%d", &temp);

        while (temp < 100000){
            printf("Error: Bid must be at least $100000. Please try again: ");
            scanf("%d", &temp);
        }

        if (temp > highest){
            highest = temp;
        }

        bids[i] = temp;
    }

    printf("\nThe highest bid is: $%d", highest);

    return 0;
}