#include <stdio.h>
#define SIZE 100


int main(){

    int arraySize =0;
    int array[SIZE];
    int index1 =0;
    int index2 =0;
    int sum =0;
    int *aPTr =&index1;
    int *bPTr =&index2;

    printf("Enter the size of array (N>=5): \n");
    scanf("%d", &arraySize);

    while(arraySize <5){
        printf("Size of array must be (N>=5).\n");
    }

    printf("Enter the array elements: ");
    for(int i=0; i< arraySize; i++){
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }

    printf("Enter the indices of two elements (0 <= index1, index2 < %d): ", arraySize);
    scanf("%d %d", &index1, &index2);

    while(index1< 0 && index2>arraySize){
        printf("Indices must be within the range of the array elements. Please try again.");
        break;
    }


    printf("The sum of the two values at indices %d and %d is: %d.\n", index1, index2, sum);


    return 0;
}







