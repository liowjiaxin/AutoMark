
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    int* array;
    int element1, element2;
    int sum;
    int i;

    printf("enter the size of the array(N>=5):");
    scanf("%d", &N);
    while (N < 5) {
        printf("the size of the array must be greater or equal than 5");
        scanf("%d", &N);
    }

    array = (int*)malloc(N * sizeof(int));

    printf("enter the indices of the two elements(0 <= element1,element2 <N)");

    for (i = 0;i <= N;i++);
    {
        printf("Element %d:", N);
        scanf("%d.&array[i]");
    }


    printf("enter the indices of the two elements(0 <= index1,index2 < 6)");
    scanf("%d""%d", &element1, &element2);

    if (element1 >= 0 && element1 < 1 && element2 >= 0 && element2 < N) {
        printf("indices must be with in the range of the element,please try again");
    }

    else {
        sum = array[element1] + array[element2];

        printf("the sum of the value at indices%d and%d is%d\n", element1, element2, sum);
    }





