#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure for Student
typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next;
} Student;
Student* head = NULL; //This is a singly linked list

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    //First create the node using dynamic memory allocation and structure pointers
    Student *newNode = (Student *)malloc(sizeof(Student));

    //Check if memory allocation was successfull
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit (1);
    }

    //copy the name into new node
    strncpy(newNode->name, name, sizeof(newNode->name) - 1);
    newNode->name[sizeof(newNode->name) - 1] = '\0'; //remove newline character

    //assign id and grade
    newNode->id = id;
    newNode->grade = grade;

    //Initialize next pointer to NULL
    newNode->next = NULL;
    
    return newNode;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* newNode = createStudent(name, id, grade);

    //check if linked list is empty
    if (head == NULL) {
        //if list is empty
        head = newNode;
        return;
    }

    //if linked list is not empty, traverse to end of list
    Student* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    //move on to inserting the next node
    temp->next = newNode;
}

// Function to display all student records
void displayStudents() {
    Student* temp = head;
    //check if list is not empty
    while (temp != NULL) {
        //display list to user
        printf("Name: %s,\tID: %d, \tGrade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next;
    }

    if (temp == NULL) {
        //if list is empty give user a prompt to notify user
        printf("List is empty.\n");
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* temp = head;

    while(temp != NULL) {
        if (temp->id == id) {   //if id matches
            return temp;        //returns the matching node
        }
        temp = temp->next; // moves to the next node
    }

    //if no match return NULL
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

// Sort function to sort the student records by grade based on an algorithm that you like
void sortStudents() {
    //check if list is empty
    if (head == NULL) {
        return;
    } //No need to sort if list is empty

    int swap; //temporary variable to keep track of swaps
    Student* current;
    Student* lastSorted = NULL;

    do {
        swap = 0; //reset the swapped flag for this pass
        current = head;

        //Traverse the list until the last sorted node
        while (current->next != lastSorted) {
            if (current->grade > current->next->grade) {

                //Implemented bubble sort
                //swap the data between two nodes
                int tempID = current->id;
                float tempGrade = current->grade;
                char tempName[100];
                strncpy(tempName, current->name, sizeof(tempName) - 1);
                tempName[sizeof(tempName)- 1] = '\0';

                current->id = current->next->id;
                current->grade = current->next->grade;
                strncpy(current->name, current->next->name, sizeof(current->name) - 1);
                current->name[sizeof(current->name) - 1] = '\0';

                current->next->id = tempID;
                current->next->grade = tempGrade;
                strncpy(current->next->name, tempName, sizeof(current->next->name) - 1);
                current->next->name[sizeof(current->next->name) - 1] = '\0';

                swap = 1; //a swap occured
            }
            current = current->next; //move to the next node
        }
        lastSorted = current; //last node is now sorted
    } while (swap);

    printf("Records sorted using bubble sort.\n");
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
