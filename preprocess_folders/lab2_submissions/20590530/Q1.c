#include <stdio.h>
#include <stdlib.h>

int main() {
    int arraysize = 0;
    printf("Enter the size of the array (N >= 5): ");
    scanf("%d\n", arraysize);

    int *ptr;
    ptr = (int *)malloc(arraysize * sizeof(int));
    //prompt for user to enter array elements
    printf("Enter the array elements: \n");

    for (int j = 0; j < arraysize; j++) {
        ptr[j] = -1;
    }

    int count = 0;
    while (count < arraysize) {
        int input;
        printf("Element: ");
        scanf("%d\n", &input);
        ptr[count] = input;
        count++;
    }

    int i, k;
    printf("Enter the indices of the two elements(0 <= index1, index2 < %d): ", arraysize);
    fgets(i, sizeof(i), stdin);
    if (i > arraysize || k > arraysize) {
        printf("Error: Indices must be within the range of the array elements. Please try again.");
        return 1;
    } else {
        int i = *ptr;
        int k = *ptr;
        int sum = ptr[i] + ptr [k];
        printf("The sum of the values at indices 4 and 5 is: %d", sum);
    }
}