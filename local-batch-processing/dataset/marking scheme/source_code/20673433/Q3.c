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
        printf("Memory allocation failed.\n");
        exit(1);
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
    if (head == NULL) {
        head = newStudent;
    } else {
        Student* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;
    }
    printf("Student added successfully!\n");
}

// Function to display all student records
void displayStudents() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Student* current = head;
    printf("\nStudents in the list:\n");
    printf("ID\tName\t\tGrade\n");
    printf("----------------------------------\n");
    while (current != NULL) {
        printf("%d\t%s\t\t%.2f\n", current->id, current->name, current->grade);
        current = current->next;
    }
}

// Function to search for a student by ID
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

// Function to sort the student records by grade in ascending order
void sortStudents() {
    if (head == NULL || head->next == NULL) {
        printf("No need to sort, the list is empty or has only one student.\n");
        return;
    }

    Student* i;
    Student* j;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->grade > j->grade) {
                // Swap the data
                char tempName[100];
                int tempId;
                float tempGrade;

                strcpy(tempName, i->name);
                tempId = i->id;
                tempGrade = i->grade;

                strcpy(i->name, j->name);
                i->id = j->id;
                i->grade = j->grade;

                strcpy(j->name, tempName);
                j->id = tempId;
                j->grade = tempGrade;
            }
        }
    }
    printf("Students sorted by grade successfully!\n");
}

// Function to delete the entire list
void deleteList() {
    Student* current = head;
    while (current != NULL) {
        Student* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
    printf("List deleted successfully.\n");
}

int main() {
    int choice, id;
    char name[100];
    float grade;

    do {
        printf("\nMenu:\n");
        printf("1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records by Grade\n");
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
                strtok(name, "\n"); // Remove newline character
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
                    printf("\nFound: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
                } else {
                    printf("Student not found.\n");
                }
                break;
            case 5:
                deleteList();
                break;
            case 6:
                deleteList();
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
