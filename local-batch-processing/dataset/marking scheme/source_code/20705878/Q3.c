#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a student node
typedef struct Student {
    char name[100];       // Student name
    int id;               // Student ID
    float grade;          // Student grade
    struct Student* next; // Pointer to the next node
} Student;

Student* head = NULL;     // Pointer to the head of the linked list

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));      // Allocate memory for the new student
    strcpy(newStudent->name, name); // Copy name to the new student
    newStudent->id = id;            // Set ID
    newStudent->grade = grade;      // Set Grade
    newStudent->next = NULL;        // Initialize next pointer to NULL
    return newStudent;              // Return the new student node
}

// Function to insert a student record into the linked list
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);         // Create a new student node
    newStudent->next = head;                                      // Insert at the beginning of the list
    head = newStudent;                                            // Update head to point to the new student
    printf("Student record inserted successfully!\n");
}

// Function to display all student records
void displayStudents() {
    Student* temp = head;            // Start from the head of the list
    if (temp == NULL) {
        printf("No student records available.\n");
        return;
    }
    printf("\nStudent Records:\n");
    while (temp != NULL) {           // Traverse the list
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next;           // Move to the next node
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* temp = head;                        // Start from the head of the list
    while (temp != NULL) {                       // Traverse the list
        if (temp->id == id) return temp;         // Return the student if ID matches
        temp = temp->next;                       // Move to the next node
    }
    return NULL;                                 // Return NULL if not found
}

// Function to delete the entire linked list
void deleteList() {
    Student* temp = head;
    while (temp != NULL) {                // Traverse the list
        Student* next = temp->next;       // Save the next node
        free(temp);                       // Free the current node
        temp = next;                      // Move to the next node
    }
    head = NULL; // Reset head
    printf("All student records deleted successfully.\n");
}

// Function to sort students by grade using bubble sort
void sortStudents() {
    if (!head || !head->next) return;                          // No sorting needed for 0 or 1 element
    int swapped;
    do {
        swapped = 0;
        Student* current = head;
        Student* prev = NULL;
        while (current->next != NULL) {                        // Traverse the list
            if (current->grade > current->next->grade) {       // Swap if out of order
                // Swap logic
                Student* temp = current->next;
                current->next = temp->next;
                temp->next = current;
                if (prev == NULL) head = temp;                 // Update head if swapping the first node
                else prev->next = temp;
                swapped = 1;
            }
            prev = current;        // Move to the next node
            current = current->next;
        }
    } while (swapped);             // Repeat until no swaps
    printf("Student records sorted by grade successfully!\n");
}

int main() {
    int choice, id;
    char name[100];
    float grade;
    do {
        printf("\nStudent Records Management:\n");
        printf("1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records by Grade\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete All Records\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();    // Consume newline
        
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
                if (found) printf("Found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
                else printf("Student not found.\n");
                break;
            case 5:
                deleteList();
                break;
            case 6:
                deleteList();
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}
