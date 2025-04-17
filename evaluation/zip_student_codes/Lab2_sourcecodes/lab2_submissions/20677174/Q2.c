#include <stdio.h>
#define NAME_LENGTH 50 // Define NAME_LENGTH as 50

// Function prototype given by question
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]); // NAME_LENGTH 50 


int main (void) {
    char names[3][NAME_LENGTH]; // Array of names
    float marks[3]; // Array of marks

    // Use a for loop to get the name and mark of three students
    for (int i = 0; i < 3; ++i) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", marks+i);
    }
    displayStudentData(names, marks);
    return 0;
}

float calculateAverage(const float marks[], int count) {
    float total = 0;
    for (int i = 0; i < count; ++i) {
        total += marks[i];
    }
    return total/count; 
}

void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    float average; // Stores the average of the marks

    printf("\n"); // Formatting output based on question's sample output

    // Loop through names array and marks array to print the student's name and mark
    printf("Student Names and Marks:\n");
    for (int i = 0; i < 3; ++i) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }

    printf("\n"); // Formatting output based on question's sample output

    // Calculate the average marks and display the average marks
    average = calculateAverage(marks, 3);
    printf("Average Mark: %.2f", average); 
}


