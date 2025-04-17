#include <stdio.h>
#include <stdlib.h>

#define NAME_LENGTH 50


float calculateAverage(int mark[]) {
    float sum = 0.0;
    for (int i = 0; i < 3; i++) {
        sum += mark[i];
    }
    return sum / 3;
}

void displayStudentData(const char names[][NAME_LENGTH], const int marks[]){
    printf("\nStudent Names and Marks:");
    for (int i = 0; i < 3; i++){    
        printf("\n%s: %d", names[i], marks[i]);
    }
}

int main() {
    
    int marks[3];
    char names[3][NAME_LENGTH];

    for (int i = 0; i < 3; i++){
        printf("Enter the name of student %d:", i + 1);
        scanf("%s", &names[i]);
        printf("Enter the mark of student %d:", i + 1);
        scanf("%d", &marks[i]);
    }

    float avg = calculateAverage(marks);
    displayStudentData(names, marks);

    printf("\nAverage Mark: %.2f", avg);

    return 0;
}