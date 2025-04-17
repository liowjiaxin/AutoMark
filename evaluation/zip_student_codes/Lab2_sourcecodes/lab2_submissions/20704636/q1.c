#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN_ARRAY_SIZE 5

int get_int(const char *prompt, int *dest) {
	int status;
	do {
		fflush(stdin);
		fprintf(stdout, prompt);
		status = scanf(" %d", dest);
		if (status == EOF) {
			return EOF;
		}
	} while (status != 1);

	return 0;
}

int main(void) {
	int array_size, *arr, index1, index2;

	do {
		if (get_int("Enter the size of the array (N >= 5): ", &array_size) == EOF) {
			return 1;
		}
	} while (array_size < MIN_ARRAY_SIZE);

	arr = malloc(array_size * sizeof(int));
	if (arr == NULL) {
		return 2;
	}

	printf("Enter the array elements: \n");

	char prompt[100];
	for (int i = 0; i < array_size; i++) {
		sprintf(prompt, "Element %d: ", i);
		if (get_int(prompt, &(arr[i])) == EOF) {
			return 1;
		}
	}

	while (true) {
		printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", array_size);
		scanf(" %d %d", &index1, &index2);
		if (index1 >= 0 && index1 < array_size && index2 >= 0 && index2 < array_size) {
			break;
		} else {
			fprintf(stderr, "Error: Indices must be within the range of the array elements. Please try again.\n");
		}
	}

	printf("The sum of the values at indices %i and %i is: %i\n", index1, index2, arr[index1] + arr[index2]);

	free(arr);

	return 0;
}