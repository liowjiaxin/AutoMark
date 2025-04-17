#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	int *array;
	int index1;
	int index2;
	int sum;
	int i;
	
	do {
		printf("Enter the size of the array (N>=5):");
		scanf("%d",&N);
		if (N<5) {
			printf("There is the error!");
		}
		while(N<5);
	}

	printf("Enter the array elements:\n");
	for(int i=0; i<N; i++);
	{
		printf("Element %d:",i);
		scanf("%d",&array[i]);
	}
	do {
		printf("Enter indices of the two elements (0 <= index1,index2<6):",N);
		scanf("%d %d",&index1,&index2);
		if(index1<0||index2>=N) {
			printf("Error:Indices must be within the range of the array elemwnts.Please try again.");
		}
		while(index1<0||index2>=N);
		}

	sum=* (arr+index1)+* (arr+index2);

	printf("The sum of the values at indices %d and %d is:%d",index1,index2,sum);
	return 0;
}


