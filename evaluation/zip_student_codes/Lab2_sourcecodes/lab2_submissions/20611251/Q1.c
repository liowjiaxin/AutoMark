#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;             
    int N = 0;                
    int index1, index2;    
    while(N < 5){
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
    }

    arr = (int*)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }

    while (1){
        printf("Enter the indices of the first two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);
        if (index1 >= 0 && index2 <= N){
            int sum = *(arr + index1) + *(arr + index2);
            printf("The sum of elements at indices %d and %d is: %d\n", index1, index2, sum);
            break;
        }
        else{
            printf("Error: Indices must be within range of the array elements, please try again.\n");
        }
    }

    free(arr);

    return 0;

}