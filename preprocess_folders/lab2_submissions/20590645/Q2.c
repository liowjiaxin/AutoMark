#include <stdio.h>
#include <string.h>
#define NUM_STUDENTS 3
#define NAME_LENGTH 50

// Function prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count);



// Function to calculate the average of the marks
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

// Function to display student names and marks
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count) {
    printf("\nStudent Data:\n");
    printf("Name\t\tMarks\n");
    printf("-----------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-15s %.2f\n", names[i], marks[i]);
    }
}

int main() {
    char names[NUM_STUDENTS][NAME_LENGTH]; // Array to store student names
    float marks[NUM_STUDENTS];             // Array to store student marks
    int i;

    // Input student names and marks
    for (i = 0; i < NUM_STUDENTS; i++) {
        // Input and validate student name
        while (1) {
            printf("Enter the name of student %d: ", i + 1);
            scanf(" %[^\n]", names[i]); // Read full name including spaces

            // Validate name (not empty)
            if (strlen(names[i]) > 0) {
                break;
            } else {
                printf("Invalid input. Name cannot be empty. Please try again.\n");
            }
        }

        // Input and validate student marks
        while (1) {
            printf("Enter the marks of %s (0 to 100): ", names[i]);
            if (scanf("%f", &marks[i]) == 1 && marks[i] >= 0 && marks[i] <= 100) {
                break; // Valid marks entered
            } else {
                printf("Invalid input. Marks must be a number between 0 and 100. Please try again.\n");
                while (getchar() != '\n') // Clear invalid input
                    ;
            }
        }
    }

    // Calculate the average mark
    float average = calculateAverage(marks, NUM_STUDENTS);

    // Display the student data and average mark
    displayStudentData(names, marks, NUM_STUDENTS);
    printf("Average Marks: %.2f\n", average);

    return 0;
}