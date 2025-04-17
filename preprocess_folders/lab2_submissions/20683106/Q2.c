#include <stdio.h>
#define NAME_LENGTH 50

// Function headers
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]);

// Function to display student information, using void as the function does not return anything
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]){
    printf("Student Names and Marks:\n");
    for(int x=0;x<3;x++){
        printf("%s: %.2f\n", names[x], marks[x]);
    }
    printf("\n");
}

// Function to calculate and return the average marks of the student as a float value rounded up to 2dp
float calculateAverage(const float marks[], int count){
    float average = 0;
    for(int x=0;x<3;x++){
        average += marks[x];
    }
    return (average/count);
}

// Main function
int main(void){
    char names[3][NAME_LENGTH];
    float marks[3];

    // Populate both arrays with student names and marks
    for(int x=0;x<3;x++){
        printf("Enter the name of student %d: ", x+1);
        scanf(" %[^\n]", &names[x]);
        printf("\n");
        printf("Enter the mark of student %d: ", x+1);
        scanf("%f", &marks[x]);
        printf("\n");
    }

    // Calling the respective functions to get desired results
    displayStudentData(names, marks);
    printf("Average Mark: %.2f", calculateAverage(marks,3));
    return 0;
}