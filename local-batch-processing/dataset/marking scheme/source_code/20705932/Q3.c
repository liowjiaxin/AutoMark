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

Student* headnode = NULL;

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (!newStudent) {
        printf("Memory allocation has failed!\n");
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
    if (headnode == NULL) {
        headnode = newStudent;
        return;
    }
    Student* tempnode = headnode;
    while (tempnode->next != NULL) {
        tempnode = tempnode->next;
    }
    tempnode->next = newStudent;
}

// Function to display all student records
void displayStudents() {
    int i = 1;
    Student* tempnode = headnode;

    if (tempnode == NULL) {
        printf("The list is empty.\n");
        return;
    }

    while (tempnode != NULL) {
        printf("%d. Name: %s, ID: %d, Grade: %.2f\n", i++, tempnode->name, tempnode->id, tempnode->grade);
        tempnode = tempnode->next;
    }
}

// Function to search for a student by ID
Student* searchStudentbyID(int id) {
    Student* tempnode = headnode;
    while (tempnode != NULL) {
        if (tempnode->id == id) {
            return tempnode;
        }
        tempnode = tempnode->next;
    }
    return NULL;
}

// Function to delete the entire list
void deleteList() {
    Student* currentnode = headnode;
    Student* next;

    while (currentnode != NULL) {
        next = currentnode->next;
        free(currentnode);
        currentnode = next;
    }
    headnode = NULL;
}

void freeMemory() {
    deleteList();
}

// Bubble sort function to sort the linked list based on grade
void bubbleSort() {
    if (headnode == NULL || headnode->next == NULL) {
        printf("Can't sort an empty or one-node list.\n");
        return;
    }

    int swap;
    Student* ptr1;
    Student* lastptr = NULL;

    do {
        swap = 0;
        ptr1 = headnode;

        while (ptr1->next != lastptr) {
            if (ptr1->grade > ptr1->next->grade) {
                // Swap the grades
                float tempGrade = ptr1->grade;
                ptr1->grade = ptr1->next->grade;
                ptr1->next->grade = tempGrade;

                // Swap the IDs
                int tempID = ptr1->id;
                ptr1->id = ptr1->next->id;
                ptr1->next->id = tempID;

                // Swap the names
                char tempName[100];
                strcpy(tempName, ptr1->name);
                strcpy(ptr1->name, ptr1->next->name);
                strcpy(ptr1->next->name, tempName);

                swap = 1;
            }
            ptr1 = ptr1->next;
        }
        lastptr = ptr1;
    } while (swap);

    printf("Student records sorted by grade using Bubble Sort.\n");
}

// Sort function for the menu
void sortStudents() {
    bubbleSort();
}


// Main function to drive the program
int main() {

    int choice, id;
    char name[100];
    float grade;

    do {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records (Ascending Order)\n");
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
                Student* found = searchStudentbyID(id);
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
