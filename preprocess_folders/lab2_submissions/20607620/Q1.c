#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

    do {
        printf("What is the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Please enter a size greater than or equal to 5.\n");
        }
    } while (N < 5);


    int *array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation unsuccessful\n");
        return 1;
    }


    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }

    int index1, index2;


    while (1) {
        printf("Enter the first index (0 to %d): ", N - 1);
        scanf("%d", &index1);
        printf("Enter the second index (0 to %d): ", N - 1);
        scanf("%d", &index2);

        if (index1 >= 0 && index1 < N && index2 >= 0 && index2 < N) {
            break;
        } else {
            printf("Error:Indices must be within the range of the array elements. Please try again\n");
        }
    }
    
    int sum = *(array + index1) + *(array + index2);
    printf("The sum of the values at indices is: %d\n",sum);



    return 0;
}
