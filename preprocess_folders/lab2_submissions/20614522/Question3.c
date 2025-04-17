#include <stdio.h>

int main(void) {

    int n=0;
    printf("Enter the number of bids: ");
    scanf("%d",&n);

    while(n<2) {        //while loop when the condition does not fulfill

        printf("Error: Number of bids must be at least 2. Please try again: ");
        scanf("%d",&n);   
    }

    int array[n];       //declare an array to store data
    printf("Enter the bids (must be at least $100000):\n");
    for (int i=1; i<=n; ++i) {
        printf("Bid %d:", i);
        scanf("%d",&array[i]);

        if (array[i]>=100000) {     //if the condition is fufill continue the for loop
            continue;
        }

        while (array[i]<100000) {   //check the condition 
            printf("Error: Bid must be at least $100000. Please try again: ");
            scanf("%d", &array[i]);
        }
    }

    for (int i=1; i<n; ++i) {           //bubble sort to sort the array element

        for (int j=0; j<n-1; ++j) {
            if (array[i]>array[i+1]) {
                int hold= array[i];
                array[i]=array[i+1];
                array[i+1]=hold;
            }
        }
    }

    printf("The highest bid is: %d", array[n]);     //take the last element of the sorted array because it is the largest number

}