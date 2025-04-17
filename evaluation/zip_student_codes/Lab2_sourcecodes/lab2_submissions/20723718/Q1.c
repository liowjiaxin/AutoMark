#include <stdio.h>

int main() { // begin function main 
    int N;
    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &N);
    if (N < 5) {
        printf("Invalid array size.");
        return 0;
    }
    else {
        puts("Enter the array elements:");
    }

    int arr[N];
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }
    
    int index1, index2;
    
    while(1) {
        printf("Enter the indices of the two elements (0 <= index1, index2 < 6): ");
        scanf("%d %d", &index1, &index2);

        int *Ptr1 = &arr[index1];
        int *Ptr2 = &arr[index2];
        
        if (index1 < 0 || index2 >= (N + 1)) {
            puts("Error: Indices must be within the range of array elements.");
        } else {
            int sum = *Ptr1 + *Ptr2;
            printf("The sum of values at indices %d and %d is %d", index1, index2, sum);
            return 0;
        }
    }


    return 0;
} // end function main