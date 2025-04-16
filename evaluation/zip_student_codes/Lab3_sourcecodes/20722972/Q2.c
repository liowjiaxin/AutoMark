#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_ITEM 100
#define MAX_NAME_BUFFER 100
#define MAX_CAT_BUFFER 50

struct grocery_item{
    char *name;
    char *category;
    int quantity;
    float price;
};

union availability_status{
    int in_stock;
    int out_of_stock;
};


typedef struct grocery_item Item;
typedef union availability_status Status;

struct grocery_inventory{
    Item *item_arr;
    Status *status_arr;
    size_t total_item;
};

typedef struct grocery_inventory Inventory;

// function prototypes
void print_menu(void);
void add_item(Inventory *inv);
void list_all_items(Inventory *inv);
void list_one_item(Inventory *inv, size_t index);
void update_quantity(Inventory *inv);
size_t search_item(Inventory *inv);
void remove_item(Inventory *inv);


// function main begins program execution
int main(void){
    // initialization
    Inventory *inventory = malloc(sizeof(Inventory));
    inventory->item_arr = malloc(MAX_ITEM * sizeof(Item));
    inventory->status_arr = malloc(MAX_ITEM * sizeof(Status));
    inventory->total_item = 0;
    int choice=0;

    do{
        print_menu();

        // prompt user to enter choice based on menu
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear leftover newline char

        switch (choice) // perform actions according to user choice
        {
        case 1: // add grocery item
            add_item(inventory);
            break;

        case 2: // list all grocery items
            list_all_items(inventory);
            break;

        case 3: // update quantity
            update_quantity(inventory);
            break;

        case 4: // remove grocery item
            remove_item(inventory);
            break;

        case 5: // exit
            break;
        
        default:
            puts("Error: Invalid input.");
            break;
        }
    }while(choice!=5);

    // free allocated memory
    free(inventory->item_arr);
    free(inventory->status_arr);
    free(inventory);
}

// function that displays user guide 
void print_menu(void){
    puts("");
    puts("========== Grocery Inventory Management System ==========");
    printf("%10s%s\n","1.","Add grocery item.");
    printf("%10s%s\n","2.","List all grocery items.");
    printf("%10s%s\n","3.","Update quantity.");
    printf("%10s%s\n","4.","Remove grocery item.");
    printf("%10s%s\n","5.","Exit.");
    puts("=========================================================");
}

// function that lets user to add new item into inventory
void add_item(Inventory *inv){
    // check if inventory is full
    if(inv->total_item>=MAX_ITEM){
        puts("Error: Inventory is full.");
        return;
    }

    // get index of new item
    size_t index=inv->total_item;
    Item *new_item=inv->item_arr+index;

    // allocate memory for name and category of new item to be added
    new_item->name=malloc(sizeof(char)*MAX_NAME_BUFFER);
    new_item->category=malloc(sizeof(char)*MAX_CAT_BUFFER);
    
    // check if memory allocation was successful
    if(new_item->name == NULL || new_item->category==NULL){
        puts("Error: Memory allocation failed.");
        return;
    }

    // enter name
    char buffer[MAX_NAME_BUFFER];
    printf("Enter item name: ");
    fgets(buffer, MAX_NAME_BUFFER, stdin);
    buffer[strcspn(buffer,"\n")]=0; // remove trailing newline
    strcpy(new_item->name, buffer); 
    memset(buffer,0,sizeof(buffer)); // clear buffer

    // enter category
    printf("Enter item category: ");
    fgets(buffer, MAX_CAT_BUFFER, stdin);
    buffer[strcspn(buffer,"\n")]=0; // remove trailing newline
    strcpy(new_item->category, buffer);
    memset(buffer,0,sizeof(buffer)); // clear buffer

    // enter quantity
    printf("Enter item quantity: ");
    scanf("%d", &new_item->quantity);

    // enter item price
    printf("Enter item price: ");
    scanf("%f", &new_item->price);

    // availability status
    (inv->status_arr+index)->in_stock=new_item->quantity>0; // returns 0 if false

    inv->total_item++; 
    puts("Grocery item added successfully!");
}

