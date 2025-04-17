#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr;
    int n=0;
    // Enter size of array
    while (n<5){
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &n);
        // Validate N>=5
        if (n >= 5) {
            break;
        } else {
            printf("N<5. Please enter again.\n");
    }
    }
    int array[n];
    // Allocate memory for the array
    ptr = (int*)malloc(n * sizeof(int));
    // Enter array elements
    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }
    // Declare index1 and index2 as -1 to validate the input
    int index1 =-1, index2 =-1;
    while (index1 < 0|| index1>= n || index2<0 || index2>=n) {
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", n);
        scanf("%d %d", &index1, &index2);
        //Validate the indices (0 <= index1, index2 < N)
        if (index1>=0 && index2 < n) {
            break;
        }else{
            printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        }
    }
    // Pointer-based to find the sum of values of thr two array elements
    int sum = *(array + index1) + *(array + index2);
    // Output the sum
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);
    
    // Free the dynamically allocated memory
    free(ptr);

    return 0;
}
