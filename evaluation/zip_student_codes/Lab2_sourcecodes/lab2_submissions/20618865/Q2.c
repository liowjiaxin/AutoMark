#include <stdio.h>
#define NUM_OF_STUDENT 3
#define NAME_LENGTH 50

float calculateAverage (const float marks[], int count){
    float sum=0.0; // initialize sum
    //calculate sum 
    for (int i=0; i<count; i++){
        sum += marks[i];
    }
    //return average
    return sum/count;
}

void displayStudentData (const char names[][NAME_LENGTH], const float marks []){
    //display 3 students' names and marks
    printf("\nStudents Names and Marks:\n");
    for (int i=0; i<NUM_OF_STUDENT; i++){
        printf("%s: %.2f\n", names[i], marks[i]);
    }

    //display average mark calcuated by the first function
    printf("\nAverage Mark: %.2f\n", calculateAverage(marks, NUM_OF_STUDENT));
}

int main(){
    // initialize arrays for names and marks
    char names[NUM_OF_STUDENT][NAME_LENGTH]={0};
    float marks[NUM_OF_STUDENT]={0};

    // prompt the user to input names and marks of students
    for (int i=0; i<NUM_OF_STUDENT; i++){
        printf("Enter the name of student %d: ", i+1);
        scanf("%[^\n]", names[i]); // scan until a newline character
        
        printf("Enter the mark of student %d: ", i+1);
        scanf("%f", &marks[i]);
        getchar(); //remove newline character in buffer
    }

    // display each student's details and average mark
    displayStudentData(names, marks);

    return 0;
}