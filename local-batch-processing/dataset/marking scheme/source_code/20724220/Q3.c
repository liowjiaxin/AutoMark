#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LEN 100 // define max length for student name

// define a structure to store individual student details
typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next; // pointer to next student in the linked list
} Student; 

Student *head = NULL; // head of the linked list

// function prototypes
Student* createStudent(const char* name, int id, float grade);
void insertStudent(const char* name, int id, float grade);
void displayStudents();
Student* searchStudentByID(Student* head, int id);
void deleteList();
void freeMemory();
void sortStudents(); 
Student* mergeSort(Student* head);
Student* split(Student* head);
Student* merge(Student* left, Student* right);

// Main function to drive the program
int main() {

    int choice, id;
    char name[100];
    float grade; 

    do {
        // Main Menu
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        // handle user choice using switch case
        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n"); // remove trailing newline character
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Grade: ");
                scanf("%f", &grade);
                insertStudent(name, id, grade); // insert student record into linked list
                break;
            case 2:
                displayStudents(); // display all current student records
                break;
            case 3:
                sortStudents(); // sort student records by grade
                printf("Records sorted by grade using merge sort.\n");
                break;
            case 4:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Student* found = searchStudentByID(head, id); // search for student record by ID
                if (found) {
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
                } else {
                    printf("Student not found.\n");
                }
                break;
            case 5:
                deleteList(); // delete all student records
                printf("List deleted.\n");
                break;
            case 6:
                freeMemory();
                printf("Exiting...\n"); // exit the application
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {

    // allocate memory for a new student
    Student* newStudent = (Student*)malloc(sizeof(Student));

    if (!newStudent) {
        // handle memory allocation failure
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // initialise the new student record
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;

    return newStudent;

}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {

    Student *newStudent = createStudent(name, id, grade);
    newStudent->next = head;
    head = newStudent;

}

// Function to display all student records
void displayStudents() {

    // check if there are student records
    if (!head) {
        printf("No existing student records.\n");
        return;
    }

    Student *current = head;
    while (current) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }

}

// Function to search for a student by ID
Student* searchStudentByID(Student* head, int id) {

    Student *current = head;
    while (current) {
        if (current->id == id) { // check if the current student ID matches the search ID
            return current; // student found
        }
        current = current->next;
    }
    return NULL; // No matching student found
}

// Function to delete the entire list
void deleteList() {

    Student* current = head;
    Student* next;

    // free each node and move to the next
    while (current != NULL) { 
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

// Function to free all allocated memory
void freeMemory() {
    deleteList();
}

// Sort function to sort the student records by grade using merge sort
void sortStudents() {

    /* Merge sort is used because
        - it guarantees a time complexity of O(n log n) in the average, best, and worst cases
        - it is a stable sorting algorithm
        - it fits well with linked List because it traverses items in sequential manner, avoid random access
    */

    if (!head || !head->next) return; // No need to sort if list has 0 or 1 node
    head = mergeSort(head);

} 

// Function to do merge sort
Student* mergeSort(Student* head) {

    // Base case: if the list is empty or has only one node, it's already sorted
    if (head == NULL || head->next == NULL) return head;

    // split the list into two havles
    Student *middle = split(head);
    Student *left = head;
    Student *right = middle;

    // recursively sort each half
    left = mergeSort(left);
    right = mergeSort(right);

    // merge the two sorted havles
    return merge(left, right);

}

// Function to split the linked list into havles
Student* split(Student* head) {

    Student* fast = head;
    Student* slow = head;

    // Move fast pointer two steps and slow pointer one step to find the middle
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // split the list into two havles
    Student* middle = slow->next;
    slow->next = NULL; // terminate the first half
    return middle;

}

// function to merge two sorted linked lists
Student* merge(Student* left, Student* right) {

    // If either list is empty, return the other list
    if (left == NULL) return right;
    if (right == NULL) return left;

    // Compare grade and merge the lists
    if (left->grade < right->grade) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }

}