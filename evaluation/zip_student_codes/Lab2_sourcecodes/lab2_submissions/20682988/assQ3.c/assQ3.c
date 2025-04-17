#include <stdio.h>
#define min_bid 100000
int N;
int i;

int main()
{
	do {
		printf("Enter the number of bids:");
		scanf("%d",&N);

		if(N<2) {
			printf("Error:Number of bids must be at least 2.Please try again.\n");
		}
	} while(N<2);


	int bids[N];
	for(int i=0; i<N; i++) {
		do {
			printf("Bid %d:",i+1);
			scanf("%d",&bids[i]);
			if(bids[i]<min_bid) {
				printf("Error:Bid must be at least $100000.Please try again.\n");
			}
		} while(bids[i]<min_bid);
	}
	int highestBid = bids[0];
    for (int i = 1; i < N; i++) { // Corrected for loop syntax
        if (highestBid < bids[i]) {
            highestBid = bids[i];
        }
    }
	printf("The highest bid is:$ %d\n",highestBid);

    return 0;
}