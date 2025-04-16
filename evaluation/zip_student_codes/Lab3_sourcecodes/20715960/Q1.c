#include <stdio.h>

#define SIZE 10 //maximum size of matrices

//function to add matrices
void addMatrices(int rows, int cols, int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

//function to subtract matrices
void subtractMatrices(int rows, int cols, int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

//function to transpose a matrix
void transposeMatrix(int rows, int cols, int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];           //reverse the indices to transpose
        }
    }
}

//main function
int main() {
    int rows, cols; //matrix dimensions
    int A[SIZE][SIZE], B[SIZE][SIZE], result[SIZE][SIZE]; //matrices
    int choice; //user's menu choice

    printf("Enter the number of rows and columns (max %d): ", SIZE);           //to enter matrix dimensions
    scanf("%d %d", &rows, &cols);

    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < rows; i++) {                       //loop iterates over both rows and columns to populate matrix A
        for (int j = 0; j < cols; j++) {
        printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < rows; i++){                        //loop iterates over both rows and columns to populate matrix B
        for (int j = 0; j < cols; j++){
        printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &B[i][j]);
        }
    }
    

    do {                                                  //in a loop to ensure that menu repeats until user exits
        printf("\nMenu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {                                 //using switch-case to call respective function based on user input
            case 1:
                addMatrices(rows, cols, A, B, result);
                printf("Result of Addition:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 2:
                subtractMatrices(rows, cols, A, B, result);
                printf("Result of Subtraction:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                transposeMatrix(rows, cols, A, result);
                printf("Transpose of Matrix A:\n");
                for (int i = 0; i < cols; i++) {
                    for (int j = 0; j < rows; j++) {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 4:
                transposeMatrix(rows, cols, B, result);
                printf("Transpose of Matrix B:\n");
                for (int i = 0; i < cols; i++) {
                    for (int j = 0; j < rows; j++) {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);                                  //to exit if the user enters 5

    return 0;
}