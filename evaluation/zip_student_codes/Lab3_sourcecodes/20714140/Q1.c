#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void AddorSub(int *a, int *b, int xa, int ya, int xb, int yb, int addorsub) {
    printf("Result of Matrix A + Matrix B:\n");

    int big_x = (xa > xb) ? xa : xb;  // Larger number of rows
    int big_y = (ya > yb) ? ya : yb;  // Larger number of columns

    for (int i = 0; i < big_x; i++) {
        for (int j = 0; j < big_y; j++) {
            // Access elements from Matrix A and B, if out of scope, gives a 0

            int A = (i < xa && j < ya) ? *(a + i * ya + j) : 0;
            int B = (i < xb && j < yb) ? *(b + i * yb + j) : 0;
            if (addorsub == 1){
            printf("%d ", A + B);
            } else {printf("%d ", A - B);}
        }
        printf("\n");
    }
}

void Transpose(int *matrix, int x, int y) {
    printf("Result of Transposing Matrix A:\n");

    // Transposing and printing
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            printf("%d ", *(matrix + j * y + i));  // Print elements in transposed form
        }
        printf("\n");
    }
}

int main() {
    int x1, y1, x2, y2;

    // Dimensions for Matrix A
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d", &x1);
    scanf("%d", &y1);
    while (x1 > MAX || y1 > MAX) {
        printf("10 is the Maximum size for either grid. Please re-enter dimensions for Matrix A (rows and columns): ");
        scanf("%d", &x1);
        scanf("%d", &y1);
    }

    // Dynamically allocate memory for Matrix A
    int *MatA = (int *)malloc(x1 * y1 * sizeof(int));

    printf("Enter elements for Matrix A: \n");
    for (int i = 0; i < x1; i++) {
        for (int j = 0; j < y1; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", (MatA + i * y1 + j));  // Pointer arithmetic to assign elements
        }   // stores the matrix as an array like A = {1,2,3,4,5,6,7,8,9} where 1 is A[0][0] and 4 is [1][0]
    }

    // Dimensions for Matrix B
    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d", &x2);
    scanf("%d", &y2);
    while (x2 > MAX || y2 > MAX) {
        printf("10 is the Maximum size for either grid. Please re-enter dimensions for Matrix B (rows and columns): ");
        scanf("%d", &x2);
        scanf("%d", &y2);
    }

    // Dynamically allocate memory for Matrix B
    int *MatB = (int *)malloc(x2 * y2 * sizeof(int));

    printf("Enter elements for Matrix B: \n");
    for (int i = 0; i < x2; i++) {
        for (int j = 0; j < y2; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", (MatB + i * y2 + j));  // Pointer arithmetic to assign elements
        }
    }

    int choice = 0;
    while (choice != 5) { // Selection Menu
        printf("Matrix Operations Menu:\n1. Add Matrices\n2. Subtract Matrices\n3. Transpose Matrix A\n4. Transpose Matrix B\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            AddorSub(MatA, MatB, x1, y1, x2, y2,1);  // Addition
        }
        else if (choice == 2) {
            AddorSub(MatA, MatB, x1, y1, x2, y2,2);  // Subtraction
        }
        else if (choice == 3) {
            Transpose(MatA, x1, y1);  // Transpose Matrix A
        }
        else if (choice == 4) {
            Transpose(MatB, x2, y2);  // Transpose Matrix B
        } else if (choice != 5){
            printf("There is no such option. Please enter again.\n");
        }
    }

    printf("Exiting...\n");

    return 0;
}
