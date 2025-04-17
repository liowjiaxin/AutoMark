#include <stdio.h>

int main() {
    // initialise variables
    int N; 
    int a , b;
    
    //ask user for size of array
    printf("Enter the size of the array (N>=5): ");
    scanf("%d", &N);

    //initialise more variables after finding out size of array 
    int array[N]; 
    int *ptr = array;

    if (N < 5){ // ask user to enter bigger number if not bigger than 5
        printf("Enter a bigger number"); 
    }
    else {
        printf("Enter the array of elements\n"); //ask user to enter a value to each element
        for (int i = 0; i < N; ++i){
        printf("Enter elements %d: ", i);
        scanf("%d", ptr + i);
        }

        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ",N); // ask for which element to find the sum of 
        scanf("%d %d",&a, &b);
        if (a >= N || b >= N || a < 0 || b < 0){ // check if inputs are valid 
            printf("Indices must be within the range of array elements");
        }
        else{
            printf("The sum of the values at indices %d and %d is: %d", a, b, (*(ptr + a)) + (*(ptr + b))); //print the sum 
        }
        

    }
    return 0;
}