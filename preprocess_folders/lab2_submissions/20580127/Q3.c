#include <stdio.h>

int main() {
int N;


printf("Enter number of bids: ");
scanf("%d", &N);

//tell user  that the number of bids is at least 2
while (N < 2) {
    printf("Error: number of bids must be at least 2. Please try again: ");
    scanf("%d", &N);
    }

//array to store the bids
float bids[N];

//let the user to enter the values of the bids one by one
for (int i = 0; i < N; i++) {
    printf("Enter bid %d (must be at least $100000): ", i + 1);
    scanf("%f", &bids[i]);
    while (bids[i] < 100000) {
        printf("Error: bid must be at least $100000. Please try again: ");
        scanf("%f", &bids[i]);
        }
    }

//check which is the highest bid
float highest_bid = bids[0];
for (int i = 1; i < N; i++) {
    if (bids[i] > highest_bid) {
            highest_bid = bids[i];
        }
    }


printf("Highest bid is: $%.2f\n", highest_bid);

    return 0;
}