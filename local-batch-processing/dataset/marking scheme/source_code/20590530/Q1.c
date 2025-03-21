#include <stdio.h>

#define MAX 10 //maximum size of an array

int main() {
    //Declaration of variables for dimensions
    int dimensionA;
    int dimensionB;
    int rowA, rowB, columnA, columnB;

    //array size limited by MAX
    int matrixA[MAX][MAX];
    int matrixB[MAX][MAX];

    //Declare variable for switch case
    int choice = 0;
    int result[MAX][MAX];

    //Prompt user to enter dimensions for Matrix A
    printf("\nEnter dimensions for Matrix A (rows and columns): ");
    if (scanf("%d %d", &rowA, &columnA) != 2) {
        printf("\nError: invalid input, program will be terminated\n");
        return 1;
    }

    //Prompt user to input elements for Matrix A after setting up dimensions
    printf("Enter Elements for Matrix A: \n");

    //Establish array (MatrixA) using inputs from user
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < columnA; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrixA[i][j]);
        }
    }

    //Prompt user to enter dimensions for Matrix B
    printf("\nEnter dimensions for Matrix B (rows and columns): ");
    if (scanf("%d %d", &rowB, &columnB) != 2) {
        printf("\nError: invalid input, program will be terminated\n");
        return 1;
    }

    //Prompt user to input elements for Matrix A after setting up dimensions
    printf("Enter Elements for Matrix B: \n");

    //Establish array (MatrixB) using inputs from user
    for (int i = 0; i < rowB; i++) {
        for (int j = 0; j < columnB; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrixB[i][j]);
        }
    }

    while (1) {
        //Prompt the user to choose options for calculation
        printf("\nMatrix Operations Menu: \n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting...\n");
            break;
        }

        switch (choice) {
            //create cases 
            case 1:
                //Addition of matrices
                printf("Result of Matrix A + Matrix B: \n");
                if (rowA == rowB && columnA == columnB) {
                    for (int i = 0; i < rowA; i++) {
                        for (int j = 0; j < columnA; j++) {
                            result[i][j] = matrixA[i][j] + matrixB[i][j];
                            printf("%d ", result[i][j]);
                        }
                        printf("\n"); //prints a new row for next set of operations
                    }
                } else {
                    //if the dimensions dont match
                    printf("dimensions for both matrices dont match.\n");
                }
                break;

            case 2:
                //Subtraction of matrices
                printf("Result of Matrix A - Matrix B: \n");
                if (rowA == rowB && columnA == columnB) {
                    for (int i = 0; i < rowA; i++) {
                        for (int j = 0; j < columnA; j++) {
                            result[i][j] = matrixA[i][j] - matrixB[i][j];
                            printf("%d ", result[i][j]);
                        }
                        printf("\n"); 
                    }
                } else {
                    //if the dimensions dont match
                    printf("dimensions for both matrices dont match.\n");
                }
                break;

            case 3:
                //Transpose Matrix A
                printf("Transpose of Matrix A: \n");
                for (int i = 0; i < columnA; i++) {
                    for (int j = 0; j < rowA; j++) {
                        result[i][j] = matrixA[j][i];
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 4:
                //Transpose Matrix B
                printf("Transpose of Matrix B: \n");
                for (int i = 0; i < columnB; i++) {
                    for (int j = 0; j < rowB; j++) {
                        result[i][j] = matrixB[j][i];
                        printf("%d ", result[i][j]);
                    }
                    printf("\n"); 
                }
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid Choice, please try again.\n");
        }
    }
    return 0;
}
