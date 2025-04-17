#include <stdio.h>
#include <stdlib.h>

//define a function prototype, we use unsigned long long int due to the possibility of overflowing
//might be overkill but better safe than sorry
int find_highest_bid(unsigned long long int* bidpnt, int bidders);

int main(){
    //initialise bidders variable
	int bidders = 0;
    printf("Enter the number of bids: ");
	scanf("%d", &bidders);
    //loop to catch incorrect values
    //not my preferred implementation but this is needed to match sample program output
	while (bidders < 2) {
		if (bidders < 2) {
		    printf("Error: Number of bids must be at least 2. Please try again: ");
            scanf("%d", &bidders);
		}
	}
    //allocate space for the bid values
    //unsigned long long int strikes again
	unsigned long long int *bidpnt = malloc(bidders * sizeof(unsigned long long int));
	printf("Enter the bids (must be at least $10000):\n");
	for (int i = 0; i < bidders; ++i){
        //define a temporary variable so we can perform checks on it before placing it in our array
        unsigned long long int temp;
        printf("Bid %d: $",i+1);
        scanf("%llu",&temp);
        //again, not my preferred implementation but needed to match sample output
        while (temp < 100000){
            printf("Error: Bid must be at least $100000. Please try again: $");
            scanf("%llu", &temp);
        }
        //assign the validated value to the memory space pointed to in the array
        *(bidpnt+i) = temp;
	}
    //print our final value using a function passed as a parameter to printf()
    printf("The highest bid is: $%d\n", find_highest_bid(bidpnt,bidders));
    //make sure to free memory, even more important when dealing with long long
	free(bidpnt);
	return 0;

}

int find_highest_bid(unsigned long long int* bidpnt, int bidders){
    //assume max is first element of array
    int max = *bidpnt;
    //pratically a linear search for the highest element
    for (int i = 0; i < bidders; ++i){
        if (*(bidpnt+i) > max){
            max = *(bidpnt+i);
        }
    }
    //return our value
    return max;
}
