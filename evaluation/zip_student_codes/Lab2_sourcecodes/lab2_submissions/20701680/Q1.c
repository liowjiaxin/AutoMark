#include <stdio.h>

int main() {
    int n ;
     printf("Enter the size to the array");
    scanf("%d",& n) ;
    
    if (n <5){
       return 1;
    }
    int arr [n];
    int *ptr = &arr[50] ;
    int k, j ;
   
    printf("Enter the array elements\n") ;
    for (int i = 0 ; i < n ; i++){
        printf("Element %d : \n" ,i) ;
        scanf("%d",& *(ptr+i)) ;
    }
    printf("Enter the indices of the two elements within the range of array elements" ) ;
    scanf("%d %d", & j, &k);
    if(j>5 || k> 5){
        printf("Error:Indices must be within the range of element . Please try again");
      printf("Enter the indices of the two elements within the range of array elements" ) ;
    scanf("%d %d", & j, &k);  
    }
    
   int  sum =  *(ptr+j) + *(ptr+k) ; 
   
  printf("The sum of the values at the indices is %d" , sum) ;

    

    return 0;
}
