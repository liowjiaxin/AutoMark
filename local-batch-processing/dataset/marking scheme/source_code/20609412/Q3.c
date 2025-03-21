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

    //allocate memory for pointer
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (!newStudent) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    //copy the input values into the new student nodes
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}


// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    // Create a new student
    Student* newStudent = createStudent(name, id, grade);

    // Check if memory allocation for the new student failed
    if (!newStudent) {
        printf("Error: Memory allocation failed for the new student.\n");
        return;
    }

    // Insert the new student at the beginning of the list
    newStudent->next = head;
    head = newStudent;

    // Confirm the successful insertion
    printf("Student '%s' with ID %d has been successfully added.\n", name, id);
}


// Function to display all student records
void displayStudents() {
    if (!head) {
        printf("No student records found.\n");
        return;
    }

    //set the head to a temp pointer
    Student* temp = head;
    printf("\nStudent Records:\n");
    printf("--------------------------------------------------\n");
    while (temp) {
        printf("Name: %-15s ID: %-10d Grade: %-3.2f\n", temp->name, temp->id, temp->grade);
        //make temp pointer to the next node in the link list
        temp = temp->next;
    }
    printf("--------------------------------------------------\n");
}


// Function to search for a student by ID
Student* searchStudentByID(int id) {

    //set the head to a temp pointer
    Student* temp = head;
    //continue looping if it is not the end of the link list
    while (temp){

        // If the student ID matches the input, return the corresponding student node
        if (temp->id == id){
            return temp;
        } else {
            temp = temp->next;
        }
        return NULL;
    }

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
void sortStudents() {
    if (!head || !head->next) {
        printf("Not enough records to sort.\n");
        return;
    }

    int swapped;
    Student* ptr;
    Student* last = NULL;

    // Continue looping until no more swaps are needed
    do {
        swapped = 0;
        ptr = head;

        //continue looping if pointer is not pointing the last node
        while (ptr->next != last) {

            //if current node is greater than the next node
            if (ptr->grade > ptr->next->grade) {
                
                // Swap the grade, ID, and name of the current and next nodes
                float tempGrade = ptr->grade;
                int tempID = ptr->id;
                char tempName[100];
                strcpy(tempName, ptr->name);

                ptr->grade = ptr->next->grade;
                ptr->id = ptr->next->id;
                strcpy(ptr->name, ptr->next->name);

                ptr->next->grade = tempGrade;
                ptr->next->id = tempID;
                strcpy(ptr->next->name, tempName);

                swapped = 1;
            }
            ptr = ptr->next;    // Move to the next node
        }
        last = ptr; // Update the last node to mark the boundary for the next pass
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
