#include <stdio.h>

int main()
{
    int row, col;

    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &col);

    for(int i = 0; i < row; i++)            // iterate over each row, and print \n
    {
        for(int j = 0; j < col; j++)        // iterate over each column, and print *
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}