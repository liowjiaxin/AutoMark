#include <stdio.h>

#define NAME_LENGTH 50 // Maximum length for a student name
#define STUDENT_COUNT 3 // Number of students

// Function prototypes
// Calculates the average of marks in the array
float calculateAverage(const float marks[], int count);

// Displays student names and marks
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count);

int main() {
    // Array to store the names of students 
    char names[STUDENT_COUNT][NAME_LENGTH];
    // Array to store marks corresponding to each student
    float marks[STUDENT_COUNT];
    int i; // Loop variable

    // Step 1: Prompt the user to enter names and marks
    for (i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter the name of student %d: ", i + 1);
        // Using " %[^\n]" to read the full name including spaces
        scanf(" %[^\n]", names[i]);
        
        printf("Enter the mark of student %d: ", i + 1);
        // Input the student's mark
        scanf("%f", &marks[i]);
    }

    // Step 2: Calculate the average mark
    // Calling the calculateAverage function to compute the average of all marks
    float average = calculateAverage(marks, STUDENT_COUNT);

    // Step 3: Display the student data and the average mark
    // Calls the displayStudentData function to print names and marks
    displayStudentData(names, marks, STUDENT_COUNT);
    
    // Prints the average mark to two decimal places
    printf("\nAverage Mark: %.2f\n", average);

 
    return 0; // Indicate successful program termination
}

// Function to calculate the average mark
// Takes an array of marks and the total number of students
float calculateAverage(const float marks[], int count) {
    float sum = 0.0; // Initialize the sum of marks to 0
    for (int i = 0; i < count; i++) {
        // Add each student's mark to the sum
        sum += marks[i];
    }
    // Return the average by dividing the sum by the number of students
    return sum / count;
}

// Function to display student names and marks
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count) {
    printf("\nStudent Names and Marks:\n"); // Header for the output
    for (int i = 0; i < count; i++) {
        // Prints the name and mark for each student
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}
