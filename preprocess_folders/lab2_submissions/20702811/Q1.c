#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int N;
    int index1, index2;
    int sum;

    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Size cannot be less than 5. Please try again.\n" );
        }
    } while (N < 5);

    arr = (int*)malloc(N*sizeof(int));
    if (arr == NULL) {
        printf("Memory not allocated.");
        return 1;
    }
    
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[1]);
    }

    do {
        printf("Enter the indices of two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);
        if (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N) {
            printf("Indices must be within the range of the array element. Please try again.");
        }
        
    } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N);

    sum = *(arr + index1) + *(arr + index2);
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

}


