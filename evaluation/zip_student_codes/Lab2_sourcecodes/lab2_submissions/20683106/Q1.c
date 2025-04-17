#include <stdio.h>
#include <stdlib.h>

// Main function to start program
int main(void){
    int* arr; // Array is allocated dynamically to fit with user's input size
    int index1, index2, size, sum; // Variables needed

    // Prompt for the size of the array
    printf("Enter the size of the array (N >= 5): \n");
    scanf("%d", &size);
    // Validation of array size, check if size is at east 5, if not prompt for re-input
    while(size < 5){
        printf("Array size too small. Please enter again (N >= 5):\n");
        scanf("%d", &size);
    }
    
    // Using malloc to dynamically allocate memory for the array based on the size
    arr = (int*)malloc(size * sizeof(int));

    // Populate the array with elements input by the user
    printf("Enter the array elements:\n");
    for(int x=0;x<size;x++){
        printf("Element %d: ", x);
        scanf("%d", &arr[x]);
        printf("\n");
    }

    // Prompt user for two array indexes to perform addition and get sum
    printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", size);
    scanf("%d%d", &index1, &index2);
    printf("\n");
    // Validation for both indexes - check if both indexes are within the range of the size of the array, prompt for re-input otherwise
    while(index1 < 0 || index2 < 0 || index1 > size-1 || index2 > size-1){
        printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        printf("Enter the indices of the two elements (0 <= index1 , index2 < %d): ", size);
        scanf("%d%d", &index1, &index2);
        printf("\n");
    }

    // Perform addition to get sum using pointers with reference to the desired indexes
    sum = (*(arr+index1)) + (*(arr+index2));
    // Output result
    printf("The sum of the values at indices %d and %d is: %d", index1, index2, sum);

    return 0;
}