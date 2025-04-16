
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
    Student* addedStudent= (Student*) calloc(1, sizeof(Student)); // the addedStudent is a created pointer that points to block of the calloc memory block where the calloc is casted by the student* type making it be part of the student struct. The calloc creates sapce for one new student to be added having enough space for one students data/ structure. i used calloc as i find it safer to use as all memory is initialized to 0 so to avoind rubbish value.
    strcpy(addedStudent->name, name);//  this copies the name that was inputted from the user and stores it in the name area under the addedStudent .
    addedStudent->id=id; // this makes the id entered by the user be assigned to be in the id of the added Student.
    addedStudent->grade=grade; 
    addedStudent-> next=NULL; //this initialializes the next pointeer to Null
    return addedStudent;
} 
// Function to insert a new student record 
void insertStudent(const char* name, int id, float grade) { 
    // Write your code (1 mark) 
    Student* addedStudent=createStudent(name, id, grade); //this asigns the information of the new added student to the addedStudent list under the student structure.
    addedStudent-> next= head;// this assigns the head to now be stored in the next member of the struct instead of Null as it was before.
    head=addedStudent; //now the head pointer points to the addedStudent information
} 
// Function to display all student records 
void displayStudents() { 
 // Write your code (1 mark) 
    printf("   students data    \n");
    for(Student* top= head; top!= NULL; top= top-> next){
        printf(" name: %s, ID: %d, grade: %.2f\n", top-> name, top-> id, top -> grade);
    } // this for loop first initialozes the top pointer to point to the head which os the top of the list and then after each iteration it points to the next node which is the next students data, it iterates until it reaches the Null as then this will be the ned of the list. 


} 
// Function to search for a student by ID 
Student* searchStudentByID(int id) { 
 // Write your code (1 mark) 
    for(Student* top=head; top!= NULL; top->next){
        if(top->id==id){
            return top;
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
// Sort function to sort the student records by grade based on bubble sort because it uses a simpler logic and easy to implementand use. also since we are dealing with small amount of data it is easier to use and better. 

void sortStudents() { 
// Write your code (1 mark) 
   int sorted; // this will show that the list has been sorted.
   Student* start; // pointer that points to the head of the list.
   Student* end=NULL; // the pointer that points to the end of the list will be NULL to mark the end.

   do { // a do while loop is done so the sorting of students is done atleast one.

    sorted=0; 
    start=head;

    while( start-> next!=end){ //this makes it loop until it reaches the end which has a null.
        if(start->grade > start->next->grade){ // compares grades of 2 consecutive students and determines wheather they need to be sorted or not.
            char name2[100]; // creates temporary variables to accomodate swapping and avoid overwriting.
            int id2;
            float grade2;

            strcpy(name2, start->name); // copies information of one student to the temporary variables
            id2=start->id;
            grade2=start->grade;

            

            strcpy(start->name, start->next->name); //swapping
            start->id=start->next->id;
            start->grade=start->next->grade;

            strcpy(start->next->name, name2);
            start->next->id=id2;
            start->next->grade=grade2;

            sorted=1;// this states if a part has been sorted then return true. it is like a mark for a part being sorted.


        }
        start=start->next; //this moves the pointer to the next node.
    }
    end=start; // this shows where the sorting has reached


}while(sorted);
printf("students data and records sorted by grades");
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

if(found) { 
    printf("Found: Name: %s, ID: %d, Grade: %.2f\n",found->name, found->id, found->grade); 
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
