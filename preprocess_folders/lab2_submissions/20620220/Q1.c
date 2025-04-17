#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    int index1, index2;

    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &num);
    } while (num < 5);


    int *array = (int *)malloc(num * sizeof(int));
    if (array == NULL) {
        return 1;
    }

    printf("Enter the array elements:\n");
    for (int i = 0; i < num; i++) {
        printf("Element %d: ", i);
        scanf("%d", (array + i)); 
    }

    while (1) {
        printf("Enter the indices of the two elements (0 <= index1, index2 < 6): ");
        scanf("%d %d", &index1, &index2);

        if ((index1 >= 0 && index1 < num) && (index2 >= 0 && index2 < num)) {
            break; 
        }
        printf("Error: Indices must be within the range of the array elements. Please try again.\n");
    }

    int sum = *(array + index1) + *(array + index2);

    printf("The sum of the elements at indices %d and %d is: %d\n", index1, index2, sum);

    free(array);

    return 0;
}
