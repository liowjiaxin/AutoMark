// Q2 Grocey manage max amount in management 100

#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

// Struct for grocery items
struct GroceryItem {
    char name[100];
    char category[50];
    int quantity;
    float price;
};

// Struct to store grocery inventory data
struct GroceryInventory {
    struct GroceryItem items[MAX_ITEMS];
    int totalItems;  // Keeps track of the number of items in the inventory
};

// Function to add a grocery item
void addGI(struct GroceryInventory *inventory) {
    // If there is already 100 items
    if (inventory->totalItems >= MAX_ITEMS) {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }

    //else proceed to add items 
    struct GroceryItem newItem;
        printf("Enter grocery item name: ");
        getchar();  // Consume newline left by previous input the "enter" for fgets
        fgets(newItem.name, sizeof(newItem.name), stdin);
        newItem.name[strcspn(newItem.name, "\n")] = '\0';  // Remove trailing newline

        printf("Enter category: ");
        fgets(newItem.category, sizeof(newItem.category), stdin);
        newItem.category[strcspn(newItem.category, "\n")] = '\0';  // Remove trailing newline

        printf("Enter quantity: ");
        scanf("%d", &newItem.quantity);

        printf("Enter price: ");
        scanf("%f", &newItem.price);

        // Add to inventory
        inventory->items[inventory->totalItems] = newItem;
        inventory->totalItems++;

        printf("Grocery item added successfully!\n");
}

// List all grocery items
void listGI(struct GroceryInventory *inventory) {
    // If no items
    if (inventory->totalItems == 0) {
        printf("No items in inventory.\n");
        return;
    }

    // Display
    printf("Grocery Inventory:\n");
    for (int i = 0; i < inventory->totalItems; i++) {
        printf("\nItem %d:\n", i + 1);
        printf("Name: %s\n", inventory->items[i].name);
        printf("Category: %s\n", inventory->items[i].category);
        printf("Quantity: %d\n", inventory->items[i].quantity);
        printf("Price: $%.2f\n", inventory->items[i].price);
        
        // Automatically determine availability based on quantity
        printf("Availability: %s\n", (inventory->items[i].quantity > 0) ? "In Stock" : "Out of Stock");
    }
}

// Function to update quantity of a grocery item
void update(struct GroceryInventory *inventory) {
    int itemIndex, newQuantity;
    listGI(inventory);  // Show current items

    printf("Enter the index of the item to update (1 to %d): ", inventory->totalItems);
    scanf("%d", &itemIndex);

    if (itemIndex < 1 || itemIndex > inventory->totalItems) {
        printf("Invalid item index.\n");
        return;
    }

    printf("Enter the new quantity: ");
    scanf("%d", &newQuantity);

    // Update the quantity
    inventory->items[itemIndex - 1].quantity = newQuantity;
    printf("Quantity updated successfully!\n");
}

// Function to remove a grocery item
void removeGI(struct GroceryInventory *inventory) {
    int itemIndex;
    listGI(inventory);  // Show current items

    printf("Enter the index of the item to remove (1 to %d): ", inventory->totalItems);
    scanf("%d", &itemIndex);

    if (itemIndex < 1 || itemIndex > inventory->totalItems) {
        printf("Invalid item index.\n");
        return;
    }

    // Shift items after the deleted one to fill the gap
    for (int i = itemIndex - 1; i < inventory->totalItems - 1; i++) {
        inventory->items[i] = inventory->items[i + 1];
    }

    inventory->totalItems--;  // Decrease the total count of items
    printf("Item removed successfully!\n");
}

int main() {
    struct GroceryInventory inventory = { .totalItems = 0 };  // Initialize inventory

    int choice;
    int valid = 0;

    while (1) {
        // Display menu
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List all Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        // Input validation
        if (choice >= 1 && choice <= 5) {
            valid = 1;
        } else {
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
            valid = 0;
        }

        if (valid) {
            switch (choice) {
                case 1:  // Add
                    addGI(&inventory);
                    break;
                case 2:  // List
                    listGI(&inventory);
                    break;
                case 3:  // Update Quantity
                    update(&inventory);
                    break;
                case 4:  // Remove Item
                    removeGI(&inventory);
                    break;
                case 5:  // Exit
                    printf("Exiting the program.\n");
                    return 0;
                default:
                    break;
            }
        }
    }

    return 0;
}
