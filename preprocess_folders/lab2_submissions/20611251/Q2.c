#include <stdio.h>

#define NUM_STUDENTS 3  
#define NAME_LENGTH 50    

float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]);

//Calculate average mark
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];  
    }
    return sum / count;  
}

//Display student data
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}

int main() {
    char names[NUM_STUDENTS][NAME_LENGTH];   
    float marks[NUM_STUDENTS];                

    // Input
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);  
        
        printf("Enter the marks of student %d: ", i + 1);
        scanf("%f", &marks[i]);  
    }

    float average = calculateAverage(marks, NUM_STUDENTS);

    // Display student data
    displayStudentData(names, marks);
    printf("\nAverage mark: %.2f\n", average);

    return 0;
}
