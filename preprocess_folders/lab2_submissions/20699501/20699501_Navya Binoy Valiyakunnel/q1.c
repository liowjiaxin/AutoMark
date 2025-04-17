#include<stdio.h>
#include<stdlib.h>

int *N;
int size;
int sum;


int main(){
// prompt array size
    printf("Enter the size of the array(N >= 5): ");
    scanf("%d", &size); 

    //validate size 
    while(size < 5){
        printf("Invalid size. Please enter a valid size (N>=5):");
        scanf("%d", &size);
    }

//Dynamically allocate memory for the array
    N = (int *)malloc(size * sizeof(int));
    



    printf("Enter the array of elements:\n");
 //taking input and storing it in an array
   
    for (int i=0; i < size; i++) {
        printf("Enter number %d: ", i+1);
        scanf("%d", &N[i]);
    }

    int index1, index2;

    while(index1 >= 0, index2 < 6){
        printf("Enter the indices of the two elements (0 <= index1, index 2 < 6): ");
        scanf("%d %d", &index1, &index2);
    }

//Calculate sum
    sum = N[index1] + N[index2];
        

    printf("The sum of the values of indices %d and %d is:%d\n", index1, index2, sum );

//free allocated memory
    free(N);

    return 0;
}





