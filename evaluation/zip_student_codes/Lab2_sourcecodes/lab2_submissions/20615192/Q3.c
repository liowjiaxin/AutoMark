#include <stdio.h>

int main()
{
    int num;
    int bids[num];
    
    printf("Enter the number of bids:");
    scanf("%d", &num);
    
    if(num<2){
        printf("Error: Number of bids must be at least 2. PLease try again:");
        scanf("%d", &num);
    }
    
    printf("Enter the bids (must be at least $100,000):\n");
    for (int i=0; i<num; i++) {
        printf("Bid %d: ", i+1);
        scanf("%d", &bids[i]);
        if (bids[i]<100000) {
            printf("Error: Bid must be at least $100,000. Please try again: ");
            scanf("%d", &bids[i]);
        }
    }
    
    int big=bids[0];
    for (int i=1; i<num; i++) {
        if (bids[i]>big) {
            big=bids[i];
        }
    }
    printf("The highest bid is: $%d\n", big);

}