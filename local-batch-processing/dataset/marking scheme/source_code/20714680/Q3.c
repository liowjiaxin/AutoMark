#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// Structure for Student 
typedef struct Student {    //defining the struct Student for storing student records
    char name[100]; 
    int id; 
    float grade; 
    struct Student* next; 
    }Student; 

Student* head = NULL;   //declaring a pointer to the struct Student and initializing it to NULL

// Function to create a new student node 
Student* createStudent(const char* name, int id, float grade) { 
    //Allocate node 
    Student *new_student = (Student*) malloc(sizeof(Student)); //determines the size of Student structure, allocates memory of that number of bytes and stores a pointer to the allocated memory in the pointer new_student
    //Put in the information
    strncpy(new_student->name, name, strlen(name));
    new_student->id = id;
    new_student->grade = grade;
    new_student->next = NULL;
    return new_student;
} 

// Function to insert a new student record 
void insertStudent(const char* name, int id, float grade) {
     Student *new_student = createStudent(name, id, grade);     //This creates a new node by calling the function and assigning it to the pointer new_student
     new_student->next = head;  //This makes the next pointer of the new_student node to point to the head i.e the beginning of the list
     head = new_student;    //head is now pointing to the new node
} 

// Function to display all student records 
void displayStudents() {
     Student* current = head;   //declaring a pointer current of type Student and initializing it to head 
     //Traverse through the linked list
     while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("ID: %d\n", current->id);
        printf("Grade: %.2f\n", current->grade);
        current = current->next;    //This line accesses the next pointer of current node. Hence, updates current to point to next node in the linked list
    } 
}

// Function to search for a student by ID 
Student* searchStudentByID(int id) {
    Student* current = head;     //declaring a pointer current of type Student and initializing it to head
    //Traverse through the linked list
    while(current!=NULL) {
        if(current->id == id) {     //This checks if the current node in the linked list has the same id as the id being searched for
            return current;         //Returns a pointer to the node containing the specified id
        }
        current = current->next;    //This line accesses the next pointer of current node. Hence, updates current to point to next node in the linked list
    } 
    return NULL;    //If no node with the specified id is found, it returns NULL
} 

// Function to delete the entire list 
void deleteList() { 
    Student* current = head;    //declaring a pointer current of type Student and initializing it to head
    Student* next;      //declaring a pointer next of type Student
    //Traverse through the linked list
    while (current != NULL) { 
        next = current->next;   //This accesses the next pointer of the current node and sets next to point to the next node in the linked list
        free(current);      //deallocate memory
        current = next;     //updates current to the next node in the linked list
    } 
    head = NULL;    //This sets the head pointer to NULL after everything has been deleted
}

void freeMemory() { 
    deleteList();   //This deletes the entire linked list to deallocate memory to prevent memory leaks
} 

//function to swap information stored in two nodes
void swap(Student* student1, Student* student2) {
    char hold_Name[50];
    strcpy(hold_Name, student1->name);
    strcpy(student1->name, student2->name);
    strcpy(student2->name, hold_Name);

    int hold_ID = student1->id;
    student1->id = student2->id;
    student2->id = hold_ID;

    float hold_Grade = student1->grade;
    student1->grade = student2->grade;
    student2->grade = hold_Grade;
}

//Used bubble sort to sort the student records because it simple and easy to understand and implement
void sortStudents() {
    int swapped, i;
    Student *ptr1;  //declaring a pointer ptr1 of type Student
    Student *lptr = NULL;   //declaring a pointer lptr of type Student and intializing it to NULL
    if (head == NULL) {     //This checks if the list is empty
        return;
    }

    do
    {  
        swapped = 0;  
        ptr1 = head;    //This sets the ptr1 to point to head of the linked list
  
        while (ptr1->next != lptr) { //The loop continues to run as long as ptr1->next is not equal to lptr
            if (ptr1->grade > ptr1->next->grade) {  //If the grade in previous node is larger than the grade in next node
                swap(ptr1, ptr1->next); //call the swap function
                swapped = 1;    //This sets swapped to 1 to show that a swap has been made
            }
            ptr1 = ptr1->next;  //Updates the ptr1 to point to the next node
        }
        lptr = ptr1;    //Updates the lptr to point to ptr1
    } while (swapped);
}   

// Main function to drive the program 
int main() { 
    //Initializing variables
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
                insertStudent(name, id, grade);     //call the function to insert a new student record
                break; 
            case 2: 
                displayStudents();      //call the function to display all student records
                break; 
            case 3: 
                sortStudents();     //call the sortStudents function to arrange the students records
                break; 
            case 4: 
                printf("Enter ID to search: "); 
                scanf("%d", &id); 
                Student* found = searchStudentByID(id);     //call the function to search a student record with specific ID
                if (found) { 
                    printf("Found: Name: %s, ID: %d, Grade: %.2f\n", found->name, found->id, found->grade); 
                } else { 
                    printf("Student not found.\n");
                } 
                break; 
            case 5: 
                deleteList();       //call the function to delete the records
                printf("List deleted.\n"); 
                break; 
            case 6: 
                freeMemory();   //call the function to free the allocated memory
                printf("Exiting...\n"); 
                break; 
            default: 
                printf("Invalid choice! Please try again.\n");  //Gives error if user enters invalid input
            } 
        } while (choice != 6); 
    return 0; 
} 