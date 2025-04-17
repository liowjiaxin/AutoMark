#include <stdio.h>

int main() {
    int N, array[100], index1, index2, sum; //maximum size of 100.


    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Error: N must be at least 5. Please try again.\n");
        }
    } while (N < 5);


    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", (array + i)); 
    }


    do {
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);

        if (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N) {
            printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        }
    } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N);

    sum = *(array + index1) + *(array + index2); 


    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    return 0;
}
