/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>


int main(){
    int size;
    int array[size];
    printf("enter size of array (N>=2):\n"); //ask for size of array
    scanf("%d",&size); //put the value in variable size
if (size>=2){
    printf("\nEnter the bids (must be at least 100000)\n");
    for (int i=1; i <= size; ++i){
    printf("Enter Bid %d:\n",i);
    scanf("%d",&array[i]); //put the elements into the array
    while (array[i]<100000){
    printf("Enter Bid at least 100000 %d:\n",i+1);
    scanf("%d",&array[i]);
    }
    }
int highest; //initialise highest
int size2 = size;
int i=0;
for (i=0; i<=size2; ++i){ 
    if (array[i]>= highest){
    highest=array[i];} //determ the value of the highest bid with a loop
 }    
printf("Highest bid is %d",highest); // print highest bid
}else{
        printf("Error. Highest bid cannot be determined");//Invalidate the input if its less than 2
    }
}