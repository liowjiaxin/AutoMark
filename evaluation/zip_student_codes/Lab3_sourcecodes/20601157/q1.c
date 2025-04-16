#include <stdio.h>

int AddMatrices(int matrixA[20][20], int matrixB[20][20], int result[20][20], int matrixrowA, int matrixcolumnA, int matrixrowB, int matrixcolumnB) {

    if (matrixrowA != matrixrowB || matrixcolumnA != matrixcolumnB){
        return -1;
    }

    for (int i=0;i<matrixrowA;++i){
        for (int j=0;j<matrixcolumnA;++j){
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return 0;
}

int SubtractMatrices(int matrixA[20][20], int matrixB[20][20], int result[20][20], int matrixrowA, int matrixcolumnA, int matrixrowB, int matrixcolumnB) {

    if (matrixrowA != matrixrowB || matrixcolumnA != matrixcolumnB){
        return -1;
    }

    for (int i=0;i<matrixrowA;++i){
        for (int j=0;j<matrixcolumnA;++j){
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    return 0;
}

void TransposeMatrixA(int matrixA[20][20], int result[20][20], int matrixrowA, int matrixcolumnA) {

    // transpose = swap row and column of elements in matrix 

    for (int i=0 ; i<matrixrowA; ++i){
        for (int j=0; j<matrixcolumnA;++j){
            result[j][i]=matrixA[i][j];
        }
    }

}

void TransposeMatrixB(int matrixB[20][20], int result[20][20], int matrixrowB, int matrixcolumnB) {

    // transpose = swap row and column of elements in matrix 

    for (int i=0 ; i<matrixrowB; ++i){
        for (int j=0; j<matrixcolumnB;++j){
            result[j][i]=matrixB[i][j];
        }
    }

}



int main(){

    int choice;
    int matrixrowA;
    int matrixcolumnA;
    int matrixA[20][20];
    int matrixrowB;
    int matrixcolumnB;
    int matrixB[20][20];
    int result[20][20];

    while (1){

        printf("Enter dimensions for Matrix A (rows and columns), maximum dimension is 10x10 :");
        scanf("%d %d", &matrixrowA, &matrixcolumnA);

        if (matrixrowA > 10 || matrixcolumnA > 10){
            printf("Matrix dimensions cannot exceed 10x10.\n");
            continue;
        }

        for (int i = 0; i < matrixrowA; ++i){
            for (int j = 0; j < matrixcolumnA; ++j){
                printf("Element [%d][%d]:", i + 1, j + 1);
                scanf("%d", &matrixA[i][j]);
            }
        }

        printf("Enter dimensions for Matrix B (rows and columns), maximum dimension is 10x10 :");
        scanf("%d %d", &matrixrowB, &matrixcolumnB);

        if (matrixrowB > 10 || matrixcolumnB > 10){
            printf("Matrix dimensions cannot exceed 10x10.\n");
            continue;
        }

        for (int i = 0; i < matrixrowB; ++i){
            for (int j = 0; j < matrixcolumnB; ++j){
                printf("Element [%d][%d]:", i + 1, j + 1);
                scanf("%d", &matrixB[i][j]);
            }
        }

        break;
    }

    while (1){

        printf("\n");
        printf("Matrix Operations Menu:\n");
        printf("\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {

        case 1: // addition

            if (AddMatrices(matrixA, matrixB, result, matrixrowA, matrixcolumnA, matrixrowB, matrixcolumnB) == -1){
                printf("Matrix dimensions do not match for addition to be performed.\n");
            } 
            else {
                printf("Result of Matrix A + Matrix B:\n");
                for (int i = 0; i < matrixrowA; i++) {
                    for (int j = 0; j < matrixcolumnA; j++) {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
            }

            break;

        case 2: // subtraction 

            if (SubtractMatrices(matrixA, matrixB, result, matrixrowA, matrixcolumnA, matrixrowB, matrixcolumnB) == -1){
                printf("Matrix dimensions do not match for addition to be performed.\n");
            } 
            else {
                printf("Result of Matrix A - Matrix B:\n");
                for (int i = 0; i < matrixrowA; i++) { 
                    for (int j = 0; j < matrixcolumnA; j++) { 
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
            }
            break;

        case 3: // transpose matrix A

            TransposeMatrixA(matrixA,result,matrixrowA,matrixcolumnA);
           
            printf("Transpose of Matrix A :\n");
            for (int i = 0; i < matrixcolumnA; i++) { // transposed row = original column
                    for (int j = 0; j < matrixrowA; j++) {  // transposed column = original row
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }

            break;

        case 4: // transpose matrix B
            
            TransposeMatrixB(matrixB,result,matrixrowB,matrixcolumnB);
           
            printf("Transpose of Matrix B :\n");
            for (int i = 0; i < matrixcolumnB; i++) { // transposed row = original column
                    for (int j = 0; j < matrixrowB; j++) {  // transposed column = original row
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }

            break;

        case 5: // exit program

            printf("Exiting... \n");
            return 0;

        default: // invalid input

            printf("Invalid choice entered. Please try again.\n");
            break;
        }
    }
    return 0;
}


    
        