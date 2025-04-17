#include <stdio.h>
#include <stdlib.h>

int main(){
    int *array=NULL;
    int size, index1, index2;

    //prompt user for size of array
    printf("Enter the size of the array (N>=5)");
    scanf("%d", &size);

    //check if number of array is larger than 5
    while (size<5){
        printf("Size must be at least 5. Enter again :");
        scanf("%d",&size);
    }

    //allocate memory for array
    array =(int*)malloc(size*sizeof(int));
    if (array ==NULL){
        printf("Cant locate memory \n");
        return 1;
    }

    //prompt user to input elements of array
    printf("Enter %d elements for the array:\n", size);
    for (int i=0; i<size;i++){
        printf("Element %d:",i);
        scanf("%d", &array[i]);
    }

    //prompt user to input indices of elements
    do {
        printf("Enter the indices of the two elements ()<= index1, index2<6", size -1);
        scanf("%d %d", &index1, &index2);

        //check if indices inputted is valid
        if (index1<0 || index1>= size|| index2<0||index2 >= size){
            printf("Error: invalid indices. Please enter indices between 0 and %d.\n", size -1);
        }
    }while (index1<0 || index1>= size|| index2<0|| index2>= size);

        //compute sum
        int sum= *(array+index1)+ *(array+index2);

        //print sum
        printf("The sum of elements at indices %d and %d is %d\n", index1, index2, sum);

        //free allocated memory 
        free(array);

        return 0;
    }

