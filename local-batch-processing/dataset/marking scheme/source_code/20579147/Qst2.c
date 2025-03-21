#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// Structure to hold the availability status of an item
struct AvailabilityStatus {
    int inStock;  // 1 means in stock, 0 means out of stock
};

// Structure to hold the details of a grocery item
struct GroceryItem {
    char name[100];       // Name of the grocery item
    char category[50];    // Category of the grocery ite
    int quantity;         // Quantity available in the store
    float price;          // Price of the item
};

// Structure to hold the entire grocery inventory
struct GroceryInventory {
    struct GroceryItem items[100];          // Array of  the grocery items
    struct AvailabilityStatus availability[100]; // Array of the  availability status for each item
    int totalItems;      // Total number of items in stock
};

// Function to add a new grocery item to the inventory
void addGroceryItem(struct GroceryInventory *inventory) {
    // Check if the inventory is full
    if (inventory->totalItems < 100) {
        struct GroceryItem newItem;
        struct AvailabilityStatus newStatus;

        // Ask the user to input item details
        printf("Enter item name: ");
        getchar(); // Clear the newline character left by previous input
        fgets(newItem.name, 100, stdin);
        newItem.name[strcspn(newItem.name, "\n")] = 0; // Remove the newline character

        printf("Enter item category: ");
        fgets(newItem.category, 50, stdin);
        newItem.category[strcspn(newItem.category, "\n")] = 0; // Remove the newline character

        printf("Enter item quantity: ");
        scanf("%d", &newItem.quantity);

        printf("Enter item price: ");
        scanf("%f", &newItem.price);

        // Ask if the item is in stock
        printf("Is the item in stock? (1 for In Stock, 0 for Out of Stock): ");
        scanf("%d", &newStatus.inStock);

        // Add the new item to the inventory
        inventory->items[inventory->totalItems] = newItem;
        inventory->availability[inventory->totalItems] = newStatus;
        inventory->totalItems++;

        printf("Item added successfully!\n");
    } else {
        printf("Inventory is full, cannot add more items.\n");
    }
}

// Function to list all the grocery items in the inventory along with their availability
void listGroceryItems(struct GroceryInventory *inventory) {
    if (inventory->totalItems == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    printf("List of Grocery Items:\n");
    for (int i = 0; i < inventory->totalItems; i++) {
        printf("Name: %s\n", inventory->items[i].name);
        printf("Category: %s\n", inventory->items[i].category);
        printf("Quantity: %d\n", inventory->items[i].quantity);
        printf("Price: $%.2f\n", inventory->items[i].price);
        printf("Availability: %s\n", inventory->availability[i].inStock ? "In Stock" : "Out of Stock");
        printf("------------------------------\n");
    }
}

// Function to update the quantity of an existing grocery item
void updateGroceryItemQuantity(struct GroceryInventory *inventory) {
    char itemName[100];
    printf("Enter the name of the item to update: ");
    getchar(); // To clear the newline character
    fgets(itemName, 100, stdin);
    itemName[strcspn(itemName, "\n")] = 0; // Remove newline

    // Search for the item by name and update its quantity
    for (int i = 0; i < inventory->totalItems; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            int newQuantity;
            printf("Enter the new quantity: ");
            scanf("%d", &newQuantity);
            inventory->items[i].quantity = newQuantity;
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in the inventory.\n");
}

// Function to remove a grocery item from the inventory
void removeGroceryItem(struct GroceryInventory *inventory) {
    char itemName[100];
    printf("Enter the name of the item to remove: ");
    getchar(); // To clear the newline character
    fgets(itemName, 100, stdin);
    itemName[strcspn(itemName, "\n")] = 0; // Remove newline

    // Search for the item by name and remove it
    for (int i = 0; i < inventory->totalItems; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            // Shift items to fill the gap
            for (int j = i; j < inventory->totalItems - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
                inventory->availability[j] = inventory->availability[j + 1];
            }
            inventory->totalItems--;
            printf("Item removed successfully!\n");
            return;
        }
    }

    printf("Item not found in the inventory.\n");
}

int main() {
    struct GroceryInventory inventory = { .totalItems = 0 };  // Initialize  empty inventory
    int choice;

    do {
        // Display the menu of options
        printf("\nGrocery Inventory Management:\n");
        printf("1. Add grocery item\n");
        printf("2. List all grocery items with their availability\n");
        printf("3. Update quantity of a grocery item\n");
        printf("4. Remove a grocery item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the corresponding action based on the user's choice snd call the fucntion
        switch (choice) {
            case 1:
                addGroceryItem(&inventory);  
                break;
            case 2:
                listGroceryItems(&inventory); 
                break;
            case 3:
                updateGroceryItemQuantity(&inventory);  
                break;
            case 4:
                removeGroceryItem(&inventory);  
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);  // Repeat until the user chooses to exit

    return 0;
}