// function that lists all items and their details in a table
void list_all_items(Inventory *inv){
    // get index of last item
    size_t total_index=inv->total_item-1;

    // check if current inventory is empty
    if(total_index==0){
        puts("Error: Inventory is empty.");
        return;
    }
    
    // table header
    puts("===================================================================================================");
    printf("%-50s%-30s%-10s%-10s%-10s","Name", "Category", "Quantity", "Price", "Status");

    for(size_t i=0; i<total_index+1; i++){
        Item *item=inv->item_arr+i;
        Status *status=inv->status_arr+i;
        const char*available=status->in_stock ? "In Stock" : "Out of Stock";
        printf("\n%-50s%-30s%-10d%-10.2f%-10s",item->name, item->category,item->quantity, item->price, available);
    }
}

// asks user to enter name of item to search for, returns the index of the item in item_arr and status_arr
size_t search_item(Inventory *inv){
    // initialisation
    char buffer[MAX_NAME_BUFFER];
    size_t index=inv->total_item; 
    Item *item=inv->item_arr;

    // prompt user to enter name of item
    printf("Enter name of the grocery item: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer,"\n")]=0; // remove trailing newline character

    // loop through item_arr
    for(int i=0; i<index; i++){
        if(strcmp(buffer,(item+i)->name)==0){
            return i;
        }
    }

    // if item is found, return index of item, else return -1
    return -1;
}

// function that displays information of one item given its index in item_arr and status_arr
void list_one_item(Inventory *inv, size_t index){
    // initialisation
    Item *item=inv->item_arr+index;
    Status *status=inv->status_arr+index;
    char *available=status->in_stock ? "In Stock" : "Out of Stock";

    // display info of item
    printf("%-20s: %s\n", "Name", item->name);
    printf("%-20s: %s\n", "Category", item->category);
    printf("%-20s: %d\n", "Quantity", item->quantity);
    printf("%-20s: %.2f\n", "Price", item->price);
    printf("%-20s: %s\n", "Status", available);
}

// function that lets user update quantity of an item
void update_quantity(Inventory *inv){
    // get index of new item
    size_t total_index=inv->total_item-1;

    // check if current inventory is empty
    if(total_index==-1){
        puts("Error: Inventory is empty.");
        return;
    }

    // get index of item to be removed
    size_t search_index=search_item(inv);
    while(search_index==(size_t)-1){
        puts("Error: Item not found.");
        search_index=search_item(inv);
    }

    // display current quantity
    puts("Item found!");
    list_one_item(inv, search_index);

    // prompt user to enter new quantity
    Item *item=inv->item_arr+search_index;
    Status *status=inv->status_arr+search_index;

    printf("Enter new quantity of %s: ", item->name);
    scanf("%d", &item->quantity);

    // update availability status
    status->in_stock=item->quantity>0; // returns 0 if false

    puts("Item quantity updated successfully!");
}

// function that lets user search for an item and remove it
void remove_item(Inventory *inv){
    // get index of last item
    size_t total_index=inv->total_item-1;

    // check if current inventory is empty
    if(total_index==-1){
        puts("Error: Inventory is empty.");
        return;
    }

    // get index of item to be removed
    size_t search_index=search_item(inv);
    while(search_index==(size_t)-1){
        puts("Error: Item not found.");
        search_index=search_item(inv);
    }

    // display item details and confirm
    char confirm;

    puts("Item found!");
    list_one_item(inv, search_index);

    while(1){
        printf("Are you sure you want to delete this item? (Y/N): ");
        scanf("%c", &confirm);

        if(toupper(confirm)=='Y'){
            // update array
            Item *item=inv->item_arr;
            Status *status=inv->status_arr;

            free(item[search_index].name);
            free(item[search_index].category);

            for(size_t i=search_index; i<total_index; i++){
                item[i]=item[i+1];
                status[i]=status[i+1];
            }

            // clear last slot in array
            item[total_index].name=NULL;
            item[total_index].category=NULL;
            
            inv->total_item--;
            puts("Grocery item removed successfully!");
            return;

        }else if(toupper(confirm)=='N'){ // cancel
            return;

        }else{ // continue to loop
            puts("Error: Invalid input.");
        }
    }
}

