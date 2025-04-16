#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Student
typedef struct Student {
    char name[100];      // Student's name
    int id;              // Student's ID
    float grade;         // Student's grade
    struct Student* next; // Pointer to the next student in the list
} Student;

Student* head = NULL; // Pointer to the head of the linked list

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    
    // Step 1: Create a new node
    Student* newStudent = (Student*)malloc(sizeof(Student)); // Allocate memory
    if (newStudent == NULL) {
        printf("Memory allocation failed.\n");
        return NULL; // Return NULL if memory allocation fails
    }
    // Copy data into the new node
    strcpy(newStudent->name, name); // Copy name
    newStudent->id = id;           // Set ID
    newStudent->grade = grade;     // Set grade
    newStudent->next = NULL;       // Initialize 'next' to NULL
    return newStudent;             // Return the new node
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    // Create a new node using createStudent
    Student* newStudent = createStudent(name, id, grade);
    if (newStudent == NULL) {
        printf("Failed to insert student record.\n");
        return;
    }
    // Insert the new node at the beginning of the list
    newStudent->next = head; // Link new node to the current head
    head = newStudent;       // Update head to the new node
    
}

// Function to display all student records
void displayStudents() {
    if (head == NULL) {
        // Check if the list is empty
        printf("No student records to display.\n");
        return;
    }
    // Traverse the list and display each student's details
    Student* current = head;
    while (current != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    // Traverse the list to find the student with the given ID
    Student* current = head;
    while (current != NULL) {
        if (current->id == id) { // Check if the current student's ID matches
            return current; // Return the student node if found
        }
        current = current->next; // Move to the next node
    }
    return NULL; // Return NULL if the student is not found
}

// Function to delete the entire list
void deleteList() {
    // Iterate through the list and free memory for each node
    Student* current = head;
    while (current != NULL) {
        Student* next = current->next; // Store the next node
        free(current);                 // Free the current node
        current = next;                // Move to the next node
    }
    head = NULL; // Set head to NULL to indicate the list is empty
    printf("All student records have been deleted.\n");
}

// Function to sort the students by grade
void sortStudents() {
    if (head == NULL || head->next == NULL) {
        // If the list is empty or has only one node, no sorting is needed
        printf("Not enough students to sort.\n");
        return;
    }
    // Perform a simple bubble sort to arrange students by grade in ascending order
    for (Student* i = head; i != NULL; i = i->next) {
        for (Student* j = i->next; j != NULL; j = j->next) {
            if (i->grade > j->grade) { // Compare grades
                // Swap the data of nodes i and j
                char tempName[100];
                strcpy(tempName, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, tempName);

                int tempId = i->id;
                i->id = j->id;
                j->id = tempId;

                float tempGrade = i->grade;
                i->grade = j->grade;
                j->grade = tempGrade;
            }
        }
    }
    printf("Students sorted by grade in ascending order.\n");
}

// Main function to drive the program
int main() {
    int choice, id;
    char name[100];
    float grade;

    do {
        // Display the menu
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read user input
        getchar(); // Consume the newline character

        switch (choice) {
            case 1:
                // Insert a new student record
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin); // Read name
                strtok(name, "\n");              // Remove trailing newline
                printf("Enter ID: ");
                scanf("%d", &id); // Read ID
                printf("Enter Grade: ");
                scanf("%f", &grade); // Read grade
                insertStudent(name, id, grade);
                break;

            case 2:
                // Display all student records
                displayStudents();
                break;

            case 3:
                // Sort student records by grade
                sortStudents();
                break;

            case 4:
                // Search for a student by ID
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Student* found = searchStudentByID(id);
                if (found) {
                    // Display the student's details if found
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n",
                           found->name, found->id, found->grade);
                } else {
                    printf("Student not found.\n");
                }
                break;

            case 5:
                // Delete the entire list
                deleteList();
                break;

            case 6:
                // Exit the program
                deleteList(); // Free memory before exiting
                printf("Exiting...\n");
                break;

            default:
                // Handle invalid menu choices
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
