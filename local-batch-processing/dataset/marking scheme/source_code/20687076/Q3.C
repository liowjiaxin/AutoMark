#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student
typedef struct Student {
    char studentName[100];
    int studentID;
    float studentGrade;
    struct Student* next;
} Student;

// Global pointer to the head of the list
Student* listHead = NULL;

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }
    strcpy(newStudent->studentName, name);
    newStudent->studentID = id;
    newStudent->studentGrade = grade;
    newStudent->next = NULL;
    return newStudent;
}

// Function to add a student to the list
void addStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    if (!newStudent) return;

    if (listHead == NULL) {
        listHead = newStudent;
    } else {
        Student* current = listHead;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;
    }
    printf("Student added successfully!\n");
}

// Function to display all student records
void displayAllStudents() {
    if (listHead == NULL) {
        printf("No student records to display.\n");
        return;
    }

    Student* current = listHead;
    printf("\nStudent Records:\n");
    while (current != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->studentName, current->studentID, current->studentGrade);
        current = current->next;
    }
}

// Function to search for a student by ID
Student* findStudentByID(int id) {
    Student* current = listHead;
    while (current != NULL) {
        if (current->studentID == id) {
            return current;
        }
        current = current->next;
    }
    return NULL; // If no student is found
}

// Function to sort students by their grades
void sortStudentRecords() {
    if (listHead == NULL || listHead->next == NULL) {
        return; // No need to sort if 0 or 1 student exists
    }

    int swapped;
    Student* ptr1;
    Student* lastPtr = NULL;

    do {
        swapped = 0;
        ptr1 = listHead;

        while (ptr1->next != lastPtr) {
            if (ptr1->studentGrade > ptr1->next->studentGrade) {
                // Swap student records by swapping the data
                char tempName[100];
                int tempID;
                float tempGrade;

                strcpy(tempName, ptr1->studentName);
                tempID = ptr1->studentID;
                tempGrade = ptr1->studentGrade;

                strcpy(ptr1->studentName, ptr1->next->studentName);
                ptr1->studentID = ptr1->next->studentID;
                ptr1->studentGrade = ptr1->next->studentGrade;

                strcpy(ptr1->next->studentName, tempName);
                ptr1->next->studentID = tempID;
                ptr1->next->studentGrade = tempGrade;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lastPtr = ptr1;
    } while (swapped);

    printf("Student records sorted by grade in ascending order.\n");
}

// Function to delete all student records
void deleteAllStudents() {
    Student* current = listHead;
    while (current != NULL) {
        Student* next = current->next;
        free(current);
        current = next;
    }
    listHead = NULL;
    printf("All student records have been deleted.\n");
}

// Main function to handle the menu and program flow
int main() {
    int choice, id;
    float grade;
    char name[100];

    do {
        printf("\nStudent Records Menu:\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Sort Records by Grade\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete All Records\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        switch (choice) {
            case 1:
                printf("Enter Student Name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n"); // Remove trailing newline
                printf("Enter Student ID: ");
                scanf("%d", &id);
                printf("Enter Student Grade: ");
                scanf("%f", &grade);
                addStudent(name, id, grade);
                break;

            case 2:
                displayAllStudents();
                break;

            case 3:
                sortStudentRecords();
                break;

            case 4:
                printf("Enter Student ID to search: ");
                scanf("%d", &id);
                Student* student = findStudentByID(id);
                if (student) {
                    printf("Record Found - Name: %s, ID: %d, Grade: %.2f\n", student->studentName, student->studentID, student->studentGrade);
                } else {
                    printf("No student found with ID: %d\n", id);
                }
                break;

            case 5:
                deleteAllStudents();
                break;

            case 6:
                deleteAllStudents();
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
