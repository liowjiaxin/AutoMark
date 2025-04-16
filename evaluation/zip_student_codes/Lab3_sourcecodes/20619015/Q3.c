#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next;
} Student;

// Head pointer to the linked list
Student* head = NULL;

// Function prototypes
Student* createStudent(const char* name, int id, float grade);
void insertStudent(const char* name, int id, float grade);
void displayStudents();
Student* searchStudentByID(int id);
void deleteList();
void freeMemory();
void sortStudents();

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
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

// Function to insert a new student record into the linked list
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    newStudent->next = head;
    head = newStudent;
    printf("Student record inserted successfully!\n");
}

// Function to display all student records
void displayStudents() {
    if (head == NULL) {
        printf("No student records available.\n");
        return;
    }

    Student* current = head;
    printf("\n-- Student Records --\n");
    while (current != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;  // Student not found
}

// Function to delete the entire list
void deleteList() {
    Student* current = head;
    Student* temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    head = NULL;
}

// Function to free the memory when the program exits
void freeMemory() {
    deleteList();
}

// Function to sort the student records by grade 
void sortStudents() {
    if (head == NULL || head->next == NULL) {
        return;  // List is empty or has only one element
    }

    Student* current;
    Student* next;
    float tempGrade;
    int tempID;
    char tempName[100];

    // Bubble Sort
    for (current = head; current != NULL; current = current->next) {
        for (next = current->next; next != NULL; next = next->next) {
            if (current->grade > next->grade) {
                // Swap the student data
                strcpy(tempName, current->name);
                strcpy(current->name, next->name);
                strcpy(next->name, tempName);

                tempID = current->id;
                current->id = next->id;
                next->id = tempID;

                tempGrade = current->grade;
                current->grade = next->grade;
                next->grade = tempGrade;
            }
        }
    }
}

// Main function
int main() {
    int choice, id;
    char name[100];
    float grade;
    Student* student;

    do {
        printf("\n-- Student Records Menu --\n");
        printf("1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student name: ");
                getchar();  // To consume the newline left by scanf
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';  

                printf("Enter student ID: ");
                scanf("%d", &id);

                printf("Enter student grade: ");
                scanf("%f", &grade);

                insertStudent(name, id, grade);
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                sortStudents();
                printf("Student records sorted by grade using Bubble Sort.\n");
                break;

            case 4:
                printf("Enter student ID to search: ");
                scanf("%d", &id);

                student = searchStudentByID(id);
                if (student != NULL) {
                    printf("Student Found: %s (ID: %d, Grade: %.2f)\n", student->name, student->id, student->grade);
                } else {
                    printf("Student with ID %d not found.\n", id);
                }
                break;

            case 5:
                deleteList();
                printf("All student records deleted.\n");
                break;

            case 6:
                freeMemory();
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}