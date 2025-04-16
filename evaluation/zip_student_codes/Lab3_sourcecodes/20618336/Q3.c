#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student record
typedef struct Student {
    char name[100]; // Store the student's name
    int id;         // Store the student's ID
    float grade;    // Store the student's grade
    struct Student* next; // Pointer to the next student in the linked list
} Student;

Student* head = NULL; // Initialize the head of the linked list to NULL

// Function to create a new student
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student)); // Allocate memory for a new student
    if (newStudent == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newStudent->name, name); // Copy the name
    newStudent->id = id;           // Assign the ID
    newStudent->grade = grade;     // Assign the grade
    newStudent->next = NULL;       // Set the next pointer to NULL
    return newStudent;
}

// Function to add a student to the linked list
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    newStudent->next = head; // Add the new student at the beginning
    head = newStudent;
    printf("Student record added successfully!\n");
}

// Function to display all student records
void displayStudents() {
    if (head == NULL) {
        printf("No student records to display.\n");
        return;
    }

    Student* current = head;
    while (current != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

// Function to sort students by grade using Bubble Sort
void sortStudents() {
    if (head == NULL || head->next == NULL) {
        printf("Not enough records to sort.\n");
        return;
    }

    int swapped;
    Student *ptr1, *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->grade > ptr1->next->grade) {
                // Swap data between nodes
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

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    printf("Records sorted by grade successfully.\n");
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current; // Return the student if found
        }
        current = current->next;
    }
    return NULL; // Return NULL if not found
}

// Function to delete all student records
void deleteList() {
    Student* current = head;
    while (current != NULL) {
        Student* temp = current;
        current = current->next;
        free(temp); // Free memory of the current student
    }
    head = NULL; // Reset the head to NULL
    printf("All records deleted successfully.\n");
}

int main() {
    int choice;
    char name[100];
    int id;
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
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';

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
                if (found != NULL) {
                    printf("Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
                } else {
                    printf("No student found with ID %d.\n", id);
                }
                break;

            case 5:
                deleteList();
                break;

            case 6:
                deleteList();
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
