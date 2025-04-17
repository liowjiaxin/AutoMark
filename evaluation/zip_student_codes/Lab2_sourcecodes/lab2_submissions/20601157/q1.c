#include <stdio.h>
#include <stdlib.h> // library needed for malloc

int main(){

    int size;
    int index1;
    int index2;
    int arraysizecheck=0;
    int indicesrange=0;
    int sum;
    


while (!arraysizecheck){ // checks for validity of array size

    printf("Enter the size of the array (N>=5) :"); 
    scanf("%d",&size);

    if (size<5){
        printf("Invalid array size!\n");
    }

    else{
        arraysizecheck=1;  // loops infinitely until user prompts a correct array size 
    }
}

    int *array=malloc(size*sizeof(*array)); // using malloc to dynamically allocate memory for size (from user input)

    if (!array){
        printf("There was a problem in memory allocation!"); // error checking
        return 1;
    }

    for (int i=0;i<size;++i){
        printf("Enter element %d: ",i+1);   // enter elements to populate array
        scanf("%d",&array[i]);
    }

    while (!indicesrange){ // input indexes of array to get the sum of 2 elements

        printf("Enter the indices of the two elements (0 <= index1, index2 < %d)",size);
        scanf("%d %d",&index1,&index2);

        if (index1<0 || index2>size){
            printf("Error! Indices must be within the range of the array elements. Please try again!\n");
        }

        else{
            indicesrange=1; // loops indefinitely until user inputs within correct range 
        }

    }

    int *ptr=&array[0];
    sum=(*ptr+index1) + (*ptr+index2); // using pointers to point to index of elements, then dereference + sum the elements
    free(array);

    printf("The sum of the values at indices %d and %d is : %d",index1,index2,sum);
    return 0;

}