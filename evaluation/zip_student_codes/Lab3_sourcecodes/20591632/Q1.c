// Q1
#include <stdio.h>

#define MAX_DIM 10  // Since maximum of both columns and rows are 10 

// Function prototypes
void inputMatrix(int matrix[MAX_DIM][MAX_DIM], int rows, int cols);
void printMatrix(int matrix[MAX_DIM][MAX_DIM], int rows, int cols);
void addMatrices(int matrixA[MAX_DIM][MAX_DIM], int matrixB[MAX_DIM][MAX_DIM],
                 int result[MAX_DIM][MAX_DIM], int rows, int cols);
void subtractMatrices(int matrixA[MAX_DIM][MAX_DIM], int matrixB[MAX_DIM][MAX_DIM],
                      int result[MAX_DIM][MAX_DIM], int rows, int cols);
void transposeMatrix(int matrix[MAX_DIM][MAX_DIM], int transposed[MAX_DIM][MAX_DIM],
                     int rows, int cols);

int main(void){
    // Declare matrices and variables for dimensions and menu choice 
    int matrixA[MAX_DIM][MAX_DIM], matrixB[MAX_DIM][MAX_DIM];
    int result[MAX_DIM][MAX_DIM];
    int transposed[MAX_DIM][MAX_DIM];
    int rowsA, colsA, rowsB, colsB;
    int choice;

    // Prompt user to input and program validates for Matrix A
    printf("Enter dimensions for Matrix A (rows and columns): ");
    if (scanf("%d %d", &rowsA, &colsA) != 2 || rowsA <= 0 || colsA <= 0 || rowsA > MAX_DIM || colsA > MAX_DIM) {
        printf("Error: Invalid dimensions for Matrix A. Must be between 1 and %d for both rows and columns.\n", MAX_DIM);
        return 1; // Exit the program if user enter invalid input 
    }
    printf("Enter elements for Matrix A: \n");
    inputMatrix(matrixA, rowsA, colsA);

    // Prompt user to input and program validates for Matrix B
    printf("Enter dimensions for Matrix B (rows and columns): ");
    if (scanf("%d %d", &rowsB, &colsB) != 2 || rowsB <= 0 || colsB <= 0 || rowsB > MAX_DIM || colsB > MAX_DIM) {
        printf("Error: Invalid dimensions for Matrix B. Must be between 1 and %d for both rows and columns.\n", MAX_DIM);
        return 1; // Exit the program if user enter invalid input 
    }
    printf("Enter elements for Matrix B: \n");
    inputMatrix(matrixB, rowsB, colsB);

    // Display the menu and loop back the menu until the user chooses to exit
    while(1){
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        // Input choice and validate
        if (scanf("%d", &choice) != 1) {
            printf("Error: Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // Clear invalid input
            continue;
        }

        // Perform operation based on user's choice using switch 
        switch(choice){
            case 1:
                // Check if dimensions entered are compatible for addition
                if (rowsA != rowsB && colsA != colsB){
                    printf("Error: Dimensions of matrix must be same for addition");
                }
                else{
                    addMatrices(matrixA, matrixB, result, rowsA, colsA);
                    printf("Result of Matrix A + Matrix B:\n");
                    printMatrix(result, rowsA, colsA);
                }
                break;

            case 2:
                // Check if dimensions entered are compatible for subtraction 
                if (rowsA != rowsB && colsA != colsB){
                    printf("Error: Dimensions of matrix must be same for addition");
                }
                else{
                    subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
                    printf("Result of Matrix A - Matrix B:\n");
                    printMatrix(result, rowsA, colsA);
                }
                break;

            case 3: 
                // Transpose Matrix A
                transposeMatrix(matrixA, transposed, rowsA, colsA);
                printf("Transpose of Matrix A:\n");
                printMatrix(transposed, colsA, rowsA);
                break;

            case 4:
                // Transpose Matrix B 
                transposeMatrix(matrixB, transposed, rowsB, colsB);
                printf("Transpose of Matrix B:\n");
                printMatrix(transposed, colsB, rowsB);
                break;

            case 5:
                printf("Exiting...\n");
                return 0;  // Exit the program

            default: 
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

// Function to let user input matrix elements 
void inputMatrix(int matrix[MAX_DIM][MAX_DIM], int rows, int cols){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print matrix elements 
void printMatrix(int matrix[MAX_DIM][MAX_DIM], int rows, int cols){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform addition of two matrices 
void addMatrices(int matrixA[MAX_DIM][MAX_DIM], int matrixB[MAX_DIM][MAX_DIM],
    int result[MAX_DIM][MAX_DIM], int rows, int cols){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Function to perform subtraction of two matrices 
void subtractMatrices(int matrixA[MAX_DIM][MAX_DIM], int matrixB[MAX_DIM][MAX_DIM],
    int result[MAX_DIM][MAX_DIM], int rows, int cols){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

// Function to transpose matrix 
void transposeMatrix(int matrix[MAX_DIM][MAX_DIM], int transposed[MAX_DIM][MAX_DIM],
    int rows, int cols){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            transposed[j][i] = matrix[i][j];
        }
    }
}