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

Student *head = NULL;

// Function to create a new student node
Student* createStudent(const char *name, int id, float grade) {
    // Allocate memory for the new student node
    Student *newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    // Copy the data into the new node
    strncpy(newStudent->name, name, sizeof(newStudent->name) - 1);
    newStudent->name[strcspn(newStudent->name, "\n")] = 0; // Remove newline character
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;

    return newStudent;
}

// Function to insert a new student record
void insertStudent(const char *name, int id, float grade) {
    // Create a new student node
    Student* newStudent = createStudent(name, id, grade);
    newStudent->next = head; // Link the new student to the current head
    head = newStudent; // Set new student as head
}

// Function to display all student records
void displayStudents() {
    Student* current = head;

    // If the list is empty
    if (current == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("Student Records:\n");
    while (current != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next; // Move to the next student
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* current = head;

    // Traverse the list to find the student with the given ID
    while (current != NULL) {
        if (current->id == id) {
            return current; // Return the student if found
        }
        current = current->next;
    }

    return NULL; // Return NULL if student not found
}

// Function to delete the entire list
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

void freeMemory() {
    deleteList();
}

// Sort function to sort the student records by grade based on an algorithm of your choice
void sortStudents() {

    // If the list is empty
    if (head == NULL) {
        printf("No records to sort.\n");
        return;
    }

    // If there is only one record
    if (head->next == NULL) {
        return;
    }

    int swapped;
    Student *currentStudent;
    Student *lastSorted = NULL;

    // Bubble sort algorithm
    // Reason for using Bubble Sort:
    // - Easy to implement and understand
    // - Suitable for small datasets
    // - Requires only swapping of data
    do {
        swapped = 0;
        currentStudent = head;

        while (currentStudent->next != lastSorted) {
            if (currentStudent->grade > currentStudent->next->grade) {
                // Swap data
                float tempGrade = currentStudent->grade;
                int tempId = currentStudent->id;
                char tempName[100];
                strcpy(tempName, currentStudent->name);
                
                currentStudent->grade = currentStudent->next->grade;
                currentStudent->id = currentStudent->next->id;
                strcpy(currentStudent->name, currentStudent->next->name);
                
                currentStudent->next->grade = tempGrade;
                currentStudent->next->id = tempId;
                strcpy(currentStudent->next->name, tempName);
                
                swapped = 1;
            }
            currentStudent = currentStudent->next;
        }
        lastSorted = currentStudent;
    } while (swapped);

    printf("Records sorted by grade using Bubble Sort.\n");
}

// Main function to drive the program
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
        getchar(); // To consume the newline character

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
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
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