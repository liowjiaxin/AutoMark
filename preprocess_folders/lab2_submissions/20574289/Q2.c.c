#include <stdio.h>
#define STUDENT_COUNT 3
#define NAME_LENGTH 50

// Function Prototype Provided for Q2
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]);

// Main Program Block
int main() {
    // Variable, Array Declarations
    char names[STUDENT_COUNT][NAME_LENGTH];
    float marks[STUDENT_COUNT];
    int i;
    
    // Input Student Compartment
    for (i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter student %d name: ", i + 1);
        scanf(" %[^\n]", names[i]);                     // Student name Compartment
        
        printf("Enter %s's mark: ", names[i]);
        scanf("%f", &marks[i]);                         // Student grade Compartment
    }
    
    // Calculate and display results
    displayStudentData(names, marks);
    
    return 0;
}

// Average Grade Calculation Block
float calculateAverage(const float marks[], int count) {
    
    // Variable Declarations
    float sum = 0;
    int i;
    
    // Sum Calculation
    for (i = 0; i < count; i++) {
        sum += marks[i];
    }
    
    // Average Calculation by Sum/count or Total/no. of values
    return sum / count;
}

// Student Data Display Block
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    
    // Variable Declarations
    int i;
    float average;
    
    printf("\nStudent Data:\n");
    printf("-------------\n");
    
    // Requisition of names & marks from Array
    for (i = 0; i < STUDENT_COUNT; i++) {
        printf("Student: %s, Mark: %.2f\n", names[i], marks[i]);
    }
    
    // Final Summary Prints
    average = calculateAverage(marks, STUDENT_COUNT);
    printf("\nClass Average: %.2f\n", average);
}