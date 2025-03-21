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
// Write your code (1 mark) 
    Student* NewStudent = (Student*)malloc(sizeof(Student));
    if (NewStudent == NULL) {
        exit(EXIT_FAILURE);
    }
    strcpy(NewStudent->name,name);
    NewStudent->id = id; 
    NewStudent->grade = grade;
    NewStudent->next = NULL;
    return NewStudent;
} 
 
// Function to insert a new student record 
void insertStudent(const char* name, int id, float grade) { 
// Write your code (1 mark)
    Student* node = createStudent(name, id, grade);
    if(head == NULL) {
        head = node;
    } else {
        Student* temp =head;
        while (temp->next = NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
} 
 
// Function to display all student records 
void displayStudents() { 
   // Write your code (1 mark)
   if (head ==NULL) {
    printf("Empty student records.");
    return;
   }
   Student* temp = head;
   printf("Student Records:\n");
   while(temp != NULL) {
    printf("Name: %s, ID: %d, Grade: %.2f", temp->name, temp->id, temp->grade);
    temp = temp->next;
   }
} 
 
// Function to search for a student by ID 
Student* searchStudentByID(int id) { 
   // Write your code (1 mark)
    Student* temp = head;
    while (temp != NULL) {
        if (temp->id == id){
            return temp;
        }
        temp = temp->next;
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
void sortStudents() { 
// Write your code (1 mark) 
    if (head == NULL || head->next == NULL) {
        printf("No records to sort.");
        return;
    }
    int swap;
    Student* ptr1;
    Student* lptr = NULL;
    //bubble sort
    do {
        swap = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->grade < ptr1->next->grade) {
                char temp_name[100];
                int temp_ID;
                float temp_Grade;

                strcpy(temp_name, ptr1->name);
                temp_ID = ptr1->id;
                temp_Grade = ptr1->grade;

                strcpy(ptr1->name, ptr1->next->name);
                ptr1->id = ptr1->next->id;
                ptr1->grade = ptr1->next->grade;

                strcpy(ptr1->next->name, temp_name);
                ptr1->next->id = temp_ID;
                ptr1->next->grade = temp_Grade;

                swap = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swap == 1);
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