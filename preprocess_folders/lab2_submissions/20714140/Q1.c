#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int* ptr;
    
    printf("Enter the size of the array (N>=5): ");
    scanf("%d",&num);
    while (num<5){
        printf("Please enter a value bigger or equal to 5 for the size of the array: ");
        scanf("%d",&num);
    }
    
    int num_array[num];
    ptr = (int*)malloc(num * sizeof(int)); //memory allocation
    
    if (ptr == NULL){
        printf("Memory not allocated.\n");
    }
    
    printf("Enter the array elements:\n");
    for (int i = 0;i<num;++i){
        printf("Element %d: ", i);
        scanf("%d",&ptr[i]);
    }
    
    int index1,index2;
    
    printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ",num);
    scanf("%d",&index1);
    scanf("%d",&index2);
    while (index1 < 0 || index2 >= num) { //or gate to check both conditions
        printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ",num);
        scanf("%d",&index1);
        scanf("%d",&index2);
    }
    
    int sum = ptr[index1] + ptr[index2]; //sum of the two indexes
    printf("The sum of the values at indices %d and %d is %d", index1,index2,sum);
    
    return 0;
}