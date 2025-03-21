// Q3 student info list
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
// Structure for Student 
typedef struct Student { 
    char name[100]; 
    int id; 
    float grade; 
    struct Student* next; 
} 
Student;  
Student* head = NULL; 
 
// Function to create a new student node 
Student* createStudent(const char* name, int id, float grade) { 
    Student* newStudent = (Student*)malloc(sizeof(Student)); // to add
    //if fail
    if (newStudent == NULL) {
        printf("Memory allocation failed :[\n");
        return NULL;
    }
    // add into struct
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
} 
 
// Function to insert a new student record 
void insertStudent(const char* name, int id, float grade) { 
    Student* newStudent = createStudent(name, id, grade); //add new into function called 
        if (newStudent == NULL) {
            return;
        }
        
        // Insert at the beginning of the list, so it be easier to do
        newStudent->next = head;
        head = newStudent; 
} 
 
// Function to display all student records 
void displayStudents() { 
    if (head == NULL) { //if nothing in memorys
            printf("No student records available.\n");
            return;
        }
        
        Student* current = head; // print from memory
        while (current != NULL) { 
            printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade); 
            current = current->next;
        }
} 
 
// Function to search for a student by ID 
Student* searchStudentByID(int id) { 
    Student* current = head;
        while (current != NULL) { 
            if (current->id == id) {
                return current;
            }

            current = current->next;
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
 
// Sort function to sort the student records by grade based on an 
// using bubble sort
void sortStudents() { 
    // if nothing to sort
    if (head == NULL || head->next == NULL) {
        printf("Not enough students to sort.\n");
        return;
    }

    // declare
    Student* i;
    Student* j;
    float tempGrade;
    int tempID;
    char tempName[100];

    // bubble sort, is the easiest and quickest sort i know how to do properly for small amounts of data off the top of my head.
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->grade < j->grade) {
                // Swap grades
                tempGrade = i->grade;
                i->grade = j->grade;
                j->grade = tempGrade;
                
                // Swap IDs
                tempID = i->id;
                i->id = j->id;
                j->id = tempID;
                
                // Swap names
                strcpy(tempName, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, tempName);
            }
        }
    }

    printf("Students sorted by grade in descending order with bubble sort.\n");
} 
 
// Main function to drive the program 
int main() { 
 
    int choice, id; 
    char name[100]; 
    float grade; 
    int valid = 0;
 
    do { 
        printf("\n1. Insert Student Record\n"); 
        printf("2. Display Student Records\n"); 
        printf("3. Sort Records in bubble sort\n"); 
        printf("4. Search Record by ID\n"); 
        printf("5. Delete List\n"); 
        printf("6. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        // Input validation
        if (choice >= 1 && choice <= 5) {
            valid = 1;
        } else {
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
            valid = 0;
        }
        getchar(); // To consume the newline character 

        if (valid){
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
        }
        
    } while (choice != 6); 
 
    return 0; 
} 
