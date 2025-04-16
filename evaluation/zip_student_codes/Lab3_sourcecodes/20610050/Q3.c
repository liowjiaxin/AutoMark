
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next;
} Student;

Student* head = NULL;
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (!newStudent) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    // Set the values to the student
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    if (head == NULL) {
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}
void displayStudents() {
    if (head == NULL) {
        printf("No student records available.\n");
        return;
    }

    printf("\nStudent Records:\n");
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
            return temp; // Student is available
        }
        temp = temp->next;
    }
    return NULL; 
}
void deleteList() {
    Student* current = head;
    Student* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL; 
}
void freeMemory() {
    deleteList();
}
void sortStudents() {
    if (head == NULL || head->next == NULL) {
        printf("Sorting is not required for an empty or single-element list.\n");
        return;
    }
    int swapped;
    Student *i, *j = NULL;
    do {
        swapped = 0;
        i = head;

        while (i->next != j) {
            if (i->grade > i->next->grade) {
                // Swap grades of students
                float tempGrade = i->grade;
                i->grade = i->next->grade;
                i->next->grade = tempGrade;

                // Swap IDs of students
                int tempID = i->id;
                i->id = i->next->id;
                i->next->id = tempID;

                // Swap names of students
                char tempName[100];
                strcpy(tempName, i->name);
                strcpy(i->name, i->next->name);
                strcpy(i->next->name, tempName);

                swapped = 1;
            }
            i = i->next;
        }
        j = i; 
    } while (swapped);

    printf("Records sorted by grade.\n");
}
int main() {
    int choice, id;
    char name[100];
    float grade;

    do {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records by Grade\n");
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
                printf("List deleted.\n");
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
