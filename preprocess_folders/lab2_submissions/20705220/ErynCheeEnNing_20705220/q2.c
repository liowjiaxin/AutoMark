#include <stdio.h>

#define STUDENTNUM 3
#define NAMELENGTH 50

// Function prototypes
float calculateAverage(const float mark[], int count);
void displayStudentData(const char name[][NAMELENGTH], const float mark[], int count);

int main() {
    char name[STUDENTNUM][NAMELENGTH];
    float mark[STUDENTNUM];

    
    for (int i = 0; i < STUDENTNUM; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", name[i]); 
        printf("Enter the mark for student %d: ", i + 1);
        scanf("%f", &mark[i]); 
    }

    
    float average = calculateAverage(mark, STUDENTNUM);

    displayStudentData(name, mark, STUDENTNUM);

    printf("\n");

    printf("Average mark: %.2f\n", average);

    return 0;
}


float calculateAverage(const float mark[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += mark[i];
    }
    return sum / count;
}

void displayStudentData(const char name[][NAMELENGTH], const float mark[], int count) {
    printf("Student's Name and Mark:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %.2f\n", name[i], mark[i]);
    }
}
