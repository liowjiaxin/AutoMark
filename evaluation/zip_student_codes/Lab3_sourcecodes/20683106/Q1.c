#include <stdio.h>

// Function headers for the initializing matrices and 3 operations to be performed on matrices.
void validate(int *row, int *col);
void populateMatrix(int rows, int cols, int arr[rows][cols]);
void Addition(int row1, int row2, int col1, int col2, int matA[row1][col1], int matB[row2][col2]);
void Subtraction(int row1, int row2, int col1, int col2, int matA[row1][col1], int matB[row2][col2]);
void Transpose(int row, int col, int arr[row][col]);

// Function to validate range of matrix dimensions, ensuring it is within 1x1 to 10x10.
// Variables row and col are passed as pointers to directly change the values via the function.
void validate(int *row, int *col){
    while(*row<1 || *row>10){
        printf("Dimension for row is out of range. Please re-enter row:\n");
        scanf("%d", row);
    }
    while(*col<1 || *col>10){
        printf("Dimension for column is out of range. Please re-enter column:\n");
        scanf("%d", col);
    }
}

// Function to populate matrix with values provided by user.
// Validates if any non integer values are entered. If yes, prompt for re-input.
void populateMatrix(int rows, int cols, int arr[rows][cols]){
    int element;

    for(int x=0;x<rows;x++){
        for(int y=0;y<cols;y++){
            while (1){ // Infinite loop to accomodate validation
                printf("Element [%d][%d]: ", x + 1, y + 1);
                if (scanf("%d", &element) == 1) { // Check if input is a valid integer
                    arr[x][y] = element; 
                    break; // Exit the loop if it is a valid integer for the current element
                } else {
                    printf("Invalid input. Please enter a valid integer.\n");
                    while (getchar() != '\n'); // Need to clear input buffer to prevent infinite loop of error in program behaviour
                }
            }
        }
    }
    printf("\n");
}

// Function to add matrix A and B. By laws of matrices - In order for addition to be performed both matrix must have same dimensions.
void Addition(int row1, int row2, int col1, int col2, int matA[row1][col1], int matB[row2][col2]){

    if(row1 != row2 || col1 != col2){
        // Unable to perform addition if different dimensions. Output error message and skip addition process.
        printf("Both matrices do not have the same dimensions. Unable to perform matrix addition.\n");
    } else {
        printf("\nResult of matrix addition:");
        for(int x=0;x<row1;x++){
            printf("\n");
            for(int y=0;y<col1;y++){
                printf("%d ",matA[x][y] + matB[x][y]); // Prints final output while looping
            }
        }
    }
    printf("\n");
}

// Function to subtract matrix B from A. By laws of matrices - In order for subtraction to be performed both matrix must have same dimensions.
void Subtraction(int row1, int row2, int col1, int col2, int matA[row1][col1], int matB[row2][col2]){
    
    if(row1 != row2 || col1 != col2){
        // Same as addition function
        printf("Both matrices do not have the same dimensions. Unable to perform matrix subtraction.\n");
    } else {
        printf("\nResult of matrix subtraction:");
        for(int x=0;x<row1;x++){
            printf("\n");
            for(int y=0;y<col1;y++){
                printf("%d ",matA[x][y] - matB[x][y]);
            }
        }
    }
    printf("\n");
}

// Function to transpose matrix
void Transpose(int row, int col, int arr[row][col]){
    
    // Transposed matrix will be stored in here. Dimensions are flipped to accomodate rules of transposition
    int Transpose[col][row]; 
    
    // Flipping matrix according to diagonal
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
            Transpose[j][i] = arr[i][j];
        }
    }

    // Print final matrix
    printf("\nTranspose of the matrix:\n");
    for (int i = 0; i < col; ++i){
        for (int j = 0; j < row; ++j){
            printf("%d  ", Transpose[i][j]);
            if (j == row - 1)
            printf("\n");
        }
    }
    printf("\n");
}

// Main function to start the program
int main(void){
    int row1, row2, col1, col2;

    // Prompts user for matrix A and B dimensions, calls validate function to validate input
    printf("Enter the dimensions of matrix A: (Min - 1x1, Max - 10x10)\n");
    scanf("%d%d", &row1,&col1);
    validate(&row1,&col1);
    
    printf("Enter the dimensions of matrix B: (Min - 1x1, Max - 10x10)\n");
    scanf("%d%d", &row2,&col2);
    validate(&row2,&col2);

    // Initialize matrices after getting user input
    int matA[row1][col1], matB[row2][col2];

    // Calls populate function to populate matrices
    printf("Enter elements for Matrix A (%dx%d):\n", row1,col1);
    populateMatrix(row1,col1,matA);
    printf("\n");
    printf("Enter elements for Matrix B (%dx%d):\n", row2, col2);
    populateMatrix(row2,col2,matB);

    printf("Matrix Operations Menu:\n");
    printf("1. Add Matrices\n");
    printf("2. Subtract Matrices\n");
    printf("3. Transpose Matrix A\n");
    printf("4. Transpose Matrix B\n");
    printf("5. Exit\n");
    
    // Infinite loop to accomodate multiple operations from user. Only ends when user decides to terminate.
    int choice;
    while(1){
        printf("\nEnter your choice (5 to exit): ");
        if (scanf("%d", &choice) == 1) { // Check if input is a valid integer
            // Condition to end infinite loop and terminate program.
            if (choice == 5) { 
                printf("Program terminated by user.");
                break;
            }
            // Calls respective functions base on user operations.
            switch (choice) {
                case 1:
                    Addition(row1, row2, col1, col2, matA, matB);
                    break;
                case 2:
                    Subtraction(row1, row2, col1, col2, matA, matB);
                    break;  
                case 3:
                    Transpose(row1, col1, matA);
                    break;
                case 4:
                    Transpose(row2, col2, matB);
                    break;
                // To check if user input integer that is not 1-5. Shows error message and prompts for re-input.
                default:
                    printf("Invalid choice. Please enter a valid option (1-5).\n");
            }
        } else { // If input is not a valid integer, shows error message and prompts for re-input
            printf("Invalid input. Please enter a valid integer.\n");
            printf("\n");
            while (getchar() != '\n'); // Need to clear input buffer to prevent infinite loop of error in program behaviour
        }
    }
    
    return 0;
}