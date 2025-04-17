#include <stdio.h>

int main(void) {
    int n, i, index1, index2; 

    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &n);

    if (n >= 5) {
        int arr1[n];

        printf("Enter the array elements:\n");
        for (i = 0; i < n; i++) {
            printf("Element %d: ", i + 1);
            scanf("%d", &arr1[i]);
        }

        printf("Enter the indices of the 2 elements (0 <= index1, index2 < %d): ", n);
        scanf("%d %d", &index1, &index2);

        //check index
        if (0 <= index1 && index1 < n && 0 <= index2 && index2 < n) {
            int sum = arr1[index1] + arr1[index2];
            printf("The sum of values at indices %d and %d is: %d\n", index1, index2, sum);
        } else {
            printf("Error: Indices must be within the range 0 to %d. Please try again.\n", n - 1);
        }
    } else {
        printf("Error: Size of the array must be at least 5.\n");
    }

    return 0;
}
