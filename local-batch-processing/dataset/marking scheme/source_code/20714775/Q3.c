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
}

// Function to display all student records
void displayStudents() {
    if (!head) {
        printf("No student records available.\n");
        return;
    }

    Student* temp = head;
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

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

// Sort function to sort the student records by grade using Bubble Sort
void sortStudents() {
    if (!head || !head->next) {
        printf("Insufficient records to sort.\n");
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
                // Swap data
                char tempName[100];
                int tempID;
                float tempGrade;

                strcpy(tempName, ptr1->name);
                tempID = ptr1->id;
                tempGrade = ptr1->grade;

                strcpy(ptr1->name, ptr1->next->name);
                ptr1->id = ptr1->next->id;
                ptr1->grade = ptr1->next->grade;

                strcpy(ptr1->next->name, tempName);
                ptr1->next->id = tempID;
                ptr1->next->grade = tempGrade;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    printf("Records sorted by grade using Bubble Sort.\n");
}

// Function to free memory
void freeMemory() {
    deleteList();
}

// Main function to drive the program
int main() {
    int choice, id;
    char name[100];
    float grade;

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
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n");
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Grade: ");
                scanf("%f", &grade);
                insertStudent(name, id, grade);
                break;
            }
            case 2: {
                displayStudents();
                break;
            }
            case 3: {
                sortStudents();
                break;
            }
            case 4: {
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
            case 5: {
                deleteList();
                printf("List deleted.\n");
                break;
            }
            case 6: {
                freeMemory();
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice! Please try again.\n");
            }
        }
    } while (choice != 6);

    return 0;
}