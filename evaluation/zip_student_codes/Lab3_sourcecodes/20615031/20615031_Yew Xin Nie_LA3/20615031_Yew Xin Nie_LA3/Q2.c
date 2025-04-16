#include <stdio.h>
#include <string.h>
#include <stdbool.h>    // for boolean

#define MAX_ITEMS 100   // MAX SIZE for Grocery Items
#define MAX_NAME_LENGTH 100
#define MAX_CATEGORY_LENGTH 50

// Struct definitions //
typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    float price;
    bool inStock;
} GroceryItem;

typedef struct {
    GroceryItem items[MAX_ITEMS];   // array of GroceryItem (all grocery list in array)
    int itemCount;  // track how many items are currently in the inventory
} GroceryInventory;

// Function prototypes //
void addGroceryItem(GroceryInventory *inventory);
void listGroceryItems(GroceryInventory *inventory);
void updateItemQuantity(GroceryInventory *inventory);
void removeGroceryItem(GroceryInventory *inventory);

int main() {
    // Initialize the inventory //
    GroceryInventory inventory = { .itemCount = 0 };    
    int choice = 0;


    do {
        // Display Menu //
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity of Grocery Item\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addGroceryItem(&inventory);
                break;
            case 2:
                listGroceryItems(&inventory);
                break;
            case 3:
                updateItemQuantity(&inventory);
                break;
            case 4:
                removeGroceryItem(&inventory);
                break;
            case 5:
                printf("Exiting program. Have a nice day, Bye bye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

// Function to add a grocery item //
void addGroceryItem(GroceryInventory *inventory) {
    // Check the inventory does not exceed the maximum size //
    if (inventory->itemCount >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }
    
    // Create a pointer (item) directly points the next slot in the array //
    GroceryItem *item = &inventory->items[inventory->itemCount];

    printf("Enter item name: ");
    getchar(); // Clear newline from input buffer 
    fgets(item->name, MAX_NAME_LENGTH, stdin); // Recieve data input for item name
    item->name[strcspn(item->name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter item category: ");
    fgets(item->category, MAX_CATEGORY_LENGTH, stdin); // Receive data input of category
    item->category[strcspn(item->category, "\n")] = '\0'; 

    printf("Enter quantity: ");
    scanf("%d", &item->quantity);

    printf("Enter price: ");
    scanf("%f", &item->price);

    // Automatically update the stock availability status //
    // inStock = true : item > 0 
    // inStock = false: item < 0 (Out of stock)
    item->inStock = (item->quantity > 0);

    // increment of itemCount as each time the user add
    inventory->itemCount++;
    printf("Grocery item added successfully!\n");
}

// Function to list all grocery items
void listGroceryItems(GroceryInventory *inventory) {
    // Check if inventory is empty or not
    if (inventory->itemCount == 0) {
        printf("No items in inventory.\n");
        return;
    }

    printf("\tListing All Grocery Items\t\n");
    printf("\nGrocery Items:\n");
    for (int i = 0; i < inventory->itemCount; i++) {
        GroceryItem *item = &inventory -> items[i];

        printf("Name: %s\nCategory: %s\nQuantity: %d\nPrice: %.2f\nStatus: %s\n",
               item->name, item->category, item->quantity, item->price,
               item->inStock ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of a grocery item
void updateItemQuantity(GroceryInventory *inventory) {
    //Check if inventory is empty
    if (inventory->itemCount == 0) {
        printf("No items in inventory to update.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the item to update: ");
    getchar(); // Clear newline from input buffer
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0';   // remove new line character from the input string

    // Search grocery item in inventory //
    for (int i = 0; i < inventory->itemCount; i++) {
        GroceryItem *item = &inventory -> items[i];
        if (strcmp(item->name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &item->quantity);
            item->inStock = (item->quantity > 0);
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in inventory.\n");
}

// Function to remove a grocery item
void removeGroceryItem(GroceryInventory *inventory) {
    //Check if inventory is empty
    if (inventory->itemCount == 0) {
        printf("No items in inventory to remove.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the item to remove: ");
    getchar(); // Clear newline from input buffer
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0';

    // Search grocery item in inventory //
    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            for (int j = i; j < inventory->itemCount - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
            }
            inventory->itemCount--;     // removing item from inventory
            printf("Grocery item '%s' removed successfully!\n", name);
            return; // return value to the function
        }
    }

    printf("Item not found in inventory.\n");
}
