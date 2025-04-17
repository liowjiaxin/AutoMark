#include <stdio.h>
#include <string.h>
#define NUM_STUDENT 3

struct StudentData {
    char studentName[50];
    float studentMark;
};

int main() {
    struct StudentData persons[NUM_STUDENT];
    float avg;
    

    for(int i=0; i<NUM_STUDENT; i++){
        printf("Enter the name of student: ");
        scanf(" %[^\n]", persons[i].studentName);
        
        printf("Enter the mark of student: ");
        scanf("%f", &persons[i].studentMark);
        getchar();
        
    }

    void displayStudentData(const char names[][50], const float marks[]);

    float calculateAverage(const float marks[], int count);
    printf("Average Mark: %.2f", avg);
    
    return 0;
}
    