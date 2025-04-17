// QUESTION 3

#include<stdio.h>
#include<string.h> // to use function strlen

//function prototypes
int valid_bid(int bid);
void display_error(char error_msg[]);
int highest_bidder(int bid_arr[], size_t num_bit);

// function main begins program execution
int main(void){
    // initialisation of variables
    int num_bids=0;
    int bid=0;

    // prompt user to enter number of bids
    printf("%30s", "Enter the number of bids: ");
    scanf("%d", &num_bids);
    while(num_bids<2){
        display_error(" Error: Number of bids must be at least 2. Please try again.");
        printf("%30s", "Enter the number of bids: ");
        scanf("%d", &num_bids);
    }

    // initialise bid array
    int valid_bid_arr[num_bids];

    // prompt user to enter their bids one by one
    // perform validation of user inputs (at least 100,000);
    puts("==========================================");
    puts("Enter the bids (must be at least $100,000)");
    puts("");
    for(int i=0; i<num_bids; i++){ // loop to enter bid
        printf("Bid %d: $", i+1);
        scanf("%d", &bid);

        while(valid_bid(bid)<0){ // validation
            display_error(" Error: Bid must be at least $100,000. Please try again");
            printf("\tBid %d: $", i+1);
            scanf("%d", &bid);
        }

        // store valid bid in array
        valid_bid_arr[i]=bid;
    }
    int result=highest_bidder(valid_bid_arr, num_bids);

    // display result
    puts("==========================================");
    printf("The highest bid is $%d by bidder #%d.", valid_bid_arr[result], result+1);
}

// ========= OTHER FUNCTIONS ============

// checks if bid is valid
int valid_bid(int bid){
    if(bid>=100000){
        return 1;
    }else{
        return -1;
    }
}

// displays formatted error message
void display_error(char error_msg[]){
    int length=strlen(error_msg);
    for(int i=0;i<length+2;i++){
            printf("-");
        }
        puts("");
        puts(error_msg);
        for(int i=0;i<length+2;i++){
            printf("-");
        }
        puts("");
}

// finds and returns the highest bidder
int highest_bidder(int bid_arr[], size_t num_bid){
    // initialise local variables
    int max=0;
    int bidder_index=0;

    for(int i=0; i<num_bid; i++){
        if(bid_arr[i]>max){ // loop through array and 
            max=bid_arr[i]; // update value of max if there is a larger bid
            bidder_index=i;
        }
    }
    return bidder_index; 
}