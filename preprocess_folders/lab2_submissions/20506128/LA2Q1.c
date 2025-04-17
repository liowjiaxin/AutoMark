#include <stdio.h>
int main(void){

    printf("Please enter the size of the array (greater than or equal to 5) : ");
    int arrsize;
    scanf("%d",&arrsize);

    if (arrsize<5){
        printf("Please enter a value equal to or greater than 5");
    }

    else {
        int arr[arrsize];
        int *arrptr=arr;

        for(int i=0;i<arrsize;++i){
            printf("Enter element %d:\n",i);
            scanf("%d\n",(arrptr+i));
        }

        printf("Enter indices of two elements: ");
        int in1;
        int in2;
        scanf("%d" "%d",&in1,&in2);
        
        if (in1<0 || in2>arrsize-1) {
            printf("Please enter indices within the array bounds");
        }
        
        else {
            int sum=*(arrptr+in1)+*(arrptr+in2);
            printf("The sum of the elements in those indices is %d.",sum);
        }
    }
}
