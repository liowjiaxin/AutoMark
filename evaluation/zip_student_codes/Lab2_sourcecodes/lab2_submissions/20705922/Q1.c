#include <stdio.h>  // for standard input-output
#include <stdlib.h>  // for memory allocation

// This function validates the array size
int validateSize() {
    int size;
    do {
        printf("You may enter the size of the array (N >= 5): ");
        scanf("%d", &size);
        if (size < 5) {
            printf("Invalid array size. Please re-enter N >= 5.\n");
        }
    } while (size < 5);
    return size;
}

// this function dynamically allocates memory for the array
int* allocateArray(int size) {
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation has failed.\n");
        exit(1);
    }
    return arr;
}

// This function will get array elements input from the user
void getArrayElements(int *arr, int size) {
    printf("You may enter the array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i);
        scanf("%d", arr + i);
    }
}

// this function validates an index
int validateIndex(int index, int size) {
    if (index >= 0 && index < size) {
        return 1; // valid index
    } else {
        return 0; // invalid index
    }
}

// this function will prompt the user for two indices and validate them
void getValidIndices(int size, int *index1, int *index2) {
    do {
        printf("Please enter the indices of the two elements (0 <= index1, index2 < %d): ", size);
        scanf("%d %d", index1, index2);

        if (!validateIndex(*index1, size) || !validateIndex(*index2, size)) {
            printf("Error: Indices have to be within the range of the array elements. Please try again.\n");
        }
    } while (!validateIndex(*index1, size) || !validateIndex(*index2, size));
}

// this function will calculate sum of array elements at the given indices using pointer arithmetic.
int calculateSum(int *arr, int index1, int index2) {
    return *(arr + index1) + *(arr + index2);
}

int main() {
    int N;
    int index1, index2;

    // this function validates the array size
    N = validateSize();

    // This function allocates the memory
    int *arr = allocateArray(N);

    // this function gets the array elements
    getArrayElements(arr, N);

    // this function gets the valid indices.
    getValidIndices(N, &index1, &index2);

    // This function calculates the sum
    int sum = calculateSum(arr, index1, index2);

    // Prints the sum
    printf("The total sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    // free dynamically allocated memory.
    free(arr);

    return 0;
}