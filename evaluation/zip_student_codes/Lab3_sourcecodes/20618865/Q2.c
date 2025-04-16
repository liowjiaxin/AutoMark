#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LEN 100 // Maximum length for item names
#define MAX_CATEGORY_LEN 50 // Maximum length for category names
#define MAX_SIZE 100 // Maximum number of items in inventory

// Structure to represent a grocery item
typedef struct {
    char name[MAX_NAME_LEN];
    char category [MAX_CATEGORY_LEN];
    int quantity;
    float price;
}grocery_item;

//Union to represent the stock status of an item
typedef union{
    bool in_stock;
    bool out_of_stock;
}status;

// Structure to represent the grocery inventory
typedef struct {
    grocery_item items[MAX_SIZE]; // Array of grocery items
    status availability_status[MAX_SIZE]; // Array of availability statuses
    int counter; // Number of items currently in inventory
}grocery_inventory;

// Function to read and validate a quantity input from the user
int read_valid_quantity(void){
    int quantity;
    do {
        scanf("%d", &quantity);
        getchar(); // Consume newline character
        
        if (quantity<0){
            printf("Invalid quantity. Quantity must be >= 0.\nTry again: ");
        }
    }while(quantity<0); //keep asking user to input if the quantity is invalid

    return quantity;
}

void add_item(grocery_inventory *inventory){
    // Check if the inventory is full
    if (inventory->counter == MAX_SIZE){
        printf("Inventory fulled. Items cannot be added.\n\n");
        return;
    }
    grocery_item new_grocery; // Temporary variable to hold the new item
    status new_status; // Temporary variable to hold the new item's status

    // Read item details from the user
    printf("Enter Item Name: ");
    fgets(new_grocery.name, MAX_NAME_LEN, stdin);
    new_grocery.name[strcspn(new_grocery.name, "\n")]='\0'; //remove newline character

    printf("Enter category: ");
    fgets(new_grocery.category, MAX_CATEGORY_LEN, stdin);
    new_grocery.category[strcspn(new_grocery.category, "\n")]='\0';

    printf("Enter Quantity: ");
    new_grocery.quantity = read_valid_quantity();
    
    printf("Enter Price: ");
    scanf("%f", &new_grocery.price);
    getchar(); //consume newline character

    // assign the new_grocery struct to the items array at the index "counter" of grocery inventory
    inventory->items[inventory->counter] = new_grocery;

    // Update the availability status based on the quantity
    if(new_grocery.quantity > 0){
        new_status.out_of_stock = false;
    }
    else{
        new_status.in_stock = false;
    }

    inventory->availability_status[inventory->counter] = new_status;
    inventory->counter ++; //increment the inventory counter
    printf("Grocery item added successfully!\n\n");
}

void list_items(grocery_inventory *inventory){
    //check whether the inventory is empty
    if(inventory->counter == 0){
        printf("Inventory is empty. No item to list.\n\n");
        return;
    }
    printf("\n");
    printf("-----------------------------\n");
    //print the details of each item
    for (int i=0; i<inventory->counter; i++){
        printf("Item %d\n", i+1);
        printf("\tName: %s\n", (inventory->items[i]).name);
        printf("\tCategory: %s\n", (inventory->items[i]).category);
        printf("\tQuantity: %d\n", (inventory->items[i]).quantity);
        printf("\tPrice: %.2f\n", (inventory->items[i]).price);
        //if quantity of the item is not 0, the status is in stock
        if((inventory->items[i]).quantity > 0){
            printf("\tStatus: In Stock\n");
        }
        //else, the item is out of stock
        else{
            printf("\tStatus: Out of Stock\n");
        }
        printf("-----------------------------\n");
    }
    printf("\n");
}

