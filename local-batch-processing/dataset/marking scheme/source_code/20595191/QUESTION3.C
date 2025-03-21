#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Student
typedef struct Student {
    char name[100];  // The name of the student (up to 100 characters)
    int id;          // The unique ID for the student
    float grade;     // The grade of the student
    struct Student* next;  // Pointer to the next student in the list
} Student;

Student* head = NULL;  // This points to the start of the linked list

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    // Allocate memory for a new student
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (!newStudent) {
        printf("Oops! Memory allocation failed.\n");
        exit(1);  // Exit the program if we can't allocate memory
    }
    // Fill in the student's details
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;  
    return newStudent;  
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    // Create a new student
    Student* newStudent = createStudent(name, id, grade);
    // Add the new student to the front of the list
    newStudent->next = head;
    head = newStudent;  // Update the head to point to the new student
    printf("Great! Student record added successfully.\n");
}

// Function to display all student records
void displayStudents() {
    if (head == NULL) {  // Check if the list is empty
        printf("No student records found.\n");
        return;
    }
    Student* current = head;  // Start from the beginning of the list
    while (current != NULL) {  // Go through each student
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;  // Move to the next student
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* current = head;  // Start at the beginning
    while (current != NULL) {  // Go through each student
        if (current->id == id) {  // Found a match
            return current;
        }
        current = current->next;  // Move to the next student
    }
    return NULL;  // If no match is found, return NULL
}

// Function to delete the entire list
void deleteList() {
    Student* current = head;  // Start at the beginning
    Student* next;
    while (current != NULL) {  // Go through each student
        next = current->next;  // Save the next student
        free(current);  // Free the memory for the current student
        current = next;  // Move to the next student
    }
    head = NULL;  // The list is now empty
    printf("All student records have been deleted.\n");
}

// Sort function to sort the student records by grade using Bubble Sort
void sortStudents() {
    if (head == NULL || head->next == NULL) {  // Check if the list is empty or has just one student
        printf("No records to sort.\n");
        return;
    }

    Student* i;
    Student* j;
    float tempGrade;
    int tempId;
    char tempName[100];

    // Bubble sort algorithm
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->grade > j->grade) {  // Compare the grades
                // Swap grades
                tempGrade = i->grade;
                i->grade = j->grade;
                j->grade = tempGrade;

                // Swap IDs
                tempId = i->id;
                i->id = j->id;
                j->id = tempId;

                // Swap names
                strcpy(tempName, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, tempName);
            }
        }
    }

    printf("Records sorted by grade using Bubble Sort.\n");
}

// Function to free memory when exiting
void freeMemory() {
    deleteList();  // Reuse deleteList to clean up everything
}

// Main function to drive the program
int main() {
    int choice, id;
    char name[100];
    float grade;

    do {
        // Display menu
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
                // Add a new student record
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
                // Show all student records
                displayStudents();
                break;
            case 3:
                // Sort records by grade
                sortStudents();
                break;
            case 4:
                // Search for a specific student by ID
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
                // Delete the entire list of records
                deleteList();
                break;
            case 6:
                // Exit the program
                freeMemory();
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);  // Keep showing the menu until the user exits

    return 0;
}
