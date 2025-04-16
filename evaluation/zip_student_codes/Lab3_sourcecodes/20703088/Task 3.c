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

Student* head = NULL;

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    // Allocate memory for the new student
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // Copy the student's information into the node
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;

    return newStudent; // Return the new student node
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    // Create a new student node
    Student* newStudent = createStudent(name, id, grade);
    if (newStudent == NULL) {
        return; // If memory allocation failed, exit the function
    }

    // If the list is empty, set the new student as the head
    if (head == NULL) {
        head = newStudent;
    } else {
        // Otherwise, traverse to the end of the list and add the student
        Student* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }

    printf("Student record added successfully!\n");
}

// Function to display all student records
void displayStudents() {
    if (head == NULL) {
        printf("No student records to display.\n");
        return;
    }

    Student* temp = head;
    printf("\nStudent Records:\n");
    while (temp != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next;
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* temp = head;

    // Traverse the list to find the student with the given ID
    while (temp != NULL) {
        if (temp->id == id) {
            return temp; // Return the student if found
        }
        temp = temp->next;
    }

    return NULL; // Return NULL if the student is not found
}

// Sort function to sort the student records by grade (simple bubble sort)
void sortStudents() {
    if (head == NULL || head->next == NULL) {
        printf("Not enough students to sort.\n");
        return;
    }

    Student* current;
    Student* next;
    int swapped;

    // Bubble sort algorithm
    do {
        swapped = 0;
        current = head;

        while (current->next != NULL) {
            next = current->next;

            if (current->grade > next->grade) {
                // Swap data between current and next
                char tempName[100];
                int tempId;
                float tempGrade;

                strcpy(tempName, current->name);
                tempId = current->id;
                tempGrade = current->grade;

                strcpy(current->name, next->name);
                current->id = next->id;
                current->grade = next->grade;

                strcpy(next->name, tempName);
                next->id = tempId;
                next->grade = tempGrade;

                swapped = 1;
            }

            current = current->next;
        }
    } while (swapped);

    printf("Students sorted by grade successfully!\n");
}

// Function to delete the entire list
void deleteList() {
    Student* current = head;
    Student* next;

    while (current != NULL) {
        next = current->next;
        free(current); // Free the memory of the current node
        current = next;
    }

    head = NULL; // Set head to NULL since the list is now empty
    printf("All student records have been deleted.\n");
}

// Function to free memory when the program exits
void freeMemory() {
    deleteList();
}

// Main function to drive the program
int main() {
    int choice, id;
    char name[100];
    float grade;

    do {
        printf("\nMenu:\n");
        printf("1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records by Grade\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete All Records\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left in the input buffer

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n"); // Remove the trailing newline character
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
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
                } else {
                    printf("Student with ID %d not found.\n", id);
                }
                break;
            case 5:
                deleteList();
                break;
            case 6:
                freeMemory();
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
