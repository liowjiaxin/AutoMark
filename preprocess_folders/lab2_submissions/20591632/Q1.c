#include <stdio.h>

int sum_numbers(int *arr1, int *arr2) {
    return *arr1 + *arr2; // Dereference pointers to get the values
}

int main() {
    int size = 0;
    int idc1, idc2;

    printf("Enter the size of the array (N>=5): ");
    scanf("%d", &size);

    // Check if the size is less than 5
    if (size < 5) {
        printf("Please enter an array size of 5 or more.\n");
        return 1; // Exit if size is invalid
    }

    int arr[size];

    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the indices of two elements (0 <= index1, index2 < %d): ", size);
    scanf("%d%d", &idc1, &idc2);

    // Check if indices are valid
    if (idc1 > 0 && idc1 <= size && idc2 > 0 && idc2 <= size) {
        // Call sum_numbers with the addresses of the elements
        printf("The sum of the values at indices %d and %d is: %d\n", idc1, idc2, sum_numbers(&arr[idc1-1], &arr[idc2-1]));
    } else {
        printf("Invalid indices entered.\n");
    }

    return 0;
}
