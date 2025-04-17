#include <stdio.h>

//Function to find the highest bid 
float* highest_float(float *a, float *b, float *c){
    if (*a > *b, *a > *c) {
        return a;
    }
    if (*b > *a, *b > *c) {
        return b;
    }
    if (*c > *a, *c > *b) {
        return c;
    }
}

int main()
{
    int num_bid;
    float num1, num2, num3;
    
    printf("Enter the number of bids: ");
    scanf("%d", &num_bid);
        
    printf("Enter the bids (must be at least $100000):\n");
    
    printf("Bid 1: ");
    scanf("%f", &num1);
        
    printf("Bid 2: ");
    scanf("%f", &num2);
    
    printf("Bid 3: ");
    scanf("%f", &num3);
    
    //Call function to find highest bid 
    float *highest = highest_float(&num1, &num2, &num3);
    
    printf("The highest bid is: $%f\n", *highest);
    
    return 0;
    }
    
