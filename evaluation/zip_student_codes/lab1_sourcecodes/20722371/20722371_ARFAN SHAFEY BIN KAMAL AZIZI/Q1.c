#include <stdio.h>

int main()
{
    int r, c, a, b;

    printf("Enter number of rows :");
    scanf("%d", &r); //input number of rows

    printf("Enter number of columns :");
    scanf("%d", &c); //input number of columns

    for(a = 1; a <= r ; a++) //iterate through each row
    {
        for(b = 1; b <= c ; b++) //iterate through each column
        { 
            printf("*"); //print an asterisk for each column
        }

        printf("\n"); //move on to the next row
    }

    return 0;
}
