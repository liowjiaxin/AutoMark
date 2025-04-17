#include <stdio.h>

int main() {
    int N;
    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &N);
    //keep asking userinput until size of array is not less than 5
    while (N < 5) {
        printf("Invalid input. Please enter a number greater than or equal to 5: ");
        while (getchar() != '\n'); // clear input buffer
    }

    int arr[N];
    printf("Enter %d elements of the array:\n", N);
    //use for loop to write down elements in the array 
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }

    int index1, index2; //assign two variables for addition 
    printf("Enter the first index (0 <= index1 < %d): ", N);
    scanf("%d", &index1);
    //check if userinput is valid and within range 
    while (index1 < 0 || index1 >= N) {
        printf("Invalid input. Please enter a value between 0 and %d: ", N - 1);
        while (getchar() != '\n'); // clear input buffer
    }

    printf("Enter the second index (0 <= index2 < %d): ", N);
    scanf("%d", &index2);
    //validation for index2, check if index2 = index 1 and same conditions maintained like index 1
    while (index2 < 0 || index2 >= N || index2 == index1) {
        printf("Invalid input, the number is same as index 1 or less than 0 or greater than the number of elements");
        while (getchar() != '\n'); // clear input buffer
    }

    int sum = *(arr + index1) + *(arr + index2); //use pointers to find address of index 1 and 2 to add them by dereferencing
    printf("The sum of the elements at indices %d and %d is: %d\n", index1, index2, sum);

}