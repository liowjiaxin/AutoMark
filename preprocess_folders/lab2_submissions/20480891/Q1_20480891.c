#include <stdio.h>

int main() {
    int N, index1, index2;

    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &N);

    //Validate the size
    while (N < 5) {
        printf("Invalid size. Please enter valid array: ");
        scanf("%d", &N);
    }

    //Array memory
    int *arr = (int *)malloc(N * sizeof(int));

    //Array element
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    //The indices of the two elements
    do {
        printf("Enter the first index (0 <= index1 < N): ");
        scanf("%d", &index1);
        printf("Enter the second index (0 <= index2 < N): ");
        scanf("%d", &index2);

        if (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N) {
            printf("Invalid indices. Please enter valid indices.\n");
        }
    } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N);

    //The sum
    int *ptr1 = &arr[index1];
    int *ptr2 = &arr[index2];
    int sum = *ptr1 + *ptr2;

    //Print the sum
    printf("The sum of the two elements is: %d\n", sum);

    //Free the dynamically allocated memory
    free(arr);

    return 0;
}