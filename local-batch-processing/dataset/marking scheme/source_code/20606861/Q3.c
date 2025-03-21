#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Student
typedef struct Student {
    char name[100];         // Student's name
    int id;                 // Student's ID
    float grade;            // Student's grade
    struct Student* next;   // Pointer to the next student in the list
} Student;

Student* head = NULL; // Head pointer for the linked list (initially empty)

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student)); // Allocate memory
    if (newStudent == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strcpy(newStudent->name, name); // Copy name
    newStudent->id = id;            // Assign ID
    newStudent->grade = grade;      // Assign grade
    newStudent->next = NULL;        // Set next pointer to NULL
    return newStudent;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    if (newStudent == NULL) return;

    if (head == NULL) { // If list is empty, make new student the head
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next != NULL) { // Traverse to the end of the list
            temp = temp->next;
        }
        temp->next = newStudent; // Add the new student at the end
    }
    printf("Student added successfully.\n");
}

// Function to display all student records
void displayStudents() {
    if (head == NULL) {
        printf("No student records found.\n");
        return;
    }
    printf("Student Records:\n");
    Student* temp = head;
    while (temp != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next; // Move to the next student
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->id == id) return temp; // Return student if ID matches
        temp = temp->next;              // Move to the next student
    }
    return NULL; // Return NULL if not found
}

// Function to delete the entire list
void deleteList() {
    Student* current = head;
    Student* next;
    while (current != NULL) {
        next = current->next; // Save the next student
        free(current);        // Free the current student's memory
        current = next;       // Move to the next student
    }
    head = NULL; // Reset the list to empty
    printf("All records deleted successfully.\n");
}

// Function to sort students by grade using Bubble Sort
void sortStudents() {
    if (head == NULL || head->next == NULL) {
        printf("Not enough records to sort.\n");
        return;
    }

    int swapped;
    Student *i;
    Student *j = NULL;

    // Perform Bubble Sort
    do {
        swapped = 0;
        i = head;

        while (i->next != j) {
            if (i->grade > i->next->grade) {
                // Swap student details (name, ID, grade)
                char tempName[100];
                int tempID;
                float tempGrade;

                strcpy(tempName, i->name);
                tempID = i->id;
                tempGrade = i->grade;

                strcpy(i->name, i->next->name);
                i->id = i->next->id;
                i->grade = i->next->grade;

                strcpy(i->next->name, tempName);
                i->next->id = tempID;
                i->next->grade = tempGrade;

                swapped = 1; // Mark as swapped
            }
            i = i->next; // Move to the next node
        }
        j = i; // Reduce the unsorted portion of the list
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
        printf("3. Sort Records by Grade\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        // Handle user input based on menu choice
        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin); // Get name input
                strtok(name, "\n");              // Remove trailing newline
                printf("Enter ID: ");
                scanf("%d", &id); // Get ID input
                printf("Enter Grade: ");
                scanf("%f", &grade); // Get grade input
                insertStudent(name, id, grade);
                break;
            case 2:
                displayStudents(); // Display all students
                break;
            case 3:
                sortStudents(); // Sort students by grade
                break;
            case 4:
                printf("Enter ID to search: ");
                scanf("%d", &id); // Get ID to search
                Student* found = searchStudentByID(id);
                if (found) {
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
                } else {
                    printf("Student not found.\n");
                }
                break;
            case 5:
                deleteList(); // Delete all records
                break;
            case 6:
                deleteList(); // Cleanup memory before exiting
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6); // Loop until the user chooses to exit

    return 0;
}
