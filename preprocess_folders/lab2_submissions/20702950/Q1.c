// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int n, userint, index1, index2;
    int elements[100] = {0};
    printf("Enter the size of the array (N >= 5): ");    //Prompt user input for size of array
    scanf("%d",&n);
    while (n < 5) {         //Validates input
        printf("Invalid, enter size of array thats at least 5: ");
        scanf("%d",&n);
    }
    printf("Enter the array elements: \n");     //Asking user to input elements
    for (int i = 0; i < n; i+=1) {
        printf("Element %d: ",i+1);
        scanf("%d", &userint);
    }
    printf("Enter the indices of the two elements (0 <=index1, index2 < %d): ", n);      //Asking user for index 1 and 2
    scanf("%d %d", &index1, &index2);
    while (index1 < 0 || index2 >= n) {         //Validating both inputs
        printf("Error: Indices must be within range of the array elements. Please try again: ");
        scanf("%d %d", &index1, &index2);
    }
    return 0;
}