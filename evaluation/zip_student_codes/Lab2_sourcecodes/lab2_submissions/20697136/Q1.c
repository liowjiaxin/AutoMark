#include <stdio.h>

int main(void){
    int N = 0;
    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &N);

    int array[N];
    int *arrPtr = array;
    printf("Enter the array elements:\n");
    for(int i = 0; i<N; i++){
        printf("Element %d: ", i);
        scanf("%d", (arrPtr+i));
    }

    int ind1;
    int ind2;
    int sum;
    for(int j = 0; j>=0; j++){
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &ind1, &ind2);
        if((ind1 >= 0) && (ind2 < N)){
            sum = arrPtr[ind1]+ arrPtr[ind2];
            printf("The sum of the values at indices %d and %d is: %d\n", ind1, ind2, sum);
            break;
        }
        else {
            printf("Error: indices must be within the range of the array elements. Please try again.\n");
        } 
    }
}