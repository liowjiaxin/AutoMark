#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


typedef struct item{
    char name[101];
    char category[51];
    int quantity;
    float price;
}Item;

Item array[100];
Item *to_insert = array; // pointer to address where to add a new item

bool is_quantity(const char *s);
bool is_price(const char *s);
bool is_option(const char *s);

void add_item();
Item* find_by_name(char *s);
void update_quantity();
void list_all_items();
void delete_item();
int menu();


int main(){
    int status;
    do
    {
        status = menu();
    } while (status);

    return 0;
}




bool is_option(const char *s){
    // first character is digit
    if (!isdigit(s[0])) return false;

    // len(s) == 1
    if (s[1] != '\0') return false;

    // available options
    if (s[0] > '5' || s[0] < '1') return false;

    return true;
}


bool is_quantity(const char *s){
    // all digits
    for (int i = 0; s[i] != '\0'; i++){
        if (!isdigit(s[i])) return false;
    }
    return true;
}



bool is_price(const char *s){

    // only digits and '.' are allowed
    for (int i = 0; s[i] != '\0'; i++){
        if (!isdigit(s[i]) && (s[i] != '.')) return false;
    }

    // if all digits and no '.' then valid
    if (strchr(s, '.') == NULL) return true;

    // only 1 or 0 '.'
    if (strchr(s, '.') != strrchr(s, '.')) return false;

    // 1 or 2 fractional digits
    int frac_digits = strlen(s) - (strchr(s, '.') - s) - 1;
    if (frac_digits > 2 || frac_digits < 1) return false;

    // first character is not '.'
    if (s[0] == '.') return false;

    return true;
}


// returns pointer to searched item, NULL if not found
Item* find_by_name(char *s){
    for (Item *item = array; item < to_insert; item++)
    {
        if (strcmp(item->name, s) == 0) return item;
    }
    return NULL;
}


// add item option
void add_item(){

    // check if possible to add
    if(to_insert - 100 == array){
        printf("Maximum number of items (100) in the list exceeded. Cannot add an item.\n");
        return;
    }

    char buffer[101];

    // Enter name
    printf("Enter Item Name: ");
    scanf("%[^\n]s", buffer);
    getchar(); // here and further used to to flush '\n' after scanf
    buffer[100] = '\0';

    // check if already exists
    if (find_by_name(buffer) != NULL){
        printf("There already exist an item with name: %s\n", buffer);
        printf("Contact was not added.\n");
        return;
    }

    // address where to write
    Item * item = to_insert;

    // Put name
    strcpy(item->name, buffer);

    // Enter Category
    printf("Enter Item Category: ");
    scanf("%[^\n]s", item->category);
    getchar();
    item->category[50] = '\0';

    // Enter and validate quantity
    printf("Enter Item Quantity: ");
    scanf("%[^\n]s", buffer);
    getchar();
    buffer[19] = '\0'; // maximum 20 characters for price
    while (!is_quantity(buffer)){
        printf("Invalid input. Try again.\n");
        printf("Enter Item Quantity: ");
        scanf("%[^\n]s", buffer);
        getchar();
        buffer[19] = '\0';
    }
    sscanf(buffer, "%d", &(item->quantity));


    // Enter and validate price
    printf("Enter Item Price: $");
    scanf("%[^\n]s", buffer);
    getchar();
    buffer[19] = '\0';
    while (!is_price(buffer)){
        printf("Invalid input. Try again.\n");
        printf("Enter Item Price: $");
        scanf("%[^\n]s", buffer);
        getchar();
        buffer[19] = '\0';
    }
    sscanf(buffer, "%d", &(item->price));

    // increment pointer for the next free space
    to_insert++;

    printf("Item has been successfully added\n\n");
}


//print all items
void list_all_items(){
    for (Item *item = array; item < to_insert; item++)
    {
        printf("Name: %s\n", item->name);
        printf("Category: %s\n", item->category);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %d\n", item->price);
        printf("Status: %s\n\n", item->quantity > 0 ? "In Stock" : "Out of Stock");
    }
}


// updates quantity of entered item
void update_quantity(){
    char buffer[101];

    // Enter name
    printf("Enter Item Name: ");
    scanf("%[^\n]s", buffer);
    getchar();
    buffer[100] = '\0';

    // check if exists
    Item *item = find_by_name(buffer);
    while (item == NULL){
        printf("There is no item with name: %s\n", buffer);
        printf("Try again.\n");

        //enter again
        printf("Enter Item Name: ");
        scanf("%[^\n]s", buffer);
        getchar();
        buffer[100] = '\0';

        item = find_by_name(buffer);
    }

    // enter new quantity
    printf("Enter new quantity for %s: ", item->name);
    scanf("%[^\n]s", buffer);
    getchar();
    buffer[100] = '\0';


    // validate input
    while (!is_quantity(buffer)){
        printf("Invalid input. Try again.\n");

        // enter again
        printf("Enter new quantity for %s: ", item->name);
        scanf("%[^\n]s", buffer);
        getchar();
        buffer[100] = '\0';
    }

    sscanf(buffer, "%d", &(item->quantity));

    printf("Quantity has been updated.\n\n");
}


// delete entered item
void delete_item(){
    char buffer[101];

    // check if list is not empty
    if (to_insert = array){
        printf("List is empty. There is nothing to delete\n");
        return;
    }

    // Enter name
    printf("Enter Item Name: ");
    scanf("%[^\n]s", buffer);
    getchar();
    buffer[100] = '\0';

    Item *item_to_delete = find_by_name(buffer);

    // check if exists
    while (item_to_delete == NULL){
        printf("There is no item with name: %s\n", buffer);
        printf("Try again.\n");

        //enter again
        printf("Enter Item Name: ");
        scanf("%[^\n]s", buffer);
        getchar();
        buffer[100] = '\0';

        item_to_delete = find_by_name(buffer);
    }

    // shift remaining items one position left
    for (Item *item = item_to_delete; item < to_insert - 1; item++){
        strcpy(item->name, (item + 1)->name);
        strcpy(item->category, (item + 1)->category);
        item->quantity = (item + 1)->quantity;
        item->price = (item + 1)->price;
    }

    // shift insert poition
    to_insert--;

    printf("Item has been deleted.\n\n");
}



// menu function to loop. Returns 0 to stop, 1 to continue
int menu(){
    int option;
    char buffer[10];

    printf("Grocery Management System.\n" 
           "    1. Add Grocery Item\n"
           "    2. List All Grocery Items\n"
           "    3. Update Quantity\n"
           "    4. Remove Grocery Item\n"
           "    5. Exit\n");

    //enter option
    printf("Your option: ");
    scanf("%[^\n]s", buffer);
    getchar();
    buffer[9] = '\0';

    // validate input
    while (!is_option(buffer)){
        printf("Invalid input. Try again.\n");

        printf("Your option: ");
        scanf("%[^\n]s", buffer);
        getchar();
        buffer[9] = '\0';
    }
    sscanf(buffer, "%d", &option);


    // process option
    switch (option)
    {
    case 1:
        add_item();
        break;
    case 2:
        list_all_items();
        break;
    case 3:
        update_quantity();
        break;
    case 4:
        delete_item();
        break;
    case 5:
        printf("Exiting...");
        return 0; // exit status
    default:
        perror("Impossible.");  // option validation has already been performed before
        break;
    }

    return 1; // continue status
}
