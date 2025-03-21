#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//define sizes
#define MAX_ITEMS 100 //max number of items in inventory
#define MAX_NAME_LENGTH 100 //max length of an item's name
#define MAX_CATEGORY_LENGTH 50 //max length of an item's category

//struct for grocery item 
typedef struct{
    char name[MAX_NAME_LENGTH];         //name of grocery item
    char category[MAX_CATEGORY_LENGTH]; //category of grocery item
    int quantity;                       //quanitity of grocery item
    float price;                        //price of grocery item
    bool in_stock;                      //boolean flag to indicate stock status
} GroceryItem;

//struct for entire inventory
typedef struct{
    GroceryItem items[MAX_ITEMS]; //array of grocery items
    int count;                    //no of items currently in inventory
} GroceryInventory;

//function to display menu 
void displayMenu(){
    printf("\nGrocery Inventory Management System\n");
    printf("1. Add Grocery Item\n");
    printf("2. List all grocery items\n");
    printf("3. Update Quantity\n");
    printf("4. Remove grocery item\n");
    printf("5. Exit\n");

}

//function to add a grocery item 
void addItem(GroceryInventory *inventory){
    //check if inventory is full
    if(inventory->count >= MAX_ITEMS){
        printf("Inventory is full. Cannot add more items.\n"); //display message if inventory is full
        return;
    }

    //get the pointer to the next available slot in inventory
    GroceryItem *item =&inventory-> items[inventory-> count];

    //input details for new grocery item:
    printf("Enter item name:\n");
    scanf(" %[^\n]", item->name); //read name, allowing spaces

    printf("Enter category:\n");
    scanf(" %[^\n]", item->category);// read category, allowing spaces

    printf("Enter quantity:\n");
    scanf("%d", &item->quantity); //read quantity as integer

    while (getchar() != '\n'); //clear input buffer

    printf("Enter price:\n");
    scanf("%f", &item->price); //read price as float

    while (getchar() != '\n'); //clear input buffer

    item->in_stock = item->quantity >0; //set in- stock status to instock if item quantity>0

    inventory->count++; //incement inventory count
    printf("Item added successfully!\n");

}

//function to list grocery items 
void listItems(const GroceryInventory *inventory){
    //check if inventory is empty
    if (inventory->count ==0){
        printf("No items in inventory.\n"); //display message that inventory is empty
        return;
    }

    printf("\nGrocery Inventory:\n");
    //loop through all items and print thier detials
    for (int i=0; i< inventory->count; i++){
        const GroceryItem *item= &inventory->items[i];
        printf("Item %d:\n", i+1);
        printf("Name:%s\n", item->name);
        printf("Category:%s\n", item->category);
        printf("Quantity:%d\n", item->quantity);
        printf("Price:$%.2f\n", item->price);
        printf("Status:%s\n", item->in_stock?"In stock":"Out of Stock");
    }
}

//function to update quantity of an item 
void updateQuantity(GroceryInventory *inventory){
    //check if inventory is empty
    if(inventory->count ==0){
        printf("No items in inventory.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];


    //prompt user for name of item that want quantity to be updates
    printf("Enter name of the grocery item to update quantity:");
    while (getchar() != '\n'); //clear input buffer 
    fgets(name,MAX_NAME_LENGTH,stdin); //read item name

    //remove trailing newline character 
    size_t len=strlen(name);
    if (len>0 && name[len-1]=='\n'){
        name[len-1]='\0';
    }

    //search for the item in inventory
    for (int i = 0; i<inventory->count;i++){
        GroceryItem *item= &inventory->items[i];
        //when have a match:
        if (strcmp(item->name,name)==0){
            printf("Enter new quantity:"); //prompt user for new quantity
            scanf("%d", &item->quantity); // read new quantity of the item 
            //clear input buffer 
            while (getchar() != '\n');
            //update in stock status- instock if new quantity>0 
            item->in_stock=item->quantity>0;
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Item not found in inventory.\n"); //error message that item keyed in cant be found in inventory

}

//function to remove grocery item 
void removeItem(GroceryInventory *inventory){

    //check if inventory is empty
    if(inventory->count ==0){
        printf("No items in inventory.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("Enter name of item to be removed:"); //prompt user for item name that want to be removed. 
    while (getchar() != '\n'); //clear input buffer
    scanf("%[^\n]", name); //read item name

    //search for item to be removed using loop 
    for (int i=0; i< inventory-> count; i++){
        
        //when a match is found:
        if (strcmp(inventory-> items[i].name, name)==0){
            //shift all subsequent items to fill the gap 
            for (int j=i; j<inventory->count -1; j++){
                inventory->items[j]= inventory->items[j+1];
            }
            inventory->count--; //decrease inventory count
            printf("Item removed successfully!\n"); //display message that item is removed successfully
            return;
        }
    }
    printf("Item not found in inventory.\n"); //if item keyed in does not exist in inventory
}

int main(){
    GroceryInventory inventory={.count =0}; //initialise an empty inventory
    int choice; //variable to story user's menu choice
    
    while (1){ //main program loop
        displayMenu(); //call function to display menu 
        printf("Enter your choice:");//prompt user for inputting choice
        scanf("%d",&choice); //read user choice

        //switch case 
        switch (choice){
            
            //choice 1: add item 
            case 1:
                addItem(&inventory); //call function addItem
                break;

            //choice 2: list items
            case 2:
                listItems(&inventory); //call function listItems
                break;

            //chioce 3: update quantity
            case 3:
                updateQuantity(&inventory); //call function updateQuantity
                break;

            //Choice 4: remove item
            case 4:
                removeItem(&inventory); //call function to removeItem
                break;

            //Choice 5: exit program
            case 5:
                printf("Exiting program...");
                return 0; //exit program

            //if choice other than 1-5
            default:
                printf("Invalid choice. Please try again.\n");  //display error message.
        }
    
    }
}
