#include <stdio.h>

#define MAX_SIZE 10

// Function prototypes
void inputMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], char name);
void printMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE]);
void addMatrices(int rows, int cols, int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]);
void subtractMatrices(int rows, int cols, int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]);
void transposeMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]);

int main() {
    int rowsA, colsA, rowsB, colsB;
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int choice;

    // Input dimensions and validate
    do {
        printf("Enter dimensions for Matrix A (rows and columns, max 10): "); //how many dimensions you want for Matrix A
        scanf("%d %d", &rowsA, &colsA);
    } while (rowsA <= 0 || rowsA > MAX_SIZE || colsA <= 0 || colsA > MAX_SIZE);

    do {
        printf("Enter dimensions for Matrix B (rows and columns, max 10): "); //how many dimensions you want for Matrix B
        scanf("%d %d", &rowsB, &colsB);
    } while (rowsB <= 0 || rowsB > MAX_SIZE || colsB <= 0 || colsB > MAX_SIZE);

    // Input matrices
    inputMatrix(rowsA, colsA, A, 'A');
    inputMatrix(rowsB, colsB, B, 'B');

    // Menu loop
    do {
        printf("\nMatrix Operations Menu:\n"); //show the menu
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: //add Matrices
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(rowsA, colsA, A, B, result);
                    printf("Result of Matrix A + Matrix B:\n");
                    printMatrix(rowsA, colsA, result);
                } else {
                    printf("Addition not possible. Matrices must have the same dimensions.\n");
                }
                break;

            case 2: //subtract Matrices
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(rowsA, colsA, A, B, result);
                    printf("Result of Matrix A - Matrix B:\n");
                    printMatrix(rowsA, colsA, result);
                } else {
                    printf("Subtraction not possible. Matrices must have the same dimensions.\n");
                }
                break;

            case 3: //Transpose Matrix A
                transposeMatrix(rowsA, colsA, A, result);
                printf("Transpose of Matrix A:\n");
                printMatrix(colsA, rowsA, result);
                break;

            case 4: //Transpose Matrix B
                transposeMatrix(rowsB, colsB, B, result);
                printf("Transpose of Matrix B:\n");
                printMatrix(colsB, rowsB, result);
                break;

            case 5: //Exit program
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n"); //if you input the wrong number(no option from the menu)
        }
    } while (choice != 5);

    return 0;
}

// Function definitions
void inputMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], char name) { //for input the element for matrix A & B
    printf("Enter elements for Matrix %c:\n", name); 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE]) { 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int rows, int cols, int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) { //add Matrices option
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int rows, int cols, int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) { //sub matrices option
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

void transposeMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) { //transpose matrix A/B option
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}
