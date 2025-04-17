#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
    } while (N < 5);

  
    int *array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }


    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }

    int index1, index2;

  
    while (1) {
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);
        
        if (index1 >= 0 && index1 < N && index2 >= 0 && index2 < N) {
            break; 
        } else {
            printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        }
    }

   
    int sum = *(array + index1) + *(array + index2);
    
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    free(array);
    return 0;
}