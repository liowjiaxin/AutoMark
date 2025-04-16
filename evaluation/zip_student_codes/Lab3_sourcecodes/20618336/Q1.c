#include <stdio.h> // Include standard input/output header file
#define MAX 10 // Define the maximum size for matrices

// Function declarations
void inputMatrix(int matrix[MAX][MAX], int rows, int cols, char name); // Function to take input for a matrix
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int rows, int cols); // Function to add two matrices
void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int rows, int cols); // Function to subtract one matrix from another
void transposeMatrix(int matrix[MAX][MAX], int rows, int cols, char name); // Function to transpose a matrix

int main() {
    int A[MAX][MAX], B[MAX][MAX]; // Declare matrices A and B
    int rowsA, colsA, rowsB, colsB; // Variables to store dimensions of matrices
    int choice; // Variable to store user's menu choice

    
    printf("Enter the number of rows and columns for Matrix A: "); // Gather dimensions and elements for Matrix A
    scanf("%d %d", &rowsA, &colsA); // Input dimensions for Matrix A
    if (rowsA > MAX || colsA > MAX || rowsA <= 0 || colsA <= 0) { // Validate dimensions
        printf("Error: Dimensions must be between 1 and %d.\n", MAX);


        return 1;
    }
    inputMatrix(A, rowsA, colsA, 'A'); // Input elements for Matrix A

    
    printf("Enter the number of rows and columns for Matrix B: "); // Gather dimensions and elements for Matrix B
    scanf("%d %d", &rowsB, &colsB); // Input dimensions for Matrix B
    if (rowsB > MAX || colsB > MAX || rowsB <= 0 || colsB <= 0) { // Validate dimensions
        printf("Error: Dimensions must be between 1 and %d.\n", MAX);
        return 1;
    }
    inputMatrix(B, rowsB, colsB, 'B'); // Input elements for Matrix B



    // Display menu for matrix operations
    do {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice); // Input user's menu choice

        switch (choice) {
            case 1:
                if (rowsA == rowsB && colsA == colsB) { // Check if dimensions match for addition
                    addMatrices(A, B, rowsA, colsA); // Perform addition
                } else {
                    printf("Addition not possible: Matrices must have the same dimensions.\n");
                }
                break;

            case 2:
                if (rowsA == rowsB && colsA == colsB) { // Check if dimensions match for subtraction
                    subtractMatrices(A, B, rowsA, colsA); // Perform subtraction
                } else {
                    printf("Subtraction not possible: Matrices must have the same dimensions.\n");
                }
                break;

            case 3:
                transposeMatrix(A, rowsA, colsA, 'A'); // Transpose Matrix A
                break;

            case 4:
                transposeMatrix(B, rowsB, colsB, 'B'); // Transpose Matrix B
                break;

            case 5:
                printf("Exiting program. Goodbye!\n"); // Exit the program
                break;

            default:
                printf("Invalid option. Please select a valid choice.\n"); // Handle invalid input
        }
    } while (choice != 5); // Repeat until user chooses to exit

    return 0;
}

// Function to input elements for a matrix

void inputMatrix(int matrix[MAX][MAX], int rows, int cols, char name) {
    printf("Enter the elements for Matrix %c:\n", name); // Prompt user for elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1); // Indicate position of element
            scanf("%d", &matrix[i][j]); // Input element value
        }
    }
}

// Function to add two matrices

void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int rows, int cols) {
    printf("Result of Matrix A + Matrix B:\n"); // Indicate addition result
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", A[i][j] + B[i][j]); // Compute and print sum of elements
        }
        printf("\n"); // Newline after each row
    }
}

// Function to subtract two matrices

void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int rows, int cols) {
    printf("Result of Matrix A - Matrix B:\n"); // Indicate subtraction result
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", A[i][j] - B[i][j]); // Compute and print difference of elements
        }
        printf("\n"); // Newline after each row
    }
}

// Function to transpose a matrix

void transposeMatrix(int matrix[MAX][MAX], int rows, int cols, char name) {
    printf("Transpose of Matrix %c:\n", name); // Indicate transposition result
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", matrix[j][i]); // Print transposed element
        }
        printf("\n"); // Newline after each row
    }
}
