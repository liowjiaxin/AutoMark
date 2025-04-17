#include <stdio.h>
#define NAME_LENGTH 50

void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int NumStudent);
float calculateAverage(const float marks[], int count);

int main() {
    char names[3][NAME_LENGTH];   // Array to store student names
    float marks[3];               // Array to store student marks
    int i;

    // Input student names and marks
    for (i = 0; i < 3; i++) {
        printf("Enter the name of student %d: ", i + 1);             // Prompt the user to enter student names
        scanf(" %[^\n]", names[i]);  
        printf("Enter the mark of student %d: ", i + 1);              // Prompt the user to enter student marks
        scanf("%f", &marks[i]);  
    }
   
   
    float average = calculateAverage(marks, 3);         // Calculate the average
    
   
    displayStudentData(names, marks, 3);                // Display student data

    printf("\nAverage mark: %.2f\n", average);             // Display student average mark

    return 0;
}


void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int NumStudent) {        // Function that display student names and marks
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < NumStudent; i++) {
        printf(" %s: %.2f\n", names[i], marks[i]);
    }
}


float calculateAverage(const float marks[], int count) {            //Function that calculate the average mark
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}
