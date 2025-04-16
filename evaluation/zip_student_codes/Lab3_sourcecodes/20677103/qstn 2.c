#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a structure to represent a grocery item
typedef struct {
    char name[100];       // Name of the item
    char category[50];    // Category of the item
    int quantity;         // Quantity of the item
    float price;          // Price of the item
} groceryItem;

// Define a union to represent the availability status of an item
typedef union {
    bool inStock;         // Indicates if the item is in stock
    bool noStock;         // Indicates if the item is out of stock
} availabilityStatus;

// Define a structure to represent the grocery inventory
typedef struct {
    groceryItem item[100];         // Array of grocery items
    availabilityStatus status[100]; // Array of availability statuses
    int inventoryCount;            // Number of items in the inventory
} groceryInventory;

// Declare a global pointer to the grocery inventory
groceryInventory* inventory;

// Function to add a new grocery item to the inventory
void addItem() {
    // Point to the next available slot in the item array
    groceryItem* addedItem = &inventory->item[inventory->inventoryCount]; 

    // Prompt user to enter item name
    printf("Enter Item name:\n");
    fgets(addedItem->name, sizeof(addedItem->name), stdin);  // Read the item name from standard input
    strtok(addedItem->name, "\n");  // Remove the newline character from the name

    // Prompt user to enter category
    printf("Enter category:\n");
    fgets(addedItem->category, sizeof(addedItem->category), stdin);  // Read the category from standard input
    strtok(addedItem->category, "\n");  // Remove the newline character from the category

    // Prompt user to enter quantity
    printf("Enter quantity:\n");
    scanf("%d", &addedItem->quantity);  // Read the quantity from standard input
    getchar();  // Consume the newline character left by scanf

    // Prompt user to enter price
    printf("Enter price:\n");
    scanf("%f", &addedItem->price);  // Read the price from standard input
    getchar();  // Consume the newline character left by scanf

    // Update the availability status based on the quantity
    inventory->status[inventory->inventoryCount].inStock = (addedItem->quantity > 0);

    // Increment the inventory count
    inventory->inventoryCount++;
    printf("Grocery item added successfully!\n");
}

// Function to list all grocery items in the inventory
void listItems() {
    // Check if inventory is empty
    if (inventory->inventoryCount == 0) {
        printf("No grocery items in the inventory\n");
    } else {
        // Loop through all items in the inventory and display their details
        for (int i = 0; i < inventory->inventoryCount; i++) {
            groceryItem* item = &inventory->item[i];  // Point to the current item in the array
            printf("Name: %s\nCategory: %s\nQuantity: %d\nPrice: $%.2f\nStatus: %s\n\n",
                   item->name, item->category, item->quantity, item->price,
                   inventory->status[i].inStock ? "In Stock" : "Out of Stock");
        }
    }
}

// Function to update the quantity of a specific grocery item
void updateQuantity() {
    char itemName[100];
    // Prompt user to enter the name of the item to update
    printf("Enter name of the grocery item to update quantity:\n");
    fgets(itemName, sizeof(itemName), stdin);  // Read the item name from standard input
    strtok(itemName, "\n");  // Remove the newline character from the item name

    // Loop through the inventory to find the item
    for (int i = 0; i < inventory->inventoryCount; i++) {
        if (strcmp(inventory->item[i].name, itemName) == 0) {
            int addedQuantity;

            // Prompt user to enter the new quantity
            printf("Enter new quantity for %s:\n", itemName);
            scanf("%d", &addedQuantity);  // Read the new quantity from standard input
            getchar();  // Consume the newline character left by scanf

            // Update the item's quantity and availability status
            inventory->item[i].quantity = addedQuantity;
            inventory->status[i].inStock = (addedQuantity > 0);
            printf("Quantity updated successfully\n");
            return;
        }
    }
    printf("Item not found in inventory\n");
}

// Function to remove a specific grocery item from the inventory
void removeItems() {
    char itemName[100];
    // Prompt user to enter the name of the item to remove
    printf("Enter name of grocery item to remove:\n");
    fgets(itemName, sizeof(itemName), stdin);  // Read the item name from standard input
    strtok(itemName, "\n");  // Remove the newline character from the item name

    // Loop through the inventory to find the item
    for (int i = 0; i < inventory->inventoryCount; i++) {
        if (strcmp(inventory->item[i].name, itemName) == 0) {
            // Shift all subsequent items one position to the left
            for (int j = i; j < inventory->inventoryCount - 1; j++) {
                inventory->item[j] = inventory->item[j + 1];
                inventory->status[j] = inventory->status[j + 1];
            }
            // Decrement the inventory count
            inventory->inventoryCount--;
            printf("Item removed successfully!\n");
            return;
        }
    }
    printf("Item not found in inventory\n");
}

// Main function to drive the program
int main() {
    // Allocate memory for the inventory
    inventory = (groceryInventory*)malloc(sizeof(groceryInventory));  
    if (!inventory) {  // Check if memory allocation was successful
        printf("Memory allocation failed!\n");
        return 1;
    }
    // Initialize the inventory count to 0
    inventory->inventoryCount = 0;  

    int choice = 0;
    while (choice != 5) {
        // Display the menu options
        printf("Grocery Inventory Management System\n");
        printf("1. Add grocery item\n");
        printf("2. List all grocery items\n");
        printf("3. Update quantity\n");
        printf("4. Remove grocery item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume the newline character

        // Handle the user's choice
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                listItems();
                break;
            case 3:
                updateQuantity();
                break;
            case 4:
                removeItems();
                break;
            case 5:
                printf("Exited\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    // Free the allocated memory for the inventory
    free(inventory);
    return 0;
}
