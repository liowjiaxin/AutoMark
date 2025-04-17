#include <stdio.h>
#include <stdlib.h>

int main(){
    int n =0;
    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &n);
    if (n<5){
        printf("Error: N must be >= 5. Pls try again: ");
        scanf("%d", &n);
    }
    while(n >= 5){
        
        int *aPtr = (int*)malloc(n*sizeof(int));    // create a size modfiyable array which is base on user input
        puts("Enter the array elements: ");
            
        for (int i=0; i<n; i++){
            int element=0;
            printf("Element %d: ", i);
            scanf("%d", &element);
            aPtr[i] =  element;   
        }

        int index1=0;
        int index2=0;
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", n);
        scanf("%d %d", &index1, &index2);
        if (index1 > n || index2 > n){      // if indices out of array's range, print error message
            printf("Error: Indices must be within the range of the array elements.\nPlease try again: ");                
            scanf("%d %d", &index1, &index2);   // scan & save again
        }
        while (0 < index1 < n && 0 <= index2 <n){
            int *indexPtr = aPtr;
            int sum = *(indexPtr + index1) + *(indexPtr + index2);  // calculate sum of two elements at the corresponding indices
            printf("The sum of the values at indices %d and %d is: %d", index1, index2, sum);    
            break;      // break out of inner while loop
        }
        break;  // break out of outer while loop
    }

    return 0;
}

