#include <stdio.h>

#define NAME_LENGTH 50 //Maximum length of a student's name
#define STUDENT_COUNT 3 //Number of students
//Function to calculate the average of student marks
float calculateAverage(const float marks[], int count) {
    float sum = 0.0; //Variable to store the total marks
    for (int i = 0; i < count; i++) {
        sum += marks[i]; //Add each mark to the total
    }
    return sum / count; //Calculate and return the average
}

//Function to display student names and marks along with the average
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    printf("Student Data:\n");
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("%s: %.2f\n", names[i], marks[i]); // Print each student's name and mark
    }
}


int main() {
    char names[STUDENT_COUNT][NAME_LENGTH]; //Array to store names of students
    float marks[STUDENT_COUNT]; //Array to store marks of students

    //Prompt the user to input names and marks of students
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]); //Input the student's name
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]); //Input the student's mark
    }

    //Calculate the average mark
    float average = calculateAverage(marks, STUDENT_COUNT);

    //Display the student data and the average mark
    displayStudentData(names, marks);
    printf("Average mark: %.2f\n", average);

    return 0;
}