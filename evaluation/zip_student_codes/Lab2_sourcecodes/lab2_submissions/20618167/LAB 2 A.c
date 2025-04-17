#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N, *array, index1, index2, sum;

    //Prompt user to enter the size of the array
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Invalid input. Please enter a value >= 5.\n");
        }
    } while (N < 5);

    //allocate memory for the array
    array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    //Prompt user to enter each element of the array
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", (array + i)); 
    }

    //Prompt user to enter two index and validate them
    while (1) {
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);

        if (index1 >= 0 && index1 < N && index2 >= 0 && index2 < N) {
            break;
        } else {
            printf("Indices must be within the range of the array elements. Please try again.\n");
        }
    }

    //Calculate the sum of the values 
    sum = *(array + index1) + *(array + index2);

    //Print the output
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

}
