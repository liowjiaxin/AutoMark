#include <stdio.h>

int sumOfElement(int index1, int index2, int *arrayPtr);  //Function prototype to calculate the sum of the two elements

int main(){
    int arraySize = 0;  //declaring the size of array
    int index1 = 0;
    int index2 = 0;

    printf("Enter the size of the array (N>=5): ");
    scanf("%d",&arraySize);  //Get the size of array from user
    int array[arraySize];  //declaring the array after getting the size
    int *arrayPtr = array; //declaring the pointer to the array

    while (arraySize <= 4){ 
        printf("Invalid input. Please enter a number greater than or equal to 5.\n");
        if (arraySize >= 5){    //Break loop if user is >=5
            break;
        }
        else{   //Repeat until user enter value >=5
            printf("Enter the size of the array (N>=5): ");
            scanf("%d",&arraySize);
        }
    }
    //If the array size is greater than or equal to 5
    for (int i=0; i<arraySize; ++i){  // Corrected loop condition
        printf("Enter the element %d: ",i);
        scanf("%d", arrayPtr + i);   // Corrected the way elements are stored
    }

    printf("Enter the indices of the two elements (0<=index1, index2<%d): ",arraySize);
    scanf("%d %d",&index1,&index2);   // Corrected scanf to use address-of operator
    while (index1 < 0 || index2 < 0 || index1 >= arraySize || index2 >= arraySize){  //Check the condition of the indices
        printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        printf("Enter the indices of the two elements (0<=index1, index2<%d): ",arraySize);
        scanf("%d %d",&index1,&index2);   // Corrected scanf to use address-of operator
    }

    int sum = sumOfElement(index1,index2,arrayPtr);  //Call the function to calculate the sum of the two elements
    printf("The sum of the values at indices %d and %d is %d\n",index1,index2,sum);  //Print the sum of the two elements

    return 0;
}

//Function to calculate the sum of the two elements
int sumOfElement(int index1, int index2, int *arrayPtr){
    int sum = 0;
    sum = *(arrayPtr+index1) + *(arrayPtr+index2);  //Calculate the sum of the two elements
    return(sum);  //Return the sum
}


