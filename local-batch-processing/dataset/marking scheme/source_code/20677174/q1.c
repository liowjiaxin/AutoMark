#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int row; // Number of rows of the matrix
    int col; // Number of columns of the matrix
    int * matrix;
} matrix2D;


int validateDimension (int dimension) {
    // Max size is 10 x 10 so dimension is <= 10
    // Dimension also cannot be < 1
    return dimension >= 1 && dimension <= 10; 
}

// Function to print the matrix out
void printMatrices (matrix2D m) {
    int * ptr; // Temp pointer
    for (int i = 0; i < m.row; ++i) {
        ptr = m.matrix + (i * m.col); // Make temp ptr point to each ROW during each entry into the loop
        for (int j = 0; j < m.col; ++j) {
            printf("%d ", ptr[j]); // Make temp ptr point to elements in each COL in this loop
        }
        printf("\n");
    }
}

// Add two matrices
void addMatrices(matrix2D mA, matrix2D mB) {
    if ((mA.row != mB.row) || (mA.col != mB.col)) {
        printf("The two matrices have different sizes. Unable to add\n");
        return;
    }
    int resultVals[mA.row][mA.col];
    int * ptrA; // Temp pointer used for matrix A
    int * ptrB; // Temp pointer used for matrix B
    matrix2D result; // Result matrix
    result.row = mA.row;
    result.col = mA.col;
    for (int i = 0; i < mA.row; ++i) {
        ptrA = mA.matrix + (i * mA.col); // Make ptrA point to each ROW during each entry into the loop
        ptrB = mB.matrix + (i * mB.col); // Make ptrB point to each ROW during each entry into the loop
        for (int j = 0; j < mB.col; ++j) {
            resultVals[i][j] = ptrA[j] + ptrB[j];
        }
    }
    result.matrix = *resultVals;
    printf("Result of Matrix A + Matrix B:\n");
    printMatrices(result);
}

void subtractMatrices(matrix2D mA, matrix2D mB) {
    if ((mA.row != mB.row) || (mA.col != mB.col)) {
        printf("The two matrices have different sizes. Unable to subtract\n");
        return;
    }
    int resultVals[mA.row][mA.col]; // 2D array used to hold the result matrix
    int * ptrA; // Temp pointer used for matrix A
    int * ptrB; // Temp pointer used for matrix B
    matrix2D result; // Result matrix
    result.row = mA.row;
    result.col = mA.col;
    for (int i = 0; i < mA.row; ++i) {
        ptrA = mA.matrix + (i * mA.col); // Make ptrA point to each ROW during each entry into the loop
        ptrB = mB.matrix + (i * mB.col); // Make ptrB point to each ROW during each entry into the loop
        for (int j = 0; j < mA.col; ++j) {
            // a - b = a + (-b) = a + (-1 * b)
            // Therefore, multiply the element in matrix B by -1 before adding it to element in matrix A
            resultVals[i][j] = ptrA[j] + (ptrB[j] * -1); 
        }
    }
    result.matrix = *resultVals;
    printf("Result of Matrix A - Matrix B:\n");
    printMatrices(result);
}

// Transpose a matrix
matrix2D transposeMatrices(matrix2D m) {
    int temp; // Store temp values
    int * ptr = m.matrix; // temp ptr
    // Transpose operation swaps number of rows and number of columns of the matrix
    int resultVals[m.col][m.row]; // 2D array used to hold the values of the result matrix
    // Read horrizontally, write vertically
    for (int i = 0; i < m.row; ++i) {
        ptr = m.matrix + (i * m.col); // Make ptr point to each ROW during each entry into the loop
        for (int j = 0; j < m.col; ++j) {
            resultVals[j][i] = ptr[j];
        }
    }
    temp = m.row;
    m.row = m.col;
    m.col = temp;
    int * newM = malloc(sizeof(int) * m.col * m.row);
    memcpy(newM, resultVals, sizeof(resultVals)); // Copy the transposed matrix to the dynamic memory allocated to store it
    free(m.matrix); // Free the dynamic memory allocated to store the old matrix to prevent memory leaking
    m.matrix = newM;
    printMatrices(m);
    return m;
}



int main(void){
    // Declare a vairable to store the user's choice for the operation to be performed
    int choice;
    // Create two structs to hold the matrices
    matrix2D matrixA;
    matrix2D matrixB;
    // Prompt user input for the dimensions of matrix A and validate it
    // Loop until the user input valid dimensions for matrix A
    while (1) {
        printf("Enter dimensions for Matrix A (rows and columns): ");
        scanf("%d %d", &matrixA.row, &matrixA.col);
        if (!validateDimension(matrixA.row) || !validateDimension(matrixA.col)) {
            printf("Invalid input. Please enter valid matrix dimensions\n");
        } else {
            break;
        }
    }
    // Create the matrix A (use 2D array as the data structure to hold the values of the matrix)
    int arr1[matrixA.row][matrixA.col];
    // Prompt user input to populate the matrix
    printf("Enter elements for matrix A: \n");
    for (int i = 0; i < matrixA.row; ++i) {
        for (int j = 0; j < matrixA.col; ++j) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &arr1[i][j]);
        }
    }

    int * mA = malloc(sizeof(int) * matrixA.row * matrixA.col);
    memcpy(mA, arr1, sizeof(arr1));
    matrixA.matrix = mA;
    // Prompt user input for the dimensions of matrix B and validate it
    // Loop until the user input valid dimensions for matrix B
    while (1) {
        printf("Enter dimensions for Matrix B (rows and columns): ");
        scanf("%d %d", &matrixB.row, &matrixB.col);
        if (!validateDimension(matrixB.row) || !validateDimension(matrixB.col)) {
            printf("Invalid input. Please enter valid matrix dimensions\n");
        } else {
            break;
        }
    }
    // Create the matrix B (use 2D array as the data structure to hold the values of the matrix)
    int arr2[matrixB.row][matrixB.col];
    // Prompt user input to populate the matrix
    printf("Enter elements for matrix B: \n");
    for (int i = 0; i < matrixB.row; ++i) {
        for (int j = 0; j < matrixB.col; ++j) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &arr2[i][j]);
        }
    }

    int * mB = malloc(sizeof(int) * matrixB.row * matrixB.col);
    memcpy(mB, arr2, sizeof(arr2));
    matrixB.matrix = mB;

    // Display the menu and allow the user to select operations based on different choices
    // Loop until the user chooses to exit
    do {
        printf("Matrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMatrices(matrixA, matrixB);
                break;
            case 2:
                subtractMatrices(matrixA, matrixB);
                break;
            case 3:
                printf("Transpose of Matrix A:\n");
                matrixA = transposeMatrices(matrixA);
                break;
            case 4:
                printf("Transpose of Matrix B:\n");
                matrixB = transposeMatrices(matrixB);
                break;
            case 5:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice. Please enter again!\n");
        }
    } while (choice != 5);
    
    return 0;
}
