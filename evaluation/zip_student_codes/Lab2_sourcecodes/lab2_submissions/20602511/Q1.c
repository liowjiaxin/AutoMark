#include <stdio.h>

int main() {
    int arr[100]; //Declare a array with a maximum size of 100
    int i;	// Declare i variable
    int n; // Declare n variable
    int sum;	// Declare sum variable
    int index1, index2; // Declare indexs variable
    int *pIndex1, *pIndex2; // Declare pointers to integers

    
    while (1) {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &n); 
        
	// Validate if input of size is in range
        if (n < 5) {
            printf("Error: Size of array must more than 5.\n");
            continue;
        } else {
            printf("Enter the array elements:\n"); 
            for (i = 0; i < n; ++i) {
                printf("Element %d: ", i);
                scanf("%d", &arr[i]); 
            }
            break; 
        }
    }
    
    while (1) {
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d):", n);
        scanf("%d %d", &index1, &index2); 
            
        if (index1 >= 0 && index1 < n && index2 >= 0 && index2 < n) { 
            pIndex1 = &arr[index1];
            pIndex2 = &arr[index2];
            sum = *pIndex1 + *pIndex2;
            break; 
        } else {
            printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        }
    }
    
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);
    
    return 0;
}