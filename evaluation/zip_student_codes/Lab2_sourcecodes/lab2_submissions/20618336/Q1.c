#include <stdio.h>
#include <stdlib.h>
//QUESTION 1

int main() {
    int N;
    int index1;
    int index2; //Declaration of variables N, index1, index2

    // Ask the user for the size of the array
    
    printf("Enter the size of the array (N >= 5): ");
    
    scanf("%d", &N);

    // Validate the size of the array
    
    while (N < 5) {
        
        printf("The size is invalid. Enter a minimum size of 5: ");
        scanf("%d", &N);
    }

    //Dynamically allocate memory for an array
    
    int *array = malloc(N * sizeof(int));
    if (array == NULL) {
        
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Ask the user to fill the elements of the array
    
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }

    //Ask the user to input valid indices
    
    do {
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
        
        scanf("%d %d", &index1, &index2);
        
        

        if (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N) {
            printf("Error: Indices must be within the range of the array. Please try again.\n"); //This line indicates an error message 
        }
    } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N);

    //Calculate the sum using pointers
    
    int sum = *(array + index1) + *(array + index2); //Calculate the sum using pointers

    //Display the result
    
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    // Free the allocated memory
    free(array);

    return 0;
}