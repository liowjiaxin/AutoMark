
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    int N, index1, index2;
    int sum = 0;

    
    printf("Enter the size of the array (N ≥ 5): ");
    scanf("%d", &N);
    if (N < 5) {
        printf("The size of the array must be at least 5.\n");
        return 1;
    }

    
    array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

   
    printf("Enter the array elements :\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    
    do {
        printf("Enter the first index (0 <= index1 < N): ");
        scanf("%d", &index1);
        printf("Enter the second index (0 <= index2 < N): ");
        scanf("%d", &index2);
        if (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N) {
            printf("Error:Indices must be within the range of the array elements. Please try again.\n");
        }
    } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N);

    

   
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    
    free(array);

    return 0;
}