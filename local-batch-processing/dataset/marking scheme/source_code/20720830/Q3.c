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
    // Allocate memory for new student
    Student* newStud = (Student*)malloc(sizeof(Student));
    strcpy(newStud->name, name);// Copy name to new student
    newStud->id = id;
    newStud->grade = grade;
    newStud->next = NULL;
    return newStud;
}

// Function to insert a new student record at the beginning
void insertStudent(const char* name, int id, float grade) {
    Student* newStud = createStudent(name, id, grade);
    newStud->next = head; //move the head pointer to the next node
    head = newStud;//set the new student as the head
}

// Function to display all student records
void displayStudents() {
    Student* current = head;
    while (current != NULL) {
        // Display student information
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next; // Move to next student
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* current = head;
    while (current != NULL) {
        // If student ID matches, return the current student
        if (current->id == id) {
            return current;
        }
        current = current->next;// Move to next student
    }
    // If student not found, return NULL
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

// Function to get the length of the linked list
int getLength(Student *head)
{
    int len = 0;
    Student *current = head;
    //Loop through the list and add up the length
    while (current != NULL)
    {
        len++;
        current = current->next;
    }
    return len;
}

// Sort function to sort the student records by grade based on an algorithm of your choice
void sortStudents() {
    Student* current = head;
    int len = getLength(head);
    int itr = 0;
    int swapped;
    //Loop through the list and sort the records by grade using Bubble Sort
    while (itr < len)
    {
        Student *traverseNode = head; 
        Student *prevNode = head;
        swapped = 0;

        while (traverseNode->next != NULL)
        {
            // Temporary pointer to store the next node
            Student *ptr = traverseNode->next;
            // If the grade of the current node is greater than the grade of the next node, swap the nodes
            if (traverseNode->grade > ptr->grade)
            {
                swapped = 1; // Set swapped flag to 1
                // Check if the current node is the head of the linked list
                if (traverseNode == head)
                {
                    // Performing swap operations and updating the head of the linked list
                    traverseNode->next = ptr->next;
                    ptr->next = traverseNode;
                    prevNode = ptr;
                    head = prevNode;
                }
                else
                {
                    // Performing swap operation
                    traverseNode->next = ptr->next;
                    ptr->next = traverseNode;
                    prevNode->next = ptr;
                    prevNode = ptr;
                }
                continue;
            }
            prevNode = traverseNode; // Update the previous node
            traverseNode = traverseNode->next; // Move to the next node
        }

        // If no swap occurred, break the loop
        if (!swapped)
        {
            break;
        }

        ++itr;
    }
    printf("Records sorted by grade using Bubble Sort.\n");
    return;
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
