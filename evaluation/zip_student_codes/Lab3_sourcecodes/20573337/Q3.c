#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Student
typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student *next;
} Student;

//intialise the start to null
Student *head = NULL;

// Function prototypes
Student *createStudent(const char *name, int id, float grade);

void insertStudent(const char *name, int id, float grade);

void displayStudents();

Student *searchStudentByID(int id);

void deleteList();

void freeMemory();

void sortStudents();

void recursiveBubbleSort(Student **headRef, int length);

int getListLength(Student *head);

// Create a new student node
Student *createStudent(const char *name, int id, float grade) {
    Student *newStudent = (Student *) malloc(sizeof(Student));
    if (!newStudent) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

// Insert a new student record
void insertStudent(const char *name, int id, float grade) {
    Student *newStudent = createStudent(name, id, grade);
    if (head == NULL) {
        head = newStudent;
    } else {
        Student *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
    printf("Student record inserted.\n");
}

// Display all student records
void displayStudents() {
    if (head == NULL) {
        printf("No student records to display.\n");
        return;
    }
    Student *temp = head;
    while (temp != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next;
    }
}

// Search for a student by ID
Student *searchStudentByID(int id) {
    // Using ternary operator for concise code
    Student *temp = head ? head : NULL;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Delete the entire list
void deleteList() {
    Student *current = head;
    Student *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

// Free all allocated memory (just calls deleteList here)
void freeMemory() {
    deleteList();
}

// We will use a recursive bubble sort approach for sorting by grade.
// Reason for choosing bubble sort: Easy to implement recursively.
void sortStudents() {
    int length = getListLength(head);
    if (length < 2) {
        printf("No need to sort.\n");
        return;
    }
    recursiveBubbleSort(&head, length);
    printf("Records sorted by grade in ascending order.\n");
}

// Get the length of the list
int getListLength(Student *head) {
    int count = 0;
    Student *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Recursive Bubble Sort: Recursively passes through the list and bubbles up the largest element in each pass.
//What is recursion but fancier iteration
void recursiveBubbleSort(Student **headRef, int length) {
    // Base case
    if (length == 1) return;

    Student *current = *headRef;
    Student *nextNode = current->next;
    Student *prev = NULL;

    for (int i = 0; i < length - 1; i++) {
        if (current->grade > nextNode->grade) {
            // Swap nodes
            if (prev == NULL) {
                // swapping first two nodes
                current->next = nextNode->next;
                nextNode->next = current;
                *headRef = nextNode;
                prev = nextNode;
            } else {
                prev->next = nextNode;
                current->next = nextNode->next;
                nextNode->next = current;
                prev = nextNode;
            }
        } else {
            prev = current;
            current = current->next;
        }
        nextNode = current->next;
        if (nextNode == NULL) {
            break;
        }
    }

    // Recur for the sublist of length-1
    recursiveBubbleSort(headRef, length - 1);
}

// Main program
int main() {
    int choice, id;
    char name[100];
    float grade;
    //using do while loops to make sure the body of code executes at least once
    do {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records (choose sorting method)\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline
        //Using switch as it's faster than if-else and also more easier to debug
        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n");
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Grade: ");
                scanf("%f", &grade);
                insertStudent(name, id, grade);
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                sortStudents();
                break;
            case 4: {
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Student *found = searchStudentByID(id);
                if (found) {
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
                } else {
                    printf("Student not found.\n");
                }
                break;
            }
            case 5:
                deleteList();
                printf("List deleted.\n");
                break;
            case 6:
                freeMemory();
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
