#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    //enter the size of array
    printf("enter the size of the array (n>=5): ");
    scanf("%d", &n);

    //check if the size if bigger or equal to 5
    while (n < 5) {
        printf("size must be at least 5. please enter again: ");
        scanf("%d", &n);
    }

    //allocates a memory area for n
    int* array = (int*)malloc(n * sizeof(int));

    if (array == 0) 
    {
        printf("memory not allocated.\n");
        return -1;
    }

    //enter each element of the array
    for (int i = 0; i < n; i++) {
        printf("element %d: ", i);
        scanf("%d", &array[i]);
    }

    int index1, index2;

    while (1) {
        printf("enter the indices of the two elements (0 <= index1, index2 < %d): ", n);
        scanf("%d %d", &index1, &index2);

        if ((index1 >= 0 && index1 < n) && (index2 >= 0 && index2 < n))
            break;

        else
            printf("error: indices must be within the range of array elements. please try again.\n");
    }
    
    //calculate
    int sum = *(array + index1) + *(array + index2);

    //print the result
    printf("the sum of values at indices %d and %d is: %d\n", index1, index2, sum);

    //deallocate array
    free(array);

    return 0;
}
