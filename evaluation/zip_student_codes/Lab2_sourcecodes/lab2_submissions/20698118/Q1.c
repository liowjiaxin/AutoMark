#include <stdio.h>
#include <stdlib.h>

int main(){
    int N = 0; //initializing variables
    int sum = 0;
    int index1, index2;

    while(N < 5){ //validation loop
    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &N);

    if(N < 5){
        printf("Please enter a value greater than or equal to 5 for the array size!\n");
    }
    }

    int numbers[N]; //initializing array and pointer
    int *ptr = numbers;

    
    int temp = 0; //putting elements into array
    for(int i = 1; i <= N; i++){
        printf("Element %d: ", i);
        scanf("%d", &temp);
        numbers[i-1] = temp;
    }
    
    int validation = 0; //validation for indexes
    while(!validation){
    printf("Enter the indices of two elements (0 <= index1, index2 < %d)\n", N);
    scanf("%d %d", &index1, &index2); //user input of indices
    
    if(index1 < 0 || index2 >= N){ 
        printf("Error: Indices must be within the range of the array elements. Please try again.\n");
    }else{
        validation = 1;
    }
    }
    
    sum = *(ptr + index1) + *(ptr + index2); //calculating sum


    printf("The sum of the values at indices %d and %d is %d", index1, index2, sum);
}
