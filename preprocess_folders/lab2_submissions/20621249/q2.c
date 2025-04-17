#include <stdio.h>
#define NAME_LENGTH 50
#define SIZE 3

float calculateAverage(const float marks[], int count){
    float sum=0;
    float average=0;
    for(int i=0;i<3;i++){
        sum=sum+marks[i];
        count++;
    }
    average=sum/count;
    return average;
}

void displayStudentData(const char names[][NAME_LENGTH], const float marks[]){
    for(int i=0;i<3;i++){
        printf("\n%s: %.2f",names[i],marks[i]);
    }
}

int main(){
    char names[SIZE][NAME_LENGTH];
    float marks[SIZE];

    for(int i=0;i<SIZE;i++){
        printf("\nEnter the name of student [%d]: ",i+1);
        scanf("%s",names[i]);
        printf("\nEnter the mark of student [%d]: ",i+1);
        scanf("%f", &marks[i]);
    }

    printf("\nStudent Names and Marks:");
    displayStudentData(names,marks);

    printf("\nAverage Mark: %.2f",calculateAverage(marks,0));

    return  0;
}