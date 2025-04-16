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

Student* head = NULL;       // singly linked list

// Function prototypes

// 1. Inserts a new student record into the linked list.
void insertStudent(const char* name, int id, float grade);
Student* createStudent(const char* name, int id, float grade);  // Creates a new student node and returns a pointer to it.

// 2. Displays all current student records in the linked list.
void displayStudents(Student* head1); 

// 3. Sort the student records by grade according to a sorting algorithm of your choice. 
void sortStudents(); 
Student* split_list(Student* head1);        // split linked-list into two halves
Student* mergeSort(Student* head1);
Student* merge(Student* first, Student* second);

// 4. Searches for a student record by student ID and returns a pointer to the corresponding student node.
Student* searchStudentByID(int id);  

// 5. Deletes the entire linked list and frees the allocated memory.
void deleteList();  

// 6. Exit - A utility function to ensure that all memory is freed when the program exits.
void freeMemory();  

// Main function to drive the program
int main() {
    int choice, id;
    char name[100];
    float grade;

    do {
        printf("\n1. Insert Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Sort Records (Merge Sort)\n"); 
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
                while(1){
                    printf("Enter ID: ");
                    scanf("%d", &id);
                    // use searchStudentByID(id) to see if the ID is already in used
                    if (searchStudentByID(id) != NULL){
                        printf("ID is taken, pls enter a valid ID.\n");
                    }
                    else{
                        break;
                    }
                }
                // grade validation - set grade range
                while(1){
                    printf("Enter Grade: ");
                    scanf("%f", &grade);
                    if (grade < 0 || grade > 100){
                        printf("Grade should be within 0-100, pls enter a valid range.\n");
                    }
                    else{
                        break;
                    }
                }
                insertStudent(name, id, grade);
                break;
            case 2:
                displayStudents(head);
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
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    return 0;
} 

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    // create a new node
    Student* newNode = (struct Student*)malloc(sizeof(Student));
    
    // assign new student node data
    strcpy(newNode->name, name);
    newNode->id = id;
    newNode->grade = grade;
    newNode->next = NULL;
    
    return newNode;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* newNode = createStudent(name, id, grade);
    // insert student at first(top) of the record
    newNode->next = head;
    head = newNode;
}

// Function to display all student records
void displayStudents(Student* head1) {
    if (head1 == NULL){
        printf("Student record is empty.\n");
        return;     // return to main() function if linked-list is empty
    }
    
    Student* temp = head1;
    while (temp != NULL){
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next;
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* current = head;

    while(current != NULL){
        if(id == current->id){
            return current;         // return compatible id to main()
        }
        current = current->next;    // else continue to compare next id
    }
    return NULL;       // return NULL if no student is found
}

// Function to delete the entire list
void deleteList() {
    Student* current = head;
    Student* next; 

    while (current != NULL) {
        next = current->next;
        free(current);          // free current allocated memory
        current = next;
    }
    head = NULL;
}

void freeMemory() {
    deleteList();
}

// Sort function to sort the student records by grade based on an algorithm of your choice
void sortStudents() {
    if (head == NULL){
        printf("Student record is empty.\n");
        return;     // return to main() function if linked-list is empty
    }
    head = mergeSort(head);
    printf("Records sorted by grade using Merge Sort\n");
}
// merge sort algorithm
// chose this algorithm because i have done this algorithm on another project so i'm more familiar with it
// it also suitable for large datasets
Student* split_list(Student* head1){      // split linked list
    // struct pointers
    Student* two = head1;
    Student* one = head1;

    // two - move 2 steps, one - move 1 step --> when two reaches the end, one is at the midpoint og list
    while (two != NULL && two->next != NULL){
        two = two->next->next;
        if (two != NULL){
            one = one->next;
        }
    }
    // split list into 2 halves
    Student* temp = one->next;
    one->next = NULL;
    return temp;
}

Student* mergeSort(Student* head1){
    // if head or next == NULL --> sorted --> merge
    if (head1 == NULL || head1->next == NULL) {
        return head1;     // return to sortStudents()
    }

    Student* second = split_list(head1);

    // recursion call (keep splitting array until both left[] & right[] only contain 1 element --> prepare to merge)
    head1 = mergeSort(head1);
    second = mergeSort(second);

    // merge the sorted halves arrays
    return merge(head1, second);
}

Student* merge(Student* first, Student* second){
    // if list is empty --> return the other list (pointed by pointer)
    if (first == NULL){
        return second;
    }
    if (second == NULL){
        return first;
    }

    // compare first->grade & second->grade
    if (first->grade <= second->grade){
        // recursively call merge() & link result to current node
        first->next = merge(first->next, second);
        return first;
    }
    else{
        // recursively call merge() & link result to current node
        second->next = merge(first, second->next);
        return second;
    }
}
