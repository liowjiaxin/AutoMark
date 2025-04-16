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
    Student* newStudent = (Student*)malloc(sizeof(Student)); // Allocate memory for the new node
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL; // Next pointer is NULL as it is the last node
    return newStudent;
}

// Function to insert a new student record
// Creates a new student node and inserts it at the end of the list.
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);

    if (head == NULL) { // First student in list if list is empty
        head = newStudent; 
    } 
    else {
        Student* temp = head; // Temporary pointer to move through link list
        while (temp->next != NULL) { // Determine last node
            temp = temp->next;
        }
        temp->next = newStudent; // Move to next node
    }
}

// Function to display all student records
void displayStudents(void) {
    if (head == NULL) {
        puts("No student records found");
        return;
    }

    Student* temp = head; // Temporary pointer to move through link list
    puts("Student Records:");
    // Display each node
    while (temp != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next;
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* temp = head; // Temporary pointer to move through link list
    while (temp != NULL) {
        if (temp->id == id) {
            return temp; // Student found
        }
        temp = temp->next; // Move to next node
    }
    return NULL; // Student not found
}

// Function to delete the entire list
void deleteList() {
    Student* current = head;  // Pointer to move through link list
    Student* next;  // Pointer to hold the next node
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next; // Move to next node
    }
    head = NULL; // Set the head pointer to NULL after deleting every node
}

void freeMemory() {
    deleteList();
}

// Sort function to sort the student records by grade based on an algorithm of your choice
void sortStudents() {
    if (head == NULL) {
        puts("No student records to sort");
        return;
    }
    int swapped;
    Student* ptr1;
    Student* ptr2 = NULL;

    // Bubble sort
    // Number of passes needed
    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next) {
        // Swap each element in struct Student
        for (Student* ptr2 = head; ptr2->next != NULL; ptr2 = ptr2->next) {
            if (ptr2->grade > ptr2->next->grade) {  // If the current student's grade is greater than the next student's grade
                // Swap the student records
                char tempName[100];  // Temporary variable to store the name during the swap
                int tempID;  // Temporary variable to store the ID during the swap
                float tempGrade;  // Temporary variable to store the grade during the swap

                strcpy(tempName, ptr2->name);  // Swap names
                strcpy(ptr2->name, ptr2->next->name);
                strcpy(ptr2->next->name, tempName);

                tempID = ptr2->id;  // Swap ID
                ptr2->id = ptr2->next->id;
                ptr2->next->id = tempID;

                tempGrade = ptr2->grade;  // Swap grades
                ptr2->grade = ptr2->next->grade;
                ptr2->next->grade = tempGrade;
            }
        }
    }

}

// Main function to drive the program
int main() {
    int choice, id;
    char name[100];
    float grade;
    do {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records (choose sorting method)\n");
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
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
                } 
                else {
                    printf("Student not found.\n");
                }
                break;
            case 5:
                deleteList();
                puts("List deleted");
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