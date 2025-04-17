#include <stdio.h>
#include <stdlib.h>

int main()
{
  // prompt user to give the array size
  int *array;
  int arraySize;
  printf("Enter the size of the array (N>=5): ");
  scanf("%d", &arraySize);
  getchar();

  // error handling
  if (arraySize < 5)
  {
    printf("The size of the array should greater than or equal to 5\n");
    return -1; // terminates with error
  }
  // create the array with the size user given

  // memory allocation
  array = (int *)malloc(arraySize * sizeof(int));

  if (array == NULL)
  {
    printf("\nMemory not allocated.\n");
    return -1;
  }

  // Memory allocated successfully
  printf("\nMemory successfully allocated \n\n");

  printf("Enter the array elements: \n");

  for (int i = 0; i < arraySize; i++)
  {
    // this is used to store the user input number
    int userElement;
    printf("Element %d: ", i);
    scanf("%d", &userElement);
    getchar();
    array[i] = userElement;
  }

  // this 2 number is used to store user input for the indices of 2 array elements
  int num1, num2;
  int total = 0;

  while (1)
  {
    printf("Enter the indices of the two elements (0<= index1, index2 < %d): ", arraySize);
    scanf("%d %d", &num1, &num2);
    getchar();

    // error handling for the user input
    if (num1 < 0 || num1 >= arraySize || num2 < 0 || num2 >= arraySize)
    {
      printf("Error: Indices must be within the range of the array elements. Please try again. \n");
      continue;
    }

    // if within the range, do the sum of elements from the array
    for (int i = num1; i <= num2; i++)
    {
      total += array[i];
    }
    // terminate the while loop
    break;
  }

  printf("The sum of the value at indices %d and %d is : %d\n", num1, num2, total);

  return 0;
}