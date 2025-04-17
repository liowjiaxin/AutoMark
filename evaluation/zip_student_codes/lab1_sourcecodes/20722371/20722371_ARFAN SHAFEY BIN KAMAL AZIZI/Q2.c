#include <stdio.h>

int main()
{
    int num1, num2, num3, sum, prod;
    float avg;

    printf("Enter three integers separated by spaces : ");
    scanf("%d %d %d", &num1, &num2, &num3);

    sum = num1 + num2 + num3; //sum of the 3 integers
    printf("\nSum : %d", sum);

    avg = (num1 + num2 + num3)/3; //average of the 3 integers
    printf("\nAverage : %f", avg);

    prod = num1 * num2 * num3; //product of the 3 integers
    printf("\nProduct : %d", prod);

    if(num1<num2) //finding smallest number in 3 integers
        {
            if(num2<num3)
                printf("\nSmallest : %d", num1);
            else
                printf("\nSmallest : %d", num3);
        }
    else
    {
        if(num2<num3)
            printf("\nSmallest : %d", num2);
        else
            printf("\nSmallest : %d", num3);
    }

    if(num1>num2) //finding biggest number in 3 integers
    {
        if(num2>num3)
            printf("\nBiggest : %d", num1);
        else
            printf("\nBiggest : %d", num3);
    }
    else
    {
        if(num2>num3)
            printf("\nBiggest : %d", num2);
        else
            printf("\nBiggest : %d", num3);
    }

    return 0;
}
