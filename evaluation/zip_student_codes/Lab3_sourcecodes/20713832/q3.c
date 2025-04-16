#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next; // used to link one student node to the next node in a singly linked list
} Student; //defining a structure named student which contains functions like name,id,grade

Student* head = NULL;

void insertStudent(const char* name, int id, float grade); // Inserts a new student record into the linked list.
void displayStudents(); // Displays all current student records in the linked list.
Student* searchStudentByID(int id); // Searches for student record by student ID and returns a pointer to the corresponding studentnode.
void deleteList(); // Deletes the entire linked list and frees the allocated memory.
void freeMemory(); // A utility function to ensure that all memory is freed when the program exits.
Student* createStudent(const char* name, int id, float grade); //Creates a new student node and returns a pointer to it.
void sortStudents(); // Sort the student records by grade according to a sorting algorithm of your choice. 


Student* createStudent(const char* name, int id, float grade) { // Initializing a function to create a new student node
    Student* newStudent = (Student*)malloc(sizeof(Student)); // Allocate memory for the new student
    if (!newStudent) {
        printf("Memory allocation failed.\n"); //Checking memory allocation
        return NULL;
    }
    strcpy(newStudent->name, name); // It Copies the name
    newStudent->id = id;           // It Assigns the ID
    newStudent->grade = grade;     // It Assigns the grade
    newStudent->next = NULL;       // Initialize the next pointer
    return newStudent;            
}


void insertStudent(const char* name, int id, float grade) { // Initializing a function to insert a new student record
    Student* newStudent = createStudent(name, id, grade); // Creating a new student node
    if (!newStudent) return; // checking if memory allocation was succesfull

    if (head == NULL) { // If the list is empty,then make the new student the head
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next != NULL) { // loop continues until the next pointer of the current node is NULL, indicating the last node in the list.
            temp = temp->next;
        }
        temp->next = newStudent; // Adding the new student to the end of the list
    }
    printf("Student record has been inserted successfully.\n"); // the following message will be displayed
}


void displayStudents() {  // intialiazing a function to display all the student records
    if (head == NULL) {
        printf("No student records to display.\n");
        return;
    }
    Student* temp = head;
    printf("Student Records:\n");
    while (temp != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade); // For each student node, print their name, ID, and grade
        temp = temp->next;  // Move to the next student in the list
    }
}

Student* searchStudentByID(int id) { // initializing a function to search for a student by ID
    Student* temp = head;
    while (temp != NULL) {
        if (temp->id == id) { // If the ID matches, then return the student details
            return temp;
        }
        temp = temp->next;
    }
    return NULL; // Return NULL if no student is found
}


void sortStudents() { // intializing a sort function to sort the student records by grade based on bubble sort
    if (head == NULL || head->next == NULL) {
        printf("No sorting is required. List is empty or has only one student.\n");
        return; // No need to sort if the list is empty or contains only one node
    }

    Student* i;
    Student* j;
    for (i = head; i->next != NULL; i = i->next) { // Outer loop to traverse the list
        for (j = head; j->next != NULL; j = j->next) { // Inner loop for pairwise comparisons
            if (j->grade > j->next->grade) { // Compare grades
                // Swap the data (name, ID, and grade) between adjacent nodes
                char tempName[100];
                int tempID;
                float tempGrade;

                strcpy(tempName, j->name);
                tempID = j->id;
                tempGrade = j->grade;

                strcpy(j->name, j->next->name);
                j->id = j->next->id;
                j->grade = j->next->grade;

                strcpy(j->next->name, tempName);
                j->next->id = tempID;
                j->next->grade = tempGrade;
            }
        }
    }
    printf("Student records sorted by grade in ascending order (using bubble sort).\n");
}


void deleteList() { // initializing a function to delete the entire list
 Student* current = head;
 Student* next;

 while (current != NULL) {
    next = current->next; // // Save the next node
    free(current); // // Free the memory of the current node
    current = next; // // Move to the next node in the list
 }
 head = NULL; // Set the head to NULL to indicate the list is empty
}

void freeMemory() { // to delete the entire linked list and free the associated memory
 deleteList();
} 

int main() {
 int choice, id;
 char name[100];
 float grade;
 do {                                               // using a do loop so that the user can access the menu again until the exit choice is selected
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records\n"); //using bubble sort
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: "); // asking the user to input the choice
        scanf("%d", &choice); // using scanf to read the inpu
        getchar(); // To consume the newline character


 switch (choice) {                           // using switch - case to use the respective functions
    case 1:
        printf("Enter the Name: ");
        fgets(name, sizeof(name), stdin);
        strtok(name, "\n");
        printf("Enter the ID: ");
        scanf("%d", &id);
        printf("Enter the Grade: ");
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
printf("Enter the ID to search: ");
scanf("%d", &id);

Student* found = searchStudentByID(id); 
if (found) {
        printf("Found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
 }
    else {
printf("Student not found in records.\n");
}
    break;
    case 5:
        deleteList();
        printf("List has been deleted.\n");
    break;
    case 6:
    deleteList();  // This handles memory cleanup already
    printf("Exiting the program...\n");
    break;

    
    default:
        printf("Invalid choice! Please try again.\n"); }
}   while (choice != 6);

return 0;
}