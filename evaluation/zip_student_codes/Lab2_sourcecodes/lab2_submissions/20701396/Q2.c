/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main(){
    
char names[3][30] = {"", "", ""}; //initialising the array (with length too)
float grades[3]; //intialise the grades array
for (int i= 0;i <=2 ; ++i){
        printf("\nEnter student %d name: ",i+1);
        scanf("%s", names[i]); //puts the names into the array
        printf("\nEnter student %d grade: ",i+1);
        scanf("%f",&grades[i]);//enters grade into the array
    
}
    
printf("\nStudent names and Marks:\n"); 

for (int i= 0;i <=2 ; ++i){
printf("%s:%.2f\n",names[i],grades[i]);// print the names and grades
}
float average = (grades[0] + grades[1] + grades[2])/3; //calculate average
printf("Average is %.2f", average);//print average
    
}

