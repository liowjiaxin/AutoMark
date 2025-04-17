#include <stdio.h>
#include <stdlib.h>

int main () {

    int arrSize = 0;
    int index1, index2 = 0;

    printf("Enter the size of the array (N >= 5): ");
    scanf(" %d", &arrSize);

    int* arr = malloc(arrSize * sizeof(int));

    for (int i = 0; i < arrSize; i++) {
        printf("Enter element %d: ", i);
        scanf(" %d", arr + i);
    }

    printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", arrSize);
    scanf(" %d %d", &index1, &index2);

    //Ensures the indexes are within the range of the array
    while ( !(index1 >= 0 && index1 < arrSize)  || !(index2 >= 0 && index2 < arrSize) ) {
        printf("Error: Indices must be within range of the array elements. Please try again.\n");

        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", arrSize);
        scanf(" %d %d", &index1, &index2);
    }

    int sum = *(arr + index1) + *(arr + index2);
    printf("The sum of values at index %d and %d is: %d", index1, index2, sum);

    return 0;
}