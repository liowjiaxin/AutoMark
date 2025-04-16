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
    Student* newStudent = (Student*)malloc(sizeof(Student)); //allocating memory

    //copying data into the list
    strcpy(newStudent->name, name); 
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
} 
 
// Function to display all student records 
void displayStudents() { 
   int i = 1;
    Student* temp = head; //Start at the head

    if(temp == NULL){
        printf("There are no students in the list\n"); //if list is empty
        return;
    }

    while(temp != NULL){
        printf("%d. Name: %s, ID: %d, Grade: %.2f\n", i++, temp->name, temp->id, temp->grade); //printing members of the list
        temp = temp->next; // going to next node
    }
} 
 
// Function to search for a student by ID 
Student* searchStudentByID(int id) { 
    Student* temp = head;
    while(temp != NULL){
        if(temp->id == id){
        return temp;
        }else{
            temp = temp->next;
        }
    }
    return NULL;
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
// Function to split the linked list into two halves
Student* splitList(Student* head) {
    Student* Left = head;
    Student* Right = head->next;

    while (Right != NULL && Right->next != NULL) {
        Left = Left->next;
        Right = Right->next->next;
    }

    Student* secondHalf = Left->next;
    Left->next = NULL; // Split the list
    return secondHalf;
}

// Function to merge two sorted lists
Student* mergeLists(Student* list1, Student* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    Student* merged = NULL;

    if (list1->grade <= list2->grade) {
        merged = list1;
        merged->next = mergeLists(list1->next, list2);
    } else {
        merged = list2;
        merged->next = mergeLists(list1, list2->next);
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

    return mergeLists(sortedFirstHalf, sortedSecondHalf); // Merge sorted halves
}

// Sort function for your skeleton
void sortStudents() {
    head = mergeSort(head);
    printf("Student records sorted by grade.\n");
}

// Function to insert a new student record 
void insertStudent(const char* name, int id, float grade) { 
    Student* newStudent = createStudent(name, id, grade); // creating a new node
    if (head == NULL) {
        head = newStudent; //inserts to the head if head is empty
        return;
    }
    Student* temp = head;
    while (temp->next != NULL) { // traverses through the list to find the last node
        temp = temp->next;
    }
    temp->next = newStudent; //enters student at end of the list

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