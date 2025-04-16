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
    if (!newStudent) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    if (!newStudent) return;

    if (!head) {
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
    printf("Student record added successfully.\n");
}

// Function to display all student records
void displayStudents() {
    if (!head) {
        printf("No student records found.\n");
        return;
    }
    Student* temp = head;
    printf("\nStudent Records:\n");
    while (temp) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next;
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* temp = head;
    while (temp) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to delete the entire list
void deleteList() {
    Student* current = head;
    Student* next;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
    printf("All student records deleted successfully.\n");
}

// Function to free memory
void freeMemory() {
    deleteList();
}

// Function to sort the student records by grade
void sortStudents() {
    if (!head || !head->next) {
        printf("Not enough records to sort.\n");
        return;
    }
    // Using Bubble Sort for simplicity
    for (Student* i = head; i; i = i->next) {
        for (Student* j = i->next; j; j = j->next) {
            if (i->grade > j->grade) {
                // Swap the contents
                char tempName[100];
                int tempId = i->id;
                float tempGrade = i->grade;

                strcpy(tempName, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, tempName);

                i->id = j->id;
                j->id = tempId;

                i->grade = j->grade;
                j->grade = tempGrade;
            }
        }
    }
    printf("Student records sorted by grade.\n");
}

// Main function to drive the program
int main() {
    int choice;
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
            case 1: {
                char name[100];
                int id;
                float grade;

                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n"); // Remove newline character
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Grade: ");
                scanf("%f", &grade);

                insertStudent(name, id, grade);
                break;
            }
            case 2:
                displayStudents();
                break;
            case 3:
                sortStudents();
                break;
            case 4: {
                int id;
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Student* found = searchStudentByID(id);
                if (found) {
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n",
                           found->name, found->id, found->grade);
                } else {
                    printf("Student not found.\n");
                }
                break;
            }
            case 5:
                deleteList();
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
