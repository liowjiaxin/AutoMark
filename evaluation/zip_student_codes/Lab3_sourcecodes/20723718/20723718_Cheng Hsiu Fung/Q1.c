#include <stdio.h>

// Function prototypes
void sumMatrices(size_t Row, size_t Col, int matrixA[Row][Col], int matrixB[Row][Col], int matrixSum[Row][Col]);
void subMatrices(size_t Row, size_t Col, int matrixA[Row][Col], int matrixB[Row][Col], int matrixDiff[Row][Col]);
void transpose(size_t Row, size_t Col, int transpose[Col][Row], int matrix[Row][Col]);
void printM(size_t Row, size_t Col, int matrix[Row][Col]);

// Function main
int main() {
    // Define and initialise dimensions
    size_t sizeARow = 0, sizeACol = 0, sizeBRow = 0, sizeBCol = 0;

    // Obtain matrix A
    printf("Enter dimensions for matrix A (rows and columns): ");
    scanf("%zu %zu", &sizeARow, &sizeACol);
    int matrixA[sizeARow][sizeACol];

    puts("Enter the elements for matrix A:");
    for (size_t i = 0; i < sizeARow; i++) {
        for (size_t j = 0; j < sizeACol; j++) {
            printf("Element [%zu][%zu]: ", i + 1, j + 1);
            scanf("%d", &matrixA[i][j]);
        }
    }

    // Obtain matrix B
    printf("Enter dimensions for matrix B (rows and columns): ");
    scanf("%zu %zu", &sizeBRow, &sizeBCol);
    int matrixB[sizeBRow][sizeBCol];

    puts("Enter the elements for matrix B:");
    for (size_t i = 0; i < sizeBRow; i++) {
        for (size_t j = 0; j < sizeBCol; j++) {
            printf("Element [%zu][%zu]: ", i + 1, j + 1);
            scanf("%d", &matrixB[i][j]);
        }
    }

    // Define and initialise more variables
    int choice = 0;
    int matrixAT[sizeACol][sizeARow];
    int matrixBT[sizeBCol][sizeBRow]; // Transposed matrices have inverted rows and columns and are defined accordingly
    int run = 1;
    int AorB = 0;

    // Run while 'run' is true
    while (run == 1) {
        // Display menu
        printf("\nMatrix operations menu:\n1. Print matrix\n2. Add matrices\n");
        printf("3. Subtract matrices\n4. Transpose matrix\n");
        printf("5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        // Use switch case
        switch(choice) {
            case 1:
                // Print matrix
                printf("\nWhich matrix do you want to print?\n1. Matrix A\n2. Matrix B\nEnter your choice: ");
                scanf("%d", &AorB);
                switch(AorB) {
                    case 1:
                        printM(sizeARow, sizeACol, matrixA);
                        break;
                    case 2:
                        printM(sizeBRow, sizeBCol, matrixB);
                        break;
                    default:
                        puts("Invalid option");
                        break;
                }
                break;
            case 2:
                // Ensure matrices are equal in dimensions
                if ((sizeARow != sizeBRow) || (sizeACol != sizeBCol)) {
                    printf("\nError: Please ensure the dimensions of both matrices are equal.\n");
                } else { // Sum matrices
                    int matrixSum[sizeARow][sizeACol]; // Summed matrix can be defined using only matrix A's dimensions as A's and B's dimensions are equal
                    sumMatrices(sizeARow, sizeACol, matrixA, matrixB, matrixSum);
                    puts("The sum of matrix A and matrix B is");
                    printM(sizeARow, sizeACol, matrixSum);
                }
                break;
            case 3:
                // Ensure matrices are equal in dimensions
                if ((sizeARow != sizeBRow) || (sizeACol != sizeBCol)) {
                    printf("\nError: Please ensure the dimensions of both matrices are equal.\n");
                } else { // Subtract matrix B from A
                    int matrixDiff[sizeARow][sizeACol]; 
                    subMatrices(sizeARow, sizeACol, matrixA, matrixB, matrixDiff);
                    puts("The subtraction of matrix B from matrix A is");
                    printM(sizeARow, sizeACol, matrixDiff);
                }
                break;
            case 4:
                printf("\nWhich matrix do you want to transpose?\n1. Matrix A\n2. Matrix B\nEnter your choice: ");
                scanf("%d", &AorB);
                // Nested switch case
                switch(AorB) {
                    case 1:
                        transpose(sizeARow, sizeACol, matrixAT, matrixA);
                        puts("The transpose of matrix A");
                        printM(sizeACol, sizeARow, matrixAT);
                        break;
                    case 2:
                        transpose(sizeBRow, sizeBCol, matrixBT, matrixB);
                        puts("The transpose of matrix B");
                        printM(sizeBCol, sizeBRow, matrixBT);                        
                        break;
                    default:
                        puts("\nInvalid option");
                        break;
                }
                break;
            case 5:
                run = 0;
                puts("\nExiting...");
                break;
            default:
                puts("\nInvalid option");
                break;
        }
        continue;
    }
}

// Function to sum matrices
void sumMatrices(size_t Row, size_t Col, int matrixA[Row][Col], int matrixB[Row][Col], int matrixSum[Row][Col]) {
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Col; j++) {
            matrixSum[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Function to subtract second matrix from first matrix
void subMatrices(size_t Row, size_t Col, int matrixA[Row][Col], int matrixB[Row][Col], int matrixDiff[Row][Col]) {
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Col; j++) {
            matrixDiff[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

// Function to transpose matrix
void transpose(size_t Row, size_t Col, int transpose[Col][Row], int matrix[Row][Col]) {
    for (size_t i = 0; i < Row; i++) {
        for (size_t j = 0; j < Col; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

// Function to print matrix
void printM(size_t Row, size_t Col, int matrix[Row][Col]) {
    puts("");
    for (size_t i = 0; i < Row; i++) {
        for (size_t j = 0; j < Col; j++) {
            printf("%d ", matrix[i][j]);
        }
        puts("");
    }
}