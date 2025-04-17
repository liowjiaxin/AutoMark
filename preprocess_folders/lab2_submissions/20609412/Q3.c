#include <stdio.h>


//function prototype
int findMax(int arr[], int n);

int main() {
    
    int highest_value, N;
    
    //get user input of how many bids all together
    printf("Enter the number of bids: ");
    scanf("%d", &N);
    
    //set a array
    int bids[N];
    
    //Perform validation that N ≥ 2
    while (N<2){
        printf("\nError: Number of bids must be at least 2. Pls try again: ");
        printf("\nEnter the number of bids: ");
        scanf("%d", &N);
    }
    
    
    //get values of the bids    
    for (int i=0; i<N; i++){
        printf("Enter the bids (must be at least $100000)\n");
        printf("Bid %d:", i+1);
        scanf("%d", &bids[i]);
        
        while (bids[i]<100000){
            printf("Error: Bid must be at least $100000. Pls try again: ");
            printf("Bid %d:", i+1);
            scanf("%d", &bids[i]);
        }
    }
    
    //use the function to find the highest bid
    printf("The highest bid is: %d", findMax(bids, N));
    
    return 0;
}


//find highest function
int findMax(int arr[], int n) {
  
      // Assume the first element is the largest
    int max = arr[0];
    for (int i = 1; i < n; i++) {
      
          // Update max if arr[i] is greater
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}