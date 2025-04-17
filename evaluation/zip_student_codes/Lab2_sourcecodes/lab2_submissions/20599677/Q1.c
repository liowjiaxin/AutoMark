#include <stdio.h>

int main(){
    int N, i, index1, index2;

    //enter size of array
    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &N);

    //declaring array
    int arr[N];
    int *ptr1;

    //enter array elements
    printf("Enter the array elements:\n");
    for (i = 0; i < N; i++){
        ptr1 = &arr[i];
        printf("Element %d: ", i);
        scanf("%d", ptr1);
    }

    while(1){
        printf("Enter the indices of the two elements (0 <= index1, index2 < 6): ");
        scanf("%d %d", &index1, &index2);

        if(0 <= index1 && index1 < N && index2 >= 0 && index2 < N){
            break;
        } else{
            printf("Error: Indices must be within the range of the array elements. Please try again.");
        }

    }

    //calculate sum of specified indices
    ptr1 = &arr[index1];
    int *ptr2 = &arr[index2];
    int sum = *ptr1 + *ptr2;
    printf("The sum of values at indices 4 and 5 is: ", sum);

    return 0;
}