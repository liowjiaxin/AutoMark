#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NAME_BUFFER 100

struct student{
    char *name;
    int id;
    float grade;
};

struct list_node{
    struct student *info; 
    struct list_node *next_node;
    struct list_node *prev_node;
};

struct list{
    struct list_node *head;
    struct list_node *tail;
    int num_nodes; // number of nodes
};

typedef struct student Student;
typedef struct list_node Node;
typedef struct list List;

// function prototypes
void print_menu(void);
void insert_student(List *list);
void display_students(List *list);
void search_student(List *list);
Node *search_by_id(List *list, const int id);
void delete_list(List *list);
void free_memory(List *list);
Node *create_student_node(const char *name, int id, float grade);
void sort_students(List *list);

int main(void){
    // initialisation 
    int choice=0;
    List *s_list=malloc(sizeof(List)); // student list

    if(s_list==NULL){ // check if memory allocation was successful
        puts("Error: Unable to allocate memory.");
        choice=6; // exit program

    }else{
        s_list->head=NULL;
        s_list->tail=NULL;
        s_list->num_nodes=0;
    }
    
    while(choice!=6){
        print_menu();

        // prompt user to enter choice
        printf("%s","Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // read trailing newline character

        switch (choice)
        {
        case 1: // allow the user to insert new stuednt records into the list
            insert_student(s_list);
            break;
        case 2: // display all current student records in the list
            display_students(s_list);
            break;
        case 3: // sort list by grade
            sort_students(s_list);
            break;
        case 4: // search for student by id
            search_student(s_list);
            break;
        case 5: // delete list
            delete_list(s_list);
            puts("List deleted successfully!");
            break;
        case 6: // exit program
            puts("Exiting...");
            break;
        
        default:
            puts("Error: Invalid input");
            break;
        }
    }

    free_memory(s_list);
}

// function that displays user guide
void print_menu(void){
    puts("====================== MENU =====================");
    printf("%12s%s\n","[1]","Insert student record.");
    printf("%12s%s\n","[2]","Display student records.");
    printf("%12s%s\n","[3]","Sort records.");
    printf("%12s%s\n","[4]","Search record by ID.");
    printf("%12s%s\n","[5]","Delete list.");
    printf("%12s%s\n","[6]","Exit.");
    puts("=================================================");
}

// create new node 
Node *create_student_node(const char *name, int id, float grade){
    //Student *new_student=malloc(sizeof(Student *));
    Node *new_node=malloc(sizeof(Node));
    new_node->info=malloc(sizeof(Student));
    new_node->info->name=malloc(strlen(name)+1);
    Student *record=new_node->info;
    if(record->name==NULL || record==NULL || new_node==NULL){ // check if memory allocation was successful
        puts("Error: failed to allocate memory.");
        return NULL;
    }
    strcpy(record->name, name);

    record->id=id;

    record->grade=grade;

    return new_node;
}

// function that prompts user to enter info of new record and inserts new node to end of list
void insert_student(List *list){
    // initialisation
    int new_id=0;
    float new_grade=0.0;
    char *buffer=malloc(MAX_NAME_BUFFER*sizeof(char));
    
    if(buffer==NULL){ // check if memory allocation is successful
        puts("Error: failed to allocate memory.");
        return;
    }

    puts("=========== [1] Insert Student Record ===========");

    // prompt user to enter name of new student
    printf("\nEnter student name: ");
    fgets(buffer, MAX_NAME_BUFFER, stdin);
    buffer[strcspn(buffer, "\n")]='\0'; // remove trailing newline character

    // prompt user to enter ID of new student
    printf("\nEnter student ID: ");
    scanf("%d", &new_id);
    while(search_by_id(list, new_id)!=NULL){
        puts("Error: ID already exists. Please enter another ID.");
        printf("\nEnter student ID: ");
        scanf("%d", &new_id);
    }

    // prompt user to enter grade of new student
    printf("\nEnter student grade: ");
    scanf("%f", &new_grade);

    Node *new_node=create_student_node(buffer, new_id, new_grade);
    free(buffer); // free allocated memory

    if(new_node==NULL){ // memory allocation failed (error msg in other function)
        return;
    }

    // insert node to the end of the list
    if(list->num_nodes==0){
        new_node->next_node=NULL;
        new_node->prev_node=NULL;
        list->head=new_node;
        list->tail=new_node;
    }else{
        list->tail->next_node=new_node;
        new_node->prev_node=list->tail;
        new_node->next_node=NULL;
        list->tail=new_node;
    }
    list->num_nodes++;

    puts("Record added successfully!");
}

// displays all current student records in the linked list 
void display_students(List *list){
    Node *curr_node=list->head;
    if(curr_node==NULL){ // check if list is empty
        puts("Error: No records exist.");
        return;
    }

    // print student records in table format
    puts("========== [2] Display Student Records ==========");
    printf("%-30s%-15s%-10s\n", "Name", "Student ID", "Grade");
    while(curr_node!=NULL){
        Student *record=curr_node->info;
        printf("%-30s%-15d%-10.1f\n", record->name, record->id, record->grade);
        curr_node=curr_node->next_node;
    }
}

// searches for a student record by student ID and returns a pointer to the corresponding student node
Node *search_by_id(List *list, const int id){
    Node *curr_node=list->head;
    while(curr_node!=NULL){
        if(curr_node->info->id==id){
            return curr_node;
        }
        curr_node=curr_node->next_node;
    }
    return curr_node;
}

// function that asks user to enter ID of student and then search for record and display
void search_student(List *list){
    int search_id;
    if(list->head==NULL){ // check if list is empty
        puts("Error: No records exist.");
        return;
    }
    puts("============ [4] Search Record by ID ============");
    printf("Enter ID of student to search for: ");
    scanf("%d", &search_id);
    Node *search_node=search_by_id(list, search_id);
    if(search_node==NULL){
        puts("Record not found.");
        return;
    }else{
        Student *record=search_node->info;
        puts("Record found!");
        printf("%10s: %s\n","Name", record->name);
        printf("%10s: %d\n","ID", record->id);
        printf("%10s: %.1f\n","Grade", record->grade);
    }
}

// delete the entire linked list and frees the allocated memory
void delete_list(List *list){
    puts("================ [5] Delete List ================");
    Node *curr_node=list->head;
    if(curr_node==NULL){
        puts("Error: List is empty.");
        return;
    }
    while(curr_node!=NULL){
        Node *del=curr_node;
        curr_node=curr_node->next_node;
        free(del->info->name);
        free(del->info);
        free(del);
    }
    list->head=NULL;
    list->tail=NULL;
    list->num_nodes=0;
    
}

// utility function that ensures that all memory is freed when the program exits
void free_memory(List *list){
    delete_list(list);
    free(list);
}

// =========================== MERGE SORT =============================
Node *split(Node *head){
    Node* slow=head; // fall on middle node at the end
    Node* fast=head->next_node; // go to end of list

    while(fast!=NULL && fast->next_node!=NULL){
        slow=slow->next_node; // one step
        fast=fast->next_node->next_node; // two steps
    }
    Node *head_b=slow->next_node; // the start of second division
    if(head_b!=NULL){ // head_b might be NULL if there is only one node in the left division
        head_b->prev_node=NULL; 
    }
    slow->next_node=NULL; // the end of first division

    return head_b;
}

Node *merge(Node *list_a, Node *list_b){
    // base case
    if (list_a==NULL){
        return list_b;
    }
    if (list_b==NULL){
        return list_a;
    } 

    // compare list_a and list_b
    if (list_a->info->grade <= list_b->info->grade) {
        list_a->next_node = merge(list_a->next_node, list_b);
        list_a->next_node->prev_node = list_a;
        list_a->prev_node = NULL;
        return list_a;
    } else {
        list_b->next_node = merge(list_a, list_b->next_node);
        list_b->next_node->prev_node = list_b;
        list_b->prev_node = NULL;
        return list_b;
    }
}

// main function to perform merge sort recursively
Node *merge_sort(Node *head){
    if(head==NULL || head->next_node==NULL){ // base case
        return head;
    }

    Node *middle=split(head);
    Node *list_a=merge_sort(head); // call merge_sort recursively
    Node *list_b=merge_sort(middle);

    return merge(list_a, list_b); // merge together once the list has been split into one node per division
}

// sort the student records by grade in ascending order using merge sort
/* merge sort is used because it runs in O(n log n) time in all cases
hence it is suitable for large data structures or LINKED LISTS*/
void sort_students(List *list){
    Node *curr_node=list->head;
    if(curr_node==NULL){
        puts("Error: List is empty.");
        return;
    }
    if(curr_node->next_node==NULL){
        return;
    }
    // sort list
    list->head=merge_sort(list->head);

    // update tail after sorting
    Node* temp=list->head;
    while(temp->next_node != NULL){
        temp=temp->next_node;
    }
    list->tail=temp;

    puts("Records successfully sorted by grades in ascending order using merge sort");
    return;
}
