// QUESTION 1

#include<stdio.h>
#include<stdlib.h>

//function prototype
int valid_index(int index, int arr_size);
void print_array(int *arrPtr, int arr_size);

// function main begins program execution
int main(void){
    //initialisation
    int arr_size=0;
    int index1=-1;
    int index2=-1;
    int sum=0;

    // 1. prompt user to enter the size N of the array
    printf("%s", "Enter the size of the array (at least 5): ");
    scanf("%d", &arr_size);

    // validate if N>=5
    while(arr_size<5){
        puts("The size of the array must be greater or equal to 5.");
        printf("%s", "Enter the size of the array (at least 5): ");
        scanf("%d", &arr_size);
    }

    // dynamically allocate memory for the array using pointers
    int *arrPtr=malloc(arr_size*sizeof(int));
    int *startPtr=arrPtr;

    // prompt the user to enter each element of the array one by one
    for(int i=0; i<arr_size; i++){
        printf("\nPlease enter the entry of the integer array with index %d: ", i);
        scanf("%d", arrPtr);
        arrPtr++;
    }
    arrPtr=startPtr;
    //testing 
    //print_array(startPtr, arr_size); 

    /*
     prompt the user to enter the two indices of the array elements of 
     their choice.
    */
   puts(" ======== SUMMING TWO ARRAY ELEMENTS ========");
   // enter first index
   while(valid_index(index1, arr_size)<0){
    printf("\nEnter index of FIRST element (any integer between 0 and %d): ", arr_size-1);
    scanf("%d", &index1);
   }

   // enter second index
   while(valid_index(index2, arr_size)<0){
    printf("\nEnter index of SECOND element (any integer between 0 and %d): ", arr_size-1);
    scanf("%d", &index2);
   }

   // find sum of the values of the two array elements
   sum=*(arrPtr+index1)+*(arrPtr+index2);

   // display output for the sum
   printf("The sum of the values at indices %d and %d is: %d", index1, index2, sum);

}

// ================= FUNCTIONS ===================
// tests if index entered by user is valid (within range of 0 to arr_size-1)
int valid_index(int index, int arr_size){
    if(index>=0 && index<arr_size){
        return 1;
    }else{
        return -1;
    }
}

// prints the array (for testing purposes)
void print_array(int *arrPtr, int arr_size){
    puts("");
    for(int i=0; i<arr_size; i++){
        printf("%d\t", *arrPtr);
        arrPtr++;
        if((i+1)%10==0){
            puts("");
        }
    }
}