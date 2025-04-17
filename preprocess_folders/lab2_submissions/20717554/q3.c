//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//    int N;
//    float* bids = NULL;//Dynamically allocating memory.
//    float highestBid = 0.0;//Storage maximum value.
//
//    printf("Enter the number of bids: ");
//    while (scanf_s("%d", &N) != 1 || N < 2) {//Check if the inputvalue is valid.
//        printf("Error: Number of bids must be at least 2. Please try again: ");
//        while (getchar() != '\n');
//    }
//
//    bids = (float*)malloc(N * sizeof(float));
//    if (bids == NULL) {//Checking memory allocation.
//        printf("Error: Memory allocation failed.\n");
//        return 1;
//    }
//
//    printf("Enter the bids (must be at least $100000):\n");
//    for (int i = 0; i < N; i++) {
//        printf("Bid %d: ", i + 1);
//        while (scanf_s("%f", &bids[i]) != 1 || bids[i] < 100000.0) {//Verify that the input value is not less than 100000.
//            printf("Error: Bid must be at least $100000. Please try again: ");
//            while (getchar() != '\n');
//        }
//    }
//
//    for (int i = 0; i < N; i++) {
//        if (bids[i] > highestBid) {
//            highestBid = bids[i];
//        }
//    }
//
//    printf("The highest bid is: $%.0f\n", highestBid);//Output maximum value.
//
//    free(bids);
//
//    return 0;
//}
