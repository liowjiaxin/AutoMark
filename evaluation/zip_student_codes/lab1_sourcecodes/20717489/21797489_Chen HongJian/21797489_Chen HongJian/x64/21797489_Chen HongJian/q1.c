#include<stdio.h>
int main()
{
	int row = 0;
	int column = 0;
	printf("Please enter the number of rows:");
	scanf_s("%d", &row);
	printf("Please enter the number of columns:");
	scanf_s("%d", &column);//get the number of rows and columns
	
	for (int y = 0; y < column; y++);//form a vertical cycle
	{
		int x = 0;
		while (x + 1 < row)// for a horizontal cycle
		{
			printf("*");
			x++;
		}
		printf("*\n");//let the end of line have a newline character
	}
	
	
	return 0;
}