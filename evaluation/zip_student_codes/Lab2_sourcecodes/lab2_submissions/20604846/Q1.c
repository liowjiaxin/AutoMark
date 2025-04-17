#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int N = 0;
    int* arr;
    
    printf("Enter the size of the array (N >= 5): ");
    scanf("%d",&N);

    while (N < 5){
        printf("Error: Enter the size of the array ( MUST BE >= 5): ");
        scanf("%d",&N);
    }

    arr = (int*)malloc(N * sizeof(int));


    printf("Enter the array elements:\n");

    int i;
    for (i = 0; i < N; i++) {
        printf("Element %d:", i);
        int temp;
        scanf("%d", &temp);

        arr[i] = temp;
    }

    int index1;
    int index2;
    int run = 1;
    while (run == 1){
        printf("Enter the indices of the two elements (0 <= index1, index2 < 6): \n");
        scanf("%d", &index1);
        scanf("%d", &index2);

        if (index1 > N || index2 > N){
            printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        }else{
            run = 0;
        }
    }

    int sum = arr[index1] + arr[index2];
    printf("The sum of the values at %d and %d is: %d", index1, index2, sum);

    return 0;
}