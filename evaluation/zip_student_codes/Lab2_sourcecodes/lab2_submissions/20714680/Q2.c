//Q2 
#include <stdio.h>
#include <string.h>

float calculateAverage(const float marks[], int count) {
    int sum =0;
    for(int i = 0; i<count;i++) {
        sum += marks[i];
}
    float calculateAverage = (float) sum/3;
}

void displayStudentData(const char names[][100], const float marks[]) {
    
}


int main(void) {
    char name1[100], name2[100], name3[100];
    float marks[3];
    float result;
    
    printf("Enter the name of student 1: ");
    fgets(name1,100,stdin);

    printf("Enter the mark of student 1: ");
    scanf("%f", &marks[0]);
    getchar();
    
    printf("Enter the name of student 2: ");
    fgets(name2,100,stdin);

    printf("Enter the mark of student 2: ");
    scanf("%f", &marks[1]);
    getchar();
    
    printf("Enter the name of student 3: ");
    fgets(name3,100,stdin);
    
    printf("Enter the mark of student 3: ");
    scanf("%f", &marks[2]);
    getchar();

    result = calculateAverage(marks,3);
    printf("Average Mark: %.2f", result);
}