#include <stdio.h>

// Function to add two matrices (A and B), storing the result in the sum matrix
void addMatrices(int A_rows, int A_columns, int a[A_rows][A_columns], int b[A_rows][A_columns], int sum[A_rows][A_columns]) {
    // Iterate through each element and add the corresponding elements from A and B
    for (int i = 0; i < A_rows; ++i)
        for (int j = 0; j < A_columns; ++j) {
            sum[i][j] = a[i][j] + b[i][j];  
        }
}

// Function to subtract matrix B from matrix A, storing the result in the subtraction matrix
void subtractMatrices(int A_rows, int A_columns, int a[A_rows][A_columns], int b[A_rows][A_columns], int subtraction[A_rows][A_columns]) {
    // Iterate through each element and subtract the corresponding elements of B from A
    for (int i = 0; i < A_rows; ++i)
        for (int j = 0; j < A_columns; ++j) {
            subtraction[i][j] = a[i][j] - b[i][j];  
        }
}

// Function to calculate the transpose of matrix A, storing the result in the transpose_result matrix
void transposeMatrix(int A_rows, int A_columns, int a[A_rows][A_columns], int transpose_result[A_columns][A_rows]) {
    // Iterate through each element and swap rows with columns for transposition
    for (int i = 0; i < A_rows; ++i)
        for (int j = 0; j < A_columns; ++j) {
            transpose_result[j][i] = a[i][j];  // Swap A[i][j] to transpose_result[j][i]
        }
}

// Function to display any matrix of given rows and columns
void displayMatrix(int rows, int columns, int matrix[rows][columns]) {
    // Print each element of the matrix row by row
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("%d ", matrix[i][j]);  
        }
        printf("\n");  // Print a new line after each row
    }
}

int main() {
    int A_rows, A_columns;  // Declare variables for the dimensions of Matrix A
    int a[100][100], b[100][100], sum[100][100], subtraction[100][100], i, j;
    int B_rows, B_columns;  // Declare variables for the dimensions of Matrix B
    int choice;  
    int transpose_result[100][100];  

    // Start of the program: user inputs for Matrix A
    start:
    printf("Enter rows and columns for Matrix A (between 1 and 10): ");
    scanf("%d %d", &A_rows, &A_columns);  // User inputs rows and columns for Matrix A

    // Input values for Matrix A
    for (i = 0; i < A_rows; ++i)
        for (j = 0; j < A_columns; ++j) {
            printf("Element [%d][%d]: ", i + 1, j + 1);  
            scanf("%d", &a[i][j]);  
        }

    // user inputs for Matrix B
    printf("Enter rows and columns for Matrix B (between 1 and 10): ");
    scanf("%d %d", &B_rows, &B_columns);  // User inputs rows and columns for Matrix B

    // Input values for Matrix B
    for (i = 0; i < B_rows; ++i)
        for (j = 0; j < B_columns; ++j) {
            printf("Element [%d][%d]: ", i + 1, j + 1);  // Prompt user for each element
            scanf("%d", &b[i][j]);  
        }


    while (1) {
        printf("\nMatrix Operations Menu:\n"
               "1. Add Matrices\n"
               "2. Subtract Matrices\n"
               "3. Transpose Matrix A\n"
               "4. Transpose Matrix B\n"
               "5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);  // User selects an operation

        // Handle the menu
        switch (choice) {
        case 1:
            // Adding two matrices (A + B)
            if (A_rows == B_rows && A_columns == B_columns) {  // Check if matrices have the same dimensions
                addMatrices(A_rows, A_columns, a, b, sum);  // Call the addMatrices function
                printf("\nResult of Matrix A + Matrix B:\n");
                displayMatrix(A_rows, A_columns, sum);  // Display the result of addition
            } else {
                printf("Error: Can't perform operation! Matrices dimensions are not equal.\n");
            }
            break;

        case 2:
            // Subtracting two matrices (A - B)
            if (A_rows == B_rows && A_columns == B_columns) {  // Check if matrices have the same dimensions
                subtractMatrices(A_rows, A_columns, a, b, subtraction);  // Call the subtractMatrices function
                printf("\nResult of Matrix A - Matrix B:\n");
                displayMatrix(A_rows, A_columns, subtraction);  // Display the result of subtraction
            } else {
                printf("Error: Can't perform operation! Matrices dimensions are not equal.\n");
            }
            break;

        case 3:
            // Transposing Matrix A
            transposeMatrix(A_rows, A_columns, a, transpose_result);  // Call the transposeMatrix function for Matrix A
            printf("\nTranspose of Matrix A:\n");
            displayMatrix(A_columns, A_rows, transpose_result);  // Display the transpose of Matrix A
            break;

        case 4:
            // Transposing Matrix B
            transposeMatrix(B_rows, B_columns, b, transpose_result);  // Call the transposeMatrix function for Matrix B
            printf("\nTranspose of Matrix B:\n");
            displayMatrix(B_columns, B_rows, transpose_result);  // Display the transpose of Matrix B
            break;

        case 5:
            // Exit the program
            printf("Exiting...\n");
            return 0;

        default:
            // For invalid choices
            printf("Error: Invalid choice!\n");
            break;
        }
    }

    return 0;
}
