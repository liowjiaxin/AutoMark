#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

   
    do {
        printf("Enter the size of the array (N ≥ 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Invalid size! Please enter a number greater than or equal to 5.\n");
        }
    } while (N < 5);

    
    int *array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }


    printf("Enter %d elements for the array:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    int index1, index2;

    do {
        printf("Enter the first index (0 to %d): ", N - 1);
        scanf("%d", &index1);
        if (index1 < 0 || index1 >= N) {
            printf("Invalid index! Please enter a valid index.\n");
        }
    } while (index1 < 0 || index1 >= N);

    do {
        printf("Enter the second index (0 to %d): ", N - 1);
        scanf("%d", &index2);
        if (index2 < 0 || index2 >= N) {
            printf("Invalid index! Please enter a valid index.\n");
        }
    } while (index2 < 0 || index2 >= N);

   
    int sum = *(array + index1) + *(array + index2);

    
    printf("The sum of elements at indices %d and %d is: %d\n", index1, index2, sum);

    free(array);

    return 0;
}
