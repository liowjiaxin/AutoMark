#include <stdio.h>

void displayStudentData(const char names[3][50], const float marks[3]) {
    printf ("Student Names and Marks: \n");
    for (int x = 0; x < 3; ++x) {
        puts(names[x]);
        printf (" %.2f\n", *(marks + x));
    }
}

float calculateAverage(const float marks[], int count) {
    float total = 0;
    for (int y = 0; y < count; ++y){
        total += marks[y];
    }
    return total / count;
}


int main (void) {
    
    int count = 3;
    char names[3][50];
    float marks[3];

    for (int i = 0; i < count; ++i) {
        printf ("Enter the name of Student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);

        printf ("Enter the mark of Student %d: ", i + 1);
        scanf("%f", (marks + i));
    }

    displayStudentData (names, marks);

    float sum = calculateAverage(marks, count);
    printf ("\nAverage Mark: %.2f", sum);
}