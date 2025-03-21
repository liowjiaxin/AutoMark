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
    Student* queue = malloc(sizeof(Student)); // Allocate space
    if (!queue) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(queue->name, name);
    queue->id = id;
    queue->grade = grade;
    queue->next = NULL;
    return queue;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* queue = createStudent(name, id, grade);
    queue->next = head;
    head = queue;
}

// Function to display all student records
void displayStudents() {
    if (head == NULL) {
        printf("List is empty, nothing to display.\n");
        return;
    }
    Student* node = head;
    printf("Student records:\n");
    while (node) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", node->name, node->id, node->grade);
        node = node->next;
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int ID) {
    if (head == NULL) {
        printf("List is empty, nothing to search.\n");
        return NULL;
    }
    Student* p = head;
    while (p) {
        if (p->id == ID) {
            return p; // Return the matching student node
        }
        p = p->next;
    }
    printf("No student found with ID %d.\n", ID);
    return NULL; // Return NULL if no match is found
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

// Function to free memory (wrapper for deleteList)
void freeMemory() {
    deleteList();
}

// Sort function to sort the student records by grade (Bubble Sort)
void sortStudents() {
    if (head == NULL) {
        printf("List is empty, nothing to sort.\n");
        return;
    }
    Student *node1, *index;
    float tempGrade;
    int tempID;
    char tempName[100];

    for (node1 = head; node1 != NULL; node1 = node1->next) {
        for (index = node1->next; index != NULL; index = index->next) {
            if (node1->grade > index->grade) {
                // Swap grades
                tempGrade = node1->grade;
                node1->grade = index->grade;
                index->grade = tempGrade;

                // Swap IDs
                tempID = node1->id;
                node1->id = index->id;
                index->id = tempID;

                // Swap names
                strcpy(tempName, node1->name);
                strcpy(node1->name, index->name);
                strcpy(index->name, tempName);
            }
        }
    }
    printf("Records sorted by grade using Bubble Sort");
}

// Main function to drive the program
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
                printf("Found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
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
