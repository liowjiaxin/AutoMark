#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

typedef struct s_student {
	char name[100];
	int id;
	float grade;
}	t_student;

typedef struct s_list {
	t_student *student;
	struct s_list *next;
}	t_list;

static void print_menu(void) {
	puts("1. Insert Student Record");
	puts("2. Display Student Records");
	puts("3. Sort Records");
	puts("4. Search Record by ID");
	puts("5. Delete List");
	puts("6. Exit");
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

	fflush(stdin);
	return 0;
}

void list_add_back(t_list **head, t_student *student) {
	t_list *new_node = (t_list *)malloc(sizeof(t_list));
	if (*head == NULL) {
		// If the list is empty
		new_node->student = student;
		new_node->next = NULL;
		*head = new_node;
		return;
	}

	t_list *tmp = *head;
	// Find the last node
	while (tmp != NULL) {
		if (tmp->student->id == student->id) {
			fprintf(stderr, "Student with ID %d already exists.\n", student->id);
			free(new_node);
			return;
		}
		if (tmp->next == NULL) {
			break;
		}
		tmp = tmp->next;
	}

	// Add the new node to the last node
	new_node->student = student;
	new_node->next = NULL;
	tmp->next = new_node;
}

void list_display(t_list *head) {
	for (t_list *tmp = head; tmp != NULL; tmp = tmp->next) {
		printf("Name: %s, ID: %d, Grade: %.2f\n", tmp->student->name, tmp->student->id, tmp->student->grade);
	}
}

t_student *list_search_by_id(t_list *head, int id) {
	t_list *tmp = head;

	while (tmp != NULL) {
		if (tmp->student->id == id) {
			return tmp->student;
		}
		tmp = tmp->next;
	}

	return NULL;
}

void list_delete(t_list **head) {
	t_list *tmp = *head;
	t_list *next = NULL;

	while (tmp != NULL) {
		next = tmp->next;
		free(tmp->student);
		free(tmp);
		tmp = next;
	}

	*head = NULL;
}

/**
 * Bubble sort
 * I use bubble sort because it is in-place, simple and easy to implement.
 * If the dataset is large, I would use quicksort, but quicksort will need to convert the linked list to array first.
 * Which needs extra memory.
 */
void list_sort_by_grade(t_list *head) {
	if (head == NULL) {
		return;
	}

	t_list *tmp = head;
	t_list *tmp2 = head;
	t_student *student = NULL;

	while (tmp != NULL) {
		while (tmp2 != NULL) {
			if (tmp->student->grade > tmp2->student->grade) {
				student = tmp->student;
				tmp->student = tmp2->student;
				tmp2->student = student;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

static void cmd_add_student(t_list **head) {
	t_student *student = (t_student *)malloc(sizeof(t_student));
	if (student == NULL) {
		fprintf(stderr, "Failed to allocate memory\n");
		exit(1);
	}

	printf("Enter name: ");
	scanf(" %100[^\n]", student->name);

	if (get_int(&student->id, "Enter ID: ") == EOF) {
		free(student);
		return;
	}

	printf("Enter grade: ");
	if (scanf(" %f", &student->grade) == EOF) {
		free(student);
		return;
	}

	list_add_back(head, student);
	printf("\n");
}

static void cmd_display_students(t_list *head) {
	if (head == NULL) {
		puts("No records found.");
		printf("\n");
		return;
	}
	list_display(head);
	printf("\n");
}

static void cmd_sort_students(t_list *head) {
	list_sort_by_grade(head);
	puts("Records sorted by grade using bubble sort.");
	printf("\n");
}

static void cmd_search_student_by_id(t_list *head) {
	int id = 0;
	if (get_int(&id, "Enter ID to search: ") == EOF) {
		return;
	}

	t_student *student = list_search_by_id(head, id);
	if (student == NULL) {
		puts("Student not found.");
	} else {
		printf("Name: %s, ID: %d, Grade: %.2f\n", student->name, student->id, student->grade);
	}
	printf("\n");
}

static void cmd_list_delete(t_list **head) {
	list_delete(head);
	puts("List deleted.");
	printf("\n");
}

void loop_do_op(t_list **head) {
	int choice = 0;
	while (true) {
		print_menu();

		if (get_int(&choice, "Enter your choice: ") == EOF) {
			break;
		}

		switch (choice) {
			case 1:
			 	cmd_add_student(head);
				break;
			case 2:
				cmd_display_students(*head);
				break;
			case 3:
				cmd_sort_students(*head);
				break;
			case 4:
				cmd_search_student_by_id(*head);
				break;
			case 5:
				cmd_list_delete(head);
				break;
			case 6:
				list_delete(head);
				puts("Exiting...");
				return;
			default:
				printf("Invalid choice.\n\n");
		}
	}
}

int main(void) {
	t_list *head = NULL;

	loop_do_op(&head);

	return 0;
}