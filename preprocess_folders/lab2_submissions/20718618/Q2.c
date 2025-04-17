#include <stdio.h>  // For input and output functions

#define NAME_LENGTH 50 // Maximum length of student names
#define NUM_STUDENTS 3 // Number of students

// Function to calculate the average of marks
float calculateAverage(const float marks[], int count) {
    float sum = 0; // Initialize the sum to 0
    for (int i = 0; i < count; i++) { // Loop through all marks
        sum += marks[i]; // Add each mark to the sum
    }
    return sum / count; // Return the average
}

// Function to display student names, marks, and the average
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], float average) {
    printf("Student Data:\n"); // Print a header
    for (int i = 0; i < NUM_STUDENTS; i++) { // Loop through all students
        printf("Name: %s, Mark: %.2f\n", names[i], marks[i]); // Print each student's name and mark
    }
    printf("Average Mark: %.2f\n", average); // Print the average mark
}

int main() {
    char names[NUM_STUDENTS][NAME_LENGTH]; // Array to store student names
    float marks[NUM_STUDENTS]; // Array to store student marks
    float average; // Variable to store the average mark

    // Prompt the user to enter student names and marks
    for (int i = 0; i < NUM_STUDENTS; i++) { // Loop through all students
        printf("Enter name of student %d: ", i + 1); // Ask for the name
        scanf(" %[^\n]", names[i]); // Read the name (handles spaces), hint
        printf("Enter mark of student %d: ", i + 1); // Ask for the mark
        scanf("%f", &marks[i]); // Read the mark
    }

    // Calculate the average without checking for invalid data (logical error here)
    average = calculateAverage(marks, NUM_STUDENTS);

    // Call the function to display the data
    displayStudentData(names, marks, average);

    return 0; // Exit the program
}

