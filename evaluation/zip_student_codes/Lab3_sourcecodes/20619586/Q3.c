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
    struct Student* new_student = (struct Student*) malloc(sizeof(struct Student));

    strcpy(new_student->name, name);
    new_student->id  = id;
    new_student->grade  = grade;
    new_student->next = NULL;

    return new_student;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
    newStudent = createStudent(name, id, grade);
    newStudent -> next = head;
    head = newStudent;
}

// Function to display all student records
void displayStudents() {
    if (head == NULL){
        printf("No records found.\n");
    }else{
        Student* current = head;
        while (current != NULL) {
            printf("Name: %s, ID: %d, Grade: %.2f \n", current->name, current->id, current->grade);
            current = current->next;
        }
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    if (head == NULL) {
        printf("No records found.\n");
        return NULL;
    }

    Student* current = head;
    while (current != NULL) {   
        if (current->id == id) {
            return current;
        }
        current = current->next;
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

void freeMemory() {
    deleteList();
}

// Sort function to sort the student records by grade based on an algorithm of your choice
    //insertion sort, is efficient, only need to loop once (efficent) and use minimal extra memory
void sortStudents() {
    if (head == NULL) {
        printf("No records found.\n");
        return;
    }

    Student* sortHead = NULL;   //line 97, replace sort head and point node to null, prevent unlimited loop
    Student* current = head;

    while (current != NULL) {
        Student* next = current->next;

        if (sortHead == NULL || current->grade < sortHead->grade) {     // if is the first node
            current->next = sortHead;               // node points to original first node to replace it
            sortHead = current;
            
        } else {
            Student* sort = sortHead;
            while (sort->next != NULL && sort->next->grade <= current->grade) {
                sort = sort->next;  
            }

            current->next = sort->next;
            sort->next = current;
        }

        current = next;
    }

    head = sortHead;    //if first node was change, change head
}

// Main function to drive the program
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
                printf("Found: Name: %s, ID: %d, Grade: %.2f\n",
                found->name, found->id, found->grade);
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