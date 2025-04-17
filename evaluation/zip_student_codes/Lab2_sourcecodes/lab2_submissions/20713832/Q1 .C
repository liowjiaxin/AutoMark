#include <stdio.h>
#include <stdlib.h> // stdlib is used as memory allocation and deallocation are part of it

int main() {
    int N; // // intiliazing the integer 'n' which is number of integers

    
    printf("Enter the size of the array (N >= 5): "); //// asking the user to input the number of elements in the array
    scanf("%d", &N);// to read the number of elements

    // Validate size
    while (N < 5) { // to check the size of the array a while loop is used
        printf("Invalid input: Size must be at least 5. Please try again.\n"); // in the case where the number of elements inputed is less than 5, this message is shown.
        printf("Enter the size of the array (N >= 5): "); // this is to ask the user again for new inputs
        scanf("%d", &N); // scanf function is used to read the number of elements and check if they are in the range
    }

    
    int *array = (int *)malloc(N * sizeof(int)); // this function is used to dynamically allocate memory for the array

    if (array == NULL) { // putting condition such that if the number of values in the array is null, the following message is shown.
        printf(" Memory allocation failed.\n"); 
        return 1;
    }

    printf("Enter the array elements:\n");// asking the user for input of the elements
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i); // used to display the element with the corresponding number
        scanf("%d", array + i); // Using the pointer arithmetic to store values
    }

    int index1, index2; // intializing the integers index1 and index2

    
    while (1) { // to validate the indices a while loop is used
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);// asking the user to enter the the indices within the range
        scanf("%d %d", &index1, &index2); // using scanf function to read the indices

        if (index1 >= 0 && index1 < N && index2 >= 0 && index2 < N) { // putting a condition using if such that the value of the indices must be more than 0 and less than N
            break; // if the conditions are met validate the indices
        } else {
            printf("Invalid input: Indices must be within the range of the array elements. Please try again.\n"); // if the mentioned conditions are not met , the following messages will be shown.
        }
    }

    
    int sum = *(array + index1) + *(array + index2); // implementing the sum using pointer based approach.

    
    printf("The sum of the values of indices %d and %d is: %d\n", index1, index2, sum); // the result is displayed.

   
    free(array);// this is used to deallocate the memory which was allocated earlier.

    return 0;
}
