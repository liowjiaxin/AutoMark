
#include <stdio.h>

int main() {
    int row, column; 
    
    //Prompt user to enter number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &column);
    
    for (int i=1; i <= row; i++) {
        for (int j=1; j <= column; j++) {
            printf(" *");
            
        }
        printf("\n"); //Newline for each row
    }
    return 0;
}