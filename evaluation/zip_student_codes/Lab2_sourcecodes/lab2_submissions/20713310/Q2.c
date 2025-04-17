#include <stdio.h>
#include <string.h>

#define NameLength 50
#define S_Count 3

//define data type of structure student
typedef struct {
    char name[NameLength];
    float mark;
} Student;

//Function prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NameLength], const float marks[], int count);

int main() {
    Student s[S_Count];
    float marks[S_Count];
    char names[S_Count][NameLength];

    //Loop for entering data of students and marks till s_count(3)
    for (int i = 0; i < S_Count; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", s[i].name);  //scanf with white spaces
        strcpy(names[i], s[i].name); //copy the value of name from student structure array to names array
        printf("Enter the mark of %s: ", s[i].name);
        scanf("%f", &s[i].mark);
        marks[i] = s[i].mark; // Copy mark from student structure array to marks array
    }

    // Calling function for calculation of average marks
    float MarkAvg = calculateAverage(marks, S_Count);

    // Display the Data and Average Marks
    displayStudentData(names, marks, S_Count);
    printf("The average mark is: %.2f\n", MarkAvg);

    return 0;
}

//Function1 (Calculate Average Marks)
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum = sum+marks[i];
    }
    return sum/count;
}

//Function2 (Display Data)
void displayStudentData(const char names[][NameLength], const float marks[], int count) {
    printf("\tStudent Data:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Mark: %.2f\n", names[i], marks[i]);
    }
}