#include <stdio.h>

#define MAX_SIZE 10

// input matrix element
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter the elements of the %dx%d matrix:\n", rows, cols);
    int i;
	for ( i = 0; i < rows; i++) {
        int j;
		for ( j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// printing matrix
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Matrix:\n");
    int i;
	for ( i = 0; i < rows; i++) {
        int j;
		for ( j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// matrix addition
void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int i;
	for ( i = 0; i < rows; i++) {
        int j;
		for ( j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// matrix subtraction
void subtractMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int i;
	for ( i = 0; i < rows; i++) {
        int j;
		for ( j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

// matrix transpose
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int i;
	for ( i = 0; i < rows; i++) {
        int j;
		for ( j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;

    // Enter the dimensions of matrices A and B
    printf("Enter the dimensions of Matrix A (rows cols): ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter the dimensions of Matrix B (rows cols): ");
    scanf("%d %d", &rowsB, &colsB);

    // Verify that matrix dimensions are valid
    if (rowsA > MAX_SIZE || colsA > MAX_SIZE || rowsB > MAX_SIZE || colsB > MAX_SIZE || rowsA <= 0 || colsA <= 0 || rowsB <= 0 || colsB <= 0) {
        printf("Invalid matrix dimensions.\n");
        return 1;
    }

    printf("Matrix A:\n");
    inputMatrix(a, rowsA, colsA);
    printf("Matrix B:\n");
    inputMatrix(b, rowsB, colsB);

    int choice;
    do {
        // display menu
        printf("\nMenu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // matrix addition
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(a, b, result, rowsA, colsA);
                    printf("Result of addition:\n");
                    printMatrix(result, rowsA, colsA);
                } else {
                    printf("Matrix dimensions do not match for addition.\n");
                }
                break;

            case 2:  // matrix subtraction
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(a, b, result, rowsA, colsA);
                    printf("Result of subtraction:\n");
                    printMatrix(result, rowsA, colsA);
                } else {
                    printf("Matrix dimensions do not match for subtraction.\n");
                }
                break;

            case 3:  // transpose matrix A
                transposeMatrix(a, result, rowsA, colsA);
                printf("Transpose of Matrix A:\n");
                printMatrix(result, colsA, rowsA);
                break;

            case 4:  // transpose matrix B
                transposeMatrix(b, result, rowsB, colsB);
                printf("Transpose of Matrix B:\n");
                printMatrix(result, colsB, rowsB);
                break;

            case 5:  // exit
                printf("Exiting program.\n");
                break;

            default:  
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

