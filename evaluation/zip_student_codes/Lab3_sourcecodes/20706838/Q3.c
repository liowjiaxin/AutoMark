#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for student 
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
    if (!newStudent) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strcpy(newStudent->name, name); // Copy the name
    newStudent->id = id;           // Assign the ID
    newStudent->grade = grade;     // Assign the grades
    newStudent->next = NULL;       // Set the next pointer to NULL
    return newStudent;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    if (!newStudent)
        return;

    newStudent->next = head; // Link the new student to the current head
    head = newStudent;       // Update head to point to the new student
    printf("Student record added.\n");
}

// Function to display all student records
void displayStudents() {
    if (!head) {
        printf("No records to display.\n");
        return;
    }

    Student* current = head;
    printf("Student Records:\n");
    while (current) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next; // Move to the next student
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* current = head;
    while (current) {
        if (current->id == id) {
            return current; // Return the student if ID matches
        }
        current = current->next;
    }
    return NULL; // Return NULL if not found
}

// Function to delete the entire linked list and free the allocated memory
void deleteList() {
    Student* current = head;
    Student* next;

    while (current!= NULL) {
        next = current->next; // Save the next student
        free(current);       // Free the current student
        current = next;      // Move to the next student
    }
    head = NULL; // Set head to NULL to indicate that the list is empty
    printf("All student records deleted.\n");

}

void freeMemory() { 
    deleteList(); 
} 

// Function to sort the students by grade (Bubble Sort)
void sortStudents() {
    if (!head || !head->next) {
        printf("Not enough records to sort.\n");
        return;
    }

    int swapped;
    Student* ptr1;
    Student* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->grade > ptr1->next->grade) {
                // Swap the data of the two nodes
                char tempName[100];
                int tempId;
                float tempGrade;

                strcpy(tempName, ptr1->name);
                tempId = ptr1->id;
                tempGrade = ptr1->grade;

                strcpy(ptr1->name, ptr1->next->name);
                ptr1->id = ptr1->next->id;
                ptr1->grade = ptr1->next->grade;

                strcpy(ptr1->next->name, tempName);
                ptr1->next->id = tempId;
                ptr1->next->grade = tempGrade;

                swapped = 1;
            }
            ptr1 = ptr1->next; // Move to the next pair
        }
        lptr = ptr1; // Reduce the range for sorting
    } while (swapped);

    printf("Records sorted by grade.\n");
}
//Main function to drive the program
int main() {
    int choice, id;
    char name[100];
    float grade;

    do {
        printf("1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records by Grade\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline character

        switch (choice) {
            case 1:
                // Insert a new student record
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n"); // Remove newline character
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Grade: ");
                scanf("%f", &grade);
                insertStudent(name, id, grade);
                break;
            case 2:
                // Display all student records
                displayStudents();
                break;
            case 3:
                // Sort student records by grade
                sortStudents();
                break;
            case 4:
                // Search for a student by ID
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
                // Delete the entire list
                deleteList();
                printf("List deleted.\n"); 
                break;
            case 6:
                // Exit and free memory
                freeMemory();
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
