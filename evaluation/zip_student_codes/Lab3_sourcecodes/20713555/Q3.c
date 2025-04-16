#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Student
typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next; // Pointer to the next student in the list
} Student;

Student* head = NULL; // Head of the linked list

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student)); // Allocate memory for a new student
    if (!newStudent) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE); // Exit if memory allocation fails
    }
    strcpy(newStudent->name, name); // Copy name
    newStudent->id = id;             // Set ID
    newStudent->grade = grade;       // Set grade
    newStudent->next = NULL;         // Initialize next pointer to NULL
    return newStudent;                // Return the new student node
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade); // Create a new student node
    newStudent->next = head; // Insert at the beginning of the list
    head = newStudent;       // Update head to point to the new student
}

// Function to display all student records
void displayStudents() {
    if (head == NULL) { // Check if the list is empty
        printf("No student records available.\n");
        return;
    }
    
    Student* current = head; // Start from the head of the list
    printf("\n--- Student Records ---\n");
    
    while (current != NULL) { // Traverse the list
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next; // Move to the next student
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* current = head; // Start from the head of the list

    while (current != NULL) { // Traverse the list
        if (current->id == id) { // Check if ID matches
            return current; // Return pointer to found student
        }
        current = current->next; // Move to the next student
    }
    
    return NULL; // Return NULL if not found
}

// Function to delete the entire list
void deleteList() {
    Student* current = head;
    Student* next;

    while (current != NULL) { // Traverse and free each node
        next = current->next;  // Store next node
        free(current);         // Free current node
        current = next;       // Move to next node
    }

    head = NULL; // Reset head to NULL after deletion
}

// Function to free all memory when exiting the program
void freeMemory() {
    deleteList(); // Ensure all memory is freed before exit
}

// Sort function to sort the student records by grade using Bubble Sort algorithm of your choice
void sortStudents() {
    if (head == NULL || head->next == NULL) {
        return; // No need to sort if list is empty or has one element
    }

    int swapped;
    Student *ptr1;
    Student *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) { // Traverse the list until last sorted element
            if (ptr1->grade > ptr1->next->grade) { // Compare grades for sorting
                // Swap data instead of nodes for simplicity and efficiency.
                char tempName[100];
                int tempID;
                float tempGrade;

                strcpy(tempName, ptr1->name);
                tempID = ptr1->id;
                tempGrade = ptr1->grade;

                strcpy(ptr1->name, ptr1->next->name);
                ptr1->id = ptr1->next->id;
                ptr1->grade = ptr1->next->grade;

                strcpy(ptr1->next->name, tempName);
                ptr1->next->id = tempID;
                ptr1->next->grade = tempGrade;

                swapped = 1; // Set swapped flag to true as we made a swap.
            }
            ptr1 = ptr1->next; // Move to next node.
        }
        lptr = ptr1; // Last sorted element.
    } while (swapped); // Repeat until no swaps are made.
}

// Main function to drive the program
int main() {
    int choice, id;
    char name[100];
    float grade;

    do {
        printf("\n--- Student Records Management ---\n");
        printf("1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records (Ascending order)\n");
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
                strtok(name, "\n");  // Remove newline character from input string.
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Grade: ");
                scanf("%f", &grade);
                insertStudent(name, id, grade);  // Insert new student record.
                break;
            case 2:
                displayStudents();  // Display all records.
                break;
            case 3:
                sortStudents();  // Sort records by grade.
                printf("Records sorted by grade using Bubble Sort.\n");
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
                deleteList();  // Delete all records.
                printf("List deleted.\n");
                break;
            case 6:
                freeMemory();  // Free memory before exiting.
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
    } while (choice != 6);  // Continue until user chooses to exit.

    return 0;
}
