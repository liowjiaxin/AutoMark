#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next;
} Student;

// Head pointer for the linked list.
Student* head = NULL;

// Function to create a new student node.
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent) {
        strcpy(newStudent->name, name);
        newStudent->id = id;
        newStudent->grade = grade;
        newStudent->next = NULL;
    }
    return newStudent;
}

// Function to insert a new student record.
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    if (!newStudent) {
        printf("Memory allocation failed.\n");
        return;
    }

    newStudent->next = head;
    head = newStudent; // Insert at the beginning of the list.
    printf("Student record inserted successfully.\n");
}

// Function to display all student records.
void displayStudents() {
    if (head == NULL) {
        printf("No student records currently available.\n");
        return;
    }

    printf("\nCurrent student records are as follows:\n");
    Student* current = head;
    while (current) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

// Function to search for a student by ID.
Student* searchStudentByID(int id) {
    Student* current = head;
    while (current) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete the entire list.
void deleteList() {
    Student* current = head;
    Student* next;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }

    head = NULL; // Set head to NULL after deletion.
}

void sortStudents() {
    if (head == NULL || head->next == NULL) {
        printf("No need to sort. List is empty or contains only one record.\n");
        return;
    }

    bool swapped;
    do {
        swapped = false;
        Student* current = head;
        while (current->next) {
            if (current->grade > current->next->grade) {
                // Swap the data.
                char tempName[100];
                int tempID;
                float tempGrade;

                strcpy(tempName, current->name);
                tempID = current->id;
                tempGrade = current->grade;

                strcpy(current->name, current->next->name);
                current->id = current->next->id;
                current->grade = current->next->grade;

                strcpy(current->next->name, tempName);
                current->next->id = tempID;
                current->next->grade = tempGrade;

                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);

    printf("Records sorted by grade using Bubble Sort.\n");
}

// Function to free memory when exit.
void freeMemory() {
    deleteList();
}

int main() {
    int choice, id;
    char name[100];
    float grade;

    do {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer.

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
            case 4:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Student* found = searchStudentByID(id);
                if (found) {
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n", 
                           found->name, found->id, found->grade);
                } else {
                    printf("Student not found.\n");
                }
                break;
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