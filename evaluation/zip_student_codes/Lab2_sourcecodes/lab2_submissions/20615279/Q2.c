#include <stdio.h>

//define constants
#define NUM_STUDENTS 3
#define NAME_LENGTH 50

// function prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]); 


int main (){
    //initialize arrays
    char names[NUM_STUDENTS][NAME_LENGTH];
    float marks[NUM_STUDENTS];

    //Get input of student names and marks from user
    for(int i = 0; i < NUM_STUDENTS; i++){
        printf("Enter the name of student%d :",i+1);
        scanf(" %[^\n]", names[i]);
        printf("Enter the mark of student%d :",i+1);
        scanf("%f",&marks[i]);
    } 
    
    //obtain mark average from functions
    float average = calculateAverage(marks, NUM_STUDENTS);
    
    //displaying student data and marks
    displayStudentData(names, marks);
    printf ("Average Mark: %.2f",average);

}

float calculateAverage(const float marks[], int count){

    //calculating total marks of 3 students
    float total = 0;
    for(int i = 0; i<3;i++){
        total += marks[i];
    }
    
    //calculating average marks of students
    float average = total / count;
    return average;
}

void displayStudentData(const char names[][NAME_LENGTH], const float marks[]){

    //display student data
    printf("\n Student Names and Marks:\n");
    for(int i = 0; i<3; i++){
        printf("%s : %.2f\n",names[i], marks[i]);
    }
}