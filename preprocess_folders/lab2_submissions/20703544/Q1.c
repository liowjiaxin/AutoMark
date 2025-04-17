#include <stdio.h>

int main()
{
    int size = 0;
    printf("Enter the size of array(N>=5) : ");
    scanf("%d", &size);
    int array[size];
    for(int i = 0; i < size; i++) {
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }
    int a;
    int b;
    printf("Enter two target indices(range: 0 <= indices < %d): ", size);
    scanf("%d %d", &a, &b);
    int *ptr1 = &array[a];
    int *ptr2 = &array[b];
    printf("The sum of the two target indices is %d", *ptr1 + *ptr2);
    return 0;
}