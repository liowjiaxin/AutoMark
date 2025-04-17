#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, *array, index1, index2, valid = 0;
    
    //Enter size of the array
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("The size of the array must be at least 5. Please try again.\n");
        }
    } while (N < 5);
    
    //Dynamically allocate memory for the array 
    array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    //Enter elements of the array 
    printf("Enter %d elements for the array:\n", N);
    
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", (array + i));
    }

    //Enter the two indices and validate
    do {
        printf("Enter the first index (0 <= index < %d): ", N);
        scanf("%d", &index1);
        printf("Enter the second index (0 <= index < %d): ", N);
        scanf("%d", &index2);
        
        if (index1 >= 0 && index1 < N && index2 >= 0 && index2 < N) {
            valid = 1; 
        } else {
            printf("Invalid indices. Please enter indices within the range 0 to %d.\n", N - 1);
        }
    } while (!valid);

    //Compute the sum 
    int sum = *(array + index1) + *(array + index2);

    //Sum 
    printf("The sum of elements at indices %d and %d is: %d\n", index1, index2, sum);

    free(array);

    return 0;
}
