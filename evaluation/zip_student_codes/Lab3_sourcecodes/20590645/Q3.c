#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// define structure for students
typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next;
} Student;

Student* head = NULL;

// Function Prototypes
void insertStudent(const char* name, int id, float grade);
void displayStudents();
Student* searchStudentByID(int id);
void deleteList();
void freeMemory();
Student* createStudent(const char* name, int id, float grade);
void sortStudents();
void swap(Student* a, Student* b);
void bubbleSort(Student* head);

int main() {
    int choice, id;
    char name[100];
    float grade;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records by Grade\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student name: ");
                getchar();  // to consume newline
                fgets(name, 100, stdin);
                name[strcspn(name, "\n")] = '\0';  // remove newline from string
                printf("Enter student ID: ");
                scanf("%d", &id);
                printf("Enter student grade: ");
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
                printf("Enter student ID to search: ");
                scanf("%d", &id);
                Student* student = searchStudentByID(id);
                if (student != NULL) {
                    printf("Student found: %s, ID: %d, Grade: %.2f\n", student->name, student->id, student->grade);
                } else {
                    printf("Student with ID %d not found.\n", id);
                }
                break;

            case 5:
                deleteList();
                break;

            case 6:
                freeMemory();
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Function Definitions
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    newStudent->next = head;
    head = newStudent;
    printf("Student record inserted.\n");
}

void displayStudents() {
    if (head == NULL) {
        printf("No student records available.\n");
        return;
    }
    Student* temp = head;
    while (temp != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next;
    }
}

Student* searchStudentByID(int id) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void deleteList() {
    Student* temp = head;
    while (temp != NULL) {
        Student* toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }
    head = NULL;
    printf("All student records deleted.\n");
}

void freeMemory() {
    deleteList();
    printf("Memory freed and program exited.\n");
}

Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (!newStudent) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strncpy(newStudent->name, name, sizeof(newStudent->name) - 1);
    newStudent->name[sizeof(newStudent->name) - 1] = '\0';
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

// Sort students by grade (Bubble Sort)
void sortStudents() {
    if (head == NULL) {
        printf("No records to sort.\n");
        return;
    }
    bubbleSort(head);
    printf("Student records sorted by grade.\n");
}

void bubbleSort(Student* head) {
    int swapped;
    Student* ptr1;
    Student* lptr = NULL;

    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->grade > ptr1->next->grade) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void swap(Student* a, Student* b) {
    int tempID = a->id;
    float tempGrade = a->grade;
    char tempName[100];
    strncpy(tempName, a->name, sizeof(a->name));

    // Swap values
    a->id = b->id;
    a->grade = b->grade;
    strncpy(a->name, b->name, sizeof(a->name));

    b->id = tempID;
    b->grade = tempGrade;
    strncpy(b->name, tempName, sizeof(b->name));
}
