#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int size;
    int num1, num2;
    int* p;

    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &size);

    if (size < 5) {
        printf("Error: Array size must be at least 5.\n");
        return 1;
    }

    p = (int*)malloc(size * sizeof(int));
    if (p == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i);
        scanf("%d", &p[i]);
    }

    while (1) {
        printf("Enter the indices of two elements (0 <= index1, index2 < %d): ", size);
        scanf("%d %d", &num1, &num2);

        if (num1 >= 0 && num1 < size && num2 >= 0 && num2 < size) {
            int sum = p[num1] + p[num2];
            printf("Sum = %d\n", sum);
            break;
        }
        else {
            printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        }
    }

    free(p);

    return 0;
}
