#include <stdio.h>

int main() {
    int n, i;
    
    printf("Enter the number of elements in the array (more than 5): ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int index1, index2;
    
    printf("Enter the indices of the two elements (0 <= index 1, index 2 < 6:\n");
    printf("Index 1: ");
    scanf("%d", &index1);
    printf("Index 2: ");
    scanf("%d", &index2);
    
    if (index1 < 0 || index1 >= n || index2 < 0 || index2 >= n) {
        printf("Error: Indices must be within range of the elements.\n");
        return 1;  
    }
    
    int *ptr1 = &arr[index1];
    int *ptr2 = &arr[index2];
    
    int sum = *ptr1 + *ptr2;
    
    printf("The sum of values at indices %d and %d is: %d\n", index1, index2, sum);
    
    return 0;
}