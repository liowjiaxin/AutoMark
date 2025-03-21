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

// Function to create a new student node (with each student recording including their name, id and grade)
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));   // allocate memory
    strcpy(newStudent->name, name);   // copies the string provided as name(function argument) into name field of structure
    newStudent->id = id;   // set id field in the structure to the value passed as the id argument
    newStudent->grade = grade;   // same as id
    newStudent->next = NULL;   // next pointer is initialized to NULL
    return newStudent;   // return the pointer
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);   // createStudent function called to allocate memory for new Student node

    // Check if list is empty, if empty new student becomes first node
    if (head == NULL) {
        head = newStudent;
    } else {   // if list not empty, find last node in the lust to add the new node at the end
        Student* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;   // links the new node to the end of the list
    }
}

// Function to display all student records
void displayStudents() {
    // if no students in record
    if (head == NULL) {
        printf("No student records available.\n");
        return;
    }

    Student* temp = head;

    // display all students in record with while loop
    while (temp != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next;
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* temp = head;

    // find similar id using while loop
    while (temp != NULL) {
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

    // use while loop to delete entire list
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

// Sort function to sort the student records by grade based on an algorithm of your choice
void sortStudents() {
    int swapped;   // to track if a swap occureed in current pass
    Student *ptr1;   // for traversing the list
    Student *lptr = NULL;   // mkaing the end of the unsorted portion

    // Coninute until no swaps are made
    do {
        swapped = 0;   // reset
        ptr1 = head;   // start from head of the list

        // traverse the list up to the unsorted portion
        while (ptr1->next != lptr) {
            // compare current node's grade with the next node's grade
            if (ptr1->grade > ptr1->next->grade) {
                // Swap the data of the two nodes
                char tempName[100];
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

                swapped = 1;   // mark that swap occured
            }
            // move to next node
            ptr1 = ptr1->next;
        }
        // update the end of the unsorted portion
        lptr = ptr1;
    } while (swapped);   

    printf("Records sorted by grade using Bubble Sort.\n");
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