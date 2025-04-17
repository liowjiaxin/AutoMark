#include <stdio.h>

#define MAX_STUDENTS 3
#define MAX_NAME 50

float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][MAX_NAME], const float marks[], int count);

// Function to calculate average mark
float calculateAverage(const float marks[], int count){
    float sum = 0.0;
    for(int i = 0; i < count; i++){
        sum += marks[i];
    }
    return sum/count;
}

// Function to display student names, marks, and average mark
void displayStudentData(const char names[][MAX_NAME], const float marks[], int count){
    printf("\nStudent Names and Marks:\n");
    for(int i = 0; i < count; i++){
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}

int main(){
    char names[MAX_STUDENTS][MAX_NAME];
    float marks[MAX_STUDENTS];

    for(int i = 0; i < MAX_STUDENTS; i++){
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]); // Use " %[^\n]" to handle spaces in names
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    float calc_average = calculateAverage(marks, MAX_STUDENTS);

    displayStudentData(names, marks, MAX_STUDENTS);
    printf("\nAverage Mark: %.2f\n", calc_average);

    return 0;
}
