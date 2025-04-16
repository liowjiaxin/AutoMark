#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int id;
    float grade;
    struct Student* next;
} Student;

Student* head = NULL;

//insert a new student record function
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = head;
    head = newStudent;
}

// display student records function
void displayStudents() {
    Student* current = head;
    printf("Name\tID\tGrade\n");
    while (current != NULL) {
        printf("%s\t%d\t%.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

// search for student handling

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

//delete the list function
void deleteList() {
    while (head != NULL) {
        Student* temp = head;
        head = head->next;
        free(temp);
    }
}

// free all memory (deletes list)
void freeMemory() {
    deleteList();
}

//sorting students function
void sortStudents() {
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
                // Swap the nodes
                char tempName[50];
                int tempId;
                float tempGrade;

                strcpy(tempName, ptr1->name);
                tempId = ptr1->id;
                tempGrade = ptr1->grade;

                strcpy(ptr1->name, ptr1->next->name);
                ptr1->id = ptr1->next->id;
                ptr1->grade = ptr1->next->grade;

                strcpy(ptr1->next->name, tempName);
                ptr1->next->id = tempId;
                ptr1->next->grade = tempGrade;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main() {
    int choice;
    char name[50];
    int id;
    float grade;

    while (1) {
        //options are output
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        //handling selected option
        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
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
                printf("Records sorted by grade in ascending order.\n");
                break;

            case 4:
                printf("Enter ID: ");
                scanf("%d", &id);
                Student* student = searchStudentByID(id);
                if (student == NULL) {
                    printf("Student not found.\n");
                } else {
                    printf("Name: %s, ID: %d, Grade: %.2f\n", student->name, student->id, student->grade);
                }
                break;

            case 5:
                deleteList();
                printf("List deleted.\n");
                break;

            case 6:
                freeMemory();
                return 0;

            default:
                //error handling for invalid inputs
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}