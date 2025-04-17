#include <stdio.h>

int main(void) {

    int n=0;
    printf("Enter the size of the array (N>=5): ");
    scanf("%d",&n);

    if (n>=5) {                     //check the condition

        printf("Enter the array elements \n");

        int array[n];
        int *arrayPtr = array;      //declare the pointer of the array
        for (int i=0; i<n; ++i) {
            printf("Element %d : ", i);
            scanf("%d", &array[i]);     //store the element in the array
        }

        int index1=0;
        int index2=0;
        printf("Enter the indices of two elements (0<=index1, index2<%d): ",n);
        scanf("%d %d", &index1, &index2);

        if (index1>=0 & index2<n) {     //check the index condition
            int sum = *(arrayPtr + index1) + *(arrayPtr + index2);
            printf("The sum of the values at indices %d and %d is: %d",index1, index2, sum);
        }

        else {
            printf("Error: Indices must be within the range of the array elements. Please try again.");
        }
    }

    else {
        printf("Array size should be >=5.");
    }

}