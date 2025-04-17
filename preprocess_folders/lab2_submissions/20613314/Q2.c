#include <string.h>
#include <stdio.h>
#include <stdlib.h>

const int NAME_LENGTH = 50;

float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]); // NAME_LENGTH 50 


int main(){
    float marks[3];
    char names[3][NAME_LENGTH];
    float average;


    for (int i = 0; i < 3; i++){
        // read student name
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);

        //read student mark
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    // display students and marks
    displayStudentData(names, marks);


    average = calculateAverage(marks, 3);
    //print average mark
    printf("Average Mark: %0.2f", average);

    return 0;
}

// calculate average
float calculateAverage(const float marks[], int count){
    int sum = 0;
    for (int i = 0; i < count; i++){
        sum += marks[i];
    }
    return sum/count;
}

// display students
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]){ // NAME_LENGTH 50
    printf("\nStudent names and marks: \n");

    for (int i = 0; i < 3; i++){
        printf("%s: %0.2f \n", names[i], marks[i]);
    }
}  