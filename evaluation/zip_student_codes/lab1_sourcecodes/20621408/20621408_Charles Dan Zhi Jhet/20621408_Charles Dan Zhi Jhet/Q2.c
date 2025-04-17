#include <stdio.h>

int main()
{
    int sum, product = 1, value1, value2, value3, smallest, largest;
    double average;

    printf("Enter three integers seperated by spaces: ");
    scanf("%d %d %d", &value1, &value2, &value3);

    //SUM
    sum = value1 + value2 + value3;
    printf("SUM: %d\n", sum);

    // AVERAGE
    average = (double)sum / 3;
    printf("Average: %.2lf\n", average);

    // PRODUCT
    product = value1 * value2 * value3; 
    printf("Product: %d\n", product);


    // Largest among all 3 values
    if(value1 > value2)
    {
      if(value1 > value3)
        largest = value1;
      else
        largest = value3;
    }
    else
    {
      if(value2 > value3)
        largest = value2;
      else
        largest = value3;
    }

    // Small among all 3 values
    if(value1 < value2)
    {
      if(value1 < value3)
        smallest = value1;
      else
        smallest = value3;
    }
    else
    {
      if(value2 < value3)
        smallest = value2;
      else
        smallest = value3;
    }

    //Display smallest number
    printf("Smallest: %d\n",smallest);

    //Display Largest Number
    printf("largest: %d\n",largest);

    return 0;
}