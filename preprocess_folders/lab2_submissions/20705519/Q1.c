#include <stdio.h>
#include <stdlib.h>

int main () {
    int N = 0;
    int *myArr = malloc(N * sizeof(int));
    int index1, index2;

    printf("Enter the size of array (N >= 5): ");
    scanf("%d", &N);
    getchar();
    while (N < 5) {
        printf("\nError: Size of array must be at least 5. Please try again: ");
        scanf("%d", &N);
        getchar();
    }

    printf("Enter the array elements: ");
    for (int i = 0; i < N; i++) {
        printf("\nElement %d: ", i);
        scanf("%d", &myArr[i]);
    }

    printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
    scanf("%d %d", &index1, &index2);
    while ((index1 < 0 || index2 < 0) || (index1 > N -1 || index2 > N -1)) {
        printf("\nError: Indices must be within the range of the array elements. Please try again: ");
        printf("\nEnter the indices of the two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);
    }

    int sum = myArr[index1] + myArr[index2];
    printf("\nThe sum of the values at the indices %d and %d is: %d", index1, index2, sum);

    free(myArr);

    return 0;
}