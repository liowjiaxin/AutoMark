#include <stdio.h>
#define NAME_LENGTH 50  
#define STUD_COUNT 3

float calculateAverage(const float marks[], int count) {   //define a function to calculate average

    float sum = 0.0; 
    for (int i = 0; i < count; i++)    // for loop to count the sum of elements of the array as we traverse
    {
        sum = sum + marks[i];
    }

    return sum/count;  // returns the average value 

}

void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {  // define a function to display all the data 

    printf("\nStudent Names and Marks: \n"); 
    int count = STUD_COUNT;
    for (int i = 0; i < count; i++)
    {
        printf("%s : %.2f\n", names[i], marks[i]);  // for loop to traverse through both the arrays and print out data 
    }
}


int main() {

    char names[STUD_COUNT][NAME_LENGTH];  //2d array for names since we have multiple names
    float marks[STUD_COUNT];

    for (int i = 0; i < STUD_COUNT; i++)
    {
        printf("Enter the name of student %d: ", i + 1);  // for loop to take user input for values
        scanf(" %[^\n]", names[i]); 

        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    displayStudentData(names, marks); // function call to display data

    float average = calculateAverage(marks, STUD_COUNT);  // function call to calculate average
    printf("\nAverage Mark: %.2f\n", average);
    

}