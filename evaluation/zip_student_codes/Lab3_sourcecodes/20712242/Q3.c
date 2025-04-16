#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 

// Define a structure to represent a student record
typedef struct Student {
    char name[50];          
    int id;                 
    float grade;            
    struct Student* next;   // Pointer to the next student in the linked list
} Student;

//pointer to manage the linked list
Student* head = NULL;

// Function to create a new student info/data
Student* createStudent(const char* name, int id, float grade) {
    // memory for student info
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (!newStudent) { // Check if memory allocation failed
        printf("Memory allocation failed.\n");
        exit(1); 
    }
    // Copy the student's name into the node
    strcpy(newStudent->name, name);
    // Assign the student's ID and grade
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent; // Return the newly created node
}

// Function to insert a new student into the linked list
void insertStudent(const char* name, int id, float grade) {
    // Create a new student node
    Student* newStudent = createStudent(name, id, grade);
    // Link the new node to the beginning of the list
    newStudent->next = head;
    // Update the head pointer to point to the new node
    head = newStudent;
    printf("Student record inserted successfully.\n");
}

// Function to display all student records in the linked list
void displayStudents() {
    if (head == NULL) { // Check if the list is empty
        printf("No records to display.\n");
        return;
    }
    // Pointer to traverse the linked list
    Student* temp = head;
    while (temp != NULL) { // Loop through each node in the list
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next; // Move to the next node
    }
}

// Function to sort student records in ascending order of grades using Bubble Sort
void sortStudents() {
    if (head == NULL || head->next == NULL) { 
        printf("Not enough records to sort.\n");
        return; 
    }
    int swapped;        // declare swap variable
    Student* ptr1;      // Pointer to traverse the list
    Student* lptr = NULL; // Pointer to mark the sorted portion of the list

    do {
        swapped = 0;    
        ptr1 = head;     // Start from the head of the list

        while (ptr1->next != lptr) { // Traverse the unsorted portion of the list
            if (ptr1->grade > ptr1->next->grade) {
                // Swap the student details between pairs
                float tempGrade = ptr1->grade;
                int tempID = ptr1->id;
                char tempName[50];
                strcpy(tempName, ptr1->name);

                ptr1->grade = ptr1->next->grade;
                ptr1->id = ptr1->next->id;
                strcpy(ptr1->name, ptr1->next->name);

                ptr1->next->grade = tempGrade;
                ptr1->next->id = tempID;
                strcpy(ptr1->next->name, tempName);

                swapped = 1; 
            }
            ptr1 = ptr1->next; //move to the next pair
        }
        lptr = ptr1; // Update the sorted portion
    } while (swapped); // Repeat until no swaps occur
//using bubble srt
    printf("Records sorted by grade using Bubble Sort.\n"); 
}

// Function to search for a student by their ID
Student* searchStudentByID(int id) {
    // Pointer to traverse the linked list
    Student* temp = head;
    while (temp != NULL) { // Loop through the list
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next; // Move to the next node
    }
    return NULL; // Return NULL if no match is found
}

// Function to delete the entire linked list and free memory
void deleteList() {
    Student* temp; 
    while (head != NULL) { 
        temp = head;       // Store the current head
        head = head->next;
        free(temp);        // Free the memory of the current node
    }
    printf("All student records deleted.\n"); 
}

// Utility function to clear the input buffer
void clearBuffer() {
    int c;
    // Consume all characters in the input buffer until a newline reached
    while ((c = getchar()) != '\n' && c != EOF);
}

//function to free all memory before program exit
void freeMemory() {
    deleteList(); 
}

// Main function to drive the program
int main() {
    int choice, id;      
    float grade;         
    char name[50];       

    do {
        // Display the menu
        printf("\nMenu:\n");
        printf("1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records\n");
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        // Validate user input for choice
        if (scanf("%d", &choice) != 1) {
            clearBuffer(); // Clear invalid input from the buffer
            printf("Invalid input. Please enter a number.\n");
            continue; 
        }

        clearBuffer(); // Clear any trailing input

        switch (choice) {
            
            case 1:
            // Input student details
            printf("Enter Name: ");
            scanf("%49s", name); 
            printf("Enter ID: ");
            if (scanf("%d", &id) != 1) { // Validate ID input
                clearBuffer();
                printf("Invalid ID. Please try again.\n");
                break;
            }
            printf("Enter Grade: ");
            if (scanf("%f", &grade) != 1) { // Validate grade input
                clearBuffer();
                printf("Invalid grade. Please try again.\n");
                break;
            }
            insertStudent(name, id, grade);
            break;
            
            case 2:
            displayStudents(); // Display all student records
            break;
            
            case 3:
            sortStudents(); // Sort student records by grade
            break;
            
            case 4: {
            printf("Enter ID to search: ");
            if (scanf("%d", &id) != 1) { // Validate ID input
                clearBuffer();
                printf("Invalid ID. Please try again.\n");
                break;
            }
            Student* student = searchStudentByID(id); // Search for the student by ID
            if (student) {
                
                printf("Record Found - Name: %s, ID: %d, Grade: %.2f\n", student->name, student->id, student->grade);
            } else {
                printf("No record found with ID %d.\n", id); 
            }
            break;
        }
            
            case 5:
            deleteList(); // Delete all student records
            break;
            
            case 6:
            freeMemory(); // Free all allocated memory
            printf("Exiting program. Goodbye!\n");
            break;
            
            default:
            printf("Invalid choice. Please try again.\n"); 
        }
    } while (choice != 6); // Repeat until the user chooses to exit

    return 0; 
}
