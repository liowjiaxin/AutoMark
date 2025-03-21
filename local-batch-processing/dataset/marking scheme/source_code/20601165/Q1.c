#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10   // maximum size 10 x 10
#define MIN_SIZE 1    // cannot be less than 0

int main () {
    int matrixRowA, matrixColumnA;   // declared to hold inputted rows and columns for matrix A
    do {
        printf("Enter dimensions for Matrix A (rows and columns): ");   // prompt
        scanf("%d %d", &matrixRowA, &matrixColumnA);   // getting user input

        // Give an error if size is not between 1 and 10
        if (matrixRowA > MAX_SIZE || matrixColumnA > MAX_SIZE || matrixRowA < MIN_SIZE || matrixColumnA < MIN_SIZE) {
            printf("Please input a value for the rows and columns between 1 and 10.\n");
        }

    } while (matrixRowA > MAX_SIZE || matrixColumnA > MAX_SIZE || matrixRowA < MIN_SIZE || matrixColumnA < MIN_SIZE);

    int matrixA[matrixRowA][matrixColumnA];   // matrixA's values will be inputted by user

    printf("Enter elements for Matrix A:\n");
    for (int i = 0; i < matrixRowA; i++) {
        for (int j = 0; j < matrixColumnA; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrixA[i][j]);
        }
    }

    int matrixRowB, matrixColumnB;   // declared to hold inputted rows and columns for matrix B
    do {
        printf("Enter dimensions for Matrix B (rows and columns): ");   // prompt
        scanf("%d %d", &matrixRowB, &matrixColumnB);   // getting user input

        // Give an error if size is not between 1 and 10
        if (matrixRowB > MAX_SIZE || matrixColumnB > MAX_SIZE || matrixRowB < MIN_SIZE || matrixColumnB < MIN_SIZE) {
            printf("Please input a value for the rows and columns between 1 and 10.\n");
        }

    } while (matrixRowB > MAX_SIZE || matrixColumnB > MAX_SIZE || matrixRowB < MIN_SIZE || matrixColumnB < MIN_SIZE);

    int matrixB[matrixRowB][matrixColumnB];   // matrixB's values will be inputted by user

    printf("Enter elements for Matrix B:\n");
    for (int i = 0; i < matrixRowB; i++) {
        for (int j = 0; j < matrixColumnB; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrixB[i][j]);
        }
    }

    // Menu interface
    while (1) {
        int choice;
        int transposeA[matrixColumnA][matrixRowA];   // declared transpose A with flipped rows and columns
        int transposeB[matrixColumnB][matrixRowB];   // declared transpose B with flipped rows and columns

        printf("Matrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter you choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Result of Matrix A + Matrix B:\n");
                // Addition assuming matrixA and matrixB has similar rows and columns
                for (int i = 0; i < matrixRowA; i++) {
                    for (int j = 0; j < matrixColumnA; j++) {
                        int sum = matrixA[i][j] + matrixB[i][j];
                        printf("%d ", sum);
                    }
                    printf("\n");
                }

                printf("\n");
                break;
            case 2:
                printf("Result of Matrix A - Matrix B:\n");
                // Subtraction assuming matrixA and matrixB has similar rows and columns
                for (int i = 0; i < matrixRowA; i++) {
                    for (int j = 0; j < matrixColumnA; j++) {
                        int dif = matrixA[i][j] - matrixB[i][j];
                        printf("%d ", dif);
                    }
                    printf("\n");
                }

                printf("\n");
                break;
            case 3:
                // Swapping rows and columns
                for (int i = 0; i < matrixRowA; i++) {
                    for (int j = 0; j < matrixColumnA; j++) {
                        transposeA[j][i] = matrixA[i][j];
                    }
                }

                printf("Transpose of Matrix A:\n");

                // print the transpose of matrix A
                for (int i = 0; i < matrixColumnA; i++) {
                    for (int j = 0; j < matrixRowA; j++) {
                        printf("%d ", transposeA[i][j]);
                    }
                    printf("\n");
                }

                printf("\n");
                break;
            case 4:
                // Swapping rows and columns
                for (int i = 0; i < matrixRowB; i++) {
                    for (int j = 0; j < matrixColumnB; j++) {
                        transposeB[j][i] = matrixB[i][j];
                    }
                }

                printf("Transpose of Matrix B:\n");

                // print the transpose of matrix B
                for (int i = 0; i < matrixColumnB; i++) {
                    for (int j = 0; j < matrixRowB; j++) {
                        printf("%d ", transposeB[i][j]);
                    }
                    printf("\n");
                }

                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please pick a number between 1 and 5.\n");
                break;
        }
    }

    return 0;
}