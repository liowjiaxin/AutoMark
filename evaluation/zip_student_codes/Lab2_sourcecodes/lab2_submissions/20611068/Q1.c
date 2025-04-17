#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, index1, index2;
    int *arr;

    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Invalid size. N must be greater than or equal to 5.\n");
        }
    } while (N < 5);

    
    arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", arr + i); 
    }

    
    do {
        printf("Enter the index of the first element (0 <= index1 < N): ");
        scanf("%d", &index1);
        printf("Enter the index of the second element (0 <= index2 < N): ");
        scanf("%d", &index2);
        if (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N) {
            printf("Invalid indices. Indices must be within the array bounds.\n");
        }
    } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N);


    
    int sum = *(arr + index1) + *(arr + index2); 

    
    printf("The sum of the elements at indices %d and %d is: %d\n", index1, index2, sum);



    return 0;
}