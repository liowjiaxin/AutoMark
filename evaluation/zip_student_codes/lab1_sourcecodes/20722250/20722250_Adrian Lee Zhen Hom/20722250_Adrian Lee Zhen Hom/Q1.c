#include <stdio.h>

int main()
{
    int row, column;

    //prompt and read number of rows from user
    printf("Enter the number of rows: ");
    scanf("%d", &row);

    //prompt and read number of columns from user
    printf("Enter the number of columns: ");
    scanf("%d", &column);

    //loop row
    for(int i=1; i<=row; ++i)
    {
        //loop column
        for(int j=1; j<=column; ++j)
        {
            //print asterisk
            printf("*");
        }

        //print newline
        printf("\n");
    }

    return 0;
}