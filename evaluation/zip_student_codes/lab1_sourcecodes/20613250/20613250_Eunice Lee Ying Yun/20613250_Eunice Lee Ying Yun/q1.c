#include <stdio.h>

int main(void)
{
    int row, col; // row and column
    
    //request number of rows
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    //request number of columns
    printf("Enter the number of columns: ");
    scanf("%d", &col);
    
    for (row; row>0; --row){ //repeat until all rows have been displayed, no remainding row
        
        for (int count = col; count>0; --count){ //repeat until all columns on that row have been displayed, no remainding column
            printf("* ");
        }

        printf("\n"); //newline for next row
    }

    return 0;
}