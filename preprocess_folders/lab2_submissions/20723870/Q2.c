#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 3 //setting up max array size
#define NAME_LENGTH 50 

float calculateAverage(const float marks[], int count) { //formula is = student1...3 mark sum / 3 
    float total = 0.0; 
    for (int i = 0; i < count; i++) {
        total += marks[i];
    }
    return total / count;
}


void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    printf("\nStudent Data\n");
    

    for (int i = 0; i < MAX_STUDENTS; i++) { //printing every student details
        printf("Student %d: Name = %s, \nMark = %.2f\n", 
               i + 1, names[i], marks[i]);
    }
    
}

void main() {
    char names[MAX_STUDENTS][NAME_LENGTH]; //initialising array for student names
    float marks[MAX_STUDENTS]; //initialising array for marks
    
    for (int i = 0; i < MAX_STUDENTS; i++) { // for loops for inputting 3 student
        
        printf("\nEnter name for Student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);
        
        printf("Enter mark for %s: ", names[i]);
        scanf(" %f", &marks[i]);
    }

    displayStudentData(names, marks); // Calling the displayStudentData

    float averageMark = calculateAverage(marks, MAX_STUDENTS); // Calling the averageMark function
    printf("\nAverage Mark: %.2f\n", averageMark); //printig average mark
    
  
}