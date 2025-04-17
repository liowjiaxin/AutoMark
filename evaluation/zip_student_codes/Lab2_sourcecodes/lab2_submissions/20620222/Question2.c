#include <stdio.h>

float calculateAverage(const float marks[], int count);

int main(void) {
    char names[3][100];
    float marks[3];
    int i;

    //obtaining the data
    for (i = 0; i < 3; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", names[i]);

        printf("Enter marks of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    float average = calculateAverage(marks, 3);
    printf("Average marks = %.2f\n", average);

    return 0;
}

//calculating the average
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}