void update_quantity (grocery_inventory *inventory){
    //check whether the inventory is empty
    if(inventory->counter == 0){
        printf("Inventory is empty. No items to be updated.\n\n");
        return;
    }

    char name_to_update[MAX_NAME_LEN];
    printf("Enter name of the grocery item to update quantity: ");
    fgets (name_to_update, MAX_NAME_LEN, stdin);
    name_to_update[strcspn(name_to_update, "\n")] = '\0'; //remove newline character

    int found = 0; //found flag
    //search for the item in the inventory
    for (int i=0; i<inventory->counter; i++){
        if(strcmp((inventory->items[i]).name, name_to_update)==0){

            //item_to_update == inventory -> items[i]
            //item_to_update.name == (inventory->items[i]).name
            //status_to_update == inventory -> availability_status[i]
            grocery_item *item_to_update = &inventory->items[i]; //use pointer to struct to directly change the quantity
            status *status_to_update = &inventory->availability_status[i]; //use pointer to struct to directly change the status

            found = 1; //set the flag to indicate item is found
            printf("Current quantity of %s: %d\n", item_to_update->name, item_to_update->quantity);
            printf("Enter new quantity for %s: ", item_to_update->name);

            //update the quantity of the searched item
            item_to_update->quantity = read_valid_quantity();

            //update the availability status of the searched item
            if (item_to_update->quantity > 0){
                status_to_update->out_of_stock=false;
            }
            else{
                status_to_update->in_stock=false;
            }
            printf("\nQuantity of %s updated to %d.\n\n", item_to_update->name, item_to_update->quantity);
            return;
        }
    }
    //if flag is not set, item is not found
    if (!found){
        printf("%s is not found in inventory list\n\n", name_to_update); //display not found message
        return;
    }
}

void remove_item(grocery_inventory *inventory){
    //check whether the inventory is empty
    if(inventory->counter == 0){
        printf("Inventory list is empty. No items to be deleted.\n\n");
        return;
    }

    char name_to_remove[MAX_NAME_LEN];
    printf("Enter name of the grocery item to remove: ");
    fgets (name_to_remove, MAX_NAME_LEN, stdin);
    name_to_remove[strcspn(name_to_remove, "\n")] = '\0'; //remove newline character

    int found = 0; //found flag
    int id_to_delete = 0;

    //search for the item to remove in inventory
    for (int i=0; i<inventory->counter; i++){
        if(strcmp((inventory->items[i]).name, name_to_remove)==0){
            id_to_delete = i;
            found =1; //found and set the flag to 1
        }
    }
    //if the flag is not set, item to remove is not found
    if (!found){
        printf("%s is not found in inventory list\n\n", name_to_remove);
        return;
    }
    //shift the items after the item to be removed to fill the gap left by the removed item
    for (int i = id_to_delete; i<inventory->counter-1; i++){
        inventory->items[i] = inventory->items[i+1];
        inventory->availability_status[i] = inventory->availability_status[i+1];  
    }
    inventory->counter--; //decrement the inventory counter
    printf("Item %s is removed successfully.\n\n", name_to_remove);
}

int main(){
    int menu_choice;
    grocery_inventory inventory;
    inventory.counter=0; // initialize the counter of items to 0

    do{
        //display menu for at least once
        printf("***** Grocery Inventory Management System *****\n");
        printf("\t1. Add Grocery Items\n");
        printf("\t2. List all Grocery Items\n");
        printf("\t3. Update Quantity\n");
        printf("\t4. Remove Grocery Item\n");
        printf("\t5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &menu_choice);
        getchar(); //consume newline character

        switch (menu_choice){
            case 1:
            add_item(&inventory);
            break;

            case 2:
            list_items(&inventory);
            break;

            case 3:
            update_quantity(&inventory);
            break;

            case 4:
            remove_item(&inventory);
            break;

            case 5:
            printf("Thank you for using Grocery Inventory Management System.\nTerminating program...\n");
            break;

            default:
            printf("Invalid choice.\n\n");
            break;
        }
    }while(menu_choice != 5); //keep looping back to display menu if user doesn't choose to exit

    return 0;
}
