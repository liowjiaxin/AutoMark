#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, index1, index2;
    int *array;

    //array size validation
    while (1) {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &size);
        if (size < 5) {
            printf("Size should be at least 5.\n");
        }
        else {
            break;
        }
    }
    
    //allocate memory
    array = (int *)malloc(size * sizeof(int));

    //elements input
    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i);
        scanf("%d", (array + i));
    }

    //loop for indices input validation
    while (1) {
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d: ", size);
        scanf("%d %d", &index1, &index2);

        if (index1 >= 0 && index1 < size && index2 >= 0 && index2 < size && index1 <= index2) {
            break;
        } 
        else {
            printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        }
    }

    //sum up value
    int sum = 0;
    for (int i = index1; i <= index2; i++) {
        sum += *(array + i);
    }

    //output
    printf("The sum of at indices %d and %d is: %d\n", index1, index2, sum);

    //free memory
    free(array);

    return 0;
}
