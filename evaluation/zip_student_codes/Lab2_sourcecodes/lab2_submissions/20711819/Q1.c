#include <stdio.h>
#include <stdlib.h> // library for malloc

int main(){
    // *uwuArray is pointr for the malloc dynamic array
    // uwuSize for the user input array size
    // uwuHold for holding each element value enter by the user
    // index1, index2 for the indices specified by user
    // outOfBound check if the indices are not in array range
    // answer for storing the sum
    int *uwuArray, uwuSize = 0, uwuHold, index1, index2, outOfBound = 1, answer = 0;
    
    // prompt user to enter the array size
    printf("Enter the size of the array (N >= 5): ");
    // check if the size input is < 5, if so, repeat asking the user
    for (scanf("%d", &uwuSize); uwuSize < 5; scanf("%d", &uwuSize)){
        printf("Enter the size of the array (N >= 5): ");
    }
    // dynamically allocate memory chunk for the array, return the address of first element to the pointer
    uwuArray = malloc(uwuSize * sizeof(uwuSize));
    
    // promt user to enter each elemnt's value
    for (int i = 0; i < uwuSize; i++){
        printf("Element %d: ", i);
        scanf("%d", &uwuHold);
        // dereference and store the value into the pointed address
        *uwuArray = uwuHold;
        // increment the address by 1 (size of int, in this case, 4 bytes)
        uwuArray++;
    }
    // reset the address the pointer is pointing to the first elemet
    uwuArray -= uwuSize;
    
    // prompt the user to enter valid indices when they are out of bound
    while(outOfBound){
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", uwuSize);
        scanf("%d %d", &index1, &index2);
        // check if the indices are beyond the array range
        if ((index1 < 0 || index1 >= uwuSize) || (index2 < 0 || index2 >= uwuSize)){
            // error message if they are out of bound
            printf("Error: Indices must be within the range of the array elements. Pwease try again.\n");
        }else{
            // else quit the loop
            outOfBound = 0;
        }
    }
    
    // looping until the pointer is pointing to index1 of array
    for (int i = 0; i < index1; i++){
        uwuArray++;   
    }
    // add the value to answer
    answer += *uwuArray;
    // reset the pointer's pointing address
    uwuArray -= index1;
    
    // looping until the pointer is pointing to index2 of array
    for (int i = 0; i < index2; i++){
        uwuArray++;   
    }
    // add the value to answer
    answer += *uwuArray;
    // reset the pointer's pointing address
    uwuArray -= index2;

    // print the answer
    printf("The sum of value at indices %d and %d is: %d\n", index1, index2, answer);

    return 0;
}