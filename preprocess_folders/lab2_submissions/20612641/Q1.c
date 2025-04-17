#include <stdio.h>
#define SIZE 100

int main() {

    int arr[SIZE];
    int *ptr;
    int size;
    int index1, index2;
    int sum = index1+index2;


    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &size);

    if (size==5 | size<5){
        printf("the number should be equal or more than 5. try again.\n");
        return main();
    }

    printf("Enter the array elements: \n");
    for (int i=0;i<size;++i){
        printf("Element %d: ",i+1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the indices of the two elements (0 <= index, index2 < %d): ",size);
    scanf("%d %d", &index1, &index2);

    int *ptr1 = index1;
    int *ptr2 = index2;

    if (0 <= ptr1 && ptr2<size){
        printf("The sum of the two values at indices %d and %d is: %d",index1,index2,index1+index2);
    } else {
        printf("the number should be equal or more than 5. try again.\n");
        return main();
    }


    return 0;
}
