#include <stdio.h>

int main() {
    // Initialize row and column variables
    int nRow = 0, nColumn = 0;

    // Prompt user input
    printf("Enter the number of rows: ");
    scanf("%d", &nRow);
    printf("Enter the number of columns: ");
    scanf("%d", &nColumn);

    // Loop for each row
    for (int row = 0; row < nRow; row++) {
        // Loop to print one line
        for (int column = 0; column < nColumn; column++) {
            printf("* ");
        }
        
        // Print new line
        printf("\n");
    }

    return 0;
}