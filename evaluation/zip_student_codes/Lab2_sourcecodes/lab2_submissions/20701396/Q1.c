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
    printf("enter size of array (N>=5:\n"); //ask for size of array
    scanf("%d",&size);
    if (size>=5){ //conditional statement to continue with the code
    printf("enter the array elements: \n");
    for (int i=0; i <= size; ++i){
    printf("Element %d:\n",i);
    scanf("%d",&array[i]); //put the elements into the array
    }
    int index1;
    int index2;
    int size2 = size; //because there is an error when I run (size becomes 3)
    printf("enter the value of index1: ");
    scanf("%d",&index1);
    printf("enter the value of index2: ");
    scanf("%d",&index2); //ask the user for input and read the values and store them in index1 and index2
    while (index1>=size2||index2>=size2){
    printf("please enter the value of index1 less than %d: ",size2);
    scanf("%d",&index1);
    printf("please enter the value of index2 less than %d: ",size2);
    scanf("%d",&index2);  
    }
    
    
    int *index1ptr = &array[index1];
    int *index2ptr = &array[index2]; //initialise both pointers to point to array of indice index1 and index2 respectively
    int sum = 0; //intialise sum
    sum = *index1ptr + *index2ptr; //make the value of sum the sum of values located in array[index1] and [index2]
    
    printf("the sum of the values at indices %d and %d is: %d",index1,index2,sum);
    }else{ //dont run the code if the number is less than 5
        printf("You should enter a number greater than or equal to 5");}
    
    
        
}

