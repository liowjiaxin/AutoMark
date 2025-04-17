#include <stdio.h>

int main(){

    int first = 0;
    int second = 0;
    int third = 0;
    int sum = 0;
    int average = 0;
    int product = 0;
    int smallest = 0;
    int largest = 0;

    printf("Enter three integers separated by a single space:");
    scanf("%d\t%d\t%d",&first,&second,&third);

    sum = first + second + third;
    average = sum / 3;
    product = first * second * third;

    if(first >= second){
        largest = first;
        if (second >= third){
            smallest = third;
        }
        else{
            smallest = second;
        }
    }
    else if (second >= third){
        largest = second;
        smallest = first;
    }
    else{
        largest = third;
        smallest = first;
    }

    printf("Sum:%d\nAverage:%d\nProduct:%d\nSmallest:%d\nLargest:%d\n",sum,average,product,smallest,largest);
}