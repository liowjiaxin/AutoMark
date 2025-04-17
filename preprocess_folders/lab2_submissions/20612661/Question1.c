#include <stdio.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Discards leftover characters
}

int main(){
    int arraySize = 0;
    int num1 = 0; 
    int num2 = 0;
    int sum = 0;
    int *sumPtr = &sum; 
    int array[100] = {0};
    int *arrayPtr1 = array;
    int *arrayPtr2 = array;

    do{
        printf("Enter the size of the array ( N>= 5 ): ");
        scanf("%d", &arraySize);
        clearInputBuffer();
        if (arraySize < 5){
            printf("Error: Size entered must be higher or equal to 5. \n");
        }

    }while(arraySize < 5);



    printf("Enter the array elements: \n");
    for(int i = 0; i < arraySize; i++){
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }




        do{
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", arraySize);
        scanf("%d %d", &num1, &num2);
        clearInputBuffer();

        if (!(((0 <= num1 ) && (num1 < arraySize)) && ((0 <= num2 ) && (num2 < arraySize)))){
            printf("Error: Indicates must be within the range of the array elements. Please try again.\n");
        }

    }while (!((((0 <= num1 ) && (num1 < arraySize)) && ((0 <= num2 ) && (num2 < arraySize)))));

    arrayPtr1 += num1;
    arrayPtr2 += num2;
    *sumPtr = *arrayPtr1 + * arrayPtr2;

    printf("The sum of the values at indicates %d and %d is: %d", num1, num2, sum);
}