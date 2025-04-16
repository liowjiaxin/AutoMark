#include <stdio.h>
#include <string.h>  //including string library to use funtions like strcmp

#define MAX_ITEMS 100 //maximum number of items allowed in inventory

//struct for grocery item
typedef struct {
    char name[100];          //name of the item
    char category[50];       //category of the item
    int quantity;            //quantity available in stock
    float price;             //price per unit of the item
} GroceryItem;               //structure that stores details about each grocery item

//struct for grocery inventory
typedef struct {
    GroceryItem items[MAX_ITEMS];      //array of grocery items to store all items in inventory
    int count;                         //track number of items are currently in inventory
} GroceryInventory;         //a structure that represents the inventory of all items

//function prototypes
void addGroceryItem(GroceryInventory *inventory);
void listGroceryItems(const GroceryInventory *inventory);
void updateQuantity(GroceryInventory *inventory);
void removeGroceryItem(GroceryInventory *inventory);

int main() {
    GroceryInventory inventory = { .count = 0 }; //initialize inventory
    int choice;  //to store user's menu selection

    do {
        printf("\nMenu:\n");
        printf("1. Add Grocery Item\n");
        printf("2. List Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); //to consume newline character left in buffer

        switch (choice) {      //calls appropriate function based on choice
            case 1:
                addGroceryItem(&inventory);
                break;
            case 2:
                listGroceryItems(&inventory);
                break;
            case 3:
                updateQuantity(&inventory);
                break;
            case 4:
                removeGroceryItem(&inventory);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);     //loop continues until user selects 5

    return 0;
}

//function to add a grocery item
void addGroceryItem(GroceryInventory *inventory) {
    if (inventory->count >= MAX_ITEMS) {        //exits with an error message if inventory is full
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }

    GroceryItem *item = &inventory->items[inventory->count];     //points to next available slot in the items array

    //reads details for new items
    printf("Enter item name: ");        
    scanf(" %[^\n]%*c", (*item).name);
    printf("Enter category: ");
    scanf(" %[^\n]%*c", (*item).category);
    printf("Enter quantity: ");
    scanf("%d", &(*item).quantity);
    printf("Enter price: ");
    scanf("%f", &(*item).price);

    inventory->count++;
    printf("Item added successfully!\n");    //increments count after adding item
}

//function to list all grocery items
void listGroceryItems(const GroceryInventory *inventory) {
    if (inventory->count == 0) {
        printf("No items in inventory.\n");
        return;
    }

   //loops through all items and print their details
    printf("\nGrocery Items:\n");
    for (int i = 0; i < inventory->count; i++) {
        const GroceryItem *item = &inventory->items[i];
        printf("Item %d:\n", i + 1);
        printf("  Name: %s\n", (*item).name);
        printf("  Category: %s\n", (*item).category);
        printf("  Quantity: %d\n", (*item).quantity);
        printf("  Price: %.2f\n", (*item).price);
        printf("  Availability: %s\n", (*item).quantity > 0 ? "In Stock" : "Out of Stock");
    }
}

//function to update the quantity of a grocery item
void updateQuantity(GroceryInventory *inventory) {
    char name[100];
    printf("Enter the name of the item to update quantity: ");
    scanf(" %[^\n]%*c", name);

    //searches for items and updates its quantity
    for (int i = 0; i < inventory->count; i++) {
        GroceryItem *item = &inventory->items[i];
        if (strcmp((*item).name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &(*item).quantity);
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in inventory.\n");
}

//function to remove a grocery item
void removeGroceryItem(GroceryInventory *inventory) {
    char name[100];
    printf("Enter the name of the item to remove: ");      //reads names of items to be removed
    scanf(" %[^\n]%*c", name);

    //finds the item and shifts all subsequent items to close the gap
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            for (int j = i; j < inventory->count - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
            }
            inventory->count--;           //decrements count after removing items
            printf("Item removed successfully!\n");
            return;
        }
    }

    printf("Item not found in inventory.\n");
}
