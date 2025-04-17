#include <stdio.h>
#include <stdlib.h>

int main() {
    int input[101];    
    int sizeN;
    int index1;
    int index2;
    int *p = input;
    

    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &sizeN);

    while(sizeN<5){
        printf("Error input!\n");
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &sizeN);

    }

    printf("Enter the array elements:\n ");
// Read the input string from the user
    for(int i = 0; i < sizeN; i++) {
    
    printf("Element %d: ", i);
    scanf("%d", (p+i));
     
  }

    printf("Enter the indices of the two elements(0 <= index1, index2 < %d): ", sizeN);
    scanf("%d %d", &index1, &index2);
    


// Check if the index is in the valid range
    while (index1 < 0 || index2 >= sizeN) {
        printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        printf("Enter the indices of the two elements(0 <= index1, index2 < %d): ", sizeN);
        scanf("%d %d", &index1, &index2);
           
        }

    
    int sum = *(p + index1) + *(p + index2);
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    
    return 0;
}
