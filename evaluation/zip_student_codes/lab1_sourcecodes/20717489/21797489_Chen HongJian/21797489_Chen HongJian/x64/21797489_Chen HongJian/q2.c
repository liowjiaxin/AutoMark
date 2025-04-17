#include<stdio.h>
int main()
{
	int sum = 0;
	int average = 0;
	int product = 1;
	int smallest = 0;
	int smallest_cnt = 0;
	int biggest = 0;
	int biggest_cnt = 0;
	int integer = 0;
	int count = 0;
	int i = 0;
	printf("please enter how many integers you want to enter:");
	scanf_s("%d", count);
	for (i = 0; i < count; i++)
	{
		printf("please enter the interger separated by a single space:");
		scanf_s("%d", &integer[i]);//to let the user enter the integer
	}
	int p = 0;
	while(p<count)
	{
		i++;
		sum = sum + integer;//the sum of integers
		average = average + integer;//the average of integers
		product = product * integer;//the product of integers
		biggest_cnt = biggest;
		biggest = integer;
		if (biggest > biggest_cnt)
			biggest = biggest;
		else biggest = biggest_cnt;//to find which integer is biggest one
		smallest_cnt = smallest;
		smallest = integer;
		if (smallest < smallest_cnt)
			smallest_cnt = smallest;
		else smallest = smallest_cnt;//to find which integer is smallest one

			
	}
	average = average / count;
	printf("the sum is", sum);
	printf("the average is", average);
	printf("the product is", product);
	printf("the smallest is", smallest);
	printf("the biggest is", biggest);
	
	
	
	return 0;
	
}