#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    int elementNum, index1, index2, sum;
    

    // Prompt to enter the size elementNum of the array and validate if elementNum ≥ 5
    printf("Enter the size of the array (elementNum>=5): ");
    scanf("%d", &elementNum);
    if (elementNum < 5) {
        printf("The size of the array must be at least 5.\n");
        return 1;
    }

    // Dynamically allocate memory for the array using pointers
    array = (int *)malloc(elementNum * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Prompt the user to enter each element of the array one by one
    printf("Enter the elements of the array(elementNum>=5):\n");
    int i;
    for (i = 0; i < elementNum; i++) {
        printf("Element %d:",i);
        scanf("%d", &array[i]);
    }


    //Prompt the user to enter the two indices and validate them
    int valid_indices = 1;
    while (valid_indices) {
        printf("Enter the first index (0 <= index < %d): ",elementNum);
        scanf("%d", &index1);
        printf("Enter the second index (0 <= index < %d): ",elementNum);
        scanf("%d", &index2);

        if (index1 < 0 || index1 >= elementNum || index2 < 0 || index2 >= elementNum || index1 == index2) {
            printf("Invalid indices. Please enter again.\n");
        } else {
            valid_indices = 0;
        }
    } 

    //get the sum of the values of the two array elements
    sum = *(array + index1) + *(array + index2);

    //Print the output for the sum
    printf("The sum of the elements at indices %d and %d is: %d\n", index1, index2, sum);

    // Free the dynamically allocated memory
    free(array);
    return 0;
}