#include <stdio.h>
#define NAME_LENGTH 50


float calculateAverage(const float marks[], int count){
    float sum=0.0;
    for (int i=0;i <count;i++){
        sum += marks[i];

    }
    return sum/3;
} 
       
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]){
    printf("Student Names and Marks:\n");
    for (int i=0; i<3 ;i++){
        printf("%s:%.2f\n",names[i],marks[i]);
    }
}   

void main(){
     char names[3][NAME_LENGTH];
     float marks[3];
    

    for (int i=0; i <3;i++){
        printf("Enter the name of student %d:",i);
        scanf(" %[^\n]", names[i]);
        getchar();
        printf("Enter the mark of student %d:",i);
        scanf("%f", &marks[i]);
    

    }

  
    displayStudentData(names,marks);
    float average=calculateAverage(marks,3 );
    printf("\nAverage Mark:%.2f",average);


    
}