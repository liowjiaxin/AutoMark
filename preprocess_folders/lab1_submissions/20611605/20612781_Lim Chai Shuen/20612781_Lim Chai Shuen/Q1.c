#include <stdio.h>

int main()
{
    // define variable
	int row = 0;
	int column = 0;
    
    // ask user input number of row and column
	printf("Enter the number of rows: ");
	scanf("%d", &row);
	printf("Enter the number of columns: ");
	scanf("%d", &column);

    // loop for printing '*'
	for (int j=0; j<row; ++j) {
	    for ( int i=0; i<column; i++) {
	        printf("* "); 
	    }
	    printf("\n");
	}

	return 0; // program execute successfully
}