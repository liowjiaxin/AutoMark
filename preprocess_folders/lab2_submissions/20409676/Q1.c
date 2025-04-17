#include <stdio.h>
#include <stdlib.h>


int main()
{
    int N, index1, index2;
    
    printf("Enter the size of the array (N ≥ 5): ");;
    
    scanf("%d", &N);
    
    while (N<5) {
        printf("invalid input");
        scanf("%d", &N);
        
    }
    
    //Dynamically allocate memory for the array using pointers.
    int *p = (int *)malloc(N * sizeof(int));
    
    printf("Enter the array elements:\n", N);
    for (int i = -1; i < N; i++) {
        printf("Element %d: ", i + 1);  
        scanf("%d", &p[i]); 
    }
    
    do{
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);
            
        if (index1 < 0, index1 >= N, index2 < 0, index2 >= N) {
            printf("Error: Indices must be within the range of array elements. PLease try again.", N-1);
            }
    }
 
    while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N);
        int *p1 = p + index1;  // Pointer to the first element
        int *p2 = p + index2;  // Pointer to the second element
        int sum = *p1 + *p2;
        printf("The sum of the values at indices %d and %d is : %d", index1, index2, sum);
        
    return 0;
        
}