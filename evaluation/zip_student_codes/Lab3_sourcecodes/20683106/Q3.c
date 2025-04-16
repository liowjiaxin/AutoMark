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

    // Using malloc to define a new link list
    Student *studentlist = (Student*)malloc(sizeof(Student));

    // Set respective variables from function parameters
    studentlist->id = id;
    studentlist->grade = grade;

    // Here I want to use strncpy to copy student name to its variable, so I defined a len for length and strncpy it
    unsigned int len = sizeof(studentlist->name);
    strncpy(studentlist->name,name,len-1);
    studentlist->name[len-1] = '\0'; // Add zero terminator after cpying

    // Move pointer after adding
    studentlist->next = NULL;

    return studentlist;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    
    // Calls createstudent function to create a student first in order to insert
    Student *addstudent = createStudent(name,id,grade);

    // If linked list is empty it becomes the first node (head)
    if(head == NULL){
        head = addstudent;
    }else{
        // Set a temp pointer as head, loop until temp->next is NULL which indicate end of list
        Student *temp = head;
        while(temp->next){
            temp = temp->next;
        }
        // When end of linked list add student to last node
        temp->next = addstudent;
    }

    printf("\nStudent record successfully inserted.\n");
}

// Function to display all student records
void displayStudents() {
    
    // Set a temp pointer that points to the head of the linked list
    Student *temp = head;
    // While temp is not NULL print every information
    while(temp){
        printf("Name: %s, ID: %d, Grade: %.2f\n",temp->name,temp->id,temp->grade);
        temp = temp->next;
    }
    
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {

    // Loop until temp is NULL which means end of list (student not found). If found it will return temp which is pointer to the node that matches and exit
    Student *temp = head;
    while(temp != NULL){
        if(temp->id == id){
            return temp;
        }
        temp = temp-> next;
    }
    
    return NULL; // Student not found
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

// From here onwards the functions are for my implementation of merge sort based on how it functions.
// I have three functions, split to split the list in half, merge to merge the lists together after sorting, and mergesort to perform the sorting.
// I used merge sort because it is more efficient in the case of linked list since linked list only support sequential accessed data so algorithms that uses random access perform badly

Student *split(Student *head){

    // Define two pointer, fast will point to the end and while it is at the end slow will be at midpoint. This prepares for splitting
    Student *fast = head;
    Student *slow = head;

    // Fast increments twice while slow moves once
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        if(fast != NULL){
            slow = slow->next;
        }
    }

    // Using slow to split the list into two (start to one after slow pointer and the rest)
    Student *temp = slow->next;
    slow->next = NULL;
    return temp;

}

// Recursive function to combine lists again after sorting. 
Student *merge(Student *first, Student *second){

    // Handle cases where either half of the list is empty
    if(first == NULL) return second;
    if(second == NULL) return first;

    // If the grade of the first student (first->grade) is less than the grade of the second student (second->grade).
    // The current node in the first list should appear first in the merged list because it has a smaller grade.
    // Same applies to otherwise (when second is larger than first)
    if(first->grade < second->grade){
        first->next = merge(first->next,second);
        return first;
    } else {
        second->next = merge(first,second->next);
        return second;
    }

}

Student *mergesort(Student *head){

    // Check if list is empty of only have one node which dont need sorting
    if(head == NULL || head->next == NULL){
        return head;
    }

    // Calls split function to split initial list
    Student *second = split(head);

    // Call mergesort function recursively for both first half and second half of the list to keep splitting and srting
    head = mergesort(head);
    second = mergesort(second);

    printf("\nStudent records have been successfully sorted by grade using merge sort.\n");

    // Returns head of the sorted linked list
    return merge(head,second);

}


// Main function to drive the program
int main() {

    int choice, id;
    char name[100];
    float grade;

    do {
            printf("\n1. Insert Student Record\n");
            printf("2. Display Student Records\n");
            printf("3. Sort Records using Merge Sort\n");
            printf("4. Search Record by ID\n");
            printf("5. Delete List\n");
            printf("6. Exit\n");
            printf("\nEnter your choice: ");
            scanf("%d", &choice);
            getchar(); // To consume the newline character
            printf("\n");

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
                head = mergesort(head);
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