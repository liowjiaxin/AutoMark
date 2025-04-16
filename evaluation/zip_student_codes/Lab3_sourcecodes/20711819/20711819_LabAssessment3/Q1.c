#include <stdio.h>
#include <stdlib.h>

// give int[][] a name "matrix" for easir recognition
typedef int **matrix;
// typedef size as int for easier reference
typedef int size;
// typedef for operation type cause why not
typedef int operationType;
// typedef for sentient check CAUSE WHY NOT
typedef int sentientType;

enum EnumOperationType{
    ADDITION = 1,
    SUBTRACTION = -1
};

enum EnumSentientType{
    CONTINUE = 1,
    STOP = 0
};

// function to print the matrix
void uwuPrintMatrix(matrix thisMatrix){
    size row, column;

    // record the size of row and column of ua matrix
    row = sizeof(thisMatrix) / sizeof(size);
    column = sizeof(thisMatrix[0]) / sizeof(size);

    // loop and print
    for (size i = 0; i < row; i++){
        for (size j = 0; j < column; j++){
            printf("%d ", thisMatrix[i][j]);
        }
        printf("\n");
    }
}

// function to create and return a pointer to matrix
matrix createMatrix(char *matrixName){
    size row = 1, column = 1; // variables for the row and column of matrix
    printf("uwu Enter the dimensions for Matrix %s (row, column): ", matrixName); // prompt the user to enter the row and column
    // loop scanf until user enter a valid row and column
    for(scanf("%d %d", &row, &column); (row < 1 || row > 10) || (column < 1 || column > 10) ; scanf("%d %d", &row, &column)){
        printf("Invalid row/column input, pwease try again uwu.\n(maximum row/column: 10; minimum row/column: 1)\n\n");
        printf("uwu Enter the dimensions for Matrix %s: ", matrixName);
    }

    // create a new matrix
    matrix uwuNewMatrix = malloc(sizeof(matrix));
    // loop and prompt the user to input elements
    for (size i = 0; i < row; i++){
        // create a placeholder int[] for recording the element in row i
        int *thisRow = malloc(sizeof(int) * column);
        for (size j = 0; j < column; j++){
            // read input element from user
            printf("Element[%d][%d]: ", i+1, j+1);
            scanf("%d", &thisRow[j]);
        }
        // assign the row to the matrix
        uwuNewMatrix[i] = thisRow;
    }

    return uwuNewMatrix;
}

// function to add 2 matrix (A + B) or subtract (A - B)
matrix uwuAddOrSubMatrix(matrix A, matrix B, operationType operation){
    size ARow, AColumn, BRow, BColumn;

    // record the size of row and column of A & B
    ARow = sizeof(A) / sizeof(size);
    AColumn = sizeof(A[0]) / sizeof(size);
    BRow = sizeof(B) / sizeof(size);
    BColumn = sizeof(B[0]) / sizeof(size);

    // cannot add or subtract the two matrices if their size are not the same
    if (ARow != AColumn || BRow != BColumn){
        printf("Unable to add or subtract matrices with different size of row/column :<\n");
        printf("Size of first matrix: %d x %d\n", ARow, AColumn);
        printf("Size of second matrix: %d x %d\n", BRow, BColumn);
        return NULL;
    }else{
        // create new matrix to return
        matrix uwuNewMatrix = malloc(sizeof(matrix));
        for (size i = 0; i < ARow; i++){
            // placeholder int[] to store the current row
            int *thisRow = malloc(sizeof(int) * AColumn);
            for (size j = 0; j < BRow; j++){
                // add the values together and store to the new row; * operation because if subtraction, operation = -1
                // and A - B == A + (B*-1)
                thisRow[j] = A[i][j] + (B[i][j] * operation);
            }
            // add the new row into the new matrix
            uwuNewMatrix[i] = thisRow;
        }
        printf("Result of Matrix A %c Matrix B:\n", (operation ? '+' : '-'));
        uwuPrintMatrix(uwuNewMatrix);
        // return the matrix in case it needs to be use again
        return uwuNewMatrix;
    }
}

// function to return transpose matrix
matrix uwuTransposeMatrix(matrix thisMatrix){
    size row, column;

    // record the size of row and column of ua matrix
    row = sizeof(thisMatrix) / sizeof(size);
    column = sizeof(thisMatrix[0]) / sizeof(size);

    // create new matrix to return uwu
    matrix uwuNewMatrix = malloc(sizeof(matrix));

    for (size i = 0; i < column; i++){
        // create a int[] row placeholder
        int *thisRow = malloc(sizeof(int) * row);
        for (size j = 0; j < row; j++){
            thisRow[j] = thisMatrix[j][i];
        }
        // add the new row
        uwuNewMatrix[i] = thisRow;
    }
    uwuPrintMatrix(uwuNewMatrix);
    // return the matrix in case it needs to be use again
    return uwuNewMatrix;
}

int main(){
    matrix A, B;
    A = createMatrix("A"); // create first matrix
    B = createMatrix("B"); // create second matrix
    sentientType sentient = CONTINUE; // sentient check
    int choice = 0;
    while(sentient){
        choice = 0; // choice = 0
        // print options
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        // repeat until valid choice
        while (choice < 1 || choice > 5){
            printf("Invalid choice, please try again.\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
        }
        // perform operation base on choice
        switch(choice){
            case 1:
                uwuAddOrSubMatrix(A, B, ADDITION);
                break;
            case 2:
                uwuAddOrSubMatrix(A, B, SUBTRACTION);
                break;
            case 3:
                uwuTransposeMatrix(A);
                break;
            case 4:
                uwuTransposeMatrix(B);
                break;
            case 5:
                printf("Exiting... uwu\n");
                sentient = STOP;
                break;
        }
    }
}