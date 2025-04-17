#include <stdio.h>


int calculate_average(float mark[], int count);
void display(char name[], float mark[]);

int main()
{
    char studentName[3];
    float mark[3];
    for(int i = 0; i < 3; i++) {
        printf("Name of student %d: ", i + 1);
        scanf( " %[^\n]", &studentName[i]);
        printf("Mark: ");
        scanf("%f", &mark[i]);
    }
    display(studentName, mark);
    return 0;
}

int calculate_average(float mark[], int count) {
    float total = 0;
    for(int j = 0; j < count; j++) {
        total += mark[count];
    }
    float average = (float) total / count;
    return average;
}

void display(char name[], float mark[]) {
    for(int k = 0; k < 3; k++) {
    printf("%20s %.2f\n", name[k], mark[k]);
    }
    printf("The average mark of the studetns is %d", calculate_average(mark, 3));
}