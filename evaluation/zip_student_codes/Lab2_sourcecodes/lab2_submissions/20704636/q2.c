#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 3
#define NAME_LENGTH 50

int get_float(const char *prompt, float *dest) {
	int status;
	do {
		fflush(stdin);
		fprintf(stdout, prompt);
		status = scanf(" %f", dest);
		if (status == EOF) {
			return EOF;
		}
	} while (status != 1);

	return 0;
}

int get_name_marks(int index, char *name, float *marks) {
	fflush(stdin);
	fprintf(stdout, "Enter the name of student %d: ", index);
	if (scanf(" %[^\n]", name) == EOF) {
		return EOF;
	}

	char prompt[100];
	sprintf(prompt, "Enter the mark of student %d: ", index);
	return get_float(prompt, marks);
}

void print_students_info(char names[ARRAY_SIZE][NAME_LENGTH], float marks[ARRAY_SIZE]) {
	printf("Student Names and Marks: \n");
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		printf("%s: %.2f\n", names[i], marks[i]);
	}
}

float get_average_marks(float marks[ARRAY_SIZE]) {
	float sum = 0;
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		sum += marks[i];
	}

	return (sum / ARRAY_SIZE);
}

int main(void) {
	char names[ARRAY_SIZE][NAME_LENGTH];
	float marks[ARRAY_SIZE];

	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (get_name_marks(i, names[i], &(marks[i])) == EOF) {
			return 1;
		}
	}

	printf("\n");

	print_students_info(names, marks);

	printf("\n");

	float average_marks = get_average_marks(marks);
	printf("Average Mark: %.2f", average_marks);

	return 0;
}