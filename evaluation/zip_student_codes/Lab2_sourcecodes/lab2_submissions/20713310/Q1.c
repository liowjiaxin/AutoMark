#include <stdio.h>
#include <stdlib.h>

int main()
{   
    int *array;

    int n,i,index1,index2;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int sum=0;
    printf("Enter the array elements:\n");

    array= (int*)malloc(n* sizeof(int));

    if(n<5){
        printf("Memory not allocated");
    }

    else{
        for (i = 0; i < n; i++)
        {
            printf("Element %d:",i);
            scanf("%d",array+i);
        }

        while(1)
        {
            printf("Enter the indices of the two elements (0 <= index1, index2 < %d):",n);
            scanf("%d",&index1);
            scanf("%d",&index2);

            if(index2 >=n)
            {
                printf("index2 >= %d\n,Try again\n",n);
            }

            else{
                for (i = index1; i <= index2; i++)
                {
                    sum=sum+*(array+i);
                }

                printf("Sum of values at the indices %d and %d is: %d",index1,index2,sum);
                break;
                }
        }
    }
    return 0;
}