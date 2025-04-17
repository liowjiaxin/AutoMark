#include <stdio.h>

#define MAX_STUDENTS 3
#define NAME_LENGTH 50

float calculateAverage(const float marks[], int count); //declare calculateAverage
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]);//Array to for storing name and marks of students

//Main Function
int main() {
    char names[MAX_STUDENTS][NAME_LENGTH];
    float marks[MAX_STUDENTS];
    
    //Ask the user to put in the students names and their marks
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);
        printf("Enter marks of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    //Calculate average marks
    float average = calculateAverage(marks, MAX_STUDENTS);
    
    //Show student's datas and average marks
    displayStudentData(names, marks);
    printf("Average Marks: %.2f\n", average);

    return 0;
}

    //Function to calculate the average marks
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

    //Function to show student's datas with proper format
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    printf("\nStudent Data:\n");
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("Name: %s, Marks: %.2f\n", names[i], marks[i]);
    }
}