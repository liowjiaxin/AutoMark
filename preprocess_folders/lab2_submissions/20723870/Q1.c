#include <stdio.h>
#include <stdlib.h> 

void main() {
    int n = 0;
    int i, j, index1, index2, value1, value2, size ; //variable declaration and initialisation
    int* integer=NULL;
    //int* k = &integer[0];
    printf("Enter size of arrays(N>=5): \n"); 
    while (1) { //checking user's array size
        scanf(" %d", &n);
        if (n<5) {
            printf("Please enter bigger than 5\n");
        }
        else {
            break;
        }
                }  
 
    integer = (int*)malloc(sizeof(int) * n); //using malloc for dynamic array 

    for (i=0; i<n; i++){
        printf("Enter element %d: \n", i); //taking user input for array elements
        scanf(" %d", &integer[i]);


}
    printf("Enter the first index:\n"); //input validation for both indexes
    while(1) {
        scanf(" %d", index1);
        if (index1 < 0){
            printf("Must be atleast 0, Enter the first index:\n");     
        }
        else {
            break;
        }
    }
    printf("Enter the second index:\n");
    while(1) {
        scanf(" %d", index2);
        if (index2 > n ){
            printf("Do not exceed array size, Enter the second index:\n");

        }
        else {
            break;
        }        
    }

    int sum = *(integer + index1) + *(integer + index2); //pointer arithmetic with pointer casting idk
    printf("Sum of the values at indices %d and %d is: %d\n", index1, index2, sum); //printing sum of the two numbers

    free(integer); //malloc free
}
