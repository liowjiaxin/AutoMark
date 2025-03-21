#include <stdio.h>
#define N 10 // maximum allowed size of matrix

// Function adds A[][] and B[][] and stores the result in C[][]
void addMatrices (int A[][N], int B[][N], int C[][N]) {
    int i, j;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function subtract A[][] and B[][] and stores the result in C[][]
void subtractMatrices (int A[][N], int B[][N], int C[][N]) {
    int i, j;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to transpose Matrix A
void transposeMatrixA (int A[][N], int T[][N]) {
    int i, j;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            T[j][i] = A[i][j];
        }
    }
}

// Function to transpose Matrix B
void transposeMatrixB (int B[][N], int T[][N]) {
    int i, j;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            T[j][i] = B[i][j];
        }
    }
}

int main() {
    int A[N][N], B[N][N], C[N][N], T[N][N];
    int choice; 
    int i, j;
    
    // Input matrix A
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d\n", &i, &j);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Enter elements for Matrix A [%d][%d]:", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }
    
    // Input matrix B
    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d\n", &i, &j);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Enter elements for Matrix B [%d][%d]:", i + 1, j + 1);
            scanf("%d", &B[i][j]);
        }
    }
    
    printf("Matrix Operations Menu:\n");
    printf("1. Add Matrices\n");
    printf("2. Subtract Matrices\n");
    printf("3. Transpose Matrix A\n");
    printf("4. Transpose Matrix B\n");
    printf("5. Exit\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1: 
            addMatrices(A, B, C);
            printf("Result of Matrix A + Matrix B:\n");
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    printf("%d ", C[i][j]);
                }
                printf("\n");
            }
            break;
        
        case 2: 
            subtractMatrices(A, B, C);
            printf("Result of Matrix A - Matrix B:\n");
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    printf("%d ", C[i][j]);
                }
                printf("\n");
            }
            break;
            
        case 3: 
            transposeMatrixA(A, T);
            printf("Transpose of Matrix A:\n");
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    printf("%d ", T[i][j]);
                }
                printf("\n");
            }
            break;
        
        case 4: 
            transposeMatrixB(B, T);
            printf("Transpose of Matrix B:\n");
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    printf("%d ", T[i][j]);
                }
                printf("\n");
            }
            break;
        
        case 5:
            printf("Exiting...\n");
            break;
        
        default:
            printf("Invalid choice. Please try again");
    }

    return 0;
}