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
    Student student;
    Student* studentPtr = malloc(sizeof(Student));

    strcpy(student.name, name);
    student.id = id;
    student.grade = grade;
    student.next = NULL;

    memcpy(studentPtr, &student, sizeof(Student));

    return studentPtr;
}

// Function to insert a new student record
void insertStudent(const char* name, int id, float grade) {
    Student* studentPtr = createStudent(name, id, grade);
    studentPtr->next = head;
    head = studentPtr;
}

// Function to display all student records
void displayStudents(Student* head, int len) {
    Student* current = head;
    Student* next;

    if (head == NULL) {
        puts("There are no students to display.");
    }

    while (current != NULL && len!=0) {
        next = current->next;
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = next;
        len--;
    }
    
}

// Function to search for a student by ID
Student* searchStudentByID(int id) {
    Student* current = head;
    Student* next;
    while (current != NULL) {
        next = current->next;
        if (current->id == id) {
            return current;
        }
        current = next;
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

int countStudents(Student* headPtr) {
    int counter=0;
    Student* current = headPtr;
    Student* next;
    while (current != NULL) {
        next = current->next;
        counter++;
        current = next;
    }
    return counter;
}

// Sort function to sort the student records by grade based on an algorithm of your choice
void sortStudents() {
    // Merge sort | Because it is stable, better time complexity than bubblesort or insertion sort that is simpler, appending the sublists when the other is empty is easy with linked lists
    Student *bufhead, *buftail;
    int k = 1;
    Student *leftstart, *leftend, *rightstart, *rightend, *end;
    Student *largerPtr;
    int len = countStudents(head);

    char dummy;

    // Left sublist: [leftstart,...,leftend]
    // Right sublist: [rightstart,...,rightend]

    while (k < len) {
        leftstart = head;
        bufhead = NULL;
        buftail = bufhead;

        // Goes through list
        while (leftstart != NULL) {

            // Sets the start of right sublist to right after the leftsublist
            leftend = leftstart;
            for (int i = 0; i < k-1; i++) {
                // Left sublist reaches end of list
                if (leftend->next == NULL) {
                    break;
                } else {
                    leftend = leftend->next;
                }
            }
            // Left sublist reaches end of list
            if (leftend->next == NULL) {
                buftail->next = leftstart;
                buftail = leftend;
                break;
            }
            
            rightstart = leftend->next;

            // Adjusts end of right sublist, either until k moves or end of list
            rightend = rightstart;
            for (int i = 0; i < k-1; i++) {
                // Left sublist reaches end of list
                if (rightend->next == NULL) {
                    break;
                } else {
                    rightend = rightend->next;
                }
            }

            // Merging to buffer

            // Sublists not empty
            while (leftstart != leftend->next && rightstart != rightend->next) {
                // Pointing largerPtr to larger
                if (leftstart->grade >= rightstart->grade) {
                    largerPtr = leftstart;
                    leftstart = leftstart->next;
                } else {
                    largerPtr = rightstart;
                    rightstart = rightstart->next;
                }

                // Appending larger to buffer
                if (bufhead == NULL) {
                    // Case of adding first item to buffer
                    bufhead = largerPtr;
                    buftail = bufhead;
                } else {
                    buftail->next = largerPtr;
                    buftail = buftail->next;
                }
            }
            

            // if left empty
            if (leftstart == leftend->next) {
                // append right sublist to buffer
                buftail->next = rightstart;
                buftail = rightend;
                leftstart = rightend->next;
            }

            // if right empty
            if (rightstart == rightend->next) {
                // append left sublist to buffer
                buftail->next = leftstart;
                buftail = leftend;
                leftstart = rightstart;
            }
        }
        // Point the head to buffer head
        head = bufhead;
        buftail->next = NULL;

        k *= 2;
    }

    if (len) {
        puts("Record has been sorted with merge sort");
    } else {
        puts("No records to sort");
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
                displayStudents(head,100);
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
