#include <stdio.h>


#define NAME_LENGTH 50 // to define the amount of characters allowed for the name
#define STUDENT_COUNT 3 // to define the max number of students

typedef struct { // creating a new structure to store student data.
    char name[NAME_LENGTH]; // using char for name
    float mark; // using float for mark
} Student; // giving the name student for the structure

float calculateAverage(const float marks[], int count); // it takes the sum of all values stored in the array and divide it by the number of elements in the array
void displayStudentData(const Student students[], int count);// to display the names and marks of the students stored in the array

int main() {
    Student students[STUDENT_COUNT]; //  to declare the students array
    float marks[STUDENT_COUNT];// to declare the marks array

    for (int i = 0; i < STUDENT_COUNT; i++) { // using for loop to ensure the number of students doesn't exceed the limit
        printf("Enter the name of student %d: ", i + 1); // asking the user to input the name of the student one by one
        scanf(" %[^\n]", students[i].name); // scanf function is used to read the input
        printf("Enter the mark of %s: ", students[i].name); // asking the user to input the marks of the student
        scanf("%f", &students[i].mark); // scanf function is used to read the input
        marks[i] = students[i].mark; //  to copy mark for function
    }

   
    float averageMark = calculateAverage(marks, STUDENT_COUNT); // this is used to calculate average mark

    
    displayStudentData(students, STUDENT_COUNT); // Pass 'students' array here
    printf("The average mark is: %.2f\n", averageMark); // the average mark is displayed

    return 0;
}


float calculateAverage(const float marks[], int count) { // this is the function used to calculate the average mark
    float sum = 0.0;
    for (int i = 0; i < count; i++) { 
        sum += marks[i]; // used to calculate the average
    }
    return sum / count; // used for average.
}


void displayStudentData(const Student students[], int count) { // this is the function used to display the student names and marks
    printf("\nStudent Data:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Marks: %.2f\n", students[i].name, students[i].mark); // Correctly accessing 'students[i].name' and 'students[i].mark'. this is used so that when the output is displayed the names and marks of eah student is shown side by side as inidcated in the sample output
        
    }
} // i used const Student students[], int count instead of const char names[][NAME_LENGTH, as i am more comfortable with this and it works better. it also resembles the sample output.
