#include <stdio.h>

//calculate average function:
float calculateAverage(const float marks[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += marks[i]; //sum up the values 
    }
    return sum / size; //divide the sum by the size to get the avaerage 
}

// display student data function:
void displayStudentData(const char names[][50], const float marks[]) {
    printf("\nNames and marks of students:\n");
    for (int i = 0; i < 3; i++) { //there are only ever 3 entries to we use i < 3
        printf("%s: %.2f\n", names[i], marks[i]);//will print "student name:" and the mark 
    }
}

int main() {

    //1) Prompt the user to enter the values of the three student names and marks one by one:
    char names[3][50];
    float marks[3];

    for (int i = 0; i < 3; i++)
    {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    //2) calculate average mark, using function:
    float average = calculateAverage(marks, 3); //function call 

    //3) Display student names and marks and the average mark, using function:
    displayStudentData(names, marks); //function call
    
    printf("\nAverage mark: %.2f", average);

    return 0;
}