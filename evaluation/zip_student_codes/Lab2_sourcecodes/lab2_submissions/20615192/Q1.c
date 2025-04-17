#include <stdio.h>

int main() {
    int N;
    int arr[N];
    int index1; 
    int index2;
    
    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &N);

    if (N<5) {
        printf("Error: N must be greater than or equal to 5.\n");
        return 1;
    }
    
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
    scanf("%d %d", &index1, &index2);

    if (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N) {
        printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        return 1;
    }

    int sum = arr[index1] + arr[index2];
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);
    return 0;
    
}