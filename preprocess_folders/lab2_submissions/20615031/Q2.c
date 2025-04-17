#include <stdio.h>

#define MAX_LENGTH 100
#define STUDENT_COUNT 3

//Function Prototype
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][MAX_LENGTH], const float marks[], int count); // NAME_LENGTH 50 


int main(void){
    char names [STUDENT_COUNT] [MAX_LENGTH];
    float marks [STUDENT_COUNT];    // three students marks


    //Prompt the user to enter the values of the three student names and marks one 
    for( int i = 0; i < STUDENT_COUNT; i++){
        printf("Enter a student %d: ", i + 1);
        scanf(" %[^\n]", &names[i]); //Read the student name

        printf("Enter the mark of student %d: ", i+1);
        scanf("%f", &marks[i]); // Read the student marks
    }

//Calculate the average marks of student
    float Average = calculateAverage(marks, STUDENT_COUNT);

//Display the student names, marks and the average marks
    displayStudentData(names, marks, STUDENT_COUNT);
    printf("Average mark: %.2f\n", Average);

    
}

float calculateAverage(const float marks[], int count){
    float sum = 0.0;
    for(int i = 0; i < count; i++){
        sum += marks[i];
    
    }
    return sum/count;
}

//Function to display the names, marks and the average marks
void displayStudentData(const char names[][MAX_LENGTH], const float marks[], int count){
    printf("\nStudent Names and Marks\n");
    //Print each student Data
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n Mark: %.2f\n", names[i], marks[i]);
    }
}