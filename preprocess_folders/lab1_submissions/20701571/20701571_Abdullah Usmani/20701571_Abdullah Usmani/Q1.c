#include <stdio.h>

int main() {
    int rows = 0;
    int columns = 0;
    char i,j = '*';
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
        scanf("%d", &columns);

    for(int i = 1; i <= rows; ++i)
    {
        printf("%d", i);
        for (int j = 1; j <= columns; ++j)
        {
         printf("%d", j);
        }
        printf("\n"); // This is necessary as it gives the new line everytime a row ends.

    }
    

    return 0;
}