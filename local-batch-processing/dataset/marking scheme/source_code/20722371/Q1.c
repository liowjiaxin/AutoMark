#include <stdio.h>
#include <math.h>

int main() {
    int rows, columns, a[10][10], b[10][10], i, j, choice;
    int sum[10][10], diff[10][10], transposeda[10][10], transposedb[10][10];

    printf("Enter dimensions for Matrix A (rows and columns) : ");
    scanf("%d %d", &rows, &columns);

    // Input values for Matrix A
    printf("Enter elements for Matrix A : \n");
    for (i = 0; i < rows; ++i)
        for (j = 0;j<rows; ++j){
            printf("[%d][%d] : ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }

    // Input values for Matrix B
    printf("Enter elements for Matrix B : \n");
    for (i = 0; i < rows; ++i)
        for (j = 0; j < rows; ++j){
            printf("[%d][%d] : ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }

    // Display Matrix A and Matrix B
    printf("\nMatrix A : \n");
    for (i = 0; i < rows; ++i){
        for (j = 0; j < columns; ++j){
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B : \n");
    for (i = 0; i < rows; ++i){
        for (j = 0; j < columns; ++j){
            printf("%d  ", b[i][j]);
        }
        printf("\n");
    }

    // Main menu loop
    do{ 
        printf("\nMatrix Operations Menu : \n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice : ");
    
        if(scanf("%d",&choice) != 1 || choice < 1 || choice > 5){
            printf("Invalid choice. Please enter a number between 1 to 5.\n");
            continue;
        }

    // Processes
        // 1. Sum of two matrices
        for (i = 0; i < rows ; ++i){
            for(j = 0; j < columns ; ++j){
                sum[i][j] = a[i][j] + b[i][j];
            }
        }

        // 2. Difference of two matrices
        for (i = 0; i < rows ; ++i){
            for(j = 0; j < columns ; ++j){
                diff[i][j] = a[i][j] - b[i][j];
            }
        }

        // 3. Transposing Matrix A
        for (i = 0; i < rows ; ++i){
            for (j = 0 ; j < columns ; ++j){
                transposeda[j][i] = a[i][j]; // rows and columns are swapped 
            }
        }
    
        // 4. Transposing Matrix B
        for (i = 0; i < rows ; ++i){
            for (j = 0 ; j < columns ; ++j){
                transposedb[j][i] = b[i][j]; // rows and columns are swapped 
            }
        }

        switch (choice){
            case 1: 
            // 1. Add Matrices
                printf("Result of Matrix A + Matrix B : \n");
                for (i = 0; i < rows ; ++i){    
                    for (j = 0 ; j < columns ; ++j){
                        printf("%d  ", sum[i][j]);
                    }
                    printf("\n");
                }
            break;

            case 2:
            // 2. Subtract Matrices
                printf("Result of Matrix A - Matrix B : \n");
                for (i = 0; i < rows ; ++i){
                    for (j = 0 ; j < columns ; ++j){
                        printf("%d  ", diff[i][j]);
                    }
                    printf("\n");
                }
            break;

            case 3:
            // 3. Transpose Matrix A
                printf("Transpose of Matrix A : \n");
                for (i = 0; i < rows ; ++i){
                    for (j = 0 ; j < columns ; ++j){
                        printf("%d  ", transposeda[i][j]);
                    }
                    printf("\n");
                }
            break;

            case 4:
            // 4. Transpose Matrix B
                printf("Transpose of Matrix B : \n");
                for (i = 0; i < rows ; ++i){
                    for (j = 0 ; j < columns ; ++j){
                        printf("%d  ", transposedb[i][j]);
                    }
                    printf("\n");
                } 
            break;

            case 5:
            // 5. Exit
                printf("\nExiting...");
                return 0;
            break;
        }
    }
    while (choice != 5); // menu loops until user exits
    return 0;
}



