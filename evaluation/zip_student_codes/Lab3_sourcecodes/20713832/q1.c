#include <stdio.h>

// The Function prototypes used for matrix operations
void inputMatrix(int rows, int cols, int matrix[10][10], char name); // intializing a function called input matrix
void printMatrix(int rows, int cols, int matrix[10][10]); // intializing a function called print matrix
void addMatrices(int rows, int cols, int matrixA[10][10], int matrixB[10][10], int result[10][10]);// intializing a function called add matrix
void subtractMatrices(int rows, int cols, int matrixA[10][10], int matrixB[10][10], int result[10][10]); // intializing a function called subtract matrix
void transposeMatrix(int rows, int cols, int matrix[10][10], int result[10][10]); // intializing a function called transpose matrix

int main() {
    int rowsA, colsA, rowsB, colsB; // intializing rows and columns of Matrix A and Matrix B
    int matrixA[10][10], matrixB[10][10]; 
    int result[10][10]; // intializing result
    int choice;

    
    printf("Enter the dimensions for Matrix A (rows and columns): "); //Asking the User to Input the dimensions for Matrix A
    scanf("%d %d", &rowsA, &colsA); // using scanf feature to read the input

    
    inputMatrix(rowsA, colsA, matrixA, 'A'); // Asking the user to Input the elements for Matrix A

    
    printf("Enter the dimensions for Matrix B (rows and columns): "); // Asking the User to Input the dimensions for Matrix B
    scanf("%d %d", &rowsB, &colsB);//  using scanf feature to read the input

    
    inputMatrix(rowsB, colsB, matrixB, 'B'); // Asking the user to Input the elements for Matrix A

    do {                                    // using a do loop so that the user can access the menu again until the exit choice is selected
        // Display menu
        printf("\nMatrix Operations Menu:\n");  
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: "); // Asking the user for the input
        scanf("%d", &choice); // using scanf to read the input

        switch (choice) {               // using switch - case to use the respective functions
            case 1: // Addition of Matrices
                if (rowsA == rowsB && colsA == colsB) { // setting the rule that it is only possible to add matrix if the matrices are of the same dimention
                    addMatrices(rowsA, colsA, matrixA, matrixB, result);
                    printf("Result of Matrix A + Matrix B:\n");
                    printMatrix(rowsA, colsA, result); // The result of the addition is displayed.
                } else {
                    printf("Addition of the these Matrices is not possible. The Dimensions do not match.\n"); // If the dimention are not the same, the following message is displayed.
                }
                break;

            case 2: // Subtraction of Matrices
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(rowsA, colsA, matrixA, matrixB, result);
                    printf("Result of Matrix A - Matrix B:\n");
                    printMatrix(rowsA, colsA, result); // The result of the subtraction is displayed.
                } else {
                    printf("Subtraction of these Matrices is not possible. The Dimensions do not match.\n");  // If the dimention are not the same, the following message is displayed.
                }
                
                break;

                case 3: // Transpose Matrix A
                transposeMatrix(rowsA, colsA, matrixA, result);
                printf("Transpose of Matrix A:\n");
                printMatrix(colsA, rowsA, result); // inverting the rows and columns and the result is displayed
                break;

                case 4: // Transpose Matrix B
                transposeMatrix(rowsB, colsB, matrixB, result);
                printf("Transpose of Matrix B:\n");
                printMatrix(colsB, rowsB, result); // inverting the rows and columns and the result is displayed
                break;

            case 5: // Exit
                printf("Exiting the program ...\n"); 
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5); // as long as the choice is not 5 , the do loop keeps running

    return 0;
}

// Function to input a matrix
void inputMatrix(int rows, int cols, int matrix[10][10], char name) {
    printf("Enter elements for Matrix %c:\n", name); // Asking the user to input the elements of the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]); // reading the input
        }
    }
}

// Function to print a matrix
void printMatrix(int rows, int cols, int matrix[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]); // displaying the matrix
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int rows, int cols, int matrixA[10][10], int matrixB[10][10], int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j]; // adding both the matrices
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int rows, int cols, int matrixA[10][10], int matrixB[10][10], int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j]; // subtracting both the matrices
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int rows, int cols, int matrix[10][10], int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j]; // transposing the matrices by swapping the rows and columns
        }
    }
}
