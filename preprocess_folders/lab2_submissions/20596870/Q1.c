#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, index1, index2, sum;

    //size of array(at least 5)
    printf("Enter the size of the array (N >=5): ");
    scanf("%d", &N);
    while(N<5){
        printf("Size must be at least 5. Please try again: ");
        scanf("%d", &N);
    }
    
    //Dynamically allocate memory of the array of size N
    int *array = (int *)malloc(N*sizeof(int));
    if (array == NULL){
        printf("Memory allocation failed. Exiting program.\n");
        return 1; //Exit if allocation failed
    }
    
    //Input N integers into the array
    printf("Enter %d integers for the array:\n", N);
    for (int i =0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", (array +i));
    }
    
    //Input 2 valid indices
    printf("Enter two valid indices (0 <= index1, index2< %d): ", N);
    scanf("%d %d", &index1, &index2);
    
    //Check the indices
    while (index1 <0 || index1 >=N || index2 <0 || index2 >=N){
        printf ("Error: Indices must be within the range of the array elements. Please try again.\n", N-1);
        printf("Enter two valid indices (0 <= index1, index2< %d): ", N);
        scanf("%d %d", &index1, &index2);
    }
    sum=*(array + index1) + *(array + index2);
    printf("The sum of the values at the indices %d and %d is :%d\n", index1, index2, sum);

    //Free the allocated memory
    free(array);

    return 0;
}

