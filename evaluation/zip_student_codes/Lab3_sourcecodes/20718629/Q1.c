#include <stdio.h>

int main() {

    // Declare variables for matrix dimensions, arrays, and result storage
    int rowsA, columnsA, rowsB, columnsB;
    int arrA[50][50], arrB[50][50];  // Matrices A and B
    int choice;
    int sum[50][50], subtract[50][50], transposeA[50][50], transposeB[50][50];  // Result matrices for sum, subtraction, and transpose
    int i, j;

    // Input for Matrix A
    printf("Enter dimensions for Matrix A(rows and columns): ");
    scanf("%d %d", &rowsA, &columnsA);

    printf("Enter the element for Matrix A:\n");
    for (i = 1; i <= rowsA; i++) {  // Loop through each element of Matrix A
        for (j = 1; j <= columnsA; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arrA[i][j]);
        }
    }

    // Input for Matrix B
    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &columnsB);

    printf("Enter the element for Matrix B:\n");
    for (i = 1; i <= rowsB; i++) {  // Loop through each element of Matrix B
        for (j = 1; j <= columnsB; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arrB[i][j]);
        }
    }

    // Main menu for matrix operations
    do {
        printf("Matrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch case to handle the chosen matrix operation
        switch (choice) {
            // Add Matrices
            case 1: {
                // Check if matrices can be added (must have the same dimensions)
                if (rowsA == rowsB && columnsA == columnsB) {
                    for (i = 1; i <= rowsA; ++i) {  // Loop to add corresponding elements
                        for (j = 1; j <= columnsA; j++) {
                            sum[i][j] = arrA[i][j] + arrB[i][j];  // Sum of corresponding elements
                        }
                    }

                    printf("Result of Matrix A + Matrix B:\n");
                    for (i = 1; i <= rowsA; i++) {
                        for (j = 1; j <= columnsA; j++) {
                            printf("%d ", sum[i][j]);  // Print result matrix
                        }
                        printf("\n");
                    }
                    printf("\n");
                } else {
                    printf("Matrices dimensions must be the same for addition.\n");
                }
                break;
            }

            // Subtract Matrices
            case 2: {
                // Check if matrices can be subtracted (must have the same dimensions)
                if (rowsA == rowsB && columnsA == columnsB) {
                    for (i = 1; i <= rowsA; ++i) {  // Loop to subtract corresponding elements
                        for (j = 1; j <= columnsA; j++) {
                            subtract[i][j] = arrA[i][j] - arrB[i][j];  // Difference of corresponding elements
                        }
                    }

                    printf("Result of Matrix A - Matrix B:\n");
                    for (i = 1; i <= rowsA; i++) {
                        for (j = 1; j <= columnsA; j++) {
                            printf("%d ", subtract[i][j]);  // Print result matrix
                        }
                        printf("\n");
                    }
                    printf("\n");
                } else {
                    printf("Matrices dimensions must be the same for subtraction.\n");
                }
                break;
            }

            // Transpose of Matrix A
            case 3: {
                printf("Transpose of Matrix A:\n");
                for (i = 1; i <= rowsA; i++) {  // Loop to calculate transpose of Matrix A
                    for (j = 1; j <= columnsA; j++) {
                        transposeA[j][i] = arrA[i][j];  // Swap rows and columns for transpose
                    }
                }

                for (i = 1; i <= columnsA; i++) {  // Print the transposed matrix
                    for (j = 1; j <= rowsA; j++) {
                        printf("%d ", transposeA[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
                break;
            }

            // Transpose of Matrix B
            case 4: {
                printf("Transpose of Matrix B:\n");
                for (i = 1; i <= rowsB; i++) {  // Loop to calculate transpose of Matrix B
                    for (j = 1; j <= columnsB; j++) {
                        transposeB[j][i] = arrB[i][j];  // Swap rows and columns for transpose
                    }
                }

                for (i = 1; i <= columnsB; i++) {  // Print the transposed matrix
                    for (j = 1; j <= rowsB; j++) {
                        printf("%d ", transposeB[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
                break;
            }

            // Exit the program
            case 5: {
                printf("Exiting...\n");
                break;
            }

            // Invalid choice handling
            default: {
                printf("Invalid choice! Please try again.\n");
                printf("\n");
            }
        }
    } while (choice != 5);  // Continue until the user chooses to exit

    return 0;
}
