#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a Student
typedef struct Student {
    char name[100];          // Name of the student
    int id;                  // ID of the student
    float grade;             // Grade of the student
    struct Student* next;    // Pointer to the next student in the list
} Student;

Student* head = NULL; // Head pointer for the linked list

// Function prototypes
Student* createStudent(const char* name, int id, float grade);
void insertStudent(const char* name, int id, float grade);
void displayStudents();
Student* searchStudentByID(int id);
void deleteList();
void sortStudents();

// Main function to drive the program
int main() {
    int choice, id;
    char name[100];
    float grade;

    do {
        printf("\nChoose an operation:\n");
        printf("1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records by Grade\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n"); // Remove trailing newline
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Grade: ");
                scanf("%f", &grade);
                insertStudent(name, id, grade); // Insert new student
                break;
            case 2:
                displayStudents(); // Display all students
                break;
            case 3:
                sortStudents(); // Sort students by grade
                break;
            case 4:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Student* found = searchStudentByID(id); // Search for a student by ID
                if (found) {
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
                } else {
                    printf("Student not found.\n");
                }
                break;
            case 5:
                deleteList(); // Delete the entire list
                printf("List deleted.\n");
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to create a new student node
// Allocates memory and initializes the fields
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student)); // Allocate memory for a new node
    if (!newStudent) {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }
    // Assign values to the node's fields
    strcpy(newStudent->name, name); // Copy the name to the struct
    newStudent->id = id;            // Assign the ID
    newStudent->grade = grade;      // Assign the grade
    newStudent->next = NULL;        // Initialize the next pointer to NULL
    return newStudent;
}

// Function to insert a new student into the linked list
// Adds the student at the end of the list
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade); // Create a new student node
    if (!newStudent) return;

    if (head == NULL) {
        head = newStudent; // If the list is empty, the new student becomes the head
    } else {
        Student* temp = head;
        while (temp->next != NULL) {
            temp = temp->next; // Traverse to the end of the list
        }
        temp->next = newStudent; // Link the new student to the end of the list
    }
    printf("Student added successfully.\n");
}

// Function to display all students
// Traverses the list and prints each student's details
void displayStudents() {
    if (head == NULL) {
        printf("No students to display.\n");
        return;
    }
    Student* temp = head;
    printf("\nStudent Records:\n");
    while (temp != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next; // Move to the next node
    }
}

// Function to search for a student by ID
// Returns a pointer to the found student node or NULL if not found
Student* searchStudentByID(int id) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp; // If the ID matches, return the current node
        }
        temp = temp->next; // Move to the next node
    }
    return NULL; // Student not found
}

// Function to delete the entire linked list
// Frees all allocated memory
void deleteList() {
    Student* temp = head;
    while (temp != NULL) {
        Student* next = temp->next; // Store the next node
        free(temp); // Free the current node's memory
        temp = next; // Move to the next node
    }
    head = NULL; // Reset head to NULL
}

// Function to sort students by grade
// Implements Bubble Sort for simplicity
void sortStudents() {
    if (head == NULL || head->next == NULL) {
        printf("Not enough students to sort.\n");
        return;
    }

    int swapped;
    do {
        swapped = 0;
        Student* current = head;
        while (current->next != NULL) {
            if (current->grade > current->next->grade) {
                // Swap the grade values
                float tempGrade = current->grade;
                current->grade = current->next->grade;
                current->next->grade = tempGrade;

                // Swap the ID values
                int tempID = current->id;
                current->id = current->next->id;
                current->next->id = tempID;

                // Swap the name values
                char tempName[100];
                strcpy(tempName, current->name);
                strcpy(current->name, current->next->name);
                strcpy(current->next->name, tempName);

                swapped = 1; // Indicate a swap occurred
            }
            current = current->next; // Move to the next node
        }
    } while (swapped);

    printf("Students sorted by grade.\n");
}
