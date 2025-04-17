#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {

    int a = 0;  //Initialize a variable.
    double b = 0;//current bid
    double c = 0;//highest bid
    int i = 1;  //loop

    while (a < 2) {
        printf("Enter the number of bids: ");
        scanf("%d", &a);

        if (a < 2) {
            printf("Error: Number of bids must be at least 2. Please try again: ");
            scanf("%d", &a);
        }
    }
    printf("Enter the bids (must be at least $100000):\n");

    for (i = 1; i <= a; i++) {
        printf("Bid %d: ", i);
        scanf("%lf", &b);

        while (b < 100000) {
            printf("Error: Bid must be at least $100000. Please try again: ");
            scanf("%lf", &b);
        }

        if (b > c) {
            c = b;
        }
    }

    printf("The highest bid is: $%.0f\n", c);

    return 0;
}