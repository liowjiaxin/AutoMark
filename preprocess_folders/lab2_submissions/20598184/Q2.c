#include <stdio.h>

#define STUDENT_COUNT 3 // Student count set to 3
#define NAME_LENGHT 50 // Lenght of name max at 50 characters


// Initializing functions
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGHT], const float marks[], float average);

int main(void) {
    char names[STUDENT_COUNT][NAME_LENGHT]; 
    float marks[STUDENT_COUNT];
    
    // Loop for assigning names and marks
    for (int i = 0; i < 3; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);
        printf("Enter the marks of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }
    float average = calculateAverage(marks, STUDENT_COUNT); // Calculates averages using caclculateAverage function

    displayStudentData(names, marks, average); 
    
    return 0;
}

float calculateAverage(const float marks[], int count) {
    float sum = 0.0; // Initialise sum with value of 0.0

    // For loop for sum of marks
    for (int i = 0; i < count; i++ ) { 
        sum += marks[i]; 
    }
    return sum / count; // Returns the averaged marks
}


void displayStudentData (const char names[][NAME_LENGHT], const float marks[], float average) {
    printf("\nStudent Names and Marks: \n");
    for (int i = 0; i < 3; i++) {
        printf("%s : %.2f \n", names[i], marks[i]);
    }
    printf("\nAverage Mark: %.2f\n", average);

}