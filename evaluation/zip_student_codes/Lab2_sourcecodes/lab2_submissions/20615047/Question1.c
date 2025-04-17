#include <stdio.h>

int main (void) {

    int N = 0;

    printf ("Enter the size of the array (N >= 5): ");
    scanf ("%d", &N);

    while (N < 5) {
        printf ("The Size of the Array must be at least 5. Please try again: ");
        scanf ("%d", &N);
    }

    // i is a variable to loop till N
    int arr[N], i = 1;

    printf ("Enter the array elements: \n");
    for (int i = 0; i < N; ++i) {
        printf ("Element %d: ", i);
        scanf ("%d", (arr + i));
    }

    int index1, index2;
    printf ("\nEnter the indices of the two elements (0 <= index1, index2 < %d): ", N);
    scanf ("%d %d", &index1, &index2);

    while ((index1 < 0 && index2 < 0 )|| (index1 > N && index2 > N)) {
        printf ("\nError: Indices must be within the range of the array elements. Please try again: ");
        scanf ("%d %d", &index1, &index2);
    }

    while (index1 < 0 || index1 > N) {
        printf ("\nError: Indice must be within the range of the array elements. Please try again: ", index1);
        scanf ("%d", &index1);
    }

    while (index2 < 0 || index2 > N) {
        printf ("\nError: Indice must be within the range of the array elements. Please try again: ", index2);
        scanf ("%d", &index2);
    }

    // Sum function using pointer
    int sum = *(arr + index1) + *(arr + index2);
    printf ("\nThe sum of the values at indices %d and %d is: %d", index1, index2, sum);
}