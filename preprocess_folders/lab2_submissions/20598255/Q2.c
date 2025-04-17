#include <stdio.h>

#define STUDENT_COUNT 3
#define NAME_LENGTH 50 

float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count);

//function to calculate average
float calculateAverage(const float marks[], int count){
    float sum=0.0;
    for (int i =0; i<count; i++){
        sum += marks[i];
    }
    return sum / count;
}

//function to display student data
void displayStudentData(const char names[][NAME_LENGTH],const float marks[],int count){
    printf("\nStudent names and marks:\n");
    for (int i=0; i<count; i++){
        printf("%s : %.2f\n", names[i],marks[i]);
    }
}

int main(){
    char names[STUDENT_COUNT][NAME_LENGTH];
    float marks[STUDENT_COUNT];

    //prompt user to input student names and marks
    for (int i=0; i<STUDENT_COUNT; i++){
        printf("Student %d Name:", i+1);
        scanf(" %[^\n]", names[i]);
        printf("Student %d Marks:", i+1);
        scanf("%f", &marks[i]);
    }

    //calculate average by calling out func
    float average= calculateAverage(marks,STUDENT_COUNT);

    //call out function to display student data 
    displayStudentData(names, marks, STUDENT_COUNT);
    printf("\nAverage marks: %.2f\n", average);

    return 0;
}