#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Student
typedef struct Student {
    char name[100];  // Student name
    int id;          // Student ID
    float grade;     // Student grade
    struct Student* next; // Pointer to the next student node
} Student;

Student* head = NULL; // Head pointer for the linked list

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student)); // Allocate memory for a new student
    if (!newStudent) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newStudent->name, name); // Set student name
    newStudent->id = id;           // Set student ID
    newStudent->grade = grade;     // Set student grade
    newStudent->next = NULL;       // Initialize next pointer to NULL
    return newStudent;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade); // Create a new student node
    newStudent->next = head; // Insert at the beginning of the list
    head = newStudent;       // Update head pointer
    printf("Student record inserted successfully!\n");
}

// Function to display all student records
void displayStudents() {
    if (head == NULL) { // Check if the list is empty
        printf("No student records found.\n");
        return;
    }

    Student* current = head; // Pointer to traverse the list
    printf("\nStudent Records:\n");
    while (current != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next; // Move to the next node
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* current = head; // Pointer to traverse the list
    while (current != NULL) {
        if (current->id == id) { // Check if the current node matches the ID
            return current; // Return the matching node
        }
        current = current->next; // Move to the next node
    }
    return NULL; // Return NULL if not found
}

// Function to delete the entire list
void deleteList() {
    Student* current = head; // Pointer to traverse the list
    Student* next;
    while (current != NULL) {
        next = current->next; // Store the next node
        free(current);        // Free the current node
        current = next;       // Move to the next node
    }
    head = NULL; // Set head pointer to NULL
    printf("All student records deleted successfully!\n");
}

// Utility function to free memory (calls deleteList)
void freeMemory() {
    deleteList();
}

// Sort function to sort the student records by grade in ascending order
void sortStudents() {
    if (head == NULL || head->next == NULL) {
        printf("No sorting needed.\n");
        return;
    }

    // Using Bubble Sort for simplicity
    Student* i;
    Student* j;
    for (i = head; i != NULL; i = i->next) {
        for (j = head; j->next != NULL; j = j->next) {
            if (j->grade > j->next->grade) { // Compare grades
                // Swap student records
                char tempName[100];
                int tempID;
                float tempGrade;

                strcpy(tempName, j->name);
                tempID = j->id;
                tempGrade = j->grade;

                strcpy(j->name, j->next->name);
                j->id = j->next->id;
                j->grade = j->next->grade;

                strcpy(j->next->name, tempName);
                j->next->id = tempID;
                j->next->grade = tempGrade;
            }
        }
    }

    printf("Student records sorted by grade successfully!\n");
}

// Main function to drive the program
int main() {
    int choice, id;
    char name[100];
    float grade;

    do {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records by Grade\n");
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
                strtok(name, "\n"); // Remove newline character
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
