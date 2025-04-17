#include <stdio.h>

#define students 3
#define name 45

// Function prototypes
float Average(const float marks[], int count);
void displayStudentData(const char names[][name], const float marks[]);

int main() {
    char names[students][name];  // Store student name
    float marks[students];       // Store student marks

    // Prompt to enter students names and marks
    for (int i = 0; i < students; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);  
        printf("Enter marks of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    // Calculate average marks
    float average = Average(marks, students);

    // Print student names, marks, and student average
    displayStudentData(names, marks);
    printf("\nAverage mark: %.2f\n", average);

    return 0;
}

// Calculate average
float Average(const float marks[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += marks[i];
    }
    return total / count;
}

// Print studet data
void displayStudentData(const char names[][name], const float marks[]) {
    printf("\nStudent Names and Marks\n");
    for (int i = 0; i < students; i++) {
        printf("%d : %s - Marks: %.2f\n", i + 1, names[i], marks[i]);
    }
}
