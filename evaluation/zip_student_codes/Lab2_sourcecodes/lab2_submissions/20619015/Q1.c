#include <stdio.h>
#include <stdlib.h> 

int main() {
    int n, index1, index2;
    int *array, sum = 0;

    
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &n);
        if (n < 5) {
            printf("Error: The size of the array must be at least 5. Please try again.\n");
        }
    } while (n < 5);

    
    array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    
    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", (array + i)); 
    }

  
    do {
        printf("Enter the indices of the two elements (0 <=index1, index2< %d): ", n);
        scanf("%d %d", &index1, &index2);
        if (index1 < 0 || index1 >= n || index2 < 0 || index2 >= n) {
            printf("Error:Indices must be within the range of the array elements. Please try again.\n");
        }
    } while (index1 < 0 || index1 >= n || index2 < 0 || index2 >= n);

    sum = *(array + index1) + *(array + index2);

    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    free(array);

    return 0;
}
