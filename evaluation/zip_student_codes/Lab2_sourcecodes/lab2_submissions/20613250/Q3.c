#include <stdio.h>
int n=0;
int bid;

int main() {
    //prompt user to enter number of bids
    printf("Enter the number of bids:");
    while (n<2){ //validation
        scanf("%d", &n);
        if (n<2){ //validation
            printf("\nError: Number of bids must be at least 2. Please try again:");
        }
        else{
            break;
        }
    }
    //initialise array and highest bid
    int a[n];
    int h; //highest bid
    printf("\nEnter the bids(must be at least $100000): "); //prompt user to enter the bids   
    for (int i=0;i<n;i++){ //repeat for n time
        int j=i+1;
        printf("\nBid %d: ", (j)); //prompt user to enter the bid
        while (a[i] <100000){
            scanf("%d", &bid);//validation
            a[i] = bid;
            if (a[i]<100000){ //validation
                printf("\nError: Bid must be at least $100000. Please try again:");
            }
        }
    }
    //check for highest value
    for (int i=1;i<n;i++){
        if (a[i]>a[(i-1)]){ //if a[i] higher than a[i-1], then change highest bid to a[i]
            h=i;
        }
    }
    //display highest bid
    printf("\nThe highest bid is: %d", a[h]);
    
    return 0;
}