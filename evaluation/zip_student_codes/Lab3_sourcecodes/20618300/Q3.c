#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next;
} Student;

// act like a checkpoint to check if the list is empty or not
Student* head = NULL;

void displayMenu()
{
    printf("\n1. Insert Student Record\n");
    printf("2. Display Student Records\n");
    printf("3. Sort Records\n");
    printf("4. Search Record by ID\n");
    printf("5. Delete List\n");
    printf("6. Exit\n");
}

// Creates a new student node and returns a pointer to it.
Student* createStudent(const char* name, int id, float grade) 
{
    // create new node for student
    Student* newNode = (Student*)malloc(sizeof(Student));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    strcpy(newNode->name, name);
    newNode->id = id;
    newNode->grade = grade;
    newNode->next = NULL; // as a signal show that this node is the last node in the list
    return newNode; // return the pointer to the newly created newStudent node
}

// Inserts a new student record into the linked list
void insertStudent(const char* name, int id, float grade) 
{
    Student* newStudent = createStudent(name, id, grade);
    if (newStudent == NULL) return;

    // if head is NULL, means the list is empty
    // then newStudent is assigned to head, making it the first node in the list
    if (head == NULL) 
    {
        head = newStudent;
    } 
    else 
    {
        // need to find the last nodes of the list which next will be NULL
        Student* temp = head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        // when find the last nodes of the list, 
        // store the latest created node which is address of newStudent into it
        temp->next = newStudent;
    }
    printf("Student inserted successfully!\n");
}

// Displays all current student records in the linked list
void displayStudents() 
{
    // no need to sort empty list or list with one student
    if (head == NULL) 
    {
        printf("No student records to display.\n");
        return;
    }

    Student* temp = head;
    while (temp != NULL) 
    {
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        // repeat displaying the student records by moving the next into temp
        // when temp is NULL, which is last nodes, then break out the loop
        temp = temp->next;
    }
}

// Searches for a student record by student ID and returns a pointer to the corresponding student node
Student* searchStudentByID(int id) 
{
    Student* temp = head;
    // here will keep looping until the last node to find the id
    while (temp != NULL) 
    {
        if (temp->id == id) 
        {
            return temp;// passess the address of the found node back to the calling function
        }
        temp = temp->next;
    }
    return NULL; // tell the calling function the search is unsuccessful
}

// Deletes the entire linked list and frees the allocated memory
void deleteList() 
{
    Student* current = head; // stored current to the first node
    Student* next; // pointer that will temporarily store the address of the next node in the list

    while (current != NULL) 
    {
        next = current->next; // store next to the next of first node which is the address of second node
        free(current); // memory occupied by the current node is released
        current = next; // after the current is clear, then store the next to current and repeat until current is NULL
    }
    head = NULL;
    printf("List deleted.\n");
}

// Sort the student records by grade according to a sorting algorithm of your choice
void sortStudents() 
{
    // Check if the list is empty or has only one node
    if (head == NULL || head->next == NULL) 
    {
        printf("No need to sort. Not enough students.\n");
        return; 
    }

    // flag to track if a swap occurred in the current pass
    int sort;
    // pointer for traversal and tracking the last sorted node
    Student *currentNode, *lastSortedNode = NULL;  

    do {
        sort = 0; // reset the swap flag at the start of each pass
        currentNode = head;// start traversal from the head of the list

        // traverse the list until the last sorted node
        while (currentNode->next != lastSortedNode) 
        {
            // compare the grade of the current node and the next node
            // if the current node grade is greater, swap their data
            if (currentNode->grade > currentNode->next->grade) 
            {
                // temporary variables to store the data of the current node
                char tempName[100];
                int tempID;
                float tempGrade;

                // copy current node data into temporary variables
                strcpy(tempName, currentNode->name);
                tempID = currentNode->id;
                tempGrade = currentNode->grade;

                // copy the next node data into the current node
                strcpy(currentNode->name, currentNode->next->name);
                currentNode->id = currentNode->next->id;
                currentNode->grade = currentNode->next->grade;

                // copy the temporary data into the next node
                strcpy(currentNode->next->name, tempName);
                currentNode->next->id = tempID;
                currentNode->next->grade = tempGrade;

                sort = 1;  // set the flag to show the swap is occurred
            }
            currentNode = currentNode->next;
        }

        // mark the last node in this pass as sorted
        lastSortedNode = currentNode;  
    } while (sort); 

    printf("Records sorted by grade using Bubble Sort.\n");
}

// A utility function to ensure that all memory is freed when the program exits
void freeMemory()
{
    deleteList();
}

int main() 
{
    int choice, id;
    char name[100];
    float grade;

    do {
        displayMenu();

        // Validate menu choice
        printf("Enter your choice: ");
        while (scanf("%d", &choice) != 1) 
        {
            printf("Invalid choice! Please re-enter: ");
            while (getchar() != '\n'); // Clear the buffer
        }
        getchar(); // Clear leftover newline character

        switch (choice) 
        {
            case 1:
                // Validate name
                printf("Enter Name: ");
                while (1) 
                {
                    if (fgets(name, sizeof(name), stdin)) 
                    {
                        name[strcspn(name, "\n")] = '\0'; // Remove newline
                        if (strlen(name) > 0) break;
                    }
                    printf("Invalid input! Please enter a valid name: ");
                }

                // validate ID
                printf("Enter ID: ");
                while (scanf("%d", &id) != 1 || id <= 0) 
                {
                    printf("Invalid input! Please enter a positive integer for ID: ");
                    while (getchar() != '\n'); // Clear the buffer
                }

                // validate grade
                printf("Enter Grade: ");
                while (scanf("%f", &grade) != 1 || grade < 0.0 || grade > 100.0) 
                {
                    printf("Invalid input! Please enter a grade between 0 and 100: ");
                    while (getchar() != '\n'); 
                }

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
                while (scanf("%d", &id) != 1 || id <= 0) 
                {
                    printf("Invalid input! Please enter a valid positive integer for ID: ");
                    while (getchar() != '\n'); 
                }

                Student* found = searchStudentByID(id);
                // means found != NULL print the details
                if (found) 
                {
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
                } 
                // when found = NULL means no such ID
                else 
                {
                    printf("Student not found.\n");
                }
                break;

            case 5:
                deleteList();
                break;

            case 6:
                freeMemory();
                printf("Have a nice day!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
