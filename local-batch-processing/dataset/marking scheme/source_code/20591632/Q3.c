#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Student
typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next;
} Student;

// Global pointer to the head of the list
Student* head = NULL;

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    // Allocate new memory for new student 
    Student* newStudent = (Student*)malloc(sizeof(Student));  
    if (newStudent == NULL) {  // Check for allocation failure 
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strncpy(newStudent->name, name, sizeof(newStudent->name));  // Copy name
    newStudent->id = id;  // Set ID
    newStudent->grade = grade;  // Set a grade
    newStudent->next = NULL;  // Initialize next pointer to NULL
    return newStudent;  // Return the new student node 
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);  // Create a new student
    if (newStudent == NULL) return;  // Return early if creation fails

    newStudent->next = head;  // Point new student's next to head
    head = newStudent;  // Update head to new student 
}

// Function to display all student records
void displayStudents() {
    Student* current = head;  // Start from head of list 
    if (current == NULL) {  // If list is empty 
        printf("No records to display.\n");
        return;
    }
    printf("\nStudent Records:\n");
    while (current != NULL) {
        // Print details for each student 
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;  // Move to next student after printing 
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* current = head;  // Start from head of list 
    while (current != NULL) {
        // If current student's ID matches
        if (current->id == id) {
            return current;  // Return current student 
        }
        current = current->next;  // Move to next student 
    }
    return NULL;  // Return NULL if not found 
}

// Function to delete the entire list
void deleteList() {
    Student* current = head;  // Start from head of list 
    Student* next;

    while (current != NULL) {
        next = current->next;  // Store next node
        free(current);  // Free current node
        current = next;  // Then move to the next node 
    }
    head = NULL;  // Set head to NULL when list is empty 
    printf("List deleted successfully.\n");
}

// Free memory function
void freeMemory() {
    deleteList();
}

// Sort function to sort the student records by grade using Bubble Sort
void sortStudents() {
    // If there is zero or only one student 
    if (head == NULL || head->next == NULL) {  
        printf("No need to sort; not enough records.\n");
        return;
    }

    int swapped;
    Student* ptr1;
    Student* ptr2 = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != ptr2) {
            if (ptr1->grade > ptr1->next->grade) {  // Compare grades
                // Swap data
                char tempName[100];
                int tempID;
                float tempGrade;

                strncpy(tempName, ptr1->name, sizeof(tempName));
                tempID = ptr1->id;
                tempGrade = ptr1->grade;

                strncpy(ptr1->name, ptr1->next->name, sizeof(ptr1->name));
                ptr1->id = ptr1->next->id;
                ptr1->grade = ptr1->next->grade;

                strncpy(ptr1->next->name, tempName, sizeof(ptr1->next->name));
                ptr1->next->id = tempID;
                ptr1->next->grade = tempGrade;

                swapped = 1;  // Mark if swap occured 
            }
            ptr1 = ptr1->next;  // Move to the next pair 
        }
        ptr2 = ptr1;  // Update last pointer 
    } while (swapped);  // Repeat until no swaps left 

    printf("Records sorted by grade using Bubble Sort.\n");
}


int main(void) {
    int choice, id;
    char name[100];
    float grade;

    do {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        getchar();  // To consume the newline character

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n"); // Remove trailing newline
                printf("Enter ID: ");
                if (scanf("%d", &id) != 1) {
                    printf("Invalid input for ID.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    continue;
                }
                printf("Enter Grade: ");
                if (scanf("%f", &grade) != 1) {
                    printf("Invalid input for grade. Please enter a number.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    continue;
                }
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
                if (scanf("%d", &id) != 1) {
                    printf("Invalid input for ID.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    continue;
                }
                Student* found = searchStudentByID(id);
                if (found) {
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n",
                           found->name, found->id, found->grade);
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
