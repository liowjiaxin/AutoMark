#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Student
typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next; // this is the pointer to the next student in the linked list
} Student;

Student* head = NULL;

void insertStudent(const char* name, int id, float grade); // Inserts a new student record into the linked list.
void displayStudents(); // Displays all current student records in the linked list.
Student* searchStudentByID(int id); // Searches for a student record by student ID and returns a pointer to the corresponding studentnode.
void deleteList(); // Deletes the entire linked list and frees the allocated memory.
void freeMemory(); // A utility function to ensure that all memory is freed when the program exits.
Student* createStudent(const char* name, int id, float grade); //Creates a new student node and returns a pointer to it.
void sortStudents(); // Sort the student records by grade according to a sorting algorithm of your choice. 

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student)); // Allocate memory for the new student
    if (!newStudent) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strcpy(newStudent->name, name); // Copy the name
    newStudent->id = id;           // Assign the ID
    newStudent->grade = grade;     // Assign the grade
    newStudent->next = NULL;       // Initialize the next pointer
    return newStudent;             // Return the new student
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade); // Create a new student node
    if (!newStudent) return;

    if (head == NULL) { // If the list is empty, make the new student the head
        head = newStudent;
    } else {
        Student* temp = head; // Temporary pointer to traverse the list
        while (temp->next != NULL) { // Goes through to the end of the list
            temp = temp->next;
        }
        temp->next = newStudent; // Add the new student to the end of the list
    }
    printf("Student record inserted successfully.\n");
}

// Function to display all student records
void displayStudents() {
    if (head == NULL) { // This checks whether the list is empty or not
        printf("No student records to display.\n");
        return;
    }
    Student* temp = head;
    printf("Student Records:\n");
    while (temp != NULL) { // Goes through the list and display each student's details
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next;
    }
}

// Function to search for a student by ID
Student* StudentID(int id) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->id == id) { // If the ID matches, return the student
            return temp;
        }
        temp = temp->next;
    }
    return NULL; // Return NULL if no student is found
}

// Sort function to sort the student records by grade based on an algorithm of your choice
void sortStudents() {
    // To view the sorted version first press 2 to display all the records in the unsorted manner then press 3 to sort all the records and view again by pressing 2
    if (head == NULL || head->next == NULL) { 
        printf("No sorting needed. List is empty or has only one student.\n");
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

                strcpy(tempName, j->name); //swaps the names
                tempID = j->id; // swaps the ID's
                tempGrade = j->grade; // swaps the grades

                strcpy(j->name, j->next->name);
                j->id = j->next->id;
                j->grade = j->next->grade;

                strcpy(j->next->name, tempName);
                j->next->id = tempID;
                j->next->grade = tempGrade;
            }
        }
    }
 printf("Student records have been sorted by grade in ascending order, using bubble sort (press 2 to view the sorted order).\n");
}

// Function to delete the entire list
void deleteList() {
 Student* current = head; // Pointer to the current node
 Student* next; // Pointer to the next node

 while (current != NULL) { // Goes through the list
    next = current->next; // Save the pointer to the next node
    free(current); // Frees up the memory for the current node
    current = next; // Moves to the next node
 }
 head = NULL;
}

void freeMemory() {
 deleteList(); // Call deleteList to free the entire list
} 


// Main function to drive the program
int main() {
 int choice, ID_NO;
 char name[100];
 float grade;
 do {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records\n"); //using bubble sort, because it is simpliest to implement and can be used for sorting records easily
        printf("4. Search Record by ID\n");
        printf("5. Delete List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To remove the newline character


 switch (choice) {
    case 1:
        printf("Enter Name: ");
        fgets(name, sizeof(name), stdin);
        strtok(name, "\n");
        printf("Enter ID: ");
        scanf("%d", &ID_NO);
        printf("Enter Grade: ");
        scanf("%f", &grade);
        insertStudent(name, ID_NO, grade);
    break;
    case 2:
    displayStudents();
    break;
    case 3:
    sortStudents();
    break;
    case 4:
printf("Enter ID to search: ");
scanf("%d", &ID_NO);

Student* found = StudentID(ID_NO); 
if (found) {
        printf("Found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade);
 }
    else {
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
        printf("Invalid choice! Please try again.\n"); }
}   while (choice != 6);

return 0;
} 
