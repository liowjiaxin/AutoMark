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
    Student *sPtr = malloc(sizeof(Student)); // Allocate dynamic memory to store the Student
    strcpy((*sPtr).name, name); // Copy the user input name to the name field of the Student
    (*sPtr).id = id; // Store the user input id into the id field of the Student
    (*sPtr).grade = grade; // Store the user input grade into the grade field of the Student
    (*sPtr).next = NULL; // Assign NULL to next pointer of the newly created Student
    return sPtr;
}
// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student * sPtr = createStudent(name, id, grade); // Create a new student and get a pointer to it
    if (head == NULL) { // 
        head = sPtr; // If head is NULL, just assign pointer to new student to it
    } else {
        Student * current = head; // Otherwise loop until the last node where the next is NULL
        while((*current).next != NULL) {
            current = (*current).next;
        }
        (*current).next = sPtr; // Assign the pointer to the new node to the next field of the last node
    }
}
// Function to display all student records
void displayStudents() {
    Student * current = head; // Start from the first node
    while(current != NULL) { // Loop until the current node is NULL
        printf("Name: %s, ID: %d, Grade: %.2f\n", (*current).name, (*current).id, (*current).grade);
        current = (*current).next;
    }
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student * current = head; // Start from the first node
    while (current != NULL) { // Loop until the current node is NULL or if the current node is the targeted node
        if ((*current).id == id) { // Check if the id of current node is the is the id we want to find
            return current; // If yes return the current node
        }
        current = (*current).next; // Or else move to the next node
    }
    return current; // If not found, current is NULL and is returned
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

// merge function that merges two sorted halve
Student* merge(Student* left, Student* right) {
    // Dummy node used for merging (makes it easier)
    Student dummy;
    dummy.next = NULL;
    Student* tail = &dummy;


    // Merge the two lists
    while (left != NULL && right != NULL) {
        if ((*left).grade <= (*right).grade) { // Start by comparing the first element of the two halves
            // If left one is smaller, assign the pointer to the left element to the next field of dummy node
            (*tail).next = left; 
            left = (*left).next; // Move left pointer forward
        } else {
            // Otherwise, assign the pointer to the right element to the next field of dummy node
            (*tail).next = right; 
            right = (*right).next; // Move right pointer forward
        }
        tail = (*tail).next; // Make tail point to newly added node
    }

    // Append the remaining elements to the merged list starting from tail
    if (left != NULL) { // If left is not NULL that means the left halve have remaining elements
        (*tail).next = left;
    } else {
        (*tail).next = right;
    }

    return dummy.next; // Return the pointer at the next field of dummy that points to the next node (begining of merged list)
}

// Split the list into parts (left part and right part)
void splitHalf(Student ** left, Student ** right, Student * head) {
    // Use slow and fast pointer method to split the list
    Student *slow = head;
    Student *fast = (*head).next;

    while (fast != NULL && (*fast).next != NULL) {
        slow = (*slow).next;
        fast = (*(*fast).next).next; // Fast pointer moves 1 additional position compared to slow pointer
    }

    // Split the list into two halves
    *left = head;            // Left part starts from head (Assign head to left)
    *right = (*slow).next;   // Right part starts from the node right after slow
    (*slow).next = NULL;     // End the left part with NULL (disconnect it from right part)
}   

// Main mergeSort function
Student * mergeSort(Student * head) {
    if ((*head).next == NULL) {
        return head; // base case (size = 1)
    } else {
        // Normal procedure: split --> mergeSort each half --> finally merge them up
        Student * left = NULL;
        Student * right = NULL;
        splitHalf(&left, &right, head);
        left = mergeSort(left);
        right = mergeSort(right);
        return merge(left, right);
    }
}

// Sort function to sort the student records by grade based on an
//algorithm of your choice
void sortStudents() {
    if (head != NULL) {
        head = mergeSort(head);
        printf("Records sorted using Merge Sort\n");
    } else {
        printf("No students stored.\n");
    }
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
