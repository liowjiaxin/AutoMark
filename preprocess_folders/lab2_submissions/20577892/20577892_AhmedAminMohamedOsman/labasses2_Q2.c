#include <stdio.h>
#define NAME_LENGTH 50

void displayStudentData(const char names[NAME_LENGTH], const
float marks[]) {

    printf("Student Names and Marks:\n");
    for (int j =  0; j<3; j++) {
        printf("%c: %.2f\n", names[j], marks[j]);
    }

}

float calculateAverage(const float marks[], int count) {
    
    // base case
    if (count == 0) {
        return 0;
    }
    else {
        // recursively calling the function
        marks[0] + calculateAverage(marks + 1, count - 1);
    }

    calculateAverage(marks, count) / 3;

}

int main() {

    char names[NAME_LENGTH]; 
    float marks[] = {};
    float average = 0;

    for (int i =  1; i<4; i++) {
        printf("Enter the name of student %d: ", i);
        scanf(" %[^\n]", names[i]);
        printf("Enter the mark of the student %d: ", i);
        scanf("%.2f", &marks);
        
    }

    average = calculateAverage(marks, 3);
    displayStudentData(names, marks);

    printf("Average Mark: %.2f", average);
    return 0;
}