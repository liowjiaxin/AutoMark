#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

static void error_exit(const char *msg) {
	fprintf(stderr, msg);
	exit(1);
}

static void free_matrix(int **m, int rows) {
	for (int i = 0; i < rows; ++i) {
		free(m[i]);
	}
	free(m);
}

static int get_int(int *input, const char *format, ...) {
	va_list args;

    // print the formatted string
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    if (scanf("%d", input) == EOF) {
		return EOF;	
	}

	return 0;
}

static int **get_matrix_values(const char *name, int *rows, int *cols) {
	// get rows and cols
	printf("Enter dimensions for Matrix A (rows and columns): ");
	if (scanf(" %d %d", rows, cols) == EOF) {
		return NULL;
	}

	if (*rows > 10 || *cols > 10) {
		fprintf(stderr, "The maximum size of the matrix is 10 * 10\n");
		return NULL;
	}

	if (rows <= 0 || cols <= 0) {
		fprintf(stderr, "Invalid rows or columns.\n");
		return NULL;
	}

	// malloc the 2D matrix
	int **m = malloc(sizeof(int *) * (*rows));
	if (m == NULL) {
		error_exit("malloc error.\n");
	}

	for (int i = 0; i < *rows; ++i) {
		m[i] = malloc(sizeof(int) * (*cols));
		if (m[i] == NULL) {
			error_exit("malloc error.\n");
		}
	}

	// loop to get each value of the matrix
	for (int i = 0; i < *rows; ++i) {
		for (int j = 0; j < *cols; ++j) {
			if (get_int(&(m[i][j]), "Element [%d][%d]: ", i + 1, j + 1) == EOF) {
				free_matrix(m, *rows);
				return NULL;			
			}
		}
	}

	return m;
}

static void print_matrix_op_menu(void) {
	puts("Matrix Operations Menu:");
	puts("1. Add Matrices");
	puts("2. Subtract Matrices");
	puts("3. Transpose Matrix A");
	puts("4. Transpose Matrix B");
	puts("5. Exit");
}

// the operator for matrix addition
static int add(int a, int b) {
	return a + b;
}

// the operator for matrix subtraction
static int sub(int a, int b) {
	return a - b;
}

static void matrices_op(int **A, int **B, int ra, int ca, int rb, int cb, char operator) {
	// error handling
	if (ra != rb || ca != cb) {
		fprintf(stderr, "Matrix A and B doesn't have the same shape!\n");
		return;
	}

	int (*op)(int, int) = NULL;	

	if (operator == '+') {
		op = add;
	} else if (operator == '-') {
		op = sub;
	} else {
		fprintf(stderr, "Invalid operator.\n");
		return;
	}

	// print out the added matrix
	for (int i = 0; i < ra; ++i) {
		for (int j = 0; j < ca; ++j) {
			int result = op(A[i][j], B[i][j]);
			printf("%d", result);
			if (j != ca - 1) {
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("\n");
}

void transpose(int **m, int rows, int cols) {
	for (int i = 0; i < cols; ++i) {
		for (int j = 0; j < rows; ++j) {
			printf("%d", m[j][i]);
			if (j != rows - 1) {
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("\n");
}

void loop_do_op(int **A, int **B, int ra, int ca, int rb, int cb) {
	int choice = 0;
	while (true) {
		print_matrix_op_menu();

		// scanf for choice
		if (get_int(&choice, "Enter your choice: ") == EOF) {
			return;
		}

		// do op, print result (or exit)
		switch (choice) {
			case 1:
				puts("Result of Matrix A + Matrix B:");
				matrices_op(A, B, ra, ca, rb, cb, '+');
				break;
			case 2:
				puts("Result of Matrix A - Matrix B:");
				matrices_op(A, B, ra, ca, rb, cb, '-');
				break;
			case 3:
				puts("Tranpose of Matrix A:");
				transpose(A, ra, ca);
				break;
			case 4:
				puts("Tranpose of Matrix B:");
				transpose(B, rb, cb);
				break;
			case 5:
				puts("Exiting...");
				return;
			default:
				printf("Invalid choice.\n");
		}
	}
}

int main(void) {
	int **A, **B, ra, ca, rb, cb;

	A = get_matrix_values("A", &ra, &ca);
	if (A == NULL) {
		return 1;
	}

	B = get_matrix_values("B", &rb, &cb);
	if (B == NULL) {
		return 1;
	}

	loop_do_op(A, B, ra, ca, rb, cb);

	free_matrix(A, ra);
	free_matrix(B, rb);

	return 0;
}