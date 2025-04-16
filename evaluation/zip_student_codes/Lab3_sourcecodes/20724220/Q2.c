#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_ITEMS 100 // define maximum number of grocery items
#define MAX_NAME_LEN 100 // define max length for item name
#define MAX_CAT_LEN 50 // define max length for item category

// define a structure to store individual grocery item details
typedef struct{
    char name [MAX_NAME_LEN];
    char category[MAX_CAT_LEN];
    int quantity;
    float price;
} GroceryItem;

// define a structure to store grocery items' availability status
typedef struct{
    bool inStock;
    bool outOfStock;
} AvailabilityStatus;

// define a structure to represent the entire grocery inventory
typedef struct{
    GroceryItem grocery[MAX_ITEMS];
    AvailabilityStatus status[MAX_ITEMS];
    int count;
} GroceryInventory;

// function prototypes
void removeNewLine(char *str);
void addGrocery(GroceryInventory *inventory);
void listGrocery(GroceryInventory *inventory);
void updateQuantity(GroceryInventory *inventory);
void removeGrocery(GroceryInventory *inventory);

int main(){
    GroceryInventory inventory = { .count = 0 }; // initialise the inventory
    int choice;

    do {
        // Main Menu
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Items\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Items\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline from input buffer

        // handle user choice using switch case
        switch (choice){
            case 1:
                addGrocery(&inventory); // add new grocery items
                break;
            case 2:
                listGrocery(&inventory); // list all grocery items
                break;
            case 3:
                updateQuantity(&inventory); // update quantity of an item
                break;
            case 4:
                removeGrocery(&inventory); // remove grocery items
                break;
            case 5:
                printf("Exited.\n"); // exit the application
                return 0;
            default:
                printf("Invalid choice. Please enter again.\n");
        }
    
    } while (choice != 5);

    return 0;

}

// function to remove newline character
void removeNewLine(char *str) 
{
	str[strcspn(str, "\n")] = 0;
}

// function to add grocery items to the inventory
void addGrocery(GroceryInventory *inventory){

    // check if inventory is full
    if (inventory->count >= MAX_ITEMS) {
        printf("Inventory is full.\n");
        return;
    }

    GroceryItem *item = &inventory->grocery[inventory->count]; // pointer to new item
    AvailabilityStatus *availability = &inventory->status[inventory->count]; // pointer to status

    printf("Enter item name: ");
    fgets(item->name, MAX_NAME_LEN, stdin);
    removeNewLine(item->name);

    printf("Enter Category: ");
    fgets(item->category, MAX_CAT_LEN, stdin);
    removeNewLine(item->category);

    printf("Enter Quantity: ");
    scanf("%d", &item->quantity);

    printf("Enter Price: ");
    scanf("%f", &item->price);
    while (getchar() != '\n'); // clear input buffer

    // update availability status based on quantity of the item
    availability->inStock = (item->quantity > 0);
    availability->outOfStock = (item->quantity == 0);

    inventory->count++; // increment inventory count
    printf("Grocery item added successfully!\n");
}

// function to list all grocery items
void listGrocery(GroceryInventory *inventory){

    // check if there are items in the inventory
    if (inventory->count == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    // display each items details
    for (int i = 0; i < inventory->count; i++){
        const GroceryItem *item = &inventory->grocery[i]; 
        const AvailabilityStatus *availability = &inventory->status[i]; 

        printf("Name: %s\n", item->name);
        printf("Category: %s\n", item->category);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);

        if (availability->inStock){
            printf("Status: %s\n", "In Stock");
        }
        else {
            printf("Status: %s\n", "Out of Stock");
        }
    }
}

// function to update grocery item quantity
void updateQuantity(GroceryInventory *inventory) {

    // Check if there are items in the inventory
    if (inventory->count == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    char name[MAX_NAME_LEN]; // name of the item to update
    int itemFound = 0; // flag to track if the item is found

    do {
        printf("Enter name of the grocery item to update quantity: ");
        fgets(name, MAX_NAME_LEN, stdin);
        removeNewLine(name);

        for (int i = 0; i < inventory->count; i++) {
            GroceryItem *item = &inventory->grocery[i];
            AvailabilityStatus *availability = &inventory->status[i];

            if (strcmp(item->name, name) == 0) {
                printf("Enter new quantity for %s: ", name);
                scanf("%d", &item->quantity);
                getchar(); // clear newline character from input buffer

                // update availability status
                availability->inStock = (item->quantity > 0);
                availability->outOfStock = (item->quantity == 0);

                printf("Quantity updated successfully!\n");
                itemFound = 1; // mark the item as found
                break; // exit the loop since the item is found
            }
        }

        if (!itemFound) {
            printf("Item not found. Please try again.\n");
        }

    } while (!itemFound);
}

// function to remove grocery items
void removeGrocery(GroceryInventory *inventory){

    // Check if there are items in the inventory
    if (inventory->count == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    char name[MAX_NAME_LEN];
    int itemFound = 0; // flag to track if the item is found

    do {
        printf("Enter name of the grocery item to remove: ");
        fgets(name, MAX_NAME_LEN, stdin);
        removeNewLine(name);

        for (int i = 0; i < inventory->count; i++) {
            GroceryItem *item = &inventory->grocery[i];
            AvailabilityStatus *availability = &inventory->status[i];

            // check if the name matches
            if (strcmp(item->name, name) == 0) {

                // shift all elements left to fill the gap
                for (int j = i; j < inventory->count - 1; j++) {
                inventory->grocery[j] = inventory->grocery[j + 1];
                inventory->status[j] = inventory->status[j + 1];
                }

                inventory->count--;
                printf("Grocery item '%s' removed successfully!\n", name);
                itemFound = 1; // mark the item as found
                break; // exit the loop since the item is found
            }
        }

        if (!itemFound) {
            printf("Item not found. Please try again.\n");
        }

    } while (!itemFound);
}