#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a Student Node
typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next;
} Student;

Student* head = NULL; // Head pointer for the linked list

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    newStudent->next = head;
    head = newStudent;
    printf("Student record added successfully!\n");
}

// Function to display all student records
void displayStudents() {
    if (!head) {
        printf("No student records to display.\n");
        return;
    }
    Student* current = head;
    while (current) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

// Merge Sort - using merge sort because it works efficiently with linked lists due to its pointer-based merging process
//https://www.geeksforgeeks.org/c-program-for-merge-sort/ (Merge sort learnt from the link provided)
// Merge two sorted linked lists
Student* merge(Student* left, Student* right) {
    if (!left) return right;
    if (!right) return left;

    Student* result = NULL;
    if (left->grade <= right->grade) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

// Function to split the linked list into two
void splitList(Student* source, Student** leftRef, Student** rightRef) {
    Student* slow = source;
    Student* fast = source->next;

    // Use the fast/slow pointer strategy to find the middle
    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *leftRef = source;
    *rightRef = slow->next;
    slow->next = NULL;
}

// Merge Sort
Student* mergeSort(Student* head) {
    if (!head || !head->next) {
        return head; // Base case: empty or single-element list
    }

    Student* left = NULL;
    Student* right = NULL;

    // Split the list into two 
    splitList(head, &left, &right);

    // Recursively sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // Merge the sorted halves
    return merge(left, right);
}

// Wrapper function to call Merge Sort and update the head pointer
void sortStudents() {
    if (!head) {
        printf("No student records to sort.\n");
        return;
    }
    head = mergeSort(head);
    printf("Records sorted by grade successfully!\n");
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* current = head;
    while (current) {
        if (current->id == id)
            return current;
        current = current->next;
    }
    return NULL;
}

// Function to delete the entire linked list
void deleteList() {
    Student* current = head;
    Student* next;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
    printf("List deleted successfully.\n");
}

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
        getchar();

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
                } else {
                    printf("Student not found.\n");
                }
                break;
            case 5:
                deleteList();
                break;
            case 6:
                deleteList(); // Free all memory before exiting
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
