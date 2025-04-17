#include <stdio.h>

//define constants
#define STUDENTS 3
#define NAME_LENGTH 50

//define function prototypes
float calculateAverage(const float marks[]);
void displayStudentData(const char names[STUDENTS][NAME_LENGTH], const float marks[]);

int main(){
    //define variables
    char studentnames[STUDENTS][NAME_LENGTH];
    float studentmarks[STUDENTS];
    
    //use for loop to get input
    //thankfully no validation needed
    for (int i = 0; i < STUDENTS; ++i){
        printf("Enter the name of student %d: ", i);
        scanf("%s", studentnames[i]);
        printf("Enter the mark of student %d: ", i);
        scanf("%f", &studentmarks[i]);
    }
    
    //use the displayStudentData subroutine to print student names and marks
    //note function vs subroutine - displayStudentData returns nothing so it is a subroutine
    displayStudentData(studentnames, studentmarks);
    //print a newline
    puts("");
    //use the function calculateAverage as an argument to printf()
    printf("Average Mark: %.2f\n", calculateAverage(studentmarks));
    return 0;
}

void displayStudentData(const char names[STUDENTS][NAME_LENGTH], const float marks[]){
    printf("Student Names and Marks: \n");
    //use for loop to iterate through the two arrays
    for (int i = 0; i < STUDENTS; ++i){
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}

float calculateAverage(const float marks[]){
    //define accumulator variable
    float acc;
    //use for loop to add all values into accumulator
    for (int i = 0; i < STUDENTS; ++i){
        acc = acc + marks[i];
    }
    //divide by number of students
    return acc / STUDENTS;
}