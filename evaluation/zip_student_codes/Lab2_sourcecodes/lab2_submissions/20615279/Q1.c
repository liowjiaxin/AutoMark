#include <stdio.h>
#include <stdlib.h>


int main (){

    //initiate values for N and indices 1 and 2
    int N;
    int ind1,ind2;

    //Let user input the size of array
    do{
    printf("Enter the size of array (N>=5):");
    scanf("%d",&N);
    if(N < 5){ //validate if the size of array is at least 5 or not
        printf("Enter a number that is at least 5!\n"); //output error if the size of array is not at least 5
        }
    }while (N < 5); // Let user input again using do-while loop

    int *integers = (int *)malloc(N * sizeof(int));//allocate and initialize to 0
    if (integers == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    //Ask user to input all the elements 
    for(int i = 0; i < N ; i++){
        printf("Element %d:",i);
        scanf("%d",&integers[i]);
    }
    
    //Obtain user input for index 1 and index 2
    do{
        printf("Enter the indices of the two elements (0 <= index1 , index2 < %d):",N);
        scanf("%d %d",&ind1, &ind2);
        if(ind1 < 0 || ind2 >N){  // Check if user's input of indexes is out of boundaries or not
            printf("Error: Indices must be within the range of the array elements. Please try again\n"); // Output error if exceeded the boundaries
        }

    }while (ind1 < 0 || ind2 >N); //Use do while loop to ensure correct input for indexes are obtained

    int sum = *(integers + ind1) + *(integers + ind2); //Calculating the sum of the numbers
    printf("The sum of the values at indices %d and %d is: %d",ind1,ind2,sum); //Output sum of numbers

    free(integers); // Free allocated memory

    return 0;
}
