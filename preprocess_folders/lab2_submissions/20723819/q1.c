#include <stdio.h>
#include <stdlib.h>

int main(){
	//initialise arrsize variable
	//needed to prevent undefined behavior in the following while loop
	int arrsize = 0;
	//use while loop to get input and validate input in one go
	while (arrsize < 5) {
		printf("Enter the size of the array (N >= 5): ");
		scanf("%d", &arrsize);
		if (arrsize < 5) {
		    printf("Please enter an integer greater than 5\n");
		}
	}

	//allocate memory for our array
	int *arrpnt = malloc(arrsize * sizeof(int));

	//get user input for array elements, using for loop to do so
	printf("Enter the array elements:\n");
	for (int i = 0; i < arrsize; ++i){
		printf("Element %d: ",i);
		scanf("%d",(arrpnt+i));
	}

	//it's always better to initialise your variables first
	//-1 to avoid breaking our fragile while condition below
	int index1, index2 = -1;
	
	//complex validation, stricter than specified
	//better safe than sorry
	while ((index1 < 0) || (index1 >= arrsize) || (index2 < 0) || (index2 >= arrsize) ) {
		printf("Enter the indices of the two elements (index1 >= 0, index2 < %d) ",arrsize);
		//get user input
		scanf("%d %d", &index1, &index2);
		if (index1 < 0 || index1 >= arrsize || index2 < 0 || index2 >= arrsize ){
			printf("Error: Indices must be within the range of the array elements. Please try again.\n");
		}
	}
	//print the sum
	printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, *(arrpnt+index1) + *(arrpnt+index2));
	//make sure to release your memory so it can ride off into the sun
	free(arrpnt);
	return 0;

}
