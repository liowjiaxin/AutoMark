#include <stdio.h>
#include <stdlib.h>

int main(){
    int N,index1,index2, *arr, sum;

    // Step 1: Prompt user for the size of the array and validate
    printf("Enter the size of the array (N>=5):  ");
    scanf("%d",&N);
    while (N<5){
        printf("Size must be at least 5. Please enter again:  ");
        scanf("%d",&N);
    }

    // Step 2: Dynamically allocate memory for the array
    arr= (int*)malloc(N* sizeof(int));
    if (arr==NULL){
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }
    
    // Step 3: Prompt user to enter elements of the array
    printf("Enter %d elements for the array:\n",N);
    for (int i=0; i<N; i++){
        printf("Elements %d: ",i+1);
        scanf("%d", arr+i);
    }

    // Step 4:  Prompt user for two valid indices and validate them
    while (1){
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ",N);
        scanf("%d %d", &index1, &index2);
        if (index1>=0 && index1<N && index2>=0 && index2<N){
            break; // Valid indices
        } else {
            printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        }
    }

    // Step 5: Use pointers to calculate the sum
    sum = *(arr+index1) + *(arr+index2);

    // Step 6: Print the result
    printf("The sum of element at indices %d and %d is:%d\n", index1, index2,sum);

    // Free the allocated memory
    free(arr);

    return 0;
}