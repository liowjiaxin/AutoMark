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
    // Define a memory spacefor with student* data type
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL){ //If define memory size error
        return NULL;
    }
    strcpy(newStudent->name, name);
    newStudent->name[strcspn(newStudent->name, "\n")] = '\0';
    newStudent->id = id;
    newStudent->grade = grade;

    return newStudent;
} 

// Function to insert a new student record 
void insertStudent(const char* name, int id, float grade) { 
    Student* newStudent = createStudent(name, id, grade);
    
    //If errror
    if(newStudent == NULL){
        puts("Memory allocation error");
        return;
    }

    // Adjust pointer
    newStudent->next = head;
    head = newStudent;
} 


// Function to display all student records 
void displayStudents() { 
    Student* curStudent = head;
    while(curStudent != NULL){
        printf("Name: %s, ID: %d, Grade: %.2f\n", curStudent->name, curStudent->id, curStudent->grade);
        curStudent = curStudent->next;
    }
} 

// Sort function to sort the student records by grade based on an algorithm of your choice 
void sortStudents(){

    if(head == NULL){
        printf("Error, at least two students to sort list.\n");
        return;
    }
    else if(head->next == NULL){
        printf("Error, at least two students to sort list.\n");
        return;
    }
    
    int swapped = 0;
    Student* lastStd = NULL;
    Student* temp1;
    Student* temp2;
    Student* Std1;
    Student* Std2;

    do{
        swapped =0;
        Std1 = head;
        Std2 = Std1->next;
        
        while(Std2 != lastStd){
            if (Std1->grade > Std2 ->grade){
                char tempName[100];
                int tempId;
                float tempGrade;

                strncpy(tempName, Std1 -> name, sizeof(Std1 -> name));
                tempId = Std1 ->id;
                tempGrade = Std1 ->grade;

                strncpy(Std1->name, Std2 ->name, sizeof(Std2->name));
                Std1 ->id = Std2 ->id;
                Std1 ->grade = Std2 ->grade;

                strncpy(Std2->name, tempName, sizeof(tempName));
                Std2 ->id = tempId;
                Std2 ->grade = tempGrade;

                swapped = 1;
            }
            Std1 = Std1->next;
            Std2 = Std1->next;
        }
        lastStd = Std1;
        //Move the lastStd forward
    }while(swapped);

    printf("Records sorted by grade using Bubble Sort.\n");
}


// Function to search for a student by ID 
Student* searchStudentByID(int id) {
    Student* Std1 = head; 
    while(Std1 != NULL){
        if (Std1->id == id){
            return Std1;
        }
        Std1 = Std1->next;
    }
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


// Main function to drive the program 
int main() { 
    int choice, id; 
    char name[100]; 
    float grade; 
    do { 
        printf("\n1. Insert Student Record\n"); 
        printf("2. Display Student Records\n"); 
        printf("3. Sort Records\n"); 
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
