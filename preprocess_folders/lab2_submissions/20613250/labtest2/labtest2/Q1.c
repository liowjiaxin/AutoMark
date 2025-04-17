#include <stdio.h>

int main(void){
    int n = 0;
    int index1=-1;
    int index2=-1;

    //size of array
    while (n < 5){
        printf("Enter the size of the array (N>=5):");//prompt user to input size of array
        scanf("%d", &n);
        if (n<5){ //check if size of array >=5
            printf("\nSize of array should more than or equal to 5\n");
        }
    }

    //initialise array and pointer
    int a[n];
    int *ptr1 =a; //point to a[0]
    int *ptr2 =a; //point to a[0]

    //array element
    printf("\nEnter the array elements:\n");
    for (size_t i =0; i<n; ++i){ //prompt user to input all array element
        printf("Element %zu: ", i);
        scanf("%d", &a[i]);
    }
    
    //array indices
    while ((index1<0 || index1>=n)||(index2<0 || index2>=n)){ //validation of index
        printf("\nEnter the indices of the two elements (0<=index1, index2 < %d): ", n); //prompt user to input two indices
        scanf("%d %d", &index1, &index2);
        if ((index1<0 || index1>=n)||(index2<0 || index2>=n)){
            printf("\nError: Indices must be within the range of the array elements. Please try again.");
        }
        
    }
    ptr1+= index1; //set pointer1 address to address index1
    ptr2+= index2; //set pointer2 address to address index2
    int x = *ptr1+*ptr2; //value on two address added together
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, x);
}