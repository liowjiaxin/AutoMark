#include <stdio.h>

#define NAME_LENGTH 50
#define number_of_student 3
float calculateAverage(const float marks[], int count) {
    float sum=0;
    for (int i=0; i<count; i++) {
        sum +=marks[i];
    }
    return sum/count;
}

void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    for (int i=0; i<number_of_student; i++) {
        printf("%s:%.2f\n",names[i],marks[i]);
    }
}

int main() {
    char names[number_of_student][NAME_LENGTH];
    float marks[number_of_student];
    int i;

    for (int i=0; i<number_of_student; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]); 
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }
    printf("\nStudent Names and Marks: ");
    displayStudentData(names,marks);
    
    float Average=calculateAverage(marks,number_of_student);
    printf("Average Mark: %.2f",Average);

    return 0;
}


