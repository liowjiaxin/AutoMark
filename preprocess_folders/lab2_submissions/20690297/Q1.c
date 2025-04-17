#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int index1;
    int index2;
    int *ptr1;
    int *ptr2;
    int result;

    n = 0;
    while (n < 5)
    {
        printf("Enter the number of elements\n");
        scanf("%d", &n);
    }
    int *arr = (int*) malloc(sizeof(char)*(n + 1));

    printf("Enter array elements: \n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    getchar();
    arr[n] = '\0';


    index1 = -1;
    index2 = -1;
    while ((index1 < 0 || index1 >= n) || (index2 < 0 || index2 >= n))
    {
        printf("Enter 2 indices of array elements: \n");
        scanf("%d", &index1);
        scanf("%d", &index2);
    }

    ptr1 = arr;
    while (ptr1 != &arr[index1])
    {
        ptr1++;
    }

    ptr2 = arr;
    while (ptr2 != &arr[index2])
    {
        ptr2++;
    }

    result = *ptr1 + *ptr2;
    printf("The sum of the values is %d", result);

    




}