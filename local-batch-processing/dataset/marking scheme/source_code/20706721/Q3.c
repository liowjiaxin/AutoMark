#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define NAME_LEN 100//define the name max length
#define ID_LEN 50//define the category max length
#define MAX_LIST_SIZE 100//max List number


int N = 0;//n current amount of student,t to gitemtrol while loop

//define linked list data type
typedef struct Student {
    char name[NAME_LEN];
    int id;
    float grade;
    struct Student *next;
} Student ;

Student *head = NULL;

//function declaretion
void insertStudent(const char* name, int id, float grade); // Inserts a new student record into the linked list.
void displayStudents(); // Displays all current student records inthe linked list.
Student* searchStudentByID(int id); // Searches for a student recordby student ID and returns a pointer to the corresponding student node.
void deleteList(); // Deletes the entire linked list and frees the allocated memory.
void freeMemory(); // A utility function to ensure that all memory is freed when the program exits.
Student* createStudent(const char* name, int id, float grade); //Creates a new student node and returns a pointer to it.
void sortStudents(); // Sort the student records by grade according to a sorting algorithm of your choice
void menu();



int main()
{
    int t=1;
    // load();
    int num;//num is menu options
    int id; 
    float grade;
    char name[NAME_LEN];
    Student* std ;

    while (t)//t is global variable
    {
        
       
        menu();//output mene
        printf("Enter your choice: ");
        scanf("%d", &num);
        // getchar(); // To consume the newline character
        switch (num)
        {
        case 1: 
            
            //Input name
            printf("Enter name:");
            getchar();
            fgets(name, sizeof(name), stdin);

            // Remove newline character if present
            size_t len = strlen(name);
            if (len > 0 && name[len - 1] == '\n') {
                name[len - 1] = '\0';
            }

            //Input ID
            printf("Enter ID:");
            scanf("%d",&id);
            

            //Input Grade
            printf("Enter Grade:");
            scanf("%f",&grade);


            insertStudent(name,id,grade); 
            break;
        case 2: 
            

            displayStudents(); 
        
            break;
        case 3: 
        
            sortStudents();
            break;
        case 4: 
            
            //Input ID
            printf("Enter ID:");
            scanf("%d",&id);
            std = searchStudentByID(id); 
            if(std)
                printf("Name: %s, ID: %d, Grade: %.2f\n", std->name, std->id, std->grade);
            else
                printf("Student not found.\n");
            break;
        case 5:
            deleteList();
            printf("List deleted.\n");
            break;
        case 6: 
            t=0; 
            break;
        default:printf("Inputs the mistake,please input again!");
        }
        
    }
    
    return 0;
}


void menu()
{
    printf("\n\n");    
    printf("1. Insert Student Record\n");
    printf("2. Display Student Records\n");
    printf("3. Sort Records\n");
    printf("4. Search Record by ID\n");
    printf("5. Delete List\n");
    printf("6. Exit\n");
}


/**
 * @brief 
 *  Inserts a new student record into the linked list.
 * @param name 
 * @param id 
 * @param grade 
 */
void insertStudent(const char* name, int id, float grade)
{
   Student *newNode = createStudent(name,id,grade);

     
//Add the new node to the end of the queue; if the current queue is empty, set the new node as the head node
    if (head == NULL) {
        head = newNode;
    } else {
        Student *current = head;
        //Find the last node
        while (current->next != NULL) {
             current = current->next;
         }
        current->next = newNode;

    }
}

/**
 * @brief 
 *  Displays all current student records inthe linked list.
 */
void displayStudents(){
    Student *current ;
    current=head;
    while (current != NULL) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", current->name, current->id, current->grade);
        current = current->next;
    }
}

/**
 * @brief 
 * Searches for a student recordby student ID and returns a pointer to the corresponding student node.
 * @param id 
 * @return Student* 
 */
Student* searchStudentByID(int id){

    //Get the head of the queue
    Student *current = head;
    //Traverse the queue from the head; if found, return the result
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }

    //Return NULL if not found
    return NULL;
}

/**
 * @brief 
 * Deletes the entire linked list and frees the allocated memory.
 */
void deleteList(){
    //Traverse from head to tail and release resources for each node
    Student* current = head;
    Student* next;
    while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
    }
    head = NULL;
}

/**
 * @brief 
 * A utility function to ensure that all memory is freed when the program exits.
 */
void freeMemory(){
    deleteList();
}
/**
 * @brief Create a Student object
 *  //Creates a new student node and returns a pointer to it.
 * @param name 
 * @param id 
 * @param grade 
 * @return Student* 
 */
Student* createStudent(const char* name, int id, float grade){
    //Create a new node
    Student *newNode = (Student*)malloc(sizeof(Student));
    if (newNode) {
        strcpy(newNode->name, name);
        newNode->id=id;
        newNode->grade = grade;
        newNode->next = NULL;
    }

    return newNode;
}

 /**
 * @brief 
 * Sort the student records by grade according to a sorting algorithm of your choice
 */
void sortStudents() { 
    if (head == NULL || head->next == NULL) {
        return; // If the linked list is empty or has only one node, sorting is not needed
    }

    Student *sorted = NULL; // Used to store the head node of the sorted part
    Student *current = head; // The current node being processed

    while (current != NULL) {
        Student *next = current->next; // Save the next node to prevent breaking the chain
        Student **pos = &sorted; // Points to the head pointer of the sorted part

        // Find the insertion position (in descending order of scores)
        while (*pos != NULL && (*pos)->grade > current->grade) {
            pos = &(*pos)->next;
        }

        // Insert the current node into the sorted linked list
        current->next = *pos;
        *pos = current;

        // Move to the next node
        current = next;
    }

    head = sorted; //Update the head pointer to the sorted linked list
}
