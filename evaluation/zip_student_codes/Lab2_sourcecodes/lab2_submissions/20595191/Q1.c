#include<stdio.h>
int main(){
    int n, index1,index2;
    printf("Enter the size of the array (N>=5): ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array :\n ");
    for(int i=0 ;i < n ;i++){
        printf("Element %d : ", i);
        scanf("%d", &arr[n]);
    }
    printf("enter the two indices of the two elements (0<= index1, index2<%d):",n);
    scanf("%d %d", index1, index2);
    int *one=arr+index1;
    int *two=arr+index2;
    int sum=0;
    sum = one + two;
    printf("the sum of values of indices %d and %d is %d", index1,index2,sum);
       
    
    
}
    