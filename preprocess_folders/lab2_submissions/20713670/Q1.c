#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, index1, index2;
    int *arr;  //  it is used to store 


    // get the size of array from user
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &n);
    } while (n < 5);

    // allocate 
    arr = malloc(n * sizeof(int));  
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;  // the end of program
    }

   
    printf("Enter the array elements:\n");//get elements from user
    for (int i = 0; i < n; i++) { //the first is Element0
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);  // use arr[i] to get element
    }

    // Enter two indexes and make sure
    do {
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", n);
        scanf("%d %d", &index1, &index2);
        if (index1 < 0 || index1 >= n || index2 < 0 || index2 >= n) {
            printf("Error: Indices out of range. Try again.\n");
        }
    } while (index1 < 0 || index1 >= n || index2 < 0 || index2 >= n);

    // calculate sum 
    int sum = arr[index1] + arr[index2];
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    
    free(arr);  // Freeing allocated memory

    return 0;
}

