#include <stdio.h>
#define NAME_LENGTH 50

// Function prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]);

struct Data {
    char name[3][NAME_LENGTH];
    float marks[3];
};

int main() {
    struct Data data;
    for (int i = 0; i < 3; i++) {
        printf("Enter student's name[%d]: ", i);
        fgets(data.name[i], NAME_LENGTH, stdin); // Get student's name
        printf("Enter student's marks[%d]: ", i);
        scanf("%f", &data.marks[i]); // Get student's marks
        getchar(); // To consume the newline character left by scanf
    }

    displayStudentData(data.name, data.marks); // Call the function to display student's data

    float average = calculateAverage(data.marks, 3); // Call the function to calculate the average of the marks
    printf("Average mark: %.2f\n", average); // Print the average of the marks

    return 0;
}

void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    printf("Student's Name and Marks:\n");
    for (int i = 0; i < 3; ++i) {
        printf("Name: %s", names[i]); // Print student's name
        printf("Marks: %.2f\n", marks[i]); // Print student's marks
    }
}

float calculateAverage(const float marks[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    float average = sum / count; // Calculate the average of the marks
    return average; // Return the average
}



