#include <stdio.h>
#include <stdlib.h>

// Define row and column and Matrix A and B globally
int **matrix_A;
int row_A, col_A;
int **matrix_B;
int row_B, col_B;

// Function to create matrix with given row and column
int **create_matrix(int row, int col) {
    // Create an array first
    int **matrix = malloc(sizeof(int*) * row);
    if (matrix == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    // Allocate n columns for each row
    for (int i = 0; i < row; i++) {
        matrix[i] = malloc(sizeof(int) * col);
        if (matrix[i] == NULL) {
            printf("Memory allocation failed\n");
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

// Function to delete all elements and the matrix
void delete_matrix(int **matrix, unsigned int row) {
    for (int i = 0; i < row; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to define matrix
void get_matrix_info() {
    // User input for matrix A
    while (1) {
        // Dimension for matrix A
        printf("Enter dimensions for Matrix A (rows and columns): ");
        if (scanf("%d %d", &row_A, &col_A) != 2 || row_A <= 0 || row_A > 10 || col_A <= 0 || col_A > 10) {
            printf("Invalid input (Maximum size: 10x10)\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        break;
    }

    // Create matrix A
    matrix_A = create_matrix(row_A, col_A);

    // Elements for matrix A
    printf("Enter elements for Matrix A: \n");
    for (int i = 0; i < row_A; i++) {
        for (int j = 0; j < col_A; j++) {
            while (1) {
                printf("Element [%d][%d]: ", i + 1, j + 1);
                if (scanf("%d", &matrix_A[i][j]) != 1) {
                    printf("Invalid input. Enter again\n");
                    while (getchar() != '\n'); // Clear input buffer
                } else {
                    break;
                }
            }
        }
    }


    // User input for matrix B
    while (1) {
        // Dimension for matrix B
        printf("Enter dimensions for Matrix B (rows and columns): ");
        if (scanf("%d %d", &row_B, &col_B) != 2 || row_B <= 0 || row_B > 10 || col_B <= 0 || col_B > 10) {
            printf("Invalid input (Maximum size: 10x10)\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        } else if (row_B != row_A || col_B != col_A) {      // Caution for different dimension with matrix A
            printf("\033[33mCaution! - The row or column of Matrix A and B are different!\033[0m\n");
            while (getchar() != '\n'); // Clear input buffer
        }
        break;
    }
    
    // Create matrix B
    matrix_B = create_matrix(row_B, col_B);

    // Elements for matrix B
    printf("Enter elements for Matrix B: \n");
    for (int i = 0; i < row_B; i++) {
        for (int j = 0; j < col_B; j++) {
            while (1) {
                printf("Element [%d][%d]: ", i + 1, j + 1);
                if (scanf("%d", &matrix_B[i][j]) != 1) {
                    printf("Invalid input. Enter again\n");
                    while (getchar() != '\n'); // Clear input buffer
                } else {
                    break;
                }
            }
            
        }
    }
}

// Function to display menu and get choice
int menu_get_choice() {
    int choice;
    while (1) {
        printf("\nMatrix Operations Menu: \n");
        printf("1. Add Matrices\n2. Subtract Matrices\n3.Transpose Matrix A\n4.Transpose Matrix B\n5.Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 5) {
            printf("Invalid input. Enter again\n");
            while (getchar() != '\n'); // Clear input buffer
        } else {
            break;
        }
    }
    return choice;
}

// Function to perform addition
void add_matrices(int **matrix_A, int row_A, int col_A, int **matrix_B, int row_B, int col_B) {
    // Check for dimensions
    if (row_A != row_B || col_A != col_B) {
        printf("Cannot add two matrices that have different dimension!\n");
        return;
    }
    // Define result matrix
    int **result = create_matrix(row_A, col_A);
    printf("Result of Matrix A + Matrix B: \n");
    // Add each elements
    for (int i = 0; i < row_A; i++) {
        for (int j = 0; j < col_B; j++) {
            result[i][j] = matrix_A[i][j] + matrix_B[i][j];
            printf("%d ", result[i][j]);
        }
        puts("");
    }
    // Free the result matrix
    delete_matrix(result, row_A);
}

// Function to perform subtraction
void sub_matrices(int **matrix_A, int row_A, int col_A, int **matrix_B, int row_B, int col_B) {
    // Check for dimensions
    if (row_A != row_B || col_A != col_B) {
        printf("Cannot subtract two matrices that have different dimension!\n");
        return;
    }
    // Define result matrix
    int **result = create_matrix(row_A, col_A);
    printf("Result of Matrix A - Matrix B: \n");
    // Subtract each elements
    for (int i = 0; i < row_A; i++) {
        for (int j = 0; j < col_B; j++) {
            result[i][j] = matrix_A[i][j] - matrix_B[i][j];
            printf("%d ", result[i][j]);
        }
        puts("");
    }
    // Free the result matrix
    delete_matrix(result, row_A);
}

// Function to perform transpose
void transpose(int **matrix, int row, int col, char name) {
    // Define result matrix
    int **result = create_matrix(col, row);     // Swap dimensions 
    if (result == NULL) { 
        printf("Memory allocation failed\n");
    } 
    printf("Transpose of Matrix %c:\n", name);
    for (int i = 0; i < row; i++) { 
        for (int j = 0; j < col; j++) { 
            result[j][i] = matrix[i][j]; // Swap row and column indices (can just printf the elements)
        }
    }
    // Printing the result
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("%d ", result[i][j]);
        }
        puts("");
    }
    // Free the result matrix
    delete_matrix(result, col);
}


int main(void) {
    get_matrix_info();
    int choice;
    while (1) {
        choice = menu_get_choice();
        switch (choice) {
            case 1:
                add_matrices(matrix_A, row_A, col_A, matrix_B, row_B, col_B);
                break;
            case 2 :
                sub_matrices(matrix_A, row_A, col_A, matrix_B, row_B, col_B);
                break;
            case 3 :
                transpose(matrix_A, row_A, col_A, 'A');
                break;
            case 4 :
                transpose(matrix_B, row_B, col_B, 'B');
                break;
            case 5 :
                printf("Exiting...");
                break;
            default:
                printf("Invalid input. Enter again.\n");
        }
        if (choice == 5) {
            // Free both matrix A and B
            delete_matrix(matrix_A, row_A);
            delete_matrix(matrix_B, row_B);
            break;  // Exit the loop
        }
    }
    return 0;
}