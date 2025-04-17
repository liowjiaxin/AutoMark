#include <stdio.h>
#include <stdlib.h>


int main(void){
    //This pointer will hold the 
    //base adddress of the block created
    int* ptr;
    int n, value = 0;


//Dynamic allocate memory using malloc()
    ptr = (int*) malloc(n * sizeof(int));

//Check if the memory has been succesfully 
//allocated by malloc or not
    if(ptr == NULL){
        printf("Memory not allocated.\n");
        exit(0);    //Exit Success

    }

//Get the number of elements for the array one by one
    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &n);

    printf("Enter number the array elements:\n");
    for(int i = 0; i < n; ++i){
        printf("Element %d: ", i);
        scanf("%d", &value);
        ptr[i] = i + 1;
    }

   /* printf("The elements of the array are: ");
    for(int i = 0; i < n; ++i){
        printf("%d ", ptr[i]);
    }
*/

    int index1, index2 = 0;
do{

    printf("\nEnter the indices of the two elements (0 <= index1, index2 < 6): ");
    scanf("%d %d", &index1, &index2);

    if(index1 < 0 || index1 >= n || index2 < 0 || index2 >= n){
        printf("Error: Indices must be within the range array elements, Please try again.");
    }
    
    int sum = *(ptr + index1) + *(ptr + index2);
    printf("The sum of the values at indices %d and %d is: ", index1 , index2 , sum);

}while( index1 < 0 || index1 >= n || index2 < 0 || index2 >= n);


}


