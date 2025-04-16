#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student node
typedef struct Student {
    char name[100]; // Name of the student
    int id;         // ID of the student
    float grade;    // Grade of the student
    struct Student* next; // Pointer to the next student in the list
} Student;

// Head pointer for the linked list
Student* head = NULL;

// Function prototypes
Student* createStudent(const char* name, int id, float grade);
void insertStudent(const char* name, int id, float grade);
void displayStudents();
Student* searchStudentByID(int id);
void deleteList();
void sortStudents();

// Utility function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    // Allocate memory for the new node
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (!newStudent) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    // Copy data into the new node
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a new student record into the linked list
void insertStudent(const char* name, int id, float grade) {
    // Create a new student node
    Student* newStudent = createStudent(name, id, grade);
    // Insert at the beginning of the list
    newStudent->next = head;
    head = newStudent;
    printf("Student record inserted successfully.\n");
}

// Function to display all student records
void displayStudents() {
    if (head == NULL) {
        printf("No student records to display.\n");
        return;
    }
    Student* current = head;
    printf("\nStudent Records:\n");
    while (current != NULL) {
        // Print details of the current student
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

// Function to search for a student record by ID
Student* searchStudentByID(int id) {
    Student* current = head;
    while (current != NULL) {
        // Check if current student matches the ID
        if (current->id == id) {
            return current; // Found the student
        }
        current = current->next;
    }
    return NULL; // Student not found
}

// Function to delete the entire linked list and free memory
void deleteList() {
    Student* current = head;
    while (current != NULL) {
        // Save the current node to free later
        Student* temp = current;
        current = current->next;
        free(temp); // Free each node
    }
    head = NULL;
    printf("All student records deleted successfully.\n");
}

// Function to sort student records by grade (using Bubble Sort for simplicity)
void sortStudents() {
    if (head == NULL || head->next == NULL) {
        // No need to sort if the list is empty or has one element
        return;
    }
    int swapped;
    do {
        swapped = 0;
        Student* current = head;
        while (current->next != NULL) {
            // Compare grades of adjacent nodes
            if (current->grade > current->next->grade) {
                // Swap the data of current node and next node
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

                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
    printf("Student records sorted by grade successfully.\n");
}

int main() {
    int choice;
    char name[100];
    int id;
    float grade;

    do {
        // Display menu options
        printf("\nStudent Record Management System\n");
        printf("1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records by Grade\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete All Records\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert new student
                printf("Enter name: ");
                getchar(); // Consume newline character
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove trailing newline

                printf("Enter ID: ");
                scanf("%d", &id);

                printf("Enter grade: ");
                scanf("%f", &grade);

                insertStudent(name, id, grade);
                break;

            case 2:
                // Display all records
                displayStudents();
                break;

            case 3:
                // Sort records by grade
                sortStudents();
                break;

            case 4:
                // Search for a student by ID
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Student* student = searchStudentByID(id);
                if (student) {
                    printf("Student found: Name: %s, ID: %d, Grade: %.2f\n", student->name, student->id, student->grade);
                } else {
                    printf("Student with ID %d not found.\n", id);
                }
                break;

            case 5:
                // Delete all records
                deleteList();
                break;

            case 6:
                // Exit program
                printf("Exiting the program.\n");
                deleteList(); // Ensure memory is freed before exit
                break;

            default:
                // Handle invalid choice
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
