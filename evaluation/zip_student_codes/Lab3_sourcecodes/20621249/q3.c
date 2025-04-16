#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Student
typedef struct Student {
    char name[100];            // Name of the student
    int id;                    // ID of the student
    float grade;               // Grade of the student
    struct Student* next;      // Pointer to the next student in the list
} Student;

// Pointer to the head of the linked list
Student* head = NULL;

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student)); // Allocate memory for a new student
    if (!newStudent) { // Check for memory allocation failure
        printf("Memory allocation has failed!\n");
        exit(1);
    }

    // Assign values to the new student node
    strcpy((*newStudent).name, name);
    (*newStudent).id = id;
    (*newStudent).grade = grade;
    (*newStudent).next = NULL;
    return newStudent; // Return the new student node
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade); // Create a new student
    if (!head) { // If the list is empty, make the new student the head
        head = newStudent;
    } else {
        Student* current = head; // Traverse to the end of the list
        while ((*current).next) {
            current = (*current).next;
        }
        ((*current).next) = newStudent; // Add the new student at the end
    }
}

// Function to display all student records
void displayStudents() {
    if (!head) { // Check if the list is empty
        printf("No student records found!\n");
        return;
    }
    Student* current = head; // Start from the head
    while (current) { // Traverse and display each student
        printf("Name: %s, ID: %d, Grade: %.2f\n", (*current).name, (*current).id, (*current).grade);
        current = (*current).next;
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* current = head; // Start from the head
    while (current) { // Traverse the list
        if ((*current).id == id) { // Check if the current student's ID matches
            return current;
        }
        current = (*current).next; // Move to the next student
    }
    return NULL; // Return NULL if the student is not found
}

// Function to delete the entire list
void deleteList() {
    Student* current = head; // Start from the head
    Student* next;
    while (current != NULL) { // Traverse and free each node
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL; // Reset the head pointer
}

// Wrapper function to delete the list (free all memory)
void freeMemory() {
    deleteList();
}

// Function to sort the student records by grade using Bubble Sort
void sortStudents() {
    if (!head || !(*head).next) { // Check if sorting is necessary
        printf("No need to sort.\n");
        return;
    }

    int swapped;
    Student* current;
    Student* lastnode = NULL;

    do {
        swapped = 0;
        current = head;
        while ((*current).next != lastnode) { // Traverse the list
            if ((*current).grade > (*(*current).next).grade) { // Compare grades
                // Swap data between current and next node
                char tempname[100];
                int tempid;
                float tempgrade;

                strcpy(tempname, (*current).name);
                tempid = (*current).id;
                tempgrade = (*current).grade;

                strcpy((*current).name, (*(*current).next).name);
                (*current).id = (*(*current).next).id;
                (*current).grade = (*(*current).next).grade;

                strcpy((*(*current).next).name, tempname);
                (*(*current).next).id = tempid;
                (*(*current).next).grade = tempgrade;

                swapped = 1; // Mark as swapped
            }
            current = (*current).next; // Move to the next node
        }
        lastnode = current; // Update the last sorted node
    } while (swapped);

    printf("Records sorted by grade using Bubble Sort.\n");
}

// Main function to drive the program
int main() {
    int choice, id;
    char name[100];
    float grade;

    do {
        // Display menu options
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records (choose sorting method)\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice) {
            case 1: // Insert a new student
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n"); // Remove newline character
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Grade: ");
                scanf("%f", &grade);
                insertStudent(name, id, grade);
                break;
            case 2: // Display all students
                displayStudents();
                break;
            case 3: // Sort students by grade
                sortStudents();
                break;
            case 4: // Search for a student by ID
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Student* found = searchStudentByID(id);
                if (found) {
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
                } else {
                    printf("Student not found.\n");
                }
                break;
            case 5: // Delete the list
                deleteList();
                printf("List deleted.\n");
                break;
            case 6: // Exit the program
                freeMemory();
                printf("Exiting...\n");
                break;
            default: // Invalid input
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6); // Repeat until the user chooses to exit

    return 0;
}
