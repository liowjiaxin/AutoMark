//q3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines the structure for a student record
typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next;
} Student;

Student* head = NULL;

// Function to create a new student record
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    strncpy(newStudent->name, name, 99);
    newStudent->name[99] = '\0';
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a new student record into the linked list
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    if (head == NULL) {
        head = newStudent;
    } else {
        Student* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;
    }
}

// Function to display all student records in the list
void displayStudents() {
    Student* current = head;
    if (current == NULL) {
        printf("No student records in the list.\n");
    } else {
        printf("Student Records:\n");
        while (current != NULL) {
            printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
            current = current->next;
        }
    }
}

// Searches for student by ID
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

// Function sorts linked list using bubble sort based on grades
void bubbleSort() {
    if (head == NULL || head->next == NULL) {
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
                // Swaps the nodes data if out of order
                char tempName[100];
                strcpy(tempName, ptr1->name);
                strcpy(ptr1->name, ptr1->next->name);
                strcpy(ptr1->next->name, tempName);

                int tempID = ptr1->id;
                ptr1->id = ptr1->next->id;
                ptr1->next->id = tempID;

                float tempGrade = ptr1->grade;
                ptr1->grade = ptr1->next->grade;
                ptr1->next->grade = tempGrade;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// wr functionfpr sorting students
void sortStudents() {
    bubbleSort();
}

// Deletes the entire linked list
void deleteList() {
    Student* current = head;
    while (current != NULL) {
        Student* next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

//self explanatory
void freeMemory() {
    deleteList();
}

int main() {
    int choice, id;
    char name[100];
    float grade;

    do {
        // Display menu options
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records (Bubble Sort)\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                // Input details for a new student record
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
                // Displaya student records
                displayStudents();
                break;
            case 3:
                // Sorts by grades (le bubble sort)
                sortStudents();
                printf("Student records sorted by grade using Bubble Sort.\n");
                break;
            case 4:
                // Searches by ID
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
                // Delete list
                deleteList();
                printf("List deleted.\n");
                break;
            case 6:
                // Deletes memory and exists the program
                freeMemory();
                printf("Exiting...\n");
                break;
            default:
                // error message when invalid number
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
