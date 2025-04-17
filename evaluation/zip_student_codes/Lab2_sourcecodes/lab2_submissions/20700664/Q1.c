#include <stdio.h>
#include <stdlib.h>

int main(){
    int arrNum = 5;
    int element, index1, index2;
    int array[arrNum];
    int sum;
    int *ptr=(int*)malloc(arrNum*sizeof(int));

    printf("Enter the size of the array(N>=5):"); //enter the size of array
    scanf("%d", &arrNum);
    printf("Enter the array elements:\n");//enter elements
    for(int i=0;i<arrNum;i++){
        printf("Element %d: ", i);
        scanf("%d", &element);
        array[i]= element;
    }
    
    //calculate the sum
    printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", arrNum);
    scanf("%d %d", &index1, &index2);
    if(index1<0 || index2>=arrNum){
        printf("Error.Please try again.");
    }
    else{
        for(int i=index1; i<=index2;i++){
            sum += array[i];
        } 
        printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);
    }
    free(ptr);
    return 0;
}