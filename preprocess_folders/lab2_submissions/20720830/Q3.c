#include <stdio.h>

// Function prototype
int maximum(int arr[], int n);

int main(){
    int n=0;
    // Input the number of bids
    printf("Enter the number of bids: ");
    scanf("%d",&n);
    // Validate the number of bids (N>=2)
    while(n<2){
        printf("Error: Number of bids must be at least 2. Please try again: ");
        scanf("%d",&n);
        }
    int bids[n];
    // Input the bids
    printf("Enter the bids (must be at least $100000):\n");
    // Validate the bids (>=100000)
    for(int i=0;i<n;i++){
        printf("Bid %d: ",i+1);
        scanf("%d",&bids[i]);
        if(bids[i]<100000){
            printf("Error: Bid must be at least $100000. Please try again: ");
            scanf("%d",&bids[i]);
        }
    }
    // Output the highest bid
    printf("The highest bid is: $%d\n",maximum(bids,n));
    return 0;
}

// Function to find the highest bid
int maximum(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
