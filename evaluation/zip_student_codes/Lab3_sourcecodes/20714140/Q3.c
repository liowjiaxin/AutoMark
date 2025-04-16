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
    Student* NewStudent = (Student*)malloc(sizeof(Student));

    strncpy(NewStudent->name,name,sizeof(NewStudent->name)-1);
    NewStudent->name[sizeof(NewStudent->name) - 1] = '\0'; // Remove Null
    NewStudent->id = id;
    NewStudent->grade = grade;
    NewStudent->next = NULL;
// Write your code (1 mark) 
 
} 
 
// Function to insert a new student record 
void insertStudent(const char* name, int id, float grade) { 
    Student* NewStudent = createStudent(name,id,grade);

    NewStudent->next = head; // Initialise a new head
    head = NewStudent;
// Write your code (1 mark) 
} 
 
// Function to display all student records 
void displayStudents() { 
    if (head == NULL){
        printf("No student record available\n");
        return;
    }

    Student* display = head;
    while (display != NULL){
        printf("Name: %s, ID: %d, Grade: %.2f\n", display->name, display->id, display->grade);
        display = display->next;
    }
   // Write your code (1 mark) 
} 
 
// Function to search for a student by ID 
Student* searchStudentByID(int id) { 
    Student* now = head;
    while (now != NULL) {
        if (now->id == id) {
            return now;
        }
        now = now->next;
    }
    return NULL;
   // Write your code (1 mark) 
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
    if (head == NULL || head->next == NULL){
        printf("List has no need to be sorted\n");
        return;
    }
    
    Student* i;
    Student* j;
    char tempName[100];
    int tempID;
    float tempGrade;
    int swapped;

    for (i = head; i != NULL; i = i->next){
        swapped = 0;
        for (j = i->next; j != NULL; j = j->next){  //swap names,id and grades
            if (i->grade > j->grade) {
                strncpy(tempName, i->name, sizeof(tempName));
                tempName[sizeof(tempName) - 1] = '\0';
                strncpy(i->name, j->name, sizeof(i->name));
                i->name[sizeof(i->name) - 1] = '\0';
                strncpy(j->name, tempName, sizeof(j->name));
                j->name[sizeof(j->name) - 1] = '\0';
        
                tempID = i->id;
                i->id = j->id;
                j->id = tempID;

                tempGrade = i->grade;
                i->grade = j->grade;
                j->grade = tempGrade;

                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
    printf("Records sorted by grade using Bubble Sort.\n");
// Write your code (1 mark) 
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