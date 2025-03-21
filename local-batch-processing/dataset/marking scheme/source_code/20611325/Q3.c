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
    Student* newStudent = (Student*)malloc(sizeof(Student));    //Allocate memory for a new student record
    if (newStudent == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    //Store data of a student as linked list
    strcpy(newStudent->name, name);
    newStudent->id = id;    
    newStudent->grade = grade;
    newStudent->next = NULL;

    return newStudent;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* insertNewStudent = createStudent(name, id, grade);
    if (head == NULL) { //Check if the list is empty
        head = insertNewStudent;    
    } else {    //Insert at the end of the list
        Student* current = head;
        while (current->next != NULL) { //Traverse to the end of the list
            current = current->next;
        }
        current->next = insertNewStudent; //Link the new student to the end of the list

    }
}

// Function to display all student records
void displayStudents() {
    Student* current = head;
    if (current == NULL) {  //Check if the list is empty, by checking the head (start) of the list
        printf("No student records found.\n");
    } else {
        while (current != NULL) {   //List out all the student records until the end of the list
            printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
            current = current->next;    //Move to the next student record after current student record is accessed
        }
    }
}
// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* current = head;
    while (current != NULL){
        if (current->id == id){ //Check if ID matches, if ID found, return the student record
            return current; 
        }else{
        current = current->next;    //Move to the next student record if ID does not match
        }
    }
}
// Function to delete the entire list
void deleteList() {
    Student* current = head;
    Student* next;

    //Delete all the student records until the end of the list
    while (current != NULL) {   
    next = current->next;
    free(current);  //Free memory of the current student record after deletion
    current = next;
    }

    head = NULL;
    }

void freeMemory() {
    deleteList();
    }

// Sort function to sort the student records by grade based on an algorithm of your choice
void sortStudents() {
    Student* current = head;
    Student* next;
    Student* temp;

    if(current == NULL || current->next == NULL) { //Check if the list is empty or has only one student record
        printf("Unable to sort due to lack of student record");
        return;
    }

    //Bubble sort algorithm to sort the student records by ID in ascending order
    for(current = head; current->next != NULL; current = current->next) {   //Moving from first to second of the student records
        for(next = current->next; next != NULL; next = next->next) {        //Move from second to the last student record
            if(current->grade > next->grade) {  //Check if the current student record grade is greater than the next student record grade
                temp = createStudent(current->name, current->id, current->grade); 
                
                //Swap position of student records

                //Previous student record replaced by next student record
                strcpy(current->name, next->name);
                current->id = next->id;
                current->grade = next->grade;

                //Next student record replaced by previous student record
                strcpy(next->name, temp->name);
                next->id = temp->id;
                next->grade = temp->grade;
            }
        }
    }
    printf("Records sorted by grade using Bubble Sort algorithm\n");
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
                if (found) {    //Display the student record if found
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