#include <stdio.h>

int main(){
    int row = 0;
    int col = 0;

    printf("Enter the amount of rows:");
    scanf("%d", &row);

    printf("Enter the amount of columns:");
    scanf("%d", &col);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
    
}