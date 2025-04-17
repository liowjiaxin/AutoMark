#include <stdio.h>

#define NAME_LENGTH 50

//function prototype
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const
float marks[]); 

int main() {
    // define variable and array
    int count = 3;
    char names[count][NAME_LENGTH];
    float marks[count];
    

    // ask user to input name and marks
    for (size_t i = 0; i < count; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);
        while (getchar() != '\n');
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
        while (getchar() != '\n');
    }
    puts("");

    // display student data
    displayStudentData(names, marks);

    // display the average mark
    printf("\nAverage Mark: %.2f", calculateAverage(marks, count));
    return 0;
}

// define function
float calculateAverage(const float marks[], int count) {
    float avg = 0;
    for (int i = 0; i < count; i++) {
        // calculate the sum of the marks
        avg += marks[i];
    }
    avg /= count;
    return avg;
}

void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    printf("Student Names and Marks: \n");
    // printing the student data
    for (int i = 0; i < 3; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}