#include <stdio.h>

int main() {
    int rowA, columnA;
    printf("Enter dimensions for Matrix A (rows and column): ");
    scanf("%d %d", &rowA, &columnA);
    int matrixA[rowA][columnA];
    puts("Enter elements for Matrix A");
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < columnA; j++)
        {
            printf("Element [%d][%d]: ",i+1,j+1);
            scanf("%d", &matrixA[i][j]);
        }
    }

    int rowB, columnB;
    printf("Enter dimensions for Matrix B (rows and column): ");
    scanf("%d %d", &rowB, &columnB);
    int matrixB[rowB][columnB];
    puts("Enter elements for Matrix B");
    for (int i = 0; i < rowB; i++) {
        for (int j = 0; j < columnB; j++)
        {
            printf("Element [%d][%d]: ",i+1,j+1);
            scanf("%d", &matrixB[i][j]);
        }
    }

    while (1) {
        puts("Matrix Operation Menu: ");
        puts("1. Add Matrice");
        puts("2. Subract Matrices");
        puts("3. Transpose Matrix A");
        puts("4. Transpose Matrix B");
        puts("5. Exit");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
        case 1: //Add Matrix
            if (rowA != rowB || columnA != columnB){
                puts("Matrix of different sizes cannot add");
                break;
            }
            for (int i = 0; i < rowA; i++) {
                for (int j = 0; j < columnA; j++){
                    printf("%d ", matrixA[i][j] + matrixB[i][j]);
                }
                printf("\n");
            }
            puts("");
            break;

        case 2: //Subtract Matrix
            if (rowA != rowB || columnA != columnB){
                puts("Matrix of different sizes cannot subtract");
                break;
            }
            for (int i = 0; i < rowA; i++) {
                for (int j = 0; j < columnA; j++){
                    printf("%d ", matrixA[i][j] - matrixB[i][j]);
                }
                printf("\n");
            }    
            puts("");    
            break;

        case 3: //Transpose matrix A
            for (int j = 0; j < rowA; j++){
                for (int i = 0; i < columnA; i++) {
                    printf("%d ", matrixA[i][j]);
                }
                printf("\n");
            }    
            puts("");    
            break;

        case 4: //Transpose matrix B
            for (int j = 0; j < rowB; j++){
                for (int i = 0; i < columnB; i++) {
                    printf("%d ", matrixB[i][j]);
                }
                printf("\n");
            }    
            puts("");    
            break;

        case 5: 
            puts("Exiting...");
            return 0;
            break;

        default:
            puts("Please enter between number 1-5");
            break;
        }
    }
    
}