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
    Student* newStudent = (Student*)malloc(sizeof(Student));
    strncpy(newStudent->name, name, sizeof(newStudent->name) - 1);
    newStudent->name[sizeof(newStudent->name) - 1] = '\0'; // Ensure null termination
    newStudent->id = id; // Set the ID
    newStudent->grade = grade; // Set the grade
    newStudent->next = NULL; // Set the next pointer to NULL
    return newStudent;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    if (head == NULL) {
        head = newStudent;
        return;
    }
    Student* current = head;
    while (current->next != NULL) { // Find the last node
        current = current->next; // Move to the next node
    } 
    current->next = newStudent; // Insert the new node
}

// Function to display all student records
void displayStudents() {
    if (head == NULL) {
        printf("No student records to display.\n");
        return;
    }
    printf("Student Records (sorted alphabetically):\n");
    Student* current = head;
    while (current != NULL) { // Loop through all nodes
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
        current = current->next;
    }
    return NULL;
}

// Function to delete the entire list
void deleteList() {
    Student* current = head; 
    while (current != NULL) {
        Student* next = current->next; // Save the next node
        free(current); // Free the current node
        current = next; // Move to the next node
    }
    head = NULL;
}

// Function to free memory
void freeMemory() {
    deleteList();
}

// Function to sort the records alphabetically by name
// Using bubble sort:
void sortRecords() {
    if (head == NULL || head->next == NULL) {
        // List is empty or has only one element, no need to sort
        return;
    }

    Student* ptr1 = head; // Pointer to traverse the list
    Student* ptr2 = head->next; 

    while (ptr1 != NULL) { // Loop through the list
        ptr2 = ptr1->next; 
        while (ptr2 != NULL) {
            if (strcmp(ptr1->name, ptr2->name) > 0) { // If the current name is greater than the next name
                // Swap the names 
                char tempName[100]; // Temporary variable to hold the name
                strncpy(tempName, ptr1->name, sizeof(tempName) - 1); // Copy the name
                tempName[sizeof(tempName) - 1] = '\0'; // Ensure null termination

                strncpy(ptr1->name, ptr2->name, sizeof(ptr1->name) - 1); 
                ptr1->name[sizeof(ptr1->name) - 1] = '\0'; 

                strncpy(ptr2->name, tempName, sizeof(ptr2->name) - 1);
                ptr2->name[sizeof(ptr2->name) - 1] = '\0'; 

                // Swap the IDs
                int tempID = ptr1->id;
                ptr1->id = ptr2->id;
                ptr2->id = tempID;

                // Swap the grades
                float tempGrade = ptr1->grade;
                ptr1->grade = ptr2->grade;
                ptr2->grade = tempGrade;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    // List is now sorted, display the sorted records
    displayStudents();
}

int main() {
    int choice, id;
    char name[100];
    float grade;

    do {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records (Alphabetical by Name)\n");
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
                sortRecords();
                // printf("Records sorted alphabetically by name.\n");
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
                deleteList();
                printf("List deleted.\n");
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