#include <stdio.h>

#define SIZE 10 // Maximum size of matrices

// Function to add two matrices
void addMatrices(int rows, int cols, int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE]) {
    // Loop through each element of the matrices and add corresponding elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int rows, int cols, int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE]) {
    // Loop through each element of the matrices and subtract corresponding elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to transpose a matrix (rows become columns and vice versa)
void transposeMatrix(int rows, int cols, int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    // Switch the row and column indices to transpose the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j]; // Transposing by swapping indices
        }
    }
}

// Main function where program execution starts
int main() {
    int rows, cols; // Matrix dimensions
    int A[SIZE][SIZE], B[SIZE][SIZE], result[SIZE][SIZE]; // Matrices for operations
    int choice; // Variable to store user's menu choice

    // Prompt user to enter matrix dimensions
    printf("Enter the number of rows and columns (max %d): ", SIZE);
    scanf("%d %d", &rows, &cols);

    // Get matrix A elements from the user
    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }

    // Get matrix B elements from the user
    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &B[i][j]);
        }
    }

    // Display the menu and handle user input in a loop
    do {
        printf("\nMenu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Call function to add matrices A and B
                addMatrices(rows, cols, A, B, result);
                printf("Result of Addition:\n");
                // Display the result of the addition
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 2:
                // Call function to subtract matrix B from A
                subtractMatrices(rows, cols, A, B, result);
                printf("Result of Subtraction:\n");
                // Display the result of the subtraction
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                // Call function to transpose matrix A
                transposeMatrix(rows, cols, A, result);
                printf("Transpose of Matrix A:\n");
                // Display the transposed matrix A
                for (int i = 0; i < cols; i++) {
                    for (int j = 0; j < rows; j++) {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 4:
                // Call function to transpose matrix B
                transposeMatrix(rows, cols, B, result);
                printf("Transpose of Matrix B:\n");
                // Display the transposed matrix B
                for (int i = 0; i < cols; i++) {
                    for (int j = 0; j < rows; j++) {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 5:
                // Exit the program
                printf("Exiting...\n");
                break;

            default:
                // Handle invalid menu choices
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5); // Repeat the menu until the user chooses to exit

    return 0; // End of program
}
