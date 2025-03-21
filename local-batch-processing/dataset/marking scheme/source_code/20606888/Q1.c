#include <stdio.h>

// Function prototypes
void menu();
void addMatrices();
void substractMatrices();
void transposeMatrixA();
void transposeMatrixB();

int r, c, a[100][100], b[100][100], i, j, sum[100][100], minus[100][100], transpose[100][100];

int main() {
    // matrix A
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d%d", &r, &c);
    printf("\nEnter elements for Matrix A: \n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; ++j) {
            printf("Element [%d][%d]: ", i + 1, j+ 1);
            scanf("%d", &a[i][j]);
        }
    }
    // matrix B
    printf("\nEnter dimensions for Matrix B (rows and columns): ");
    scanf("%d%d", &r, &c);
    printf("\nEnter elements for Matrix B: \n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; ++j) {
            printf("Element [%d][%d]: ", i + 1, j+ 1);
            scanf("%d", &b[i][j]);
        }
    }

    menu();  // Display menu
    
    return 0;
}

// Menu
void menu() {
    int choice;
    do {
        printf("\nMatrix Operations Menu: \n");
        printf("1. Add Matrices\n");
        printf("2. Substract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMatrices();
                break;
            case 2:
                substractMatrices();
                break;
            case 3:
                transposeMatrixA();
                break;
            case 4:
                transposeMatrixB();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);
}

// Add matrices
void addMatrices() {
    // Add 
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++){
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    // Print results
    printf("\nResult of Matrix A + Matrix B: \n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d  ", sum[i][j]);
            if (j == c - 1) {
                printf("\n");
            }
        }
    }
}

// Substract matrices
void substractMatrices() {
    // Substract
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++){
            minus[i][j] = a[i][j] - b[i][j];
        }
    }

    // Print results
    printf("\nResult of Matrix A - Matrix B: \n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d  ", minus[i][j]);
            if (j == c - 1) {
                printf("\n");
            }
        }
    }
}

// Transpose Matrix A
void transposeMatrixA() {
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            transpose[j][i] = a[i][j];
        }
    }
    
    // Print results
    printf("\nTranspose of Matrix A:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j <c; j++) {
            printf("%d  ", transpose[i][j]);
            if (j == r - 1) {
                printf("\n");
            }
        }
    }
}

// Transpose Matrix B
void transposeMatrixB() {
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            transpose[j][i] = b[i][j];
        }
    }
    
    // Print results
    printf("\nTranspose of Matrix B:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j <c; j++) {
            printf("%d  ", transpose[i][j]);
            if (j == r - 1) {
                printf("\n");
            }
        }
    }
}