#include <stdio.h>

#define LIMIT 10
//Function to prompt user input for Matrix
void getMatrixInput(int mat[LIMIT][LIMIT], int rows, int cols, char matName) {
    printf("Enter elements for Matrix %c:\n", matName);
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            printf("Element [%d][%d]: ", r + 1, c + 1);
            scanf("%d", &mat[r][c]);
        }
    }
}
//Function to display the matrix
void displayMatrix(int mat[LIMIT][LIMIT], int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            printf("%d ", mat[r][c]);
        }
        printf("\n");
    }
}
//Function to add the 2 matrices together
void matrixAddition(int mat1[LIMIT][LIMIT], int mat2[LIMIT][LIMIT], int sum[LIMIT][LIMIT], int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            sum[r][c] = mat1[r][c] + mat2[r][c];
        }
    }
}
//Function to subtract the matrices
void matrixSubtraction(int mat1[LIMIT][LIMIT], int mat2[LIMIT][LIMIT], int diff[LIMIT][LIMIT], int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            diff[r][c] = mat1[r][c] - mat2[r][c];
        }
    }
}
//Function to compute the transpose of a matrix
void matrixTranspose(int mat[LIMIT][LIMIT], int trans[LIMIT][LIMIT], int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            trans[c][r] = mat[r][c];
        }
    }
}

int main() {
    //Variables for the matrices and the dimensions
    int mat1[LIMIT][LIMIT], mat2[LIMIT][LIMIT], result[LIMIT][LIMIT];
    int mat1Rows, mat1Cols, mat2Rows, mat2Cols;
    int option;

    //Inputting the dimensions of Matrix A
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d%d", &mat1Rows, &mat1Cols);

    //Validating dimensions for Matrix A
    if (mat1Rows > LIMIT || mat1Cols > LIMIT || mat1Rows < 1 || mat1Cols < 1) {
        printf("Error: Invalid dimensions for Matrix A.\n");
        return 1;
    }
    getMatrixInput(mat1, mat1Rows, mat1Cols, '1');

    //Inputting dimensions for Matrix B
    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d%d", &mat2Rows, &mat2Cols);

    //Validating dimensions of Matrix B
    if (mat2Rows > LIMIT || mat2Cols > LIMIT || mat2Rows < 1 || mat2Cols < 1) {
        printf("Error: Invalid dimensions for Matrix B.\n");
        return 1;   
    }
    getMatrixInput(mat2, mat2Rows, mat2Cols, '2');

    //Menu
    do {
        printf("\nMenu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix 1\n");
        printf("4. Transpose Matrix 2\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1: //To add the matrices
                if (mat1Rows == mat2Rows && mat1Cols == mat2Cols) {
                    matrixAddition(mat1, mat2, result, mat1Rows, mat1Cols);
                    printf("Result of Matrix 1 + Matrix 2:\n");
                    displayMatrix(result, mat1Rows, mat1Cols);
                } else {
                    printf("Error: Addition not possible. Dimensions must match.\n");
                }
                break;
            case 2: //To subtract the matrices
                if (mat1Rows == mat2Rows && mat1Cols == mat2Cols) {
                    matrixSubtraction(mat1, mat2, result, mat1Rows, mat1Cols);
                    printf("Result of Matrix 1 - Matrix 2:\n");
                    displayMatrix(result, mat1Rows, mat1Cols);
                } else {
                    printf("Error: Subtraction not possible. Dimensions must match.\n");
                }
                break;
            case 3: //To transpose Matrix A
                matrixTranspose(mat1, result, mat1Rows, mat1Cols);
                printf("Transpose of Matrix 1:\n");
                displayMatrix(result, mat1Cols, mat1Rows);
                break;
            case 4: //To transpose Matrix B
                matrixTranspose(mat2, result, mat2Rows, mat2Cols);
                printf("Transpose of Matrix 2:\n");
                displayMatrix(result, mat2Cols, mat2Rows);
                break;
            case 5: //Exit program
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (option != 5);

    return 0;
}


