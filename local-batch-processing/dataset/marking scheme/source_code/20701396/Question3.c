#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
//code runs on cmd
 
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
    Student* newnode = (Student*)malloc(sizeof(Student)); //allocate memory withmalloc

    //copying data into the list
    strcpy(newnode->name, name); 
    newnode->id = id;
    newnode->grade = grade;
    newnode->next = NULL;
    return newnode;
} 
 
// Function to display all student records 
void displayStudents() { 
    int i = 1;
    Student* temporaryvar = head; //begin at the head of the linked list

    if(temporaryvar == NULL){
        printf("No students are in the list\n"); //if list is empty
        return;
    }

    while(temporaryvar != NULL){
        printf("%d. Name: %s, ID: %d, Grade: %.2f\n", i++, temporaryvar->name, temporaryvar->id, temporaryvar->grade); //printing members of the list
        temporaryvar = temporaryvar->next; // go to the next node
    }
} 
 
// Function to search for a student by ID 
Student* searchStudentByID(int id) { 
    Student* temporaryvar = head;
    while(temporaryvar != NULL){ 
        if(temporaryvar->id == id){ //validate that the search element is the value of the temporary variable
        return temporaryvar; 
        }else{
            temporaryvar = temporaryvar->next;
        }
    }
    return NULL;
} 
 
// Function to delete the entire list 
void deleteList() { 
    Student* current = head; 
    Student* next; 
 
    while (current != NULL) { 
        next = current->next; //goto the next element of the list
        free(current); //delete element of the list
        current = next; //make the current element become the next element
    } 
    head = NULL; 
}
 
 
void freeMemory() { 
    deleteList(); 
} 
 
// Sort function to sort the student records by grade based on an algorithm of your choice
// Function to split the linked list into two halves
Student* splitList(Student* head) {
    Student* Right = head->next;
    Student* Left = head;
    

    while (Right != NULL && Right->next != NULL) {
        Left = Left->next;
        Right = Right->next->next;
    }

    Student* secondHalf = Left->next;
    Left->next = NULL; // Split the list
    return secondHalf;
}

// Function to merge two sorted lists
Student* merge(Student* list1, Student* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    Student* merged = NULL;

    if (list1->grade <= list2->grade) {
        merged = list1;
        merged->next = merge(list1->next, list2);
    } else {
        merged = list2;
        merged->next = merge(list1, list2->next);
    }

    return merged;
}

// Recursive Merge Sort function
Student* mergeSort(Student* head) {
    if (head == NULL || head->next == NULL) {
        return head; // Base case: 0 or 1 node
    }

    Student* secondHalf = splitList(head); // Split the list into two halves
    Student* sortedFirstHalf = mergeSort(head); // Sort the first half
    Student* sortedSecondHalf = mergeSort(secondHalf); // Sort the second half

    return merge(sortedFirstHalf, sortedSecondHalf); // Merge sorted halves
}

// Sort function for your skeleton
void sortStudents() {
    head = mergeSort(head);
    printf("Sorted Students Recors\n");
}

// Function to insert a new student record 
void insertStudent(const char* name, int id, float grade) { 
    Student* newnode = createStudent(name, id, grade); // creating a new node
    if (head == NULL) {
        head = newnode; //inserts to the head if head is empty
        return;
    }
    Student* temporaryvar = head;
    while (temporaryvar->next != NULL) { // traverses through the list to find the last node
        temporaryvar = temporaryvar->next;
    }
    temporaryvar->next = newnode; //enters student at end of the list

} 

 
// Main function to drive the program 
int main() { 
 
    int choice, id; 
    char name[100]; 
    float grade; 
 
    do { 
        printf("\n1. Insert Student Record\n"); 
        printf("2. Display Student Records\n"); 
        printf("3. Sort Records (Ascending Order)\n"); 
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
                printf("Search for ID "); 
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