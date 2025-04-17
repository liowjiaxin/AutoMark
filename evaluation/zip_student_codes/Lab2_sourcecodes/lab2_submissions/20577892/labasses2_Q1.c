#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr1;
    int *ptr2;
    char arr[] = {};
    int size = 0;
    int sum = 0;

    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &size);


    ptr1 = (int*)malloc(size * sizeof(int));
    ptr2 = (int*)malloc(size * sizeof(int));

    printf("Enter the array elements:\n");

    ptr1 = arr[*ptr1];
    ptr2 = arr[*ptr2];
    for (size_t i = 0; i < size; i++)
    {
        printf("Element %d: ", i);
        scanf("%d", &arr);
    }
    
    printf("Enter the indices of the two elements (0 <= index1, index < %d):", size);
    scanf("%d %d", &ptr1, &ptr2);

    if (ptr1 > arr || ptr2 > arr) {
        printf("Error: Indices must be within the range of the array elements. Please try again");
        printf("Enter the indices of the two elements (0 <= index1, index < %d):", size);
        scanf("%d %d", &ptr1, &ptr2);
    }

    sum = arr[*ptr1] + arr[*ptr2];
    printf("The sum of the values at the indices %d and %d is: %d", *ptr1, *ptr2, sum);

    return 0;
}