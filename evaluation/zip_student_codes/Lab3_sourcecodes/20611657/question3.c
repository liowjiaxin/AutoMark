#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for student records in a linked list
typedef struct Student {
    char name[100];         // Student's name
    int id;                 // Student's ID
    float grade;            // Student's grade
    struct Student* next;   // Pointer to the next student in the list
} Student;

// Global pointer to the head of the linked list
Student* head = NULL;

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student)); // Allocate memory for a new student
    strcpy(newStudent->name, name); // Copy the name to the student's record
    newStudent->id = id;           // Set the student's ID
    newStudent->grade = grade;     // Set the student's grade
    newStudent->next = NULL;       // Initialize the next pointer to NULL
    return newStudent;
}

// Function to insert a new student record at the beginning of the list
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade); // Create a new student node
    newStudent->next = head;      // Set the new student's next pointer to the current head
    head = newStudent;            // Update the head to the new student
    printf("Student added successfully!\n");
}

// Function to display all student records
void displayStudents() {
    Student* current = head; // Start from the head of the list
    while (current != NULL) { // Traverse the list until the end
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next; // Move to the next student
    }
}

// Function to search for a student record by ID
Student* searchStudentByID(int id) {
    Student* current = head; // Start from the head of the list
    while (current != NULL) { // Traverse the list until the end
        if (current->id == id) { // Check if the current student's ID matches the given ID
            return current; // Return the found student
        }
        current = current->next; // Move to the next student
    }
    return NULL; // Return NULL if the student is not found
}

// Function to delete the entire linked list
void deleteList() {
    Student* current = head; // Start from the head of the list
    while (current != NULL) { // Traverse the list
        Student* temp = current; // Store the current student
        current = current->next; // Move to the next student
        free(temp); // Free the memory of the current student
    }
    head = NULL; // Set the head to NULL
    printf("List deleted successfully!\n");
}

// Function to sort the students by grade in ascending order
void sortStudents() {
    if (head == NULL || head->next == NULL) return; // If the list is empty or has one student, no need to sort

    // Bubble sort implementation for linked list
    for (Student* i = head; i != NULL; i = i->next) {
        for (Student* j = i->next; j != NULL; j = j->next) {
            if (i->grade > j->grade) { // Compare grades and swap if necessary
                // Swap names
                char tempName[100];
                strcpy(tempName, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, tempName);

                // Swap IDs
                int tempID = i->id;
                i->id = j->id;
                j->id = tempID;

                // Swap grades
                float tempGrade = i->grade;
                i->grade = j->grade;
                j->grade = tempGrade;
            }
        }
    }
    printf("Students sorted by grade!\n");
}

int main() {
    int choice;    // Variable to store user's menu choice
    char name[100]; // Temporary variable to store name input
    int id;        // Temporary variable to store ID input
    float grade;   // Temporary variable to store grade input

    // Menu-driven program for managing student records
    do {
        printf("\nMenu:\n");
        printf("1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1: // Insert a new student record
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin); // Read name input
                strtok(name, "\n"); // Remove the trailing newline character
                printf("Enter ID: ");
                scanf("%d", &id); // Read ID input
                printf("Enter Grade: ");
                scanf("%f", &grade); // Read grade input
                insertStudent(name, id, grade); // Call insert function
                break;
            case 2: // Display all student records
                displayStudents();
                break;
            case 3: // Sort student records by grade
                sortStudents();
                break;
            case 4: // Search for a student record by ID
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Student* found = searchStudentByID(id); // Call search function
                if (found) {
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
                } else {
                    printf("Student not found.\n");
                }
                break;
            case 5: // Delete the entire linked list
                deleteList();
                break;
            case 6: // Exit the program
                printf("Exiting program.\n");
                break;
            default: // Handle invalid menu choice
                printf("Invalid choice!\n");
        }
    } while (choice != 6); // Repeat until the user chooses to exit

    return 0; // Exit the program
}
