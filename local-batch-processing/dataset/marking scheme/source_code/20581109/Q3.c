#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure for Student
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
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

//Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    if (newStudent == NULL) return;

    if (head == NULL) {
        head = newStudent;
    } else {
        Student* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;
    }
    printf("Student record added successfully!\n");
}

//Function to display all student records
void displayStudents() {
    if (head == NULL) {
        printf("No student records available.\n");
        return;
    }

    Student* current = head;
    printf("\nStudent Records:\n");
    while (current != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

//Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* current = head;
    while (current != NULL) {
        if (current->id == id) return current;
        current = current->next;
    }
    return NULL;
}

//Function to delete the entire list
void deleteList() {
    Student* current = head;
    Student* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    head = NULL;
    printf("All student records deleted successfully.\n");
}

//Function to free memory (utility)
void freeMemory() {
    deleteList();
    printf("Exiting...\n");
}

//Function to sort students by grade in ascending order (Bubble Sort)
void sortStudents() {
    if (head == NULL || head->next == NULL) return;

    int swapped;
    Student *current, *prev = NULL;

    do {
        swapped = 0;
        current = head;

        while (current->next != prev) {
            if (current->grade > current->next->grade) {
                char tempName[100];
                strcpy(tempName, current->name);
                strcpy(current->name, current->next->name);
                strcpy(current->next->name, tempName);

                int tempID = current->id;
                current->id = current->next->id;
                current->next->id = tempID;

                float tempGrade = current->grade;
                current->grade = current->next->grade;
                current->next->grade = tempGrade;

                swapped = 1;
            }
            current = current->next;
        }
        prev = current;
    } while (swapped);

    printf("Records sorted by grade in ascending order using Bubble Sort.\n");
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
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n"); // Remove trailing newline

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
                printf("List deleted.\n");
                break;

            case 6:
                freeMemory();
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
