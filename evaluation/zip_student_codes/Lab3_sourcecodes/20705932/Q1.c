#include <stdio.h>

#define max 10

void inputTwoMatrices(int matrixA[max][max], int matrixB[max][max], int rowsA, int colsA, int rowsB, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            printf("Matrix A [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrixA[i][j]);
        }
    }
    printf("=====================================\n");

    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            printf("Matrix B [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrixB[i][j]);
        }
    }
 
}

void DisplayMatrix(int matrix[max][max], int rows, int cols) {
     printf("Matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void MatrixAdd(int matrix1[max][max], int matrix2[max][max], int FinalArray[max][max], int rows, int cols) { 

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            FinalArray[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

}

void MatrixSubtract(int matrix1[max][max], int matrix2[max][max], int FinalArray[max][max], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            FinalArray[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    } 
}

void MatrixTranspose(int matrixT[max][max], int FinalArray[max][max], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            FinalArray[j][i] = matrixT[i][j];
        }
    }
}


int main() {
    int A[max][max];
    int B[max][max];
    int result[max][max];
    int choice;
    int rowsA;
    int colsA;
    int rowsB;
    int colsB;

    printf("Enter Matrix A(rows and columns):\n");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter Matrix B(rows and columns):\n");
    scanf("%d %d", &rowsB, &colsB);

    inputTwoMatrices(A, B, rowsA, colsA, rowsB, colsB);
    DisplayMatrix(A, rowsA, colsA);
    DisplayMatrix(B, rowsB, colsB);


    do {
        printf("\nMenu:\n");
        printf("=========================\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (rowsA == rowsB && colsA == colsB) {
                    printf("Result of addition: \n");
                    MatrixAdd(A, B, result, rowsA, colsA);
                    DisplayMatrix(result, rowsA, colsA);
                        
                } 
                else {
                    printf("Cant Add. Matrices dimensions must match.\n");
                }
                break;
            case 2:
                if (rowsA == rowsB && colsA == colsB) {
                    printf("Result of subtraction: \n");
                    MatrixSubtract(A, B, result, rowsA, colsA);
                    DisplayMatrix(result, rowsB, colsB);

                } 
                else {
                    printf("Cant Subtract. Matrices dimensions must match.\n");
                }
                break;
            case 3:
                printf("Result of Transposing Matrix A: \n");
                MatrixTranspose(A, result, rowsA, colsA);
                DisplayMatrix(result, colsA, rowsA);
                break;
            case 4:
                printf("Result of Transposing Matrix B: \n");
                MatrixTranspose(B, result, rowsB, colsB);
                DisplayMatrix(result, colsB, rowsB);
                break;
            case 5:
                printf("Ending the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}



        
