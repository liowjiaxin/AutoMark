#include <stdio.h>
#define NAME 25         // Length of name
#define STUDENTS 3      // Student count

// Function to calculate the average marks
float calcAvg(const float marks[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

// Function to display student data and the average marks
void displayStudent(const char names[][NAME], const float marks[]) {
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < STUDENTS; i++) {
        printf("%d: %s %.2f\n", i + 1, names[i], marks[i]);
    }
}

int main() {
    char names[STUDENTS][NAME]; // Array to store student names
    float marks[STUDENTS];      // Array to store student marks

    // User inputs the names and marks of students
    for (int i = 0; i < STUDENTS; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);

        printf("Enter the marks of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    // Calculate the average marks
    float average = calcAvg(marks, STUDENTS);

    // Display the student data
    displayStudent(names, marks);

    // Display the average marks
    printf("\nAverage Mark: %.2f\n", average);

    return 0;
}
