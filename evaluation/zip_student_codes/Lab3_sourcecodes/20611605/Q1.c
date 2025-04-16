#include <stdio.h>

#define MAX 10 //define maximum amount of rows/column is 10

//function for user to fill in matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

//function to input matrix
void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//function to add matrix
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

//function to subtract matrix
void subtractMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

//function to transpose matrix
void transposeMatrix(int matrix[MAX][MAX], int transposed[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

int main() {

    //initialise variables
    int matrixA[MAX][MAX], matrixB[MAX][MAX], result[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;

    //ask user to enter rows and coloumns
    printf("Enter rows and columns for Matrix A(max 10): ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter rows and columns for Matrix B(max 10): ");
    scanf("%d %d", &rowsB, &colsB);

    //ensure only allowed dimensions are entered
    if (rowsA > MAX || colsA > MAX || rowsB > MAX || colsB > MAX || rowsA < 1 || colsA < 1 || rowsB < 1 || colsB < 1) {
        printf("Invalid dimensions!\n");
        return 1;
    }

    //let user fill in the matrix
    printf("Input Matrix A:\n");
    inputMatrix(matrixA, rowsA, colsA);
    printf("Input Matrix B:\n");
    inputMatrix(matrixB, rowsB, colsB);

    int choice;
    //use a do while loop
    do {
        //print options
        printf("\nMenu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        //use switch case
        switch (choice) {
            //for addition
            case 1:
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(matrixA, matrixB, result, rowsA, colsA);
                    printf("Result of Addition:\n");
                    printMatrix(result, rowsA, colsA);
                } else {
                    printf("Addition not possible. Dimensions must match.\n");
                }
                break;
            //for subtraction
            case 2:
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
                    printf("Result of Subtraction:\n");
                    printMatrix(result, rowsA, colsA);
                } else {
                    printf("Subtraction not possible. Dimensions must match.\n");
                }
                break;
            //for transposition A
            case 3:
                {
                    int transposedA[MAX][MAX];
                    transposeMatrix(matrixA, transposedA, rowsA, colsA);
                    printf("Transpose of Matrix A:\n");
                    printMatrix(transposedA, colsA, rowsA);
                }
                break;
            
            // for transposition B
            case 4:
                {
                    int transposedB[MAX][MAX];
                    transposeMatrix(matrixB, transposedB, rowsB, colsB);
                    printf("Transpose of Matrix B:\n");
                    printMatrix(transposedB, colsB, rowsB);
                }
                break;
            // for exiting program
            case 5:
                printf("Exiting program.\n");
                break;
            //print if invalid choice
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
