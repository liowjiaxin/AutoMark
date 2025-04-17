#include <stdio.h>
#include <stdlib.h>

int main() {
  
    // Variable Declaration
    int N, ind1, ind2;
    int *ARRAY;
    
    // Input Acquisition and Validation
    printf("Enter the size of the array;");
    do {
        printf("\nPlease ensure the value is atleast 5: ");
    scanf("%d", &N);
    } while (N < 5);
    
    // Dynamic Allocation of Memory for Array/Pointer Usage
    ARRAY = (int *)malloc(N * sizeof(int));
    if (ARRAY == NULL) {
        printf("Mem Alloc Failed. . .");
        return 1;
    }
    
    // Input Array Elements
    printf("\nNow please enter the array elements.\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d:", i);
        scanf("%d", (ARRAY+i));
    }
    
    // Indices Check within the ARRAY
    printf("Enter the indices of the two elements [Index 1 >= 0] && [Index 2 < %d]", N-1);
    do {
        printf("\n Enter the first index:");
        scanf("%d", &ind1);
        printf("\n Enter the second index: ");
        scanf("%d", &ind2);
    } while ( ind1 < 0 || ind1 >= N || ind2 < 0 || ind2 >= N);
    
    // Sum, Results, Freeing MEM Allocation
    // Sum Calculation using Pointers
    int sum = *(ARRAY + ind1) + *(ARRAY + ind2);
    
    // Results Print
    printf("\nThe sum of the elements/values at indices %d and %d, is; %d\n", ind1, ind2, sum);
    
    // Free Mem Function
    free(ARRAY);
    return 0;
}
