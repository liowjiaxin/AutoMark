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
    if (newStudent == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    strncpy(newStudent->name, name, sizeof(newStudent->name) - 1);
    newStudent->name[sizeof(newStudent->name) - 1] = '\0';  // Ensuring null termination
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    if (head == NULL) {
        head = newStudent;
    } else {
        newStudent->next = head;
        head = newStudent;
    }
}

// Function to display all student records
void displayStudents() {
    if (head == NULL) {
        printf("No student records to display.\n");
        return;
    }
    Student* temp = head;
    while (temp != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next;
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;  // Return NULL if student not found
}

// Function to delete the entire list
void deleteList() {
    Student* current = head;
    Student* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

// Utility function to free memory
void freeMemory() {
    deleteList();
}

// Sort function to sort the student records by grade using Bubble Sort
void sortStudents() {
    if (head == NULL || head->next == NULL) {
        return;  // No need to sort if the list is empty or has only one element
    }
    int swapped;
    Student* current;
    Student* last = NULL;
    do {
        swapped = 0;
        current = head;
        while (current->next != last) {
            if (current->grade > current->next->grade) {

                // Swap grades and associated student data
                float tempGrade = current->grade;
                int tempID = current->id;
                char tempName[100];
                strncpy(tempName, current->name, sizeof(tempName));

                current->grade = current->next->grade;
                current->id = current->next->id;
                strncpy(current->name, current->next->name, sizeof(current->name));

                current->next->grade = tempGrade;
                current->next->id = tempID;
                strncpy(current->next->name, tempName, sizeof(current->next->name));

                swapped = 1;
            }
            current = current->next;
        }
        last = current;
        
    } while (swapped);
}

// Main function to drive the program
int main() {

    int choice, id;
    char name[100];
    float grade;
    
    do {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records by Grade\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character
        
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
                printf("Records sorted by grade using Bubble Sort.\n");
                break;
            case 4:
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
