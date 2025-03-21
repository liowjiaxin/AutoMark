#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Student
typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next;   // Pointer to the next student 
} Student;

Student* head = NULL;   // Head pointer for linked list of students

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;    // Initially, the next pointer is set to NULL
    return newStudent;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    if (head == NULL) {
        head = newStudent;  // Set new student as head if list is empty
    } else {
        Student* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent; // Link new student to the end of the list
    }
}

// Function to display all student records
void displayStudents() {
     Student* current = head;
    if (current == NULL) {
        printf("No students in the list.\n");
        return;
    }
    printf("Student Records:\n");
    while (current != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* current = head;

    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;    // Return to student node when ID is found
    }
    return NULL; 
}

// Function to delete the entire list
void deleteList() {
    Student* current = head;
    Student* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);      // Free the memory of the current node
        current = next;
    }
    head = NULL;
}

void freeMemory() {
    deleteList();
}

// Sort function to sort the student records by grade using Bubble Sort
void sortStudents() {
    if (head == NULL || head->next == NULL) return; //Nothing to sort

    Student *current, *next;
    int swapped;

    do {
        swapped = 0;
        current = head;
        next = current->next;

        while (next != NULL) {
            if (current->grade > next->grade) {
                // Swap the nodes if current student's grade is greater than next
                char tempName[50];
                strcpy(tempName, current->name);
                strcpy(current->name, next->name);
                strcpy(next->name, tempName);

                int tempID = current->id;
                current->id = next->id;
                next->id = tempID;

                float tempGrade = current->grade;
                current->grade = next->grade;
                next->grade = tempGrade;

                swapped = 1; // Swap one by one
            }
            current = next;
            next = next->next;
        }
    } while (swapped); // Continue until no more swaps

    printf("\nRecords sorted by bubble sort.\n");    // Bubble Sort is chosen for its simplicity and ease of implementation for small data
                                                     // It is stable and performs in-place sorting, making it suitable for this question

}

// Main function to drive the program
int main() {
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
        scanf("%d", &choice);
        getchar(); // To consume the newline character
        
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
                if (found) {
                    printf("Student found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
                } else {
                    printf("Student not found.\n");
                }
                break;
            case 5:
                deleteList();
                printf("List deleted.\n");
                break;
            case 6:
                freeMemory();
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please enter again.\n");
        }
    } while (choice != 6);

    return 0;
}
