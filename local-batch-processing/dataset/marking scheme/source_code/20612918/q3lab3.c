 
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
 
// Function to create new student node
Student* createStudent(const char* name, int id, float grade) { 
    Student* newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent->name, name);
    (*newStudent).id = id;
    (*newStudent).grade = grade;
    (*newStudent).next = NULL;
    return newStudent;
 
} 
 
// Function to insert a new student record 
void insertStudent(const char* name, int id, float grade) { 
    Student* newStudent = createStudent(name, id, grade);
    (*newStudent).next = head;
    head = newStudent;
} 
 
// Function to display all student records 
void displayStudents() { 
    if (head == NULL) {
        //if student struct is empty
        printf("No records to display.\n");
        return;
    }
    Student* temp = head;
    //printing student records
    while (temp != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", (*temp).name, (*temp).id, (*temp).grade);
        temp = (*temp).next;
    }
}
 
 
 
// Function to search for a student by ID 
Student* searchStudentByID(int id) { 
   // Write your code (1 mark) 
   Student* temp = head;
    while (temp != NULL) {
        if ((*temp).id == id) {
            return temp;
        }
        temp = (*temp).next;
    }
    return NULL; // Student not found
}

 
 
// Function to delete all the entire list
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
 
//Sort function to sort the student records by grade based on an algorithm of your choice 
void sortStudents() { 
// Write your code (1 mark) 
    if (head == NULL || (*head).next == NULL) {
            return; // No need to sort if there are fewer than two students
        }

        int swapped;
        Student* temp;
        Student* last = NULL;

        //bubble swap is used because its simple to use for small datasets and its easy to use for linked lists
        do {
            swapped = 0;
            temp = head;

            while ((*temp).next != last) {
                if ((*temp).grade > (*(*temp).next).grade) {
                    // Swap grades, names, and IDs
                    char tempName[100];
                    int tempID;
                    float tempGrade;

                    tempGrade = (*temp).grade;
                    tempID = (*temp).id;
                    strcpy(tempName, (*temp).name);

                    (*temp).grade = (*(*temp).next).grade;
                    (*temp).id = (*(*temp).next).id;
                    strcpy((*temp).name, (*(*temp).next).name);

                    (*(*temp).next).grade = tempGrade;
                    (*(*temp).next).id = tempID;
                    strcpy((*(*temp).next).name, tempName);

                    swapped = 1;
                }
                temp = (*temp).next;
            }
            last = temp;
        } while (swapped);
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
