#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the student structure
typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next;
} Student;

// Head pointer for the linked list
Student* head = NULL;

// Helper function to create a new student node
Student* createStudentNode(const char* name, int id, float grade) {
    Student* newNode = (Student*)malloc(sizeof(Student));
    if (newNode == NULL) {
        printf("Error allocating memory!\n");
        return NULL;
    }
    strncpy(newNode->name, name, sizeof(newNode->name) - 1);
    newNode->id = id;
    newNode->grade = grade;
    newNode->next = NULL;
    return newNode;
}

// Inserts a new student record at the beginning of the list
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudentNode(name, id, grade);
    if (newStudent == NULL) return;

    newStudent->next = head;
    head = newStudent;
}

// Displays all student records in the linked list
void displayStudents() {
    if (head == NULL) {
        printf("No records found.\n");
        return;
    }

    Student* current = head;
    while (current != NULL) {
        printf("Name: %-20s ID: %-6d Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

// Searches for a student by their ID
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

// Deletes all records in the linked list and frees memory
void deleteList() {
    Student* current = head;
    Student* temp;

    while (current != NULL) {
        temp = current->next;
        free(current);
        current = temp;
    }
    head = NULL;
}

// Function to recursively merge two sorted sublists
Student* mergeLists(Student* left, Student* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    // If left grade is smaller, it should come first
    if (left->grade <= right->grade) {
        left->next = mergeLists(left->next, right);
        return left;
    } else {
        right->next = mergeLists(left, right->next);
        return right;
    }
}

// Function to split the linked list into two halves
void splitList(Student* source, Student** left, Student** right) {
    Student* slow = source;
    Student* fast = source->next;

    // Move the fast pointer two steps for every slow pointer step
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *left = source;
    *right = slow->next;
    slow->next = NULL;
}

// Merge sort for sorting the linked list
void mergeSort(Student** list) {
    if (*list == NULL || (*list)->next == NULL) {
        return;
    }

    Student* left;
    Student* right;

    // Split the list into two halves
    splitList(*list, &left, &right);

    // Recursively sort the two halves
    mergeSort(&left);
    mergeSort(&right);

    // Merge the sorted halves
    *list = mergeLists(left, right);
}

// Sorts the student records by grade in ascending order
void sortStudents() {
    mergeSort(&head);
}

// Main function to handle user input and interaction
int main() {
    int choice;
    char name[100];
    int id;
    float grade;

    while (1) {
        printf("\nStudent Record Management System\n");
        printf("1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Student Records by Grade\n");
        printf("4. Search for a Student by ID\n");
        printf("5. Delete All Records\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student's full name: ");
                scanf(" %[^\n]", name);  // Allow for spaces in name input
                printf("Enter student ID: ");
                scanf("%d", &id);
                printf("Enter student grade: ");
                scanf("%f", &grade);
                insertStudent(name, id, grade);
                printf("Student record added.\n");
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                sortStudents();
                printf("Records have been sorted by grade in ascending order.\n");
                break;
            case 4:
                printf("Enter the ID of the student to search: ");
                scanf("%d", &id);
                Student* student = searchStudentByID(id);
                if (student != NULL) {
                    printf("Student found: Name: %s, ID: %d, Grade: %.2f\n", student->name, student->id, student->grade);
                } else {
                    printf("No student found with ID %d.\n", id);
                }
                break;
            case 5:
                deleteList();
                printf("All student records have been deleted.\n");
                break;
            case 6:
                deleteList();
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
