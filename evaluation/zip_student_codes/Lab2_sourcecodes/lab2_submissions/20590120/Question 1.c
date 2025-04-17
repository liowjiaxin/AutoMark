#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int *arr;
    int index1;
    int index2;
    int sum;
    int i;

   printf("Enter the size of the array (N >= 5): ");   //Prompt user to enter size of N
        scanf("%d",&N);

        if (N>= 5) {
    
    arr = (int*)malloc(N *sizeof(int));              //Allocate memory
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the array elements:\n");           //Prompt user to enter each element 
    for (i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }

    do {                                                                                   //Prompt the user to enter the two indices
        printf("Enter the indices of the two elements (0 <= index1,index2 < %d): ", N);
        scanf("%d %d", &index1,&index2);
        if (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N || index1 == index2) {      //Check whether indices are within the range of array elements
            printf("Error:Indices must be within the range of the array elements.Please try again.\n");
        }
    } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N || index1 == index2);

    int *ptr1 = &arr[index1];          //assign pointer to index1 and index2 
    int *ptr2 = &arr[index2];
    sum =*ptr1+*ptr2;              //calculate sum

    printf("The sum of elements at indices %d and %d is: %d\n",index1,index2,sum);     //Print sum

    } else {
        printf("Error! N must be >= 5.Please try again.");          //Print error if user input less than 5
    }

    return 0;
}