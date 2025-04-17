#include <stdio.h>
#define NAME_LENGTH 50
#define STUD_COUNT 3

//Function Prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count);


int main() {

    char names[STUD_COUNT][NAME_LENGTH];  //Array to store student names
    float marks[STUD_COUNT]; //Array for student marks

    for (int i = 0; i < STUD_COUNT; i++){
        printf("Enter the name of student %d: ", i + 1);  //for loop to get the student names and marks
        scanf(" %[^\n]", names[i]); 

        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    displayStudentData(names, marks, STUD_COUNT); //calling functions

    float average = calculateAverage(marks, STUD_COUNT);  
    printf("\nAverage Mark: %.2f\n", average);


}


float calculateAverage(const float marks[], int count) {   

    float sum = 0.0; 
    for (int i = 0; i < count; i++){    //Traversing the arrays
        sum = sum + marks[i];
    }

    return sum/count;  // returns the average marks

}

void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count) {   

    printf("\nStudent Names and Marks: \n"); 
    for (int i = 0; i < count; i++){
        printf("%s : %.2f\n", names[i], marks[i]);  // for loop to traverse through both the arrays and print out names and marks
    }
}