#include <stdio.h>
#define MAX_SIZE 10

void add_matrices(int row, int col, int A[][col], int B[][col]) {
    int result[row][col]; //declare another matrix of the same size for storing addition result 
    //use nested for loop to access each element in matrix A and matrix B
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    //nested for loop to display each element of the added matrix
    printf("Result of Matrix A + Matrix B:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d  ", result[i][j]);
        }
        printf("\n"); //print newline after each row
    }
    printf("\n"); //print newline after the whole matrix is displayed
}

void subtract_matrices(int row, int col, int A[][col], int B[][col]) {
    int result[row][col]; //declare another matrix of the same size for storing subtraction result
    //use nested for loop to access each element in matrix A and matrix B
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    //nested for loop to display each element of the subtracted matrix
    printf("Result of Matrix A - Matrix B:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d  ", result[i][j]);
        }
        printf("\n"); //print newline after each row
    }
    printf("\n"); //print newline after the whole matrix is displayed
}

void transpose_matrix(int row, int col, char name, int matrix[][col]) {
    int transpose[col][row]; //declare another matrix of the same size for storing transposed matrix

    // Computing the transpose
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Print the transpose
    printf("Transpose of Matrix %c:\n", name);
    for (int i = 0; i < col; i++) { // Loop over columns
        for (int j = 0; j < row; j++) {
            printf("%d  ", transpose[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int menu_choice;

    // Input for Matrix A
    int rowA, colA;
    do {
        printf("Enter dimensions for Matrix A (rows and columns): ");
        scanf("%d %d", &rowA, &colA);
        getchar(); //consume newline character

        //check whether row and col inputted are valid
        if (rowA <= 0 || rowA > MAX_SIZE || colA <= 0 || colA > MAX_SIZE) {
            printf("Invalid dimension. Maximum size: 10x10. Minimum size: 1x1\n");
        }
    } while (rowA <= 0 || rowA > MAX_SIZE || colA <= 0 || colA > MAX_SIZE); //if invalid, keep asking user to input until it is valid

    int matrixA[rowA][colA]; //declare matrixA of the size inputted by user
    printf("Enter elements for Matrix A:\n");
    //scan each element of Matrix A one by one using nested for loop
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colA; j++) {
            printf("Element[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrixA[i][j]);
        }
    }

    // Input for Matrix B
    int rowB, colB;
    do {
        printf("Enter dimensions for Matrix B (rows and columns): ");
        scanf("%d %d", &rowB, &colB);
        getchar(); //consume newline character

        //check whether row and col inputted are valid
        if (rowB <= 0 || rowB > MAX_SIZE || colB <= 0 || colB > MAX_SIZE) {
            printf("Invalid dimension. Maximum size: 10x10. Minimum size: 1x1\n");
        }
    } while (rowB <= 0 || rowB > MAX_SIZE || colB <= 0 || colB > MAX_SIZE); //if invalid, keep asking user to input until it is valid

    int matrixB[rowB][colB]; //declare matrixB of the size inputted by user
    printf("Enter elements for Matrix B:\n");
    //scan each element of Matrix B one by one using nested for loop
    for (int i = 0; i < rowB; i++) {
        for (int j = 0; j < colB; j++) {
            printf("Element[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrixB[i][j]);
        }
    }

    do {
        //display menu for at least once
        printf("********* Matrix Operation Menu *********\n");
        printf("\t1. Add Matrices\n");
        printf("\t2. Subtract Matrices\n");
        printf("\t3. Transpose Matrix A\n");
        printf("\t4. Transpose Matrix B\n");
        printf("\t5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &menu_choice);
        getchar(); //consume newline character

        switch (menu_choice) {
            case 1:
                //check dimensions of matrices before addition
                if (rowA == rowB && colA == colB) {
                    add_matrices(rowA, colA, matrixA, matrixB);
                } else {
                    printf("Matrix A and Matrix B are not of the same dimension.\nAddition cannot be performed.\n\n");
                }
                break;

            case 2:
                //check dimensions of matrices before subtraction
                if (rowA == rowB && colA == colB) {
                    subtract_matrices(rowA, colA, matrixA, matrixB);
                } else {
                    printf("Matrix A and Matrix B are not of the same dimension.\nSubtraction cannot be performed.\n\n");
                }
                break;

            case 3:
                transpose_matrix(rowA, colA, 'A', matrixA);
                break;

            case 4:
                transpose_matrix(rowB, colB, 'B', matrixB);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (menu_choice != 5); //loop back to display menu while user doesn't choose to exit

    return 0;
}
