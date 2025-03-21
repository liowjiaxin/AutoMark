#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for Student
typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next;
} Student;

// Head pointer for the linked list
Student* head = NULL;

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = NULL;

    do {
        newStudent = (Student*)malloc(sizeof(Student));
        if (!newStudent) {
            printf("Memory allocation failed! Retrying...\n");
        }
    } while (!newStudent);

    strncpy(newStudent->name, name, sizeof(newStudent->name) - 1);
    newStudent->name[sizeof(newStudent->name) - 1] = '\0';  // Ensures null-termination
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;

    return newStudent;
}


// Function to insert a new student at the beginning of the list
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    newStudent->next = head;
    head = newStudent;
    printf("Student record inserted successfully!\n");
}

// Function to display all student records
void displayStudents() {
    if (head == NULL) {
        printf("No records available.\n");
        return;
    }

    printf("\nStudent Records:\n");
    for (Student* current = head; current != NULL; current = current->next) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    if (head == NULL) {
        return NULL;
    }

    Student* current = head;
    do {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    } while (current != NULL);

    return NULL;
}


// Function to delete the entire list
void deleteList() {
    Student* current = head;
    while (current) {
        Student* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
    printf("All records have been deleted.\n");
}

// Bubble Sort function to sort students by grade
void sortStudents() {
    if (!head || !head->next) {
        printf("Not enough records to sort.\n");
        return;
    }
    int swapped;
    Student* ptr1;
    Student* ptr2 = NULL;
    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != ptr2) {
            if (ptr1->grade > ptr1->next->grade) {
                // Swap data
                float tempGrade = ptr1->grade;
                ptr1->grade = ptr1->next->grade;
                ptr1->next->grade = tempGrade;

                int tempID = ptr1->id;
                ptr1->id = ptr1->next->id;
                ptr1->next->id = tempID;

                char tempName[100];
                strncpy(tempName, ptr1->name, sizeof(tempName));
                strncpy(ptr1->name, ptr1->next->name, sizeof(ptr1->name));
                strncpy(ptr1->next->name, tempName, sizeof(ptr1->next->name));

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while (swapped);
    printf("Records sorted by grade.\n");
}

// Main function to manage menu options
int main() {
    int choice, id;
    char name[100];
    float grade;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove trailing newline
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
                deleteList();
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}