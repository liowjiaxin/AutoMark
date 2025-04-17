#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, index1, index2;
    int *arr;

    //ask user for the size of array N
    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &N);

    while (N < 5) {
        printf("Array size is too small, please enter a size more than or equal to 5: ");
        scanf("%d", &N);
    }

    //allocate the memory
    arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    //ask for the element of the array
    printf("Enter %d elements of the array:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", (arr + i));
    }

    //ask for 2 indices
    do {
        printf("Enter the first index (0 <= index1 < %d): ", N);
        scanf("%d", &index1);
        printf("Enter the second index (0 <= index2 < %d): ", N);
        scanf("%d", &index2);

        if (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N) {
            printf("Error: indices must be within the range of the array elements. Please try again.\n");
        }
    } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N);

    int sum = *(arr + index1) + *(arr + index2);
    //print the sum
    printf("The sum of elements in index %d and %d is: %d\n", index1, index2, sum);

    return 0;

}
