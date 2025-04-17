#include<stdio.h>
#include<stdlib.h>

//function which can check if the indices are valid
int ifvalidindex (int index, int size) {
    if (index >= 0 && index < size) {
        return 1;
    }
    return 0;
}
int main(){
    int N;
    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &N);
    while(N < 5) {
        printf("The size is invalid. Please enter a size greater or equal to 5: ");
        scanf("%d", &N);
    }
    int *array = (int *)malloc(N *sizeof(int)); //allocate meomroy for array
    if (array == NULL) {
        printf("Memmory allocation is failed\n");
        return 1;
    }
    printf("Enter the array elements: \n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", (array + i));   //access the number i element in array
    }
    int index1, index2;
    printf("Enter the indices of the two elements: ");
    scanf("%d %d", &index1, &index2);
    
    while (!ifvalidindex(index1, N) || !ifvalidindex(index2, N)){
        printf("Indice must be within the range of the array elements. Please try again.\n");
        printf("Enter the indices of the two elements again: ");
        scanf("%d %d", &index1, &index2);
    }
    int sum = *(array + index1) + *(array + index2);
    printf("The sum of the values at indices %d and %d is %d \n", index1, index2, sum); //find the sum of values of index 1 and 2
    
    free(array); //free allocated memory
    return 0;
}
