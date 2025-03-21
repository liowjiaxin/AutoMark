#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[100];
    int id;
    float grade;
    struct Student* next;
} Student;


Student* head = NULL;

// Function to create a new student node
Student* createStudent(const char* name, int id, float grade) {
    //Validation for Student name
     if ( strlen(name) == 0 || strlen(name) >= 100 ) {
        printf(" Invalid name\n");
        return NULL;
    }

    // Validation for ID 
    if (id <= 0) {
        printf("Invalid ID\n");
        return NULL;
    }

    // Validation for grade 
    if (grade < 0 || grade > 100) {
        printf(" Invalid grade\n");
        return NULL;
    }

    Student* newStudent = malloc(sizeof(Student));
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a new student record 
void insertStudent(const char* name, int id, float grade) {
    Student* newStudent = createStudent(name, id, grade);
    newStudent->next = head;
    head = newStudent;
}

// Function to display all student records
void displayStudents() {
     Student* temp = head;
    while (temp != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", temp->name, temp->id, temp->grade);
        temp = temp->next;
    }
}

// Function to search for a student record by ID
Student* searchStudentByID(int id) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
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
    


// Function to free all memory when the program exits
void freeMemory() {
    deleteList();
}



// Sort function to sort the student records by grade using Bubble Sort
void sortStudents() {
    Student* temp1 = head;
    Student* temp2 = NULL;

    
    while (temp1 != NULL) {
        temp2 = temp1->next;
        while (temp2 != NULL) {
            // Compare the grade of temp1 with temp2
            if (temp1->grade > temp2->grade) {  
               
                char tempName[100];
                int tempID;
                float tempGrade;

                // Swap the student data
                strcpy(tempName, temp1->name);
                tempID = temp1->id;
                tempGrade = temp1->grade;

                strcpy(temp1->name, temp2->name);
                temp1->id = temp2->id;
                temp1->grade = temp2->grade;

                strcpy(temp2->name, tempName);
                temp2->id = tempID;
                temp2->grade = tempGrade;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

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
    getchar(); 

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