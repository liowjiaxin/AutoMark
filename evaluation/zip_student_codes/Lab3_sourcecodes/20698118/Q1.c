#include <stdio.h>
#define MAX_SIZE 10

//function prototypes
void matrixInput(int row, int column, int matrix[row][column]);
void addMatrix(int row, int column, int MatrixA[row][column], int MatrixB[row][column], int result[row][column]);
void subtractMatrix(int row, int column, int MatrixA[row][column], int MatrixB[row][column], int result[row][column]);
void displayMatrix(int row, int column, int matrix[row][column]);
void transposeMatrix(int row, int column, int matrix[row][column], int result[column][row]);

int main(){
    //variable declarations
    int rowA, columnA, rowB, columnB;
    int choice = 0;

    //while loop to ensure proper dimensions are inputted
    while(1){
    printf("Enter the number of rows in Matrix A: ");
    scanf("%d", &rowA);
    printf("Enter the number of columns in Matrix A: ");
    scanf("%d", &columnA);

    if (rowA > MAX_SIZE || columnA > MAX_SIZE) { //checking the dimensions
        printf("The maximum size for the matrices is %dx%d!\n", MAX_SIZE, MAX_SIZE);
    }else{
        break;
    }
    }
    int MatrixA[rowA][columnA]; //initialising matrix

    //while loop to ensure proper dimensions are inputted
    while(1){
    printf("Enter the number of rows in Matrix B: ");
    scanf("%d", &rowB);
    printf("Enter the number of columns in Matrix B: ");
    scanf("%d", &columnB);

    if (rowB > MAX_SIZE || columnB > MAX_SIZE) {//checking the dimensions
        printf("The maximum size for the matrices is %dx%d!\n", MAX_SIZE, MAX_SIZE);
    }else{
        break;
    }
    }
    int MatrixB[rowB][columnB]; //initialising matrix

    printf("Enter the values for Matrix A\n"); //getting the values of the matrices
    matrixInput(rowA, columnA, MatrixA); //calling functions

    printf("Enter the values for Matrix B\n");
    matrixInput(rowB, columnB, MatrixB);

    int loop = 1;
    while(loop){ //loop infinitely to allow user to do multiple operations before exiting
        printf("===========================================\n");
        printf("\tMATRIX OPERATION MENU\n");
        printf("===========================================\n");
        printf("1. Add Matrices\n2. Subtract Matrices\n3. Transpose Matrix A\n4. Transpose Matrix B\n5. Exit\n");
        printf("Enter your choice: "); //user inputs
        scanf("%d", &choice);

        switch(choice){
            case 1:
            if(rowA != rowB || columnA != columnB){
                printf("Matrices must have same size to be added\n"); //checking if matrix dimensions are equal
                break;
            }else{
                int resultMatrix[rowA][columnA]; //calculating the addition of matrix A and B
                addMatrix(rowA, columnA, MatrixA, MatrixB, resultMatrix);
                displayMatrix(rowA, columnA, resultMatrix); //output
            break;
            }

            case 2:
            if(rowA != rowB || columnA != columnB){
                printf("Matrices must have same size to be subtracted\n"); //checking if matrices have same dimensions
                break;
            }else{
                int resultMatrix[rowA][columnA]; //calculating the difference between matrix A and B
                subtractMatrix(rowA, columnA, MatrixA, MatrixB, resultMatrix);
                displayMatrix(rowA, columnA, resultMatrix); //output
                break;
            }

            case 3: {
            int resultMatrix[columnA][rowA]; //transposing matrix A
            transposeMatrix(rowA, columnA, MatrixA, resultMatrix);
            printf("Transpose of Matrix A: \n");
            displayMatrix(columnA, rowA, resultMatrix);
            break;
            }

            case 4: {
            int resultMatrix[columnB][rowB]; //transposing matrix B
            transposeMatrix(rowB, columnB, MatrixB, resultMatrix);
            printf("Transpose of Matrix B: \n");
            displayMatrix(columnB, rowB, resultMatrix);
            break;
            }

            case 5: //exit
            printf("Exiting...");
            loop = 0;
            break;

            default: //in case user enters unsupported values
            printf("Please enter a valid input.");
            break;
        }
    }
}

//function for matrix input
void matrixInput(int row, int column, int matrix[row][column]){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){ //traverses through row and column
            printf("Enter element [%d][%d]: ", i + 1, j + 1); //getting user input
            scanf("%d", &matrix[i][j]); //saving user input into matrix
        }
    }
}

//function to add matrix A and B
void addMatrix(int row, int column, int MatrixA[row][column], int MatrixB[row][column], int result[row][column]){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){ //traversing through row and column
            result[i][j] = MatrixA[i][j] + MatrixB[i][j]; //finding the result of addition and putting it into the corresponding row and column for the result matrix
        }
    }
}

//function to subract 2 matrices
void subtractMatrix(int row, int column, int MatrixA[row][column], int MatrixB[row][column], int result[row][column]){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){ //traversing through row and column
            result[i][j] = MatrixA[i][j] - MatrixB[i][j]; //finding the result of subtraction and putting it into the corresponding row and column for the result matrix
        }
    }
}

//function to display the matrix
void displayMatrix(int row, int column, int matrix[row][column]){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){ //traversing through row and column
            printf("%d\t", matrix[i][j]); // printing element
        }
        printf("\n"); //to go to next line after a column is done
    }
}

//function to transpose a matrix
void transposeMatrix(int row, int column, int matrix[row][column], int result[column][row]){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){ //traversing through row and column
            result[j][i] = matrix[i][j]; //changing i to j and j to i
        }
    }
}