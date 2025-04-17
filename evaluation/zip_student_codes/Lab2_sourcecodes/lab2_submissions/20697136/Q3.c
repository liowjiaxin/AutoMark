#include <stdio.h>

int main(void){
    int N = 0;
    printf("Enter number of bids: ");
    scanf("%d", &N);
    if(N <= 2){
        printf("Error. Number of bids must be at least 2. Please try again. ");
        scanf("%d", &N);
    }
    int arr[N];
    printf("Enter the bids (must be at least $100000)");
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
        if(arr[i] < 100000){
            printf("Error. Bid must be at least $100000. Please try again.");
            scanf("%d", &arr[i]);    
        }
        else{
            
        }
    }
}